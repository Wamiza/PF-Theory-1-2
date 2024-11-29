#include <stdio.h>

int BinaryToDecimal(int number) {
    int decimal = 0, base = 1;
    while (number > 0) {
        int last_digit = number % 10;
        decimal += last_digit * base;
        base *= 2;
        number /= 10;
    }
    return decimal;
}

int DecimalToBinary(int decimal) {
    int binary = 0, base = 1;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }
    return binary;
}


void DecimalToHexadecimal(int number) {
    printf("Hexadecimal: %X\n", number);
}

void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = 0;
    scanf(hexNumber, "%x", &decimal);
    printf("Decimal: %d\n", decimal);
}

void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexNumber[]) {
    int decimal;
    sscanf(hexNumber, "%x", &decimal);
    int binary = DecimalToBinary(decimal);
    printf("Binary: %d\n", binary);
}

int main() {
    int choice, number;
    char hexNumber[20];

    do {
        printf("Choose a conversion:\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                printf("Decimal: %d\n", BinaryToDecimal(number));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("Binary: %d\n", DecimalToBinary(number));
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                DecimalToHexadecimal(number);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%d", &number);
                BinaryToHexadecimal(number);
                break;
            case 6:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
