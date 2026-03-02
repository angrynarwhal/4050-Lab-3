#include <stdio.h>
#include <stdlib.h>

int fibo(int n); // returns the nth Fibonacci number

// returns the number of times the kth Fibonacci number is called for nth Fibonacci number
int fibo_counter(int n, int k); 

long fibo_memo(int n);

int main() {
    int n = 10;
    int k = 5;

    printf("The %dth Fibo number is: %d\n", n, fibo(n));
    printf("For calculating the %dth Fibo number, fibo(%d) is called %d times\n", n, k, fibo_counter(n, k));

    /*Write your loop and your additions below here*/
}

int fibo(int n) {
    if (n <= 1) { // basecase 
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int global_k_counter = 0; // Global counter for fibo_counter function
int fibo_counter(int n, int k) {
    if (n == k) return 1; // if k is encountered, add one to count and stop recursion.
    if (n <= 1) return 0;
    return fibo_counter(n - 1, k) + fibo_counter(n - 2, k);
}
