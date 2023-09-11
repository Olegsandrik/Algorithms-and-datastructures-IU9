#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>
int Compare(char *S, char *T, int lenS, int i, int j) {
    int Slen=(i >= lenS)? T[i - lenS - 1]: S[i];
    int Tlen=(j >= lenS)? T[j - lenS - 1]: S[j];
    int IandlenS=(i!=lenS)? 1: 0;
    int JandlenS=(j!=lenS)? 1: 0;
    int ans=(Slen == Tlen and IandlenS and JandlenS)? 1: 0;
    if (ans){
        return true;
    }
    else {
        return false;
    }
}
int *Prefix(char *S, char *T, int lenS, int n) {
    int *pi = calloc(n, sizeof(int));
    int i = 1;
    int t = pi[0];
    while (i<n){
        while (t > 0 and !Compare(S, T, lenS, i, t))
            t = pi[t - 1];
        if (Compare(S, T, lenS, i, t)){
            t++;
        }
        pi[i] = t;
        i++;
    }
    return pi;
}
int main(int argc, char **argv) {
    char *T = argv[2], *S = argv[1];
    int lenT = strlen(T), lenS = strlen(S);
    int len = lenS + lenT + 1;
    int *prefix = Prefix(S, T, lenS, len);
    int i = lenS + 1;
    while (i < len){
        if (prefix[i] == lenS){
            printf("%d ", (i - lenS * 2 ));
        }
        i++;
    }
    free(prefix);
    return 0;
}
