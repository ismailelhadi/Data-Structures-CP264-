/*
 * your program signature
 */ 

 #include "powersum.h"

 int power_overflow(int b, int n)
 {
    int p = 1;

    for (int i = 1; i <= n; i++) {
        int temp = p * b;
        if (temp / b != p) {
            return 1;
        }
        p = temp;
    }

    return 0;
 }
 
 int mypower(int b, int n)
 {
    int p = 1;

    for (int i = 1; i <= n; i++) {
        int temp = p * b;
        if (temp / b != p) {
            return 0;
        }
        p = temp;
    }

    return p;
}
 
 int powersum(int b, int n)
 {
    int p = 1;
    int sum =1;
 
    for (int i = 1; i <= n; i++) {
        int temp = p*b;
        if ((temp/b) != p) {
            return 0;
        } else {
            p = temp;
        }
 
        if ((sum + p) < sum) {
            return 0;
        }
        sum +=p;
    }
    return sum;
 }