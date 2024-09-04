#include"symtable.h"

/*void print_bindings(SymTable_T oSym){
	node  curr=oSym.head;
	while(curr){

	printf("key:%s value: %s",curr->key,(char*)curr->value);
	curr=curr.ptr_next;
	}
	return;
}
*/
int main(){
	SymTable_T food = SymTable_new();
	

	SymTable_put(food,"pizza","8");
	SymTable_put(food,"patates","2");
	SymTable_put(food,"makaronia","1");

	SymTable_remove(food,"makaronia");
	
	SymTable_get(food,"patates");




	SymTable_free(food);
	return 0;

}
