#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int convertNum(char i) {
    switch (i) {
        case 'I' :
            return 1;
        case 'V' :
            return 5;
        case 'X' :
            return 10;
        case 'L' :
            return 50;
        case 'C' :
            return 100;
        case 'D' :
            return 500;
        case 'M' :
            return 1000;
        default :
            return 0;
    }

}

int ConvertNumRomane(char *numRomane) {
    int convertedNum=0;
    for (int i = 0; i < numRomane[i] !='\0'; ++i) {
        int value = convertNum(toupper(numRomane[i]));
        if(numRomane[i+1]!='\0'){
            int value2 = convertNum(toupper(numRomane[i+1]));
            if(value>=value2){
                convertedNum= convertedNum+value;
            }else{
                convertedNum= convertedNum-value;
            }
        } else{
            convertedNum= convertedNum+value;
        }
    }
    return convertedNum;
}

void validateDate(char date[10]) {
    char *months[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre",
                        "octubre", "noviembre", "diciembre"};
    char *dateFinal[200];
    int day, month, year, control;
    int counter = 0;
    int dayMax = 0;

    char *token;
    token = strtok(date, "/");
    while (token != NULL) {
        counter++;
        switch (counter) {
            case 1:
                control = day = atoi(token);
                break;

            case 2:
                control = month = atoi(token);
                break;

            case 3:
                control = year = atoi(token);
                break;
        }
        if (control == 0) break;
        token = strtok(NULL, "/");
    }

    if (control != 0 && counter == 3) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dayMax = 31;
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                dayMax = 30;
                break;

            case 2:
                if (year % 4 == 0) dayMax = 29;
                else dayMax = 28;
                break;
        }
        printf("Su fecha es: %2i de %s de %i\n", day, months[month - 1], year);

    } else {
        printf("El formato de la fecha es incorrecto\n");
    }
}
void seeMatrix(int fila1, int columna1, int m1[fila1][columna1] , int fila2, int columna2, int m2[fila2][columna2] ,  int m3[fila1][columna2]){
    printf("\nPrimera matriz:\n\n");
    for (int i = 0; i < fila1; ++i) {
        printf("  [");
        for (int j = 0; j < columna1; ++j) {
            printf(" %d ", m1[i][j]);
        }
        printf("]\n");
    }
    printf("\nSegunda matriz:\n\n");
    for (int i = 0; i < fila2; ++i) {
        printf("  [");
        for (int j = 0; j < columna2; ++j) {
            printf(" %d ", m2[i][j]);
        }
        printf("]\n");
    }
    printf("\nResultado:\n\n");
    for (int i = 0; i < fila1; ++i) {
        printf("  [");
        for (int j = 0; j < columna2; ++j) {
            if (m3[i][j] < 100) {
                printf("  %d ", m3[i][j]);
            } else {
                printf(" %d ", m3[i][j]);
            }
        }
        printf("]\n");
    }
    printf("\n");
}
void MultiplicacionMatrix(int row1, int column1, int row2, int column2) {
    int m1[row1][column1];
    int m2[row2][column2];
    int m3[row1][column2];


    if (column1 == row2) {
        for (int i = 0; i < row1; ++i) {
            for (int j = 0; j < column1; ++j) {
                m1[i][j] = rand()% 11+ 1;
            }
        }
        for (int i = 0; i < row2; ++i) {
            for (int j = 0; j < column2; ++j) {
                m2[i][j] = rand() % 11 + 1;
            }
        }
        for (int i = 0; i < row1; ++i) {
            for (int j = 0; j < column2; ++j) {
                m3[i][j] = 0;
                for (int k = 0; k < column1; ++k) {
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        seeMatrix(row1,column1,m1,row2,column2,m2,m3);
    } else {
        printf("\nLas matrices no se pueden multiplicar\n");
    }
}
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
    char numRomane [10];
    char formatDate [11];
    int row1, column1, row2, column2;

    printf("Seleccione una opcion:\n");
    printf("1. Verificar si un numero es egolatra.\n");
    printf("2. Generar una matriz mágica de orden impar.\n");
    printf("3. Eliminar espacios de una cadena de texto.\n");
    printf("4. Calcular los factores primos de un numero.\n");
    printf("5. Multiplicar Matrices.\n");
    printf("6. Calcular Numero Romano.\n");
    printf("7. Revisar Fecha.\n");
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
        case 5:{
            printf("Por favor digite el numero de Filas de la primera matriz\n");
            scanf("%d",&row1);
            printf("Por favor digite el numero de Columnas de la primera matriz\n");
            scanf("%d", &column1);
            printf("Por favor digite el numero de Filas de la segunda  matriz\n");
            scanf("%d",&row2);
            printf("Por favor digite el numero de Columnas de la segunda matriz\n");
            scanf("%d",&column2);
            MultiplicacionMatrix(row1, column1, row2, column2);
            break;
        }
        case 6:{
            printf("Por favor digite el numero en Romano\n");
            scanf("%s",numRomane);
            printf("el numero romano es decimal es %d",ConvertNumRomane(numRomane));
            break;
        }
        case 7:{
            printf("Por favor digite la fecha en formato dd/mm/aaaa\n");
            scanf("%s",formatDate);
            validateDate(formatDate);
            break;
        }

        default:
            printf("Opción inválida. Por favor, seleccione una opción válida.\n");
    }

    return 0;
}
