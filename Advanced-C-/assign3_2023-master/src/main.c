#include "symtable.h"

void print(const char *pcKey, void *pvValue, void *pvExtra){
    printf("Entry %s -> %s\n", pcKey, (char *)pvValue);
}


int main(){
    SymTable_T xrwmata = SymTable_new();
    int i;
    char result[50];

    if(SymTable_put(xrwmata, "mple", "blue")){
        printf("PASS: YOU ADDED ONE ELEMENT\n ");
    }else{
        printf("FAIL: Symtable_put\n");
    }
    if(!SymTable_put(xrwmata,"mple","blue")){
        printf("PASS: DID NOT ADD SECOND INSTANCE\n");
    }else{
        printf("FAIL: Symtable_put dublicate entry\n");
    }
    if(SymTable_put(xrwmata, "prasino", "green")){
        printf("PASS: ADDED 2 ELEMENT\n");
    }else{
        printf("FAIL: SymTable_put");
    }
    if(SymTable_put(xrwmata,"mov", "purple")){
        printf("PASS: ADDED 3 ELEMENT\n");
    }else{
        printf("FAIL: SymTable_put");
    }
    if(SymTable_remove(xrwmata,"mov")){
        printf("PASS: REMOVED 3RD ELEMENT\n");
    }else{
        printf("FAIL: SymTable_remove failed\n");
    }
    for(i=0;i<67000; i++){
        sprintf(result,"name%d", i);
        SymTable_put(xrwmata,result,"value");
    }
    if(SymTable_remove(xrwmata,"xrwma45")){
        printf("PASS: REMOVED XRWMA45 ELEMENT\n");
    }else{
        printf("FAIL: SymTable_remove failed\n");
    }
    if(!SymTable_get(xrwmata,"xrwma45")){
        printf("PASS: REMOVED XRWMA45 ELEMENT\n");
    }else{
        printf("FAIL: SymTable_remove function failed\n");
    }
    if(SymTable_get(xrwmata,"xrwma66")){
        printf("PASS: Got xrwma66: %s element\n", (char*)SymTable_get(xrwmata, "xrwma66"));
    }else{
        printf("FAIL: FAIL: SymTable_get failed\n");
    }
    /* SymTable_map(xrwmata,print,"");*/
    SymTable_free(xrwmata);
    return 0;

}
