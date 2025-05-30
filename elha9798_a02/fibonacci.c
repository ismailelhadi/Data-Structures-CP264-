/*
--------------------------------------------------
Project: cp264 assignment 2
Author:  ismail elhadi
Version: 24/01/2025
--------------------------------------------------
*/
#include "fibonacci.h"

int recursive_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);

}
int iterative_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int prev1= 0;
	int prev2= 1;
	int current;
	for (int i = 2; i <=n; i++){
		current = prev1 + prev2;
		prev1 = prev2;
		prev2 = current;

	}
	return current;
}

int dpbu_fibonacci(int *f, int n) {
	f[0] = 0;
	if (n > 0) f[1] = 1;

	for (int i = 2; i <= n; i++) {
	   f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];

}

int dptd_fibonacci(int *f, int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (f[n] != -1) {
		return f[n];
	}
	f[n] = dptd_fibonacci(f, n -1) + dptd_fibonacci(f, n -2);
	return f[n];
}