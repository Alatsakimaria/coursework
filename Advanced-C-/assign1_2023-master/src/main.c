/* main.c  Alatsaki Maria Foteini csd4584 */

#include <stdio.h>
#define tonos 39
#define dialytika 34



void fill(char grammata[256][3]){ /*gemizei ton pinaka */
    int i = 0,j = 0;
    char mikra[] = "avgdezh8iklmnqoprsstyfxyw";
    char kefalaia[] = "AVGDEZH8IKLMNQOPR-STYFXYW";

    for(i = 0; i < 256; i++)
    {
        grammata[i][0] = i;
        grammata[i][1] = '\0';
        grammata[i][2] = '\0';
    }
    /*gia ta mikra*/
    for(i = 225; i < 250; i++)
    {
        grammata[i][0] = mikra[j];
        j++;
    }

    /*gia ta kefalaia*/
    j=0;
    for(i = 193; i <218; i++)
    {
        grammata[i][0] = kefalaia[j];
        j++;
    }

    /*gia ta mikra me tonous*/
    grammata[220][0] = 'a';
    grammata[220][1] = tonos;
    grammata[221][0] = 'e';
    grammata[221][1] = tonos;
    grammata[222][0]  = 'h';
    grammata[222][1] = tonos;
    grammata[223][0] = 'i';
    grammata[223][1] = tonos;
    grammata[252][0] = 'o';
    grammata[252][1] = tonos;
    grammata[253][0] = 'y';
    grammata[253][1] = tonos;
    grammata[254][0] = 'w';
    grammata[254][1] = tonos;
    /*gia ta kefalaia me tonous*/
    grammata[182][0] = tonos;
    grammata[182][1] = 'A';
    grammata[184][0] = tonos;
    grammata[184][1] = 'E';
    grammata[185][0] = tonos;
    grammata[185][1] = 'H';
    grammata[186][0] = tonos;
    grammata[186][1] = 'I';
    grammata[188][0] = tonos;
    grammata[188][1] = 'O';
    grammata[190][0] = tonos;
    grammata[190][1] = 'Y';
    grammata[191][0] = tonos;
    grammata[191][1] = 'W';
    /*gia ta dialytika*/
    grammata[218][0] = 'I';
    grammata[218][1] = dialytika;
    grammata[219][0] = 'Y';
    grammata[219][1] = dialytika;
    grammata[250][0] = 'i';
    grammata[250][1] = dialytika;
    grammata[251][0] = 'u';
    grammata[251][1] = dialytika;
    grammata[192][0] = 'i';
    grammata[192][1] = tonos;
    grammata[192][2] = dialytika;
    grammata[224][0] = 'u';
    grammata[224][1] = tonos;
    grammata[224][2] = dialytika;
    /*eidikes periptwseis*/
    grammata[238][0] = 'k';
    grammata[238][1] = 's'; /*  ks*/
    grammata[248][0] = 'p';
    grammata[248][1] = 's'; /*  ps*/
    grammata[206][0] = 'K';
    grammata[206][1] = 'S'; /*  KS*/
    grammata[216][0] = 'P';
    grammata[216][1] = 'S'; /*  PS*/
}
void printstate(int c) /*diatrexei ton pinaka oti den einai adeio kanei print*/
{
    char grammata[256][3];
    fill(grammata);

    if(grammata[c][0] != '\0'){
        putchar(grammata[c][0]);
    }
    if(grammata[c][1] != '\0'){
        putchar(grammata[c][1]);
    }
    if(grammata[c][2] != '\0'){
        putchar(grammata[c][2]);
    }
}





int main() { /* elegxei oles tis periptwseis kai kanei tis katallhles energeies*/
    enum State {m,M, n, N, dflt};
    enum State state;
    int c;
    state = dflt;
    while ((c = getchar()) != EOF) {
        int done = 0;

        while (done == 0) {
            switch (state) {
                case m:
                    if (c == 208) { /* P ellhniko */
                        printstate(98);
                        done = 1;
                        state = dflt;
                    }else if(c == 240){ /*p ellhniko*/
                        printstate(98);
                        done = 1;
                        state = dflt;
                    }else {
                        printstate(c);
                        done = 1;
                        state = dflt;
                    }
                    break;
                case M:
                    if (c == 208) { /*P ellhniko*/
                        printstate(66);
                        done = 1;
                        state= dflt;
                    }else if(c==240){ /*p ellhniko*/
                        printstate(66);
                        done = 1;
                        state= dflt;
                    }else if (c == 204) { /* M ellhniko*/
                        printstate(204);
                        done = 1;
                        state= M;
                    } else if (c == 236) { /* m ellhniko*/
                        printstate(236);
                        done = 1;
                        state= m;
                    } else if (c == 205) { /*N ellhniko*/
                        printstate(205);
                        done = 1;
                        state= N;
                    } else if (c == 237) { /*n ellhniko*/
                        printstate(237);
                        done = 1;
                        state= n;
                    } else {
                        printstate(c);
                        done = 1;
                        state= dflt;
                    }
                    break;
                case n:
                    if (c == 212) { /*T ellhniko*/
                        printstate(100);
                        done = 1;
                        state= dflt;
                    }else if(c==244){ /* t ellhniko*/
                        printstate(100);
                        done = 1;
                        state = dflt;
                    }else if (c == 204) { /* M ellhniko */
                        printstate(204);
                        done = 1;
                        state=M;
                    }else if (c == 236) { /*m ellhniko */
                        printstate(236);
                        done = 1;
                        state= m;
                    } else if (c == 205) { /* N ellhniko */
                        printstate(205);
                        done = 1;
                        state= N;
                    } else if (c == 237) { /* n ellhniko */
                        printstate(237);
                        done = 1;
                        state= n;
                    }else {
                        printstate(c);
                        done = 1;
                        state= dflt;
                    }
                    break;
                case N:
                    if (c == 212) { /*T ellhniko */
                        printstate(68);
                        done = 1;
                        state= dflt;
                    }else if(c == 244){ /* t ellhniko*/
                        printstate(68);
                        done = 1;
                        state = dflt;
                    } else if(c == 205) { /* N ellhniko */
                        printstate(205);
                        done = 1;
                        state= N;
                    } else if (c == 237) { /* n ellhniko*/
                        printstate(237);
                        done = 1;
                        state= n;
                    } else if (c == 204) { /*M ellhniko */
                        printstate(204);
                        done = 1;
                        state= M;
                    } else if (c == 236) { /* m ellhniko */
                        printstate(236);
                        done = 1;
                        state= m;
                    } else {
                        printstate(c);
                        done = 1;
                        state= dflt;
                    }
                    break;
                case dflt:
                    if (c == 204) { /*M ellhniko */
                        state=M;
                    } else if (c == 236) { /* m ellhniko */
                        state= m;
                    } else if (c == 205) { /* N ellhniko */
                        state= N;
                    } else if (c == 237) { /* n ellhniko */
                        state= n;
                    } else {
                        printstate(c);
                        done = 1;
                        state= dflt;
                    }
                    break;
            }
        }

    }

}
