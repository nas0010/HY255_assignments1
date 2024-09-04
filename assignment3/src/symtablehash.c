#include "symtable.h"

#define HASH_MULTIPLIER 65599
#define BUCKETS 509U

struct node_binding{
    char* key;
    void* value;
    struct node_binding* ptr_next;
};

struct SymTable{
    struct node_binding** array;
    unsigned int size;
    unsigned int buck;
    
};
/*given hash function*/
static unsigned int SymTable_hash(const char *pcKey){
		size_t ui;

		unsigned int uiHash = 0U;

		for (ui = 0U; pcKey[ui] != '\0'; ui++)

			uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];

		return uiHash;

}
struct node_binding * Basic_check(SymTable_T oSymTable, const char *pcKey){
    struct node_binding *temp;
    assert(oSymTable);
    assert(pcKey); 
    temp= oSymTable->array[SymTable_hash(pcKey)];
    return temp;
}

SymTable_T SymTable_new(void){
    SymTable_T new_sym=malloc(sizeof(SymTable_T*));
    assert(new_sym);
    new_sym->array=malloc(BUCKETS*sizeof(struct node_binding*));
    assert(new_sym->array);
    new_sym->buck = BUCKETS;
    new_sym->size =0U;
    
    return new_sym;
}


unsigned int SymTable_getLength(SymTable_T oSymTable){
    assert(oSymTable);
    return oSymTable->size;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey,const void *pvValue){
    struct node_binding *temp;
    assert(oSymTable);
    assert(pcKey);

    if(SymTable_contains(oSymTable,pcKey))  return 0;

    temp = malloc(sizeof(struct node_binding));
    assert(temp);
    temp->key =malloc(strlen(pcKey) + 1);/*+1 for \0*/
    temp->value=(void*)pvValue;
    strcpy(temp->key,pcKey);

    temp->ptr_next = oSymTable->array[SymTable_hash(pcKey)];
    oSymTable->size++;
    oSymTable->array[SymTable_hash(pcKey)] = temp;
    
    return 1;
}

void SymTable_free(SymTable_T oSymTable){
    struct node_binding* temp;
    struct node_binding* nxt;
    int i;

    if(!oSymTable) return;
        
    for(i=0;i<BUCKETS;i++){
        temp = oSymTable->array[i];

        while(temp){
            nxt=temp->ptr_next;
            free(temp->key);
            free(temp->value);
            free(temp);
            temp=nxt;
        }
    }


    free(oSymTable->array);
    return;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    struct node_binding *prev,*curr;
    curr=Basic_check(oSymTable, pcKey); 
    
    for(;curr!=NULL;){
        if(strcmp(curr->key,pcKey)==0){
            if(curr==prev)  oSymTable->array[SymTable_hash(pcKey)] = curr->ptr_next;
            else prev->ptr_next=curr->ptr_next;
            free(curr->key);
            free(curr->value);
            free(curr);
            oSymTable->size--;
            return 1;
        }else{
                prev=curr;
                curr=curr->ptr_next;
            }
        
    }
    return 0;
}

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
    struct node_binding *curr;
    curr=Basic_check(oSymTable, pcKey);   

    for(;curr!=NULL;){
        if(strcmp(pcKey,curr->key)==0) return 1;
        curr=curr->ptr_next;
    }
    return 0;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
    struct node_binding *curr;
    curr=Basic_check(oSymTable, pcKey);   

    for(;curr!=NULL;) {
        if(strcmp(pcKey,curr->key)==0) return curr->value;
        curr=curr->ptr_next;
    }
    return NULL;
}

void SymTable_map(SymTable_T oSymTable,void (*pfApply)(const char *pcKey, void *pvValue,void *pvExtra),const void *pvExtra){
    int i;
    struct node_binding* curr;
    assert(oSymTable);

    for(i=0;i<oSymTable->buck;i++){
        curr = oSymTable->array[i];
        while(curr){
           pfApply((const char *)(curr->key),curr->value,(void*)pvExtra);
            curr = curr ->ptr_next;
        }
    }
}
