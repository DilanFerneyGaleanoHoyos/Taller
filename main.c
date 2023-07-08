#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int contarDigitos(int num) {
    int contador = 0;
    while (num != 0) {
        num /= 10;
        contador++;
    }
    return contador;
}

int esNumeroEgolatra(int num) {
    int n = contarDigitos(num);
    int temp = num;
    int suma = 0;

    while (temp != 0) {
        int digito = temp % 10;
        suma += pow(digito, n);
        temp /= 10;
    }

    return suma == num;
}

void mostrarProcesoEgolatra(int num) {
    int n = contarDigitos(num);
    int temp = num;
    printf("Proceso para el numero %d:\n", num);

    while (temp != 0) {
        int digito = temp % 10;
        printf("%d^%d ", digito, n);
        temp /= 10;

        if (temp != 0) {
            printf("+ ");
        }
    }

    printf("= %d\n", num);
}

void generarMatrizMagica(int n) {
    int matriz[n][n];
    int numElementos = n * n;
    int fila = 0, columna = n / 2;
    int i, siguienteFila, siguienteColumna;

    // Inicializar la matriz con ceros
    for (fila = 0; fila < n; fila++) {
        for (columna = 0; columna < n; columna++) {
            matriz[fila][columna] = 0;
        }
    }

    // Generar la matriz mágica
    for (i = 1; i <= numElementos; i++) {
        matriz[fila][columna] = i;

        siguienteFila = (fila + n - 1) % n;
        siguienteColumna = (columna + 1) % n;

        if (matriz[siguienteFila][siguienteColumna] != 0) {
            siguienteFila = (fila + 1) % n;
            siguienteColumna = columna;
        }

        fila = siguienteFila;
        columna = siguienteColumna;
    }

    // Imprimir la matriz mágica
    printf("Matriz magica de orden %d x %d:\n", n, n);
    for (fila = 0; fila < n; fila++) {
        for (columna = 0; columna < n; columna++) {
            printf("%2d ", matriz[fila][columna]);
        }
        printf("\n");
    }
}

void borrarEspacios(char *cadena) {
    int longitud = strlen(cadena);
    int i, j = 0;

    for (i = 0; i < longitud; i++) {
        if (!isspace(cadena[i])) {
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
}

void calcularFactoresPrimos(int num) {
    printf("Factores primos de %d: ", num);

    for (int factor = 2; factor <= num; factor++) {
        int exponente = 0;

        while (num % factor == 0) {
            exponente++;
            num /= factor;
        }

        if (exponente > 0) {
            printf("%d^%d ", factor, exponente);
        }
    }

    printf("\n");
}

int main() {
    int opcion;

    printf("Seleccione una opción:\n");
    printf("1. Verificar si un numero es egolatra.\n");
    printf("2. Generar una matriz magica de orden impar.\n");
    printf("3. Eliminar los espacios de una cadena de texto.\n");
    printf("4. Calcular los factores primos de un numero.\n");
    printf("Ingrese el numero de la opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: {
            int num;
            printf("Ingrese un numero: ");
            scanf("%d", &num);

            if (esNumeroEgolatra(num)) {
                printf("%d es un numero egolatra.\n", num);
                mostrarProcesoEgolatra(num);
            } else {
                printf("%d no es un numero egolatra.\n", num);
            }
            break;
        }
        case 2: {
            int n;
            printf("Ingrese el orden impar de la matriz magica: ");
            scanf("%d", &n);

            if (n % 2 == 0) {
                printf("El orden ingresado no es impar. Por favor, ingrese un numero impar.\n");
                return 0;
            }

            generarMatrizMagica(n);
            break;
        }
        case 3: {
            char cadena[100];
            printf("Ingrese una cadena de texto: ");
            getchar();
            fgets(cadena, sizeof(cadena), stdin);

            // Eliminar el salto de línea del final de la cadena (si existe)
            int longitud = strlen(cadena);
            if (longitud > 0 &&cadena[longitud - 1] == '\n') {
                cadena[longitud - 1] = '\0';
            }

            borrarEspacios(cadena);

            printf("Cadena sin espacios: %s\n", cadena);
            break;
        }
        case 4: {
            int num;
            printf("Ingrese un numero: ");
            scanf("%d", &num);

            calcularFactoresPrimos(num);
            break;
        }
        default:
            printf("Opción invalida. Por favor, seleccione una opcion valida.\n");
    }

    return 0;
}
