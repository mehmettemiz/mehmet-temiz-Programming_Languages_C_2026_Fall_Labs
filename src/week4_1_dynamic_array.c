/*
 * week4_1_dynamic_array.c
 * Author: Mehmet Temiz
 * Student ID: 251ADB232
 * Description:
 *   Allocates memory for n integers with malloc, reads them,
 *   prints their sum and average, then frees the memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int* arr = NULL;

  printf("Enter number of elements: ");
  /* Reject non-numbers, zero and negative sizes */
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  /* Allocate room for n integers */
  arr = malloc((size_t)n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
    sum += arr[i];
  }

  printf("Sum = %lld\n", sum);
  /* Cast to double so the average keeps its decimals */
  printf("Average = %.2f\n", (double)sum / n);

  free(arr);
  return 0;
}