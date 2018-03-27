#include <stdio.h>
#include <string.h>

void kmp(char [],char []);
void preFix(char[], int [], int);

void main() {
    char t[] = "ssdfhlbgsdjkghsljkgbsdlkjgbjsdkgsdfg";
    char p[] = "gsd";

    kmp(t,p);
    //printf("HEllo");
}

void preFix(char p[], int arr[], int m){
    int i,j=0;
    arr[0] = 0;

    for(i=1;i<m;i++){
        while(j>0 && p[j]!=p[i]){
            j = arr[j];
        }

        if(p[j]==p[i]){
            j++;
        }

        arr[i] = j;
        //printf("%d",j);
    }
}

void kmp(char t[],char p[]){

    int n = strlen(t);
    int m = strlen(p);

    int arr[m];
    int k = 0;

    preFix(p,arr,m);

    int i=0,j=0;

    while(i<n){
        if(t[i]==p[j]){
            i++;
            j++;
        }

        if(j==m){
            printf("Match found at : %d",i-j);
            printf("\n");
            j=0;
            k=1;
        }

        if(i<n && p[j]!=t[i]){
            if(j!=0){
                j = arr[j-1];
            }else{
                i++;
            }
        }
    }

    if(k==0){
        printf("cant find a match");
        printf("\n");
    }
}