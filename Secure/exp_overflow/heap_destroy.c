#include <stdio.h>
#include <stdlib.h>

// died at -5999

int set_value(int idx, int value)
{
    int *table;

    table = malloc(10);
    if (idx < 10) {
        table[idx] = value;
        free(table);
        return 0;
    } else {
        free(table);
        return -1;
    }
}

int main(int argc, char** argv) {
    int i = 0;
    for(i = 0; i > -10000000; i--){
        printf("%d\n", i);
        set_value(i, 5);
    }
}
