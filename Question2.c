// Recurrence equation to calculate Fibonacci numbers using three different methods

#include <stdio.h>

/* ------------------------ FIRST METHOD: Recursive ------------------------ */

int fib_recursive(int n){
    // Base cases
    if(n == 0 || n == 1){
        return n;
    }
    
    // Recursive calls to calculate Fibonacci number
    return fib_recursive(n-1) + fib_recursive(n-2);
}

/* ------------------------ SECOND METHOD: Memorization ------------------------ */

#define MAX_MEMORIZATION_NUM 1000
int memory[MAX_MEMORIZATION_NUM] = {0};

int fib_memorization(int n){
    // Base cases
    if(n == 0 || n == 1){
        return n;
    }
    
    // Check if the value is already computed and stored in memory
    if(memory[n] != 0){
        return memory[n];
    }
    
    // If not computed previously, calculate Fibonacci number recursively and store in memory
    memory[n] = fib_memorization(n-1) + fib_memorization(n-2);
    return memory[n];
}

/* ------------------------ THIRD METHOD: Iterative ------------------------ */

int fib_iterative(int n){
    // Base cases
    if (n == 0 || n == 1) {
        return n;
    }
    
    int prev = 0; // First Fibonacci number
    int curr = 1; // Second Fibonacci number
    int next;     // Third Fibonacci number
    
    // Calculate Fibonacci numbers iteratively using a loop
    for(int i = 2; i <= n; i++){
        next = prev + curr; // Calculate the next Fibonacci number
        prev = curr;        // Update the previous Fibonacci number
        curr = next;        // Update the current Fibonacci number
    }
    return next; // Return the nth Fibonacci number
}

/* ------------------------ MAIN ------------------------ */

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Calculate and print the Fibonacci number using all three methods
    printf("Fibonacci number of %d using recursive is %d\n", n, fib_recursive(n));
    printf("Fibonacci number of %d using iterative is %d\n", n, fib_iterative(n));
    printf("Fibonacci number of %d using memorization is %d\n", n, fib_memorization(n));
    
    return 0;
}
