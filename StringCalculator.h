
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

static int extractNumbers(const char* str, int* numArr, char delimiter) {
    int count = 0;
    int num = 0;
    bool negative = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            negative = true;
        } else if (isNumber(str[i])) {
            num = num * 10 + (str[i] - '0');
        } else if (str[i] == delimiter || str[i] == '\n') {
            if (negative) num = -num;
            numArr[count++] = num;
            num = 0;
            negative = false;
        }
    }

    if (isNumber(str[strlen(str) - 1])) {
        if (negative) num = -num;
        numArr[count++] = num;
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
