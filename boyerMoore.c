#include <stdio.h>
#include <string.h>

#define alph 256


void preProcessing(char [],char [], int []);
void boyerMoore(char [], char []);


void boyerMoore(char t[], char p[]){

    int n = strlen(t);
    int m = strlen(p);

    int prePro[alph];
    preProcessing(t,p,prePro);

    int shifts = 0;

    while(shifts <= (n-m)){
        int j = m-1;

        while(j>=0 && p[j]==t[shifts+j]){

            j--;
        }

        if(j<0) {
            printf("Match found at : %d", shifts);
            printf("\n");

            shifts++;
        }else{
            if(( j - prePro[ t [ shifts + j ] ]) > 1){
                shifts = shifts + j - prePro[ t [ shifts + j ] ];
            }else{
                shifts++;
            }
        }
    }
}
//
// Created by sonod on 3/14/18.
//

