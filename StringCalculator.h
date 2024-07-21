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

void processCharacter(char ch, int &num, bool &negative, int* numArr, int &count, char delimiter) {
    if (ch == '-') {
        handleNegative(negative);
    } else if (isdigit(ch)) {
        handleDigit(ch, num);
    } else if (ch == delimiter || ch == '\n') {
        handleEndOfNumber(num, negative, numArr, count);
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

char getCustomDelimiter(const char* numbers);
int extractNumbers(const char* numbers, int* numArr, char delimiter);
int addNumbers(int* numArr, int count);

// Main add function
int add(const char* numbers) {
    if (!numbers || strlen(numbers) == 0) {
        return 0;
    }

    char delimiter = ',';
    int numArr[MAX_NUMBERS];
    int count = 0;

    // Check for and handle custom delimiter
    if (numbers[0] == '/' && numbers[1] == '/') {
        delimiter = getCustomDelimiter(numbers);
        numbers += 4; // Skip the custom delimiter part
    }

    // Extract numbers using the determined delimiter
    count = extractNumbers(numbers, numArr, delimiter);

    // Sum and return the result
    return addNumbers(numArr, count);
}

// Extract the custom delimiter (assuming single character)
char getCustomDelimiter(const char* numbers) {
    return numbers[2]; // Custom delimiter is the third character
}

// Extract numbers from the string based on the delimiter
int extractNumbers(const char* numbers, int* numArr, char delimiter) {
    int count = 0;
    char* token;
    char str[256];
    
    strcpy(str, numbers); // Make a mutable copy of the input
    token = strtok(str, &delimiter);
    
    while (token && count < MAX_NUMBERS) {
        numArr[count++] = atoi(token);
        token = strtok(NULL, &delimiter);
    }
    
    return count;
}

// Sum the numbers
int addNumbers(int* numArr, int count) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += numArr[i];
    }
    return sum;
}
