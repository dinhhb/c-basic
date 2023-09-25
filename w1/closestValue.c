#include <stdio.h>
#include <math.h>

int main(void) {
    const int array_size = 10;
    double A[array_size];
    printf("Hay nhap 10 so:\n");
    
    for (int i = 0; i < array_size; i++)
        scanf("%lf", &A[i]); 
    
    double sum = 0.0;
    for (int i = 0; i < array_size; i++)
        sum += A[i];
    double average = sum / array_size;

    printf("Cac so theo thu tu dao nguoc:\n");
    for (int i = array_size - 1; i >= 0; i--)
        printf("%3.4f\n", A[i]);
    

    double closestValue = A[0];
    double minDifference = fabs(average - A[0]);    // fabs: take absolute float number
    
    for (int i = 1; i < array_size; i++) {
        double difference = fabs(average - A[i]);
        if (difference < minDifference) {
            minDifference = difference;
            closestValue = A[i];
        }
    }
    
    printf("Phan tu gan nhat voi gia tri trung binh la: %3.4f\n", closestValue);
    
    return 0;
}
