#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер массива должен быть больше 0\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите элементы массива (0 и 1):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxZeros = 0, currentZeros = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            currentZeros++;
            if (currentZeros > maxZeros) {
                maxZeros = currentZeros;
            }
        }
        else {
            currentZeros = 0;
        }
    }
    printf("Максимальное количество подряд идущих нулей: %d\n", maxZeros);

    free(arr);
    return 0;
}
