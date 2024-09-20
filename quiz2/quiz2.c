#include <stdio.h>
double calc_avg(int arr[], int num_elements) {
  int sum = 0;
  for (int i = 0; i < num_elements; i++) {
    sum = sum + arr[i];
  }

  return (double)sum / num_elements;
}

int main() {
  int numbers[] = {10, 20, 30, 40, 50};
  int num_elements = sizeof(numbers) / sizeof(numbers[0]);
  double average = calc_avg(numbers, num_elements);

  printf("Average: %.2f\n", average);

  return 0;
}
