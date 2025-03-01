#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);

    char** lines = (char**)malloc(sizeof(char*) * N);
    char buffer[51];
    int length;
    int min_length = 50;

    for (int i = 0; i < N; i++) {
        scanf("%s", buffer);
        length = strlen(buffer);

        char* line = (char*)malloc(sizeof(char) * (length + 1));
        strcpy(line, buffer);
        
        lines[i] = line;

        if (min_length > length) {
            min_length = length;
        }
    }

    int next_min = 50;
    int cur_length = 0;
    int stored_num = 0;
    int cur_store_num = 0;
    char** stored_lines = (char**)malloc(sizeof(char*) * N);

    while (1) {
        for (int i = 0; i < N; i++) {
            cur_length = strlen(lines[i]);

            if (min_length == cur_length) {
                char* line = (char*)malloc(sizeof(char) * (min_length + 1));
                strcpy(line, lines[i]);

                stored_lines[stored_num] = line;
                stored_num++;
                cur_store_num++;
            }
            else if (min_length < cur_length && cur_length < next_min) {
                next_min = cur_length;
            }
        }

        if (stored_num == N) {
            break;
        }
        min_length = next_min;
        next_min = 50;
    }

    int part = 0;
    bool isOver = false;
    min_length = strlen(stored_lines[0]);

    for (int i = 0; i < N; i += part) {
        part = 0;

        while (1) {
            if (i + part == N) {
                isOver = true;
                break;
            }
            
            if (min_length == strlen(stored_lines[i + part])) {
                part++;
            }
            else {
                min_length = strlen(stored_lines[i + part]);
                break;
            }
        }

        if (part > 1) {
            for (int j = i; j < i + part - 1; j++) {
                for (int k = j + 1; k < i + part; k++) {
                    if (strcmp(stored_lines[j], stored_lines[k]) > 0) {
                        char* tmp = stored_lines[j];
                        stored_lines[j] = stored_lines[k];
                        stored_lines[k] = tmp;
                    }
                }
            }
        }

        if (isOver) {
            break;
        }
        
    }

    for (int i = 0; i < N; i++) {
        if (i == 0 || strcmp(stored_lines[i - 1], stored_lines[i]) != 0) {
            printf("%s\n", stored_lines[i]);
        }
    }   
    
    return 0;
}