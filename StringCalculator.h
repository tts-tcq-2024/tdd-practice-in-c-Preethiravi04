#include "StringCalculator.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int parseNumber(const char* str, int* index, char delimiter) {
    int number = 0;
    while (str[*index] && str[*index] != delimiter && str[*index] != '\n') {
        number = number * 10 + (str[*index] - '0');
        (*index)++;
    }
    if (str[*index]) (*index)++;
    return number;
}

static char getCustomDelimiter(const char* str) {
    return str[2];
}

int add(const char* numbers) {
    if (!numbers || !numbers[0]) return 0;

    int sum = 0;
    int index = 0;
    char delimiter = ',';

    if (numbers[0] == '/' && numbers[1] == '/') {
        delimiter = getCustomDelimiter(numbers);
        index = 4;  // Skip the custom delimiter part
    }

    while (numbers[index]) {
        int num = parseNumber(numbers, &index, delimiter);
        if (num <= 1000) sum += num;
    }

    return sum;
}
