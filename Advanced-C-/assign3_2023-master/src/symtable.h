//
// Created by Μαρία Αλατσάκη on 10/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct SymTable_S *SymTable_T;

SymTable_T SymTable_new(void); /*epistrefei enan kainourgio SymTable_T pou einai adeio*/
void SymTable_free(SymTable_T oSymTable); /*kanei free olh thn mnhmh pou xrhsimopoieitai*/
unsigned int SymTable_getLength(SymTable_T oSymTable); /* epistrefei ton arithmo twn bindings sto oSymTable*/
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue);/*an den uparxei binding me pckey prosthetei ena kainourgio binding pou tha apoteleitai apo to pc key kai th timh pvValue kai epistrefei 1, alliws epistrefei 0*/
int SymTable_remove(SymTable_T oSymTable, const char *pcKey);/* an uparxei ena binding me kleidi pckey afairei to binding kai epistrefei 1 alliws epistrfei 0*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey); /* an to oSymTable periexei binding me pcKey epistrefei 1 alliws 0*/
void *SymTable_get(SymTable_T oSymTable, const char *pcKey); /* epistrefei thn timh tou binding sto oSymTable tou opoiou to kleidi einai pckey h null an den yparxei*/
void SymTable_map(SymTable_T oSymTable, void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),const void *pvExtra); /* prepei na efarmozei thn *pfApply se kathe binding sto oSymTable pernontas to pvextra ws epipleon parametro*/


