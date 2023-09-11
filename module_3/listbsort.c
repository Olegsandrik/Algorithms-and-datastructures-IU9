#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem{
    struct Elem *next;
    char *word;
};

struct Elem *bsort(struct Elem *list){
    if (list == NULL){
        return list;
    } else {
        struct Elem* bufList = list;
        while(1){
            long i = 0;
            struct Elem *pBufList = bufList;
            while(pBufList->next != NULL){
                if (strlen(pBufList->word) > strlen(pBufList->next->word))
                {
                    char *buf = pBufList->word;
                    pBufList->word = pBufList->next->word;
                    pBufList->next->word = buf;
                    i++;
                }
                pBufList = pBufList->next;
            }
            if (i == 0){
                return list;
            }
        }
    }
}

int main(){
    struct Elem* list = NULL;
    char *buffer = (char *) calloc(1000 + 1, 1);
    char symbol;
    while ((symbol = getchar()) != '\n'){
        if (symbol == ' '){
            continue;
        } else {
            ungetc(symbol, stdin);
            scanf("%s", buffer);
            int len = strlen(buffer);
            struct Elem *new_elem = (struct Elem *) malloc(sizeof(struct Elem));
            new_elem->word = (char *) calloc(len + 1, 1);
            new_elem->next = NULL;
            new_elem->word = strcpy(new_elem->word, buffer);

            struct Elem *current = list, *prev = NULL;
            while (current != NULL){
                prev = current;
                current = current->next;
            }
            if (prev == NULL) {
                list = new_elem;
            } else {
                prev->next = new_elem;
            }
            new_elem->next = NULL;
        }
    }

    list = bsort(list);
    struct Elem *cur = list, *prev = NULL;
    while (list){
        printf("%s%c", list->word, (list->next) ? ' ' : '\n');
        list = list->next;
    }

    while (cur){
        free(cur->word);
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    free(buffer);
}
