#include <stdlib.h>
#include <stdio.h>

#define OPERAND_BUFFER_SIZE 10

typedef struct {
    unsigned int oper1;
    unsigned int oper2;
    char operation;
    /* 
    Students: The Expression struct should hold the two operands and
    the operation (use a char for the operation)
    */
} Expression;

int bits_per_int() {
    return sizeof(unsigned int) * 8;
}

unsigned int parse_operand(char operand_str[]) {
    unsigned int operand;
    if (operand_str[0] == '0' && operand_str[1] == 'x') {
        sscanf(&operand_str[2], "%x", &operand);
    } else if (operand_str[0] == '0') {
        sscanf(&operand_str[1], "%o", &operand);
    } else {
        sscanf(operand_str, "%u", &operand);
    }
    return operand;
}

void print_binary(unsigned int value) {
    // Students: Print a single number as a binary string
    for (int i = bits_per_int(); i >= 0; i--) {
        printf("%d", (value & (1 << i)) >> i);
        if (i % 8 == 0 && i < 32 && i > 0)
            printf("'");
    }
}

void print_bit_operation_bin(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in bin including the result

    Bin:
    00000000'00000000'00000000'00001100
    00000000'00000000'00000000'00001111 ^
    -----------------------------------
    00000000'00000000'00000000'00000011
    */
    printf("Bin:\n");
    print_binary(expression.oper1);
    printf("\n");
    print_binary(expression.oper2);
    printf(" %c \n-----------------------------------\n", expression.operation);
    print_binary(result);
    printf("\n\n");
}

void print_bit_operation_hex(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in hex including the result

    Hex:
    0x0c ^ 0x0f = 0x03
    */
    printf("Hex:\n");
    printf("%#04x %c %#04x ", expression.oper1, expression.operation, expression.oper2);
    printf("= %#04x\n\n", result);
}

void print_bit_operation_dec(Expression expression, unsigned int result) {
    /* 
    Students: Print the entire operation in hex including the result

    Dec:
    12 ^ 15 = 3
    */

    printf("Dec:\n");
    printf("%i %c %i ", expression.oper1, expression.operation, expression.oper2);
    printf("= %i\n\n", result);
}

unsigned int bit_operation(Expression expression) {
    // Students: Do the actual bit operation and return the result
    switch (expression.operation) {
        case '&':
            return expression.oper1 & expression.oper2;
        case '|':
            return expression.oper1 | expression.oper2;
        case '^':
            return expression.oper1 ^ expression.oper2;
        case '<':
            return expression.oper1 < expression.oper2;
        case '>':
            return expression.oper1 > expression.oper2;
        default:
            return 0;
    }
}

int main() {
    char operand1_str[10];
    char operand2_str[10];
    char operation;

    unsigned int operand1, operand2;

    do {
        printf("Geben sie die Bit-Operation ein:\n");

        scanf("%s %c %s", operand1_str, &operation, operand2_str);

        operand1 = parse_operand(operand1_str);
        operand2 = parse_operand(operand2_str);

        Expression expression = {
                operand1, operand2, operation
        };   // Students: Create an expression

        unsigned int result = bit_operation(expression);
        print_bit_operation_bin(expression, result);
        print_bit_operation_hex(expression, result);
        print_bit_operation_dec(expression, result);

        while (getchar() != '\n');
        printf("\nMoechten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");

    } while (getchar() == 'n');

    printf("Byebye..\n");
    return EXIT_SUCCESS;
}