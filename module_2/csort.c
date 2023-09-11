#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
int compare (char *a, char *b){
    int ans1=(strlen(a)==strlen(b))? 0: 1;
    int ans2=(strlen(a)>=strlen(b))? 0: 2;
    int ans=ans1-ans2;
    return ans;
}

int sep(unsigned long long n, char *src, char **scr1){
    int j=-1;
    bool konecstr=true;
    int counter=0;
    for(int q = 0; q < n; q++){
        if(src[q]==' '){
            konecstr=true;
            continue;
        }
        if(konecstr){
            j++;
            scr1[j]=calloc(10000,sizeof(char));
            counter=0;
            konecstr=false;
        }
        scr1[j][counter]=src[q];
        counter++;
    }
    return j;
}

void csort(char *src, char *dest) {
    char** scr1 = calloc(10000,sizeof(char*));
    unsigned long long n=strlen(src);
    int j=sep(n, src, scr1);
    int count[j+1];
    for (int o=0; o<j+1; o++){
        count[o]=0;
    }
    //int *count=calloc(j+1, sizeof(int));
    int N=j+1;
    int i=N-1;
    while(i>=1){
        int j=i-1;
        while (j>=0){
            if (compare(scr1[i],scr1[j])<0){
                count[j]=count[j]+1;
            }
            else{
                count[i]=count[i]+1;
            }
            j--;
        }
        i--;
    }
    char** scr2 = calloc(10000,sizeof(char*));
    int e=0;
    while (e < N){
        scr2[count[e]] = scr1[e];
        e++;
    }
    int k=0;
    int s=0;
    while (s<N){
        int j=0;
        while (j<strlen(scr2[s])){
            dest[k]=scr2[s][j];
            k++;
            j++;
        }
        dest[k]=' ';
        k++;
        s++;
    }
    dest[k-1]='\0';
    for(int i=0;i<N;i++){
        free(scr2[i]);
    }
    free(scr2);
    free(scr1);
}

int main(int argc, char **argv){
    char* dest=calloc(10000,sizeof(char));
    char* src=calloc(10000,sizeof(char));
    gets(src);
    csort(src,dest);
    printf("%s",dest);
    free(dest);
    free(src);
    return 0;
}
