#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include <stdlib.h>

//Números Ególatras
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
    printf("Proceso para el numero %d:\n", num);

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
//Matriz Mágica
void generateMagicMatrix(int n) {
    int matrix[n][n];
    int numElements = n * n;
    int row = 0, column = n / 2;
    int i, nextRow, nextColumn;


    for (row = 0; row < n; row++) {
        for (column = 0; column < n; column++) {
            matrix[row][column] = 0;
        }
    }


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


    printf("\n""Matriz magica de orden %d x %d:\n", n, n);
    for (row = 0; row < n; row++) {
        for (column = 0; column < n; column++) {
            printf("%2d ", matrix[row][column]);
        }
        printf("\n");
    }
}
//Borrar Espacios
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
//Factores Primos
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
//numero Romanos
int convertNum(char c) {
    switch (toupper(c)) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
int romanToDecimal(char *romanNumber) {
    int length = strlen(romanNumber);
    int decimalValue = 0;
    int previousValue = 0;

    for (int i = length - 1; i >= 0; i--) {
        int currentValue = convertNum(romanNumber[i]);

        if (currentValue >= previousValue) {
            decimalValue += currentValue;
        } else {
            decimalValue -= currentValue;
        }

        previousValue = currentValue;
    }

    return decimalValue;
}
//Fechas
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
//Multiplicación de Matrices
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
//Producto Punto
int dotProduct(int v1[], int v2[], int s){

    int aux[s];

    for(int i = 0; i<s;i++){

        int mult = v1[i]*v2[i];

        aux[i] = mult;

    }

    int add = 0;

    for(int i = 0; i<s;i++){

        add = add + aux[i];
    }

    return add;
}
//Número Mágico
int numberDigits(int num){

    int dig = 0;

    while (num > 0) {
        num = num / 10;
        dig = dig+1;
    }

    return dig;

}
int magicNumber(int num, int s){

    int upward[s];
    int falling[s];
    int dig;

    int i=0;
    while (num > 0) {

        dig = num % 10;

        upward[i]=dig;
        falling[i]=dig;

        num = num / 10;

        i++;
    }

    int size = sizeof(falling)/ sizeof(falling[0]);

    for (int j = 0; j < size; ++j) {

        for (int k = j; k < size-1; ++k) {

            if(falling[j]<falling[k+1]){

                int aux = falling[j];
                falling[j]= falling[k+1];
                falling[k+1] = aux;
            }

        }

    }

    for (int j = 0; j < size-1; ++j) {

        for (int k = j; k < size-1; ++k) {

            if(upward[j]>upward[k+1]){

                int aux = upward[j];
                upward[j]= upward[k+1];
                upward[k+1] = aux;
            }

        }

    }
    int numFall=0;
    for (int j = 0; j < size; ++j) {
        numFall=(numFall*10)+falling[j];
    }
    int numUp=0;
    for (int j = 0; j < size; ++j) {
        numUp=(numUp*10)+upward[j];
    }

    return numFall - numUp;
}

int main() {
    int option;
    int exit = 0;
    do {
     printf("\n----- MENU PRINCIPAL ----\n");
        printf("Seleccione una opcion:\n");
        printf("1. Verificar si un numero es egolatra.\n");
        printf("2. Generar una matriz magica de orden impar.\n");
        printf("3. Eliminar espacios de una cadena de texto.\n");
        printf("4. Calcular los factores primos de un numero.\n");
        printf("5. Multiplicar matrices.\n");
        printf("6. Calcular numero romano.\n");
        printf("7. Revisar fecha.\n");
        printf("8. numero magico.\n");
        printf("9. Producto punto.\n");
        printf("0. Salir del programa.\n");
        printf("Ingrese el numero de opcion: ");
        scanf("%d", &option);
        system("cls");
        switch (option) {
            case 0:
                exit = 1;  // Salir del programa
                break;

            case 1: {
                int num;
                printf("\n----- NUMERO EGOLATRA  ----\n");
                printf("Ingrese un numero: ");
                scanf("%d", &num);

                if (isNarcissisticNumber(num)) {
                    printf("%d es un numero egolatra.\n", num);
                    showNarcissisticNumberProcess(num);
                } else {
                    printf("%d no es un numero egolatra.\n", num);
                }
            }
                break;

            case 2: {
                int n;
                printf("\n----- MATRIZ MAGICA  ----\n");
                printf("Ingrese el orden impar de la matriz magica: ");
                scanf("%d", &n);

                if (n % 2 == 0) {
                    printf("El orden ingresado no es impar. Por favor, ingrese un numero impar.\n");
                } else {
                    generateMagicMatrix(n);
                }
            }
                break;

            case 3: {
                printf("\n----- ELIMINAR ESPACIOS ----\n");
                char str[100];
                printf("Ingrese una cadena de texto: ");
                getchar();
                fgets(str, sizeof(str), stdin);
                int length = strlen(str);
                if (length > 0 && str[length - 1] == '\n') {
                    str[length - 1] = '\0';
                }

                removeSpaces(str);

                printf("Cadena sin espacios: %s\n", str);
            }
                break;

            case 4: {
                printf("\n----- FACTOR PRIMOS ----\n");
                int num;
                printf("Ingrese un numero: ");
                scanf("%d", &num);

                calculatePrimeFactors(num);
            }
                break;

            case 5: {
                printf("\n----- MULTIPLICAR MATRICES ----\n");
                int row, row2, row3, column1, column2;
                printf("Por favor, digite el numero de filas de la primera matriz: ");
                scanf("%d", &row);
                printf("Por favor, digite el numero de columnas de la primera matriz: ");
                scanf("%d", &column1);
                printf("Por favor, digite el numero de filas de la segunda matriz: ");
                scanf("%d", &row2);
                printf("Por favor, digite el numero de columnas de la segunda matriz: ");
                scanf("%d", &column2);
                MultiplicacionMatrix(row, column1, row2, column2);
            }
                break;

            case 6: {
                char romanNumber[100];

                printf("Ingrese un numero en romano: ");
                scanf("%s", romanNumber);

                int decimalValue = romanToDecimal(romanNumber);

                printf("El numero en decimal es: %d\n", decimalValue);


            }
                break;

            case 7: {
                printf("\n----- FECHA ----\n");
                char formatDate[100];
                printf("Por favor, digite la fecha en formato dd/mm/aaaa: ");
                scanf("%s", formatDate);
                validateDate(formatDate);
            }
                break;

            case 8: {
                printf("\n----- NUMERO MAGICO  ----\n");
                int num;

                do {

                    printf("Digite el numero que desea comprobar\n");
                    scanf("%i", &num);


                } while (numberDigits(num) <= 1);


                if (magicNumber(num, numberDigits(num)) == num) {

                    printf("Felicidades, %i es un numero magico", num);


                } else {

                    printf("Lo lamento, %i no es un numero magico", num);
                }

                break;

            }

            case 9: {
                printf("\n----- PRODUCTO PUNTO ----\n");
                int s;

                printf("Digite el tamano que desea para los dos arreglos\n");
                scanf("%i", &s);


                int v1[s];
                int v2[s];

                for (int i = 0; i < s; i++) {

                    printf("\nDigite el valor del vector 1 en la posicion: %i\n", i + 1);
                    scanf("%i", &v1[i]);

                }

                for (int i = 0; i < s; i++) {

                    printf("\nDigite el valor del vector 2 en la posicion: %i\n", i + 1);
                    scanf("%i", &v2[i]);

                }

                if (v1 == NULL || v2 == NULL) {
                    printf("Alguno de los vectores es nulo, por ende no se puede realizar la operacion.");
                } else {
                    printf("El producto punto entre ambos vectores es: %i", dotProduct(v1, v2, s));
                }

                break;
            }
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (!exit);

    printf("Gracias por usar el programa. Hasta luego!\n");

    return 0;
}