#include <stdio.h>
#include <cmath>
#include <math.h>
#define MAX 100

bool check(int a) {
    int sum = 0;//khai b�o bi?n sum
    for (int i = 1;i <= a / 2;i++) { //t?o v�ng l?p for ?? t�m ??c s? c?a a
        if (a % i == 0)
            sum += i; //t?ng c�c ??c s? c?a a
    }
    if (sum == a) return true; // tr? v? true
    return false; // ng??c l?i tr? v? false
}