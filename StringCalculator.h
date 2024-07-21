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
void handleNegative(bool &negative) {
    negative = true;
}

// Function to process digits
void handleDigit(char ch, int &num) {
    num = num * 10 + (ch - '0');
}

// Function to handle the end of a number
void handleEndOfNumber(int &num, bool &negative, int* numArr, int &count) {
    addNumber(num, negative, numArr, count);
    num = 0; // Reset num for the next number
    negative = false; // Reset negative flag for the next number
}

// Function to process a character
void processCharacter(char ch, int &num, bool &negative, int* numArr, int &count, char delimiter) {
    if (ch == '-') {
        handleNegative(negative);
    } else if (isdigit(ch)) {
        handleDigit(ch, num);
    } else if (ch == delimiter || ch == '\n') {
        handleEndOfNumber(num, negative, numArr, count);
    }
}

void handleNegative(bool &negative) {
    negative = !negative;
}

void handleDigit(char ch, int &num) {
    num = num * 10 + (ch - '0');
}

void handleEndOfNumber(int &num, bool negative, int* numArr, int &count) {
    if (negative) {
        num = -num;
    }
    numArr[count++] = num;
    num = 0; // Reset num for the next number
    negative = false; // Reset negative for the next number
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
