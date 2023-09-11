#include <stdio.h>
#include <string.h>
int Prefix(char *s, unsigned long long lenS, int *pi){
    int t = 0;
    pi[0] = 0;
    int i = 1;
    while( i < lenS){
        while(t > 0 && s[t] != s[i]){
            t = pi[t-1];
        }
        if(s[t] == s[i]) t++;
        pi[i] = t;
        i++;
    }
}
int KMPSubst(char *s, char *T){
    unsigned long long lenS = strlen(s), lenT = strlen(T);
    int pi[lenS];
    Prefix(s, lenS, pi);
    int q = 0;
    unsigned long long k=0;
    while(k < lenT){
        while(q > 0 && s[q] != T[k])
            q = pi[q-1];
        if(s[q] == T[k]) {
            q++;
        }
        if(q == 0) {
            return 0;
        }
        if(q == strlen(s))
            q=pi[q-1];
        k++;
    }
    return 1;
}

int main(int argc,char **argv){
    char *S = argv[1], *T = argv[2];
    //char S[100000], T[100000];
    //scanf("%s", &S);
    //scanf("%s", &T);
    if(KMPSubst(S, T)==1) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}
