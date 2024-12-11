#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    printf("������� ������ �������: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("������ ������� ������ ���� ������ 0\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������\n");
        return 1;
    }

    printf("������� �������� ������� (0 � 1):\n");
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
    printf("������������ ���������� ������ ������ �����: %d\n", maxZeros);

    free(arr);
    return 0;
}
