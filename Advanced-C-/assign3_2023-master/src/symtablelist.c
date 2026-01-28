#include "symtable.h"

struct binding{
    char *key;
    void *value;
    struct binding *next;
};

struct SymTable_S{
    struct binding *head;
    unsigned int size;
};

SymTable_T SymTable_new(void){ /*epistrefei enan kainourgio SymTable_T pou einai adeio*/
    SymTable_T new = malloc(sizeof(SymTable_T));
    assert(new);
    new -> size = 0;
    new -> head = NULL;
    return new;
}

void SymTable_free(SymTable_T oSymTable){ /*kanei free olh thn mnhmh pou xrhsimopoieitai*/
    struct binding *tmp;
    struct binding *nexttmp;
    if(oSymTable == NULL){
        return;
    }
    tmp = oSymTable -> head;
    while(tmp){
        nexttmp = tmp ->next;
        free(tmp ->key);
        free(tmp);
        tmp = nexttmp;
    }
    free(oSymTable);
}

unsigned int SymTable_getLength(SymTable_T oSymTable){ /* epistrefei ton arithmo twn bindings sto oSymTable*/
    assert(oSymTable);
    return oSymTable -> size;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue){/*an den uparxei binding me pckey prosthetei ena kainourgio binding pou tha apoteleitai apo to pc key kai th timh pvValue kai epistrefei 1, alliws epistrefei 0*/
    char *tmpkey;
    struct binding *newnode;
    assert(oSymTable && pcKey);
    if(SymTable_contains(oSymTable,pcKey) == 1){
        return 0;
    }
    tmpkey = (char *) malloc(strlen(pcKey) +1);
    assert(tmpkey);
    strcpy(tmpkey,pcKey);

    newnode = (struct binding *) malloc(sizeof(struct binding*));
    assert(newnode);
    newnode ->key = tmpkey;
    newnode -> value = (void*) pvValue;
    newnode -> next = oSymTable -> head;
    oSymTable ->head = newnode;
    oSymTable -> size++;
    return 1;
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){ /* an uparxei ena binding me kleidi pckey afairei to binding kai epistrefei 1 alliws epistrfei 0*/
    struct binding *current;
    struct binding *previous;
    assert(oSymTable && pcKey);
    current = oSymTable ->head;
    while(current){
        if(strcmp(current ->key,pcKey) ==0){
            break;
        }else{
            previous = current;
            current = current ->next;
        }
    }

    if(current != NULL){ /* an to key value den vrethei sthn lista*/
        if(previous == NULL){
            oSymTable -> head = current ->next;
        }else{
            previous -> next = current ->next;
        }

        free(current ->key);
        free(current);
        oSymTable -> size--;
        return 1;
    }
    return 0;
}
int SymTable_contains(SymTable_T oSymTable, const char *pcKey){ /* an to oSymTable periexei binding me pcKey epistrefei 1 alliws 0*/
    struct binding *current;
    assert(oSymTable);
    assert(pcKey);
    current = oSymTable -> head;
    while(current){
        if(strcmp(current ->key,pcKey) == 0 ){
            return 1;
        }
        current = current ->next;
    }
    return 0;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){/* epistrefei thn timh tou binding sto oSymTable tou opoiou to kleidi einai pckey h null an den yparxei*/
    struct binding *current;
    assert(oSymTable && pcKey);
    current = oSymTable ->head;
    while(current){
        if(strcmp(current ->key, pcKey) ==0){
            return current -> value;
        }
        current = current ->next;
    }
    return NULL;
}

void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra){ /* prepei na efarmozei thn *pfApply se kathe binding sto oSymTable pernontas to pvextra ws epipleon parametro*/
    struct binding *current;
    assert(oSymTable);
    assert(pfApply);
    current = oSymTable -> head;
    while(current!=NULL){
        pfApply((const char *)(current ->key), current ->value, (void*)pvExtra);
        current = current ->next;
    }
}

