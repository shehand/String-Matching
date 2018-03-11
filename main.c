#include <stdio.h>
#include <string.h>

void naive(char [], char []);

void main(){

    char text[50] = "asfdsdasdfasdfcasfsadfwqedsafas";
    char pattern[50] ="wqe";

    //printf("Size of text : %d", strlen(text));

    naive(text, pattern);
}

void naive(char t[], char p[]){
    int i,j;
    //char text[] = t;

    for(i=0;i< strlen(t);i++){
        j=0;
        //printf("%d",i);
        while((t[i+j]==p[j]) && j<strlen(p)){
            j++;
            if(j==(strlen(p))){
                printf("Match found at : %d",i);
                printf("\n");
            }
            else{
                continue;
            }
        }

    }
}