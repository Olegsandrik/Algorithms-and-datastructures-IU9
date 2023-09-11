#include <stdio.h>
#include <string.h>
int wcount(char* s){
    int counter = 0;
    int n=strlen(s);
    if (n==1 && s[0]!=' '){
        counter+=1;
    }
    for (int i=0; i<n-1; i++){
        if (s[i]!=' ' && i==0){
            counter+=1;
        }
        if ((s[i + 1] != ' ' && s[i] == ' ')){
            counter+=1;
        }
    }
    return counter;
}
int main(){
    char str[1002];
    //fgets(str, 1002, stdin);
    gets(str);
    printf("%d\n", wcount(str));
    char str1[]="}j5X+  w WS<#p~$v ";
    //printf("%d", wcount(str1));
    return 0;
}
