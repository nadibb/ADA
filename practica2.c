#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMBINATIONS 100
#define MAX_LENGTH 5

// Mapeo de dígitos a letras del teclado telefónico
const char *digitToLetters[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

// Función recursiva para generar combinaciones
void backtrack(char *digits, int index, char *current, char **result, int *count) {
    if (digits[index] == '\0') {  // Si llegamos al final de la cadena
        current[index] = '\0';
        result[*count] = strdup(current);  // Guardamos la combinación
        (*count)++;
        return;
    }

    int digit = digits[index] - '0';
    const char *letters = digitToLetters[digit];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, count);
    }
}

// Función principal para generar todas las combinaciones
char **letterCombinations(char *digits, int *returnSize) {
    if (*digits == '\0') {  // Si la cadena está vacía
        *returnSize = 0;
        return NULL;
    }

    char **result = malloc(MAX_COMBINATIONS * sizeof(char *));
    char current[MAX_LENGTH];  // Buffer temporal para construir combinaciones
    *returnSize = 0;

    backtrack(digits, 0, current, result, returnSize);
    return result;
}

// Función principal para probar el programa
int main() {
    char digits[MAX_LENGTH];
    printf("Ingrese los dígitos (2-9): ");
    scanf("%s", digits);

    int returnSize;
    char **combinations = letterCombinations(digits, &returnSize);

    printf("Combinaciones posibles:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
        free(combinations[i]);  // Liberar memoria
    }
    free(combinations);

    return 0;
}
