#include "symtable.h"

#define HASH_MULTIPLIER 65599
#define STARTING_BUCKETS 509

struct binding {
    char *key;
    void *value;
    struct binding *next;
};

struct SymTable_S {
    struct binding** table;
    unsigned int size;
};

static unsigned int SymTable_hash(const char *pcKey) { /* returns a hash code for pcKey*/
    size_t ui;
    unsigned int uiHash = 0U;
    for (ui = 0U; pcKey[ui] != '\0'; ui++)
        uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
    return uiHash % STARTING_BUCKETS;
}

SymTable_T SymTable_new(void){ /* ftiaxnei ena neo object tou hash list*/
    SymTable_T new = malloc(sizeof(SymTable_T));
    assert(new);
    new -> table = malloc(STARTING_BUCKETS * sizeof(struct binding*));
    new -> size = 0;
    return new;
}

unsigned int SymTable_getLength(SymTable_T oSymTable){ /* epistrefei to megethos tou table*/
    assert(oSymTable);
    return oSymTable ->size;
}

int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue) {
    char *tmpkey;
    struct binding *newnode;
    unsigned int position;
    assert(oSymTable && pcKey);
    if (SymTable_contains(oSymTable, pcKey) == 1) {
        return 0;
    }
    tmpkey = (char *) malloc(strlen(pcKey) + 1);
    assert(tmpkey);
    strcpy(tmpkey, pcKey);

    newnode = (struct binding *) malloc(sizeof(struct binding*));
    assert(newnode);
    newnode->key = tmpkey;
    newnode->value = (void *) pvValue;

    position = SymTable_hash(pcKey);
    newnode->next = oSymTable->table[position];
    oSymTable->table[position] = newnode;
    oSymTable->size++;
    return 1;
}

void SymTable_free(SymTable_T oSymTable){
    struct binding *tmp;
    struct binding *nexttmp;
    int i;
    if(oSymTable == NULL){
        return;
    }
    for(i=0; i<STARTING_BUCKETS; i++){
        tmp = oSymTable ->table[i];
        while(tmp){
            nexttmp = tmp->next;
            free(tmp ->key);
            free(tmp);
            tmp = nexttmp;
        }
    }
    free(oSymTable->table);
    free(oSymTable);
}

int SymTable_remove(SymTable_T oSymTable, const char *pcKey){
    struct binding *current;
    struct binding *previous;
    assert(oSymTable && pcKey);

    current = oSymTable ->table[SymTable_hash(pcKey)];
    previous = NULL;
    while(current){
        if(strcmp(current->key,pcKey) == 0){
            break;
        }
        previous = current;
        current = current ->next;
    }
    if(current ==NULL){
        return 0;
    }
    if(previous==NULL){
        oSymTable ->table[SymTable_hash(pcKey)] = current ->next;
    }else{
        previous ->next = current -> next;
    }
    free(current ->key);
    free(current);
    oSymTable ->size--;
    return 1;
}

int SymTable_contains(SymTable_T oSymTable, const char *pcKey){
    struct binding *current;
    assert(oSymTable && pcKey);
    current = oSymTable->table[SymTable_hash(pcKey)];
    while(current){
        if(strcmp(current->key,pcKey) ==0){
            return 1;
        }
        current = current ->next;
    }
    return 0;
}

void *SymTable_get(SymTable_T oSymTable, const char *pcKey){
    struct binding *current;
    assert(oSymTable && pcKey);
    current = oSymTable ->table[SymTable_hash(pcKey)];
    while(current){
        if(strcmp(current->key,pcKey) ==0){
            return current->value;
        }
        current = current ->next;
    }
    return NULL;
}

void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra){
    struct binding *current;
    int i;
    assert(oSymTable);
    assert(pfApply);
    for(i=0; i<STARTING_BUCKETS; i++){
        for(current = oSymTable->table[i]; current; current = current->next){
            pfApply((const char*)(current ->key), current ->value, (void*) pvExtra);
        }
    }
}
