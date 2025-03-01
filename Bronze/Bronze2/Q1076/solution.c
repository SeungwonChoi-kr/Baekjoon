#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define black 0
#define brown 1
#define red 2
#define orange 3
#define yellow 4
#define green 5
#define blue 6
#define violet 7
#define grey 8
#define white 9

int main() {
    char** colors = (char**)malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++) {
        char* color = (char*)malloc(sizeof(char) * 7);
        scanf("%s", color);
        colors[i] = color;
    }

    long long om = 0;
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            if (strcmp(colors[i], "black") == 0) {
                om += 10 * black;
            }
            else if (strcmp(colors[i], "brown") == 0) {
                om += 10 * brown;
            }
            else if (strcmp(colors[i], "red") == 0) {
                om += 10 * red;
            }
            else if (strcmp(colors[i], "orange") == 0) {
                om += 10 * orange;
            }
            else if (strcmp(colors[i], "yellow") == 0) {
                om += 10 * yellow;
            }
            else if (strcmp(colors[i], "green") == 0) {
                om += 10 * green;
            }
            else if (strcmp(colors[i], "blue") == 0) {
                om += 10 * blue;
            }
            else if (strcmp(colors[i], "violet") == 0) {
                om += 10 * violet;
            }
            else if (strcmp(colors[i], "grey") == 0) {
                om += 10 * grey;
            }
            else if (strcmp(colors[i], "white") == 0) {
                om += 10 * white;
            }
        }
        else if (i == 1) {
            if (strcmp(colors[i], "black") == 0) {
                om += black;
            }
            else if (strcmp(colors[i], "brown") == 0) {
                om += brown;
            }
            else if (strcmp(colors[i], "red") == 0) {
                om += red;
            }
            else if (strcmp(colors[i], "orange") == 0) {
                om += orange;
            }
            else if (strcmp(colors[i], "yellow") == 0) {
                om += yellow;
            }
            else if (strcmp(colors[i], "green") == 0) {
                om += green;
            }
            else if (strcmp(colors[i], "blue") == 0) {
                om += blue;
            }
            else if (strcmp(colors[i], "violet") == 0) {
                om += violet;
            }
            else if (strcmp(colors[i], "grey") == 0) {
                om += grey;
            }
            else if (strcmp(colors[i], "white") == 0) {
                om += white;
            }
        }
        else {
            if (strcmp(colors[i], "black") == 0) {
                om *= pow(10, black);
            }
            else if (strcmp(colors[i], "brown") == 0) {
                om *= pow(10, brown);
            }
            else if (strcmp(colors[i], "red") == 0) {
                om *= pow(10, red);
            }
            else if (strcmp(colors[i], "orange") == 0) {
                om *= pow(10, orange);
            }
            else if (strcmp(colors[i], "yellow") == 0) {
                om *= pow(10, yellow);
            }
            else if (strcmp(colors[i], "green") == 0) {
                om *= pow(10, green);
            }
            else if (strcmp(colors[i], "blue") == 0) {
                om *= pow(10, blue);
            }
            else if (strcmp(colors[i], "violet") == 0) {
                om *= pow(10, violet);
            }
            else if (strcmp(colors[i], "grey") == 0) {
                om *= pow(10, grey);
            }
            else if (strcmp(colors[i], "white") == 0) {
                om *= pow(10, white);
            }
        }
    }

    printf("%llu", om);

    return 0;
}