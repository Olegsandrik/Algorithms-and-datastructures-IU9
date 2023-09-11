#include <stdio.h>
#include <stdbool.h>
int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    char *max=(char*)base; // указатель на начальный элелемент
    int x=0;
    for (int i=0; i < nel; i++){
        if(compare((void*)(i*width + (char*)base), (void*)max)>0){ // сравнение элементов через указатели на них
            max=(char*)(i*width+(char*)base); // изменение указателя максимума на  указатель большего элемента
            x=i; //итый элемент найден корректно!
        }
    }
    return x; //вернем последний итый элемент, который подошел
}
int main(int argc, char **argv){

}
