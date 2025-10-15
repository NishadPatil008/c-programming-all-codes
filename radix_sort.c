#include <stdio.h>
int main() {
    int arr[100], output[100];
    int n = 5, i, j, max = 0, digits = 0, exp = 1, d;
    int count[10];
    printf("Enter 5 numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }
    int temp = max;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    for (i = 0; i < digits; i++) {
        for (j = 0; j < 10; j++)
            count[j] = 0;
        for (j = 0; j < n; j++) {
            d = (arr[j] / exp) % 10;
            count[d]++;
        }
        for (j = 1; j < 10; j++)
            count[j] += count[j - 1];
        for (j = n - 1; j >= 0; j--) {
            d = (arr[j] / exp) % 10;
            output[count[d] - 1] = arr[j];
            count[d]--;
        }  
        for (j = 0; j < n; j++)
            arr[j] = output[j];
        exp *= 10;
    }
    printf("Sorted numbers:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}