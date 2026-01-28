#include<stdio.h>
#include<assert.h>
#include<stddef.h>

size_t ms_length(const char *pcStr); /* epistrefei to mhkos tou string alla oxi tou termatikou xarakthra null */

char * ms_copy(char *st1,const char *st2); /*antigrafei to st2 sto st1 kai to epistrefei*/


char * ms_ncopy(char * st1, const char * st2,size_t n); /* antigrafei n xarakthres tou st2 sto st1 kai an to mhkos tou st2 einai mikrotero tou n tote to upoloipo tha simplirothei me null bytes*/

char * ms_concat(char * st1 ,const char *st2 );/* prosthetei to st2 sto telos tou st1*/

char * ms_nconcat (char * st1, const char *st2, size_t n); /* prosthetei to st2 sto telos tou st1 me mhkos mexri n xarakthres*/

int ms_compare (const char * st1 , const char * st2); /*sigkrinei to st1 me to st2. Epistrefei -1 an st1<st2, 1 an st2<st1, 0 an st1=st2 */


int ms_ncompare(const char * st1 , const char * st2 , size_t n);/* sigkrinei to poly ta prwta n bytes twn st1 kai st2.Epistrefei Epistrefei -1 an st1<st2, 1 an st2<st1, 0 an st1=st2*/


char * ms_search(char * st1 , const char * st2); /* vriskei thn prwth emfanish tou st2 sto st1*/
