#include <stdio.h>
#include <stdlib.h>

int fibonacciIterative(int n) {
   // the sums of the terms preceding are the current
   if (n == 1) {
      printf("0");
      return 0;
   } else if (n == 2) {
      printf("1");
      return 0;
   }
   // F(1) is firstPrevious and F(2) is secondPrevious
   int firstPrevious = 0;
   int secondPrevious = 1;
   int fibonacciSum = 1;

   // start for loop from 3 since if covers the other base cases
   for (int i = 3; i <= n; i++) {
      fibonacciSum = firstPrevious + secondPrevious;
      firstPrevious = secondPrevious;
      secondPrevious = fibonacciSum;
   }
   return fibonacciSum;
}

int fibonacciRecursive(int n) {
   // indexing was off at first since Fibonacci number 1 is 0
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }
   return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main(int argc, char *argv[]) {
   // assign command line arguments to appropriate variables
   int firstFibNumber;
   firstFibNumber = atoi(argv[1]);
   char *filename = argv[3];
   char method = argv[2][0];

   // start reading from file and then close when assigned to a variable
   FILE* filepointer;
   int fileReadNumber;
   filepointer = fopen(filename, "r");
   fscanf(filepointer, "%d", &fileReadNumber);
   fclose(filepointer);
   int fibonacciNum;
   fibonacciNum = firstFibNumber + fileReadNumber;
   
   if (method == 'i') {
      // here do the iterative method
      //printf("This is the Iterative method up to: %d\n", fibonacciNum);
      printf("%d", (fibonacciIterative(fibonacciNum)));
   } else {
      // here do the recursive method
      //printf("This is the Recursive method up to: %d\n", fibonacciNum);
      printf("%d", (fibonacciRecursive(fibonacciNum)));
   }
   return 0;
}
