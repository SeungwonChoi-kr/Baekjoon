#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_bits(char* bits, int bit_size);
void print_talbe(char** table, int bit_size);
void compare_bits(char** table, int size, int bit_size);
int pick_bit(char* table_bits, int index);

int main() {
    int bit_size, size = 0;
    scanf("%d", &bit_size);
    if (bit_size % 8 == 0) {
        size = bit_size / 8;
    } else {
        size = (bit_size / 8) + 1;
    }

    char** table = (char**)malloc(bit_size * sizeof(char*));
    for (int i = 0; i < bit_size; i++) {
        char* bits = (char*)calloc(size, sizeof(char));
        set_bits(bits, bit_size);
        table[i] = bits;
    }

    compare_bits(table, size, bit_size);
    print_talbe(table, bit_size);

    return 0;
}

void set_bits(char* bits, int bit_size) {
    int one_zero;

    for (int i = 0; i < bit_size; i++) {
        scanf("%d", &one_zero);
        if (one_zero) {
            bits[i / 8] |= (1 << (7 - (i % 8)));
        }
    }
}

void print_talbe(char** table, int bit_size) {
    for (int i = 0; i < bit_size; i++) {
        for (int j = 0; j < bit_size; j++) {
            int bit_value = pick_bit(table[i], j);
            printf("%d ", bit_value);
        }
        printf("\n");
    }
}

void compare_bits(char** table, int size, int bit_size) {
    bool isChanged = true;

    while (isChanged) {
        isChanged = false;

        for (int i = 0; i < bit_size; i++) {
            for (int j = 0; j < bit_size; j++) {
                int bit_value = pick_bit(table[i], j);

                if (bit_value) {
                    if (isChanged == true) {
                        for (int k = 0; k < size; k++) {
                            table[i][k] |= table[j][k];
                        }
                    } else if (isChanged == false) {
                        char* tmp = (char*)calloc(size, sizeof(char));
                        memcpy(tmp, table[i], size);

                        for (int k = 0; k < size; k++) {
                            table[i][k] |= table[j][k];
                        }

                        if (memcmp(table[i], tmp, size)) {
                            isChanged = true;
                        }
                        free(tmp);
                    }
                }
            }
        }
    }
}

int pick_bit(char* table_bits, int index) {
    int byte_index = index / 8;
    int bit_index = 7 - (index % 8);
    int bit_value = (table_bits[byte_index] >> bit_index) & 1;
    return bit_value;
}
