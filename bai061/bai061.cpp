#include <stdio.h>
#include <cmath>
#include <math.h>
#define MAX 100

bool check(int a) {
    int sum = 0;//khai báo bi?n sum
    for (int i = 1;i <= a / 2;i++) { //t?o vòng l?p for ?? tìm ??c s? c?a a
        if (a % i == 0)
            sum += i; //t?ng các ??c s? c?a a
    }
    if (sum == a) return true; // tr? v? true
    return false; // ng??c l?i tr? v? false
}