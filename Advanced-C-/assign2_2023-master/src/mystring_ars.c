#include <stdio.h>
#include "mystring.h"
#include <stddef.h>
#include <assert.h>
#define MAX_SIZE 100


size_t ms_length(const char pcStr[]) { /*epistrefei to mhkos tou string */
    size_t uiLength = 0U;
    assert(pcStr);
    while (pcStr[uiLength] != '\0'){
        uiLength++;
    }
    return uiLength;
}

char * ms_copy(char st1[],const char st2[]){ /* antigrafei to 2o string sto 1o kai epistrefei to 1o*/
    size_t i = 0U;
    assert(st2);
    assert(st1);
    for(i=0; st2[i] != '\0'; i++){
        st1[i] = st2[i];
    }
    st1[i] = '\0';
    return st1;

}

char * ms_ncopy(char st1[], const char st2[],size_t n){ /* antigrafei n xarakthres tou st2 sto st1 kai an to mhkos tou st2 einai mikrotero tou n tote to upoloipo tha simplirothei me null bytes*/
    size_t i;
    assert(st1);
    assert(st2);
    if (n> ms_length(st2)) {
        for (i=0U; i <ms_length(st2); i++) {
            st1[i] = st2[i];
        }
        for (i = ms_length(st2)+1; i <n-ms_length(st2); i++) {
            st1[i] = '\0';
        }
    } else{
        for (i=0U; i <n; i++) {
            st1[i] = st2[i];
        }
        st1[i] = '\0';
    }
    return st1;
}

char * ms_concat(char  st1[] ,const char st2[] ){ /* prosthetei to st2 sto telos tou st1 kai epistrefei to st1*/
    size_t  i, len1, len2;
    assert(st1);
    assert(st2);
    len1 = ms_length(st1);
    len2 = ms_length(st2);
    for( i=0; i< len2; i++){
        st1[len1+i] = st2[i];
    }
    return st1;
}

char * ms_nconcat (char st1[], const char st2[], size_t n){/* prosthetei to st2 sto telos tou st1 me mhkos mexri n xarakthres*/
    size_t i, lend;
    assert(st1);
    assert(st2);

    lend = ms_length(st1);

    for(i=0; i < n; i++)
    {
        if(st2[i] != '\0')
        {
            st1[lend + i] = st2[i];
        }
        else
        {
            break;
        }
    }
    for(; i<n; i++)
    {
        st1[i] = '\0';
    }

    return st1;

}

int ms_compare (const char st1[] , const char st2[]){ /* sigkrinei to st1 me to st2. Epistrefei -1 an st1<st2, 1 an st2< st1 kai an st1=st2*/
    size_t i, len1, len2;
    assert(st1);
    assert(st2);
    len1 = ms_length(st1);
    len2 = ms_length(st2);
    i = 0;
    while(st1[i] == st2[i])
    {
        if(i == len1 || i == len2)
        {
            return 0;
        }
        i++;
    }

    if(st1[i] > st2[i])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int ms_ncompare(const char st1[] , const char st2[] , size_t n){ /*sigkrinei to poly ta prwta n bytes twn st1 kai st2. Epistrefei -1 an st1<st2, 1 an st2<st1, 0 an st1=st2*/
    size_t i=0U;
    assert(n!=0);
    assert(st1 !=NULL && st2 != NULL);
    while(st1[i] == st2[i] && i<n){
       i++;
    }
    if(i==n){
        return 0;
    }
    return ((st1[i]<st2[i]) ? -1 : +1);
}

char * ms_search(char st1[] , const char st2[]) {/* vriskei thn prwth emfanish tou st2 sto st1*/
    size_t i, len1, len2;
    assert(st1);
    assert(st2);

    len1 = ms_length(st1);
    len2 = ms_length(st2);
    for (i = 0; i < len1 - len2; i++) {
        if (ms_ncompare(&st1[i], st2, len2) == 0) {
            return &(st1[i]);
        }
    }
    return NULL;
}

