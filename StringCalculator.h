#define MAX_NUMBERS 100
static bool isNumber(char ch) {
    return ch >= '0' && ch <= '9';
}

static int addNumbers(int* arr, int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] <= 1000) {
            total += arr[i];
        }
    }
    return total;
}

#include <cstring>

// Helper function to process the number
static void processNumber(int &num, bool &negative, int* &numArr, int &count) {
    if (negative) num = -num;
    numArr[count++] = num;
    num = 0;
    negative = false;
}

static void addNumber(int &num, bool negative, int* numArr, int &count) {
    if (negative) num = -num;
    numArr[count++] = num;
    num = 0;
}

// Helper function to process each character
static void processCharacter(char ch, int &num, bool &negative, int* numArr, int &count, char delimiter) {
    if (ch == '-') {
        negative = true;
    } else if (isdigit(ch)) {
        num = num * 10 + (ch - '0');
    } else if (ch == delimiter || ch == '\n') {
        addNumber(num, negative, numArr, count);
        negative = false; // Reset negative for the next number
    }
}

static int extractNumbers(const char* str, int* numArr, char delimiter) {
    int count = 0;
    int num = 0;
    bool negative = false;

    for (int i = 0; str[i] != '\0'; i++) {
        processCharacter(str[i], num, negative, numArr, count, delimiter);
    }

    // Add the last number if necessary
    if (isdigit(str[strlen(str) - 1])) {
        addNumber(num, negative, numArr, count);
    }

    return count;
}
static char getCustomDelimiter(const char* numbers) {
    return numbers[2];
}

int add(const char* numbers) {
    if (numbers == NULL || strlen(numbers) == 0) {
        return 0;
    }

    int numArr[MAX_NUMBERS] = {0};
    int count = 0;
    char delimiter = ',';

    if (numbers[0] == '/' && numbers[1] == '/') {
        delimiter = getCustomDelimiter(numbers);
        numbers += 4;
    }

    count = extractNumbers(numbers, numArr, delimiter);
    return addNumbers(numArr, count);
}
