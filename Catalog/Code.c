#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long convertToDecimal(int base, const char *value) {
    long long decimalValue = 0;
    int len = strlen(value);
    
    for (int i = 0; i < len; i++) {
        int digit = value[len - 1 - i] >= 'a' ? value[len - 1 - i] - 'a' + 10 : value[len - 1 - i] - '0';
        decimalValue += digit * pow(base, i);
    }
    
    return decimalValue;
}
double lagrangeBasis(int i, int x[], int k) {
    double L = 1.0;
    for (int j = 0; j < k; j++) {
        if (j != i) {
            L *= (0 - x[j]) / (double)(x[i] - x[j]);
        }
    }
    return L;
}
long long lagrangeInterpolation(int x[], long long y[], int k) {
    long long c = 0;
    for (int i = 0; i < k; i++) {
        double L_i_at_0 = lagrangeBasis(i, x, k);
        c += (long long)(y[i] * L_i_at_0);
    }
    return c;
}
int main() {
    int n = 10, k = 7;
    int x[7];
    long long y[7]; 
    x[0] = 1; y[0] = convertToDecimal(6, "13444211440455345511"); 
    x[1] = 2; y[1] = convertToDecimal(15, "aed7015a346d63");
    x[2] = 3; y[2] = convertToDecimal(15, "6aeeb69631c227c");
    x[3] = 4; y[3] = convertToDecimal(16, "e1b5e05623d881f"); 
    x[4] = 5; y[4] = convertToDecimal(8, "316034514573652620673");
    x[5] = 6; y[5] = convertToDecimal(3, "2122212201122002221120200210011020220200");
    x[6] = 7; y[6] = convertToDecimal(3, "20120221122211000100210021102001201112121");
    long long secret = lagrangeInterpolation(x, y, k);
    
    printf("The constant term c is: %lld\n", secret);
    
    return 0;
}

Output:

The constant term c is: 6437400735940616133