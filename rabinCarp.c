#include <stdio.h>
#include <string.h>

void rabinCarp(char [], char [], int ,int);
int power(int,int);

void rabinCarp(char t[], char p[], int alphebet, int q){

    int m = strlen(p);
    int n = strlen(t);
    int i,j;
    int d = alphebet;
    int hashValue = 0;
    int pHashValue = 0;

    for(i=0;i<m;i++){
        pHashValue = (pHashValue + ((int)p[i]*power(d,(m-i-1))))%q;  //calculate hash value for pattern
        hashValue = (hashValue + ((int)t[i]*power(d,(m-i-1))))%q;    //calculate hash value for first part of the text
    }

    for(i=0;i<=n-m;i++){
        j=0;
        if(pHashValue==hashValue){
            while((t[i+j]==p[j]) && j<m){
                j++;
            }

            if(j==m) {
                printf("Match found at : %d", i);
                printf("\n");
                hashValue = (((hashValue - (((int) t[i] * power(d, m - 1)) % q)) * d) + t[i + m]) % q;
                if (hashValue < 0) {
                    hashValue = hashValue + q;
                }
            }else{
                hashValue = (((hashValue - (((int) t[i] * power(d, m - 1)) % q)) * d) + t[i + m]) % q;
                if (hashValue < 0) {
                    hashValue = hashValue + q;
                }
            }
        }
        else {
            hashValue = (((hashValue - (((int) t[i] * power(d, m - 1)) % q)) * d) + t[i + m]) % q;
            if (hashValue < 0) {
                hashValue = hashValue + q;
            }
        }
    }

}

int power(int base, int d){
    int i=0;
    int total = 1;
    for(i=0;i<d;i++){
        total =total*base;
    }
    return total;
}
