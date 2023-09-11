#include <string.h>
#include <stdio.h>
#include <stdint.h>
void revarray(void *base, size_t nel, size_t width) {
    for (int j = nel/2; j < nel; j++) {
        for (int i=0; i < width; i++){
            uint8_t krash;
            krash = *((uint8_t *) base + i + j * width);
            *((uint8_t *) base + i + j * width) = *(i + (uint8_t *) base + (nel - j - 1) * width);
            *(i + (uint8_t *) base + (nel - j - 1) * width) = krash;
        }
    }
}
