#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int isNarcissisticNumber(int num) {
    int n = countDigits(num);
    int temp = num;
    int sum = 0;

    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }

    return sum == num;
}

void showNarcissisticNumberProcess(int num) {
    int n = countDigits(num);
    int temp = num;
    printf("Proceso para el número %d:\n", num);

    while (temp != 0) {
        int digit = temp % 10;
        printf("%d^%d ", digit, n);
        temp /= 10;

        if (temp != 0) {
            printf("+ ");
        }
    }

    printf("= %d\n", num);
}

void generateMagicMatrix(int n) {
    int matrix[n][n];
    int numElements = n * n;
    int row = 0, column = n / 2;
    int i, nextRow, nextColumn;

    // Initialize the matrix with zeros
    for (row = 0; row < n; row++) {
        for (column = 0; column < n; column++) {
            matrix[row][column] = 0;
        }
    }

    // Generate the magic matrix
    for (i = 1; i <= numElements; i++) {
        matrix[row][column] = i;

        nextRow = (row + n - 1) % n;
        nextColumn = (column + 1) % n;

        if (matrix[nextRow][nextColumn] != 0) {
            nextRow = (row + 1) % n;
            nextColumn = column;
        }

        row = nextRow;
        column = nextColumn;
    }

    // Print the magic matrix
    printf("\n""Matriz mágica de orden %d x %d:\n", n, n);
    for (row = 0; row < n; row++) {
        for (column = 0; column < n; column++) {
            printf("%2d ", matrix[row][column]);
        }
        printf("\n");
    }
}

void removeSpaces(char *str) {
    int length = strlen(str);
    int i, j = 0;

    for (i = 0; i < length; i++) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

void calculatePrimeFactors(int num) {
    printf("Factores primos de %d: ", num);

    for (int factor = 2; factor <= num; factor++) {
        int exponent = 0;

        while (num % factor == 0) {
            exponent++;
            num /= factor;
        }

        if (exponent > 0) {
            printf("%d^%d ", factor, exponent);
        }
    }

    printf("\n");
}

int main() {
    int option;

    printf("Seleccione una opcion:\n");
    printf("1. Verificar si un numero es egolatra.\n");
    printf("2. Generar una matriz mágica de orden impar.\n");
    printf("3. Eliminar espacios de una cadena de texto.\n");
    printf("4. Calcular los factores primos de un numero.\n");
    printf("5. Numero Magico.\n");

    printf("Ingrese el numero de opcion: ");
    scanf("%d", &option);

    switch (option) {
        case 1: {
            int num;
            printf("Ingrese un número: ");
            scanf("%d", &num);

            if (isNarcissisticNumber(num)) {
                printf("%d is a narcissistic number.\n", num);
                showNarcissisticNumberProcess(num);
            } else {

                printf("%d es un número ególatra.\n", num);
            }
            break;
        }
        case 2: {
            int n;
            printf("Ingrese el orden impar de la matriz mágica: ");
            scanf("%d", &n);

            if (n % 2 == 0) {
                printf("El orden ingresado no es impar. Por favor, ingrese un número impar.\n");
                return 0;
            }

            generateMagicMatrix(n);
            break;
        }
        case 3: {
            char str[100];
            printf("Ingrese una cadena de texto: ");
            getchar();
            fgets(str, sizeof(str), stdin);

            // Remove the newline character at the end of the string (if present)
            int length = strlen(str);
            if (length > 0 && str[length - 1] == '\n') {
                str[length - 1] = '\0';
            }

            removeSpaces(str);

            printf("Cadena sin espacios: %s\n", str);
            break;
        }
        case 4: {
            int num;
            printf("Ingrese un numero: ");
            scanf("%d", &num);

            calculatePrimeFactors(num);
            break;
        }
        default:
            printf("Opción inválida. Por favor, seleccione una opción válida.\n");
    }

    return 0;
}
