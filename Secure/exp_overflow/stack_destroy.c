#include <stdio.h>

// died at -2096345 

int set_value(int idx, int value)
{
    int table[10];
    if (idx < 10) {
        table[idx] = value;
        return 0;
    } else {
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
