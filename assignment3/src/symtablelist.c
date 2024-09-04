#include "symtable.h"

struct node_binding{
    char* key;
    void* value;
    struct node_binding* ptr_next;
};

struct SymTable{
    struct node_binding* head;
    unsigned int size;
};

struct node_binding * Basic_check(SymTable_T oSymTable, const char *pcKey){
    struct node_binding *temp;
    assert(oSymTable);
    assert(pcKey); 
    temp=oSymTable->head;
    return temp;
}

SymTable_T SymTable_new(){
    SymTable_T new_table=malloc(sizeof(SymTable_T*));
    assert(new_table);
    new_table->size =0U;
    new_table->head = NULL;
    return new_table;
}

void SymTable_free(SymTable_T oSymTable){
    struct node_binding* temp;
    struct node_binding* nxt;

    if(!oSymTable) return;
    
    temp=oSymTable->head;

    while(temp){
        nxt=temp->ptr_next;
        free(temp->key);
        free(temp->value);
        free(temp);
        temp=nxt;
    }

    free(oSymTable);
    return;

}

unsigned int SymTable_getLength(SymTable_T oSymTable){
    assert(oSymTable);
    return oSymTable->size;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue){
    struct node_binding *temp;
    temp=Basic_check(oSymTable, pcKey);   
    
    if(SymTable_contains(oSymTable,pcKey))
        return 0;

    temp = malloc(sizeof(struct node_binding));
    assert(temp);
    temp->key =malloc(strlen(pcKey) + 1);/*+1 for \0*/

    strcpy(temp->key,pcKey);

    temp->ptr_next = oSymTable->head;
    temp->value = (void*)pvValue;/**/
    
    oSymTable->size++;
    oSymTable->head = temp;
    
    return 1;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    struct node_binding *prev;
    struct node_binding *curr;
    curr=Basic_check( oSymTable, pcKey);   

    for(;curr!=NULL;){
        if(strcmp(curr->key,pcKey)==0){
            if(curr==prev) oSymTable->head=curr->ptr_next;
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

void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra){
    struct node_binding *curr;
    assert(oSymTable);
    curr=oSymTable->head;
    assert(pfApply); 
    for(;curr!=NULL;) {
        pfApply(curr->key,curr->value,(void*)pvExtra);
        curr=curr->ptr_next;
    }

    return;
}
