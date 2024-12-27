#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(void* lhs, void* rhs, size_t size) {
  unsigned char tmp[size];
  memcpy(tmp, lhs, size);
  memcpy((unsigned char*)lhs, (unsigned char*)rhs, size);
  memcpy((unsigned char*)rhs, tmp, size);
}

void bubble_sort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)) {
  for (size_t i = 0; i < num; ++i) {
    for (size_t j = 0; j < (num - i - 1) * size; j += size) {
      if (compare(base + j + size, base + j) < 0) {
        swap(base + j, base + j + size, size);
      }
    }
  }
}

int compare(const void* lhs, const void* rhs) {
  const int* a = (const int*)lhs;
  const int* b = (const int*)rhs;
  return *a - *b;
}

int main(void) {

  int a[] = {6, 1, 7, 2, 1, 6, 3};
  bubble_sort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), compare);

  for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
    printf("%d ,", a[i]);
  }
  printf("\n");

  return 0;
}
