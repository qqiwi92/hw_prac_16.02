#include <iostream>

template <class T>
T *merge(const T *const *a, size_t sa, const size_t *sai, T *c) {

  size_t *margins = new size_t[sa]();
  size_t total = 0;
  for (size_t i = 0; i < sa; ++i)
    total += sai[i];

  for (size_t i = 0; i < total; ++i) {
    size_t min_idx = 0;

    for (size_t j = 0; j < sa; ++j) {
      if (margins[j] < sai[j]) {
        if (a[j][margins[j]] < a[min_idx][margins[min_idx]]) {
          min_idx = j;
        }
      }
    }

    c[i] = a[min_idx][margins[min_idx]];
    margins[min_idx]++;
  }

  delete[] margins;
  return c;
}

int main() {
  int arr1[] = {10, 20, 30};
  int arr2[] = {5, 15, 25, 45};
  int arr3[] = {1, 2, 100};

  const int *const a[] = {arr1, arr2, arr3};

  size_t sai[] = {3, 4, 3};

  size_t sa = 3;

  size_t total_size = 0;
  for (size_t i = 0; i < sa; ++i)
    total_size += sai[i];

  int *result = new int[total_size];

  merge(a, sa, sai, result);

  for (size_t i = 0; i < total_size; ++i) {
    std::cout << result[i] << " ";
  }
  std::cout << "\n";

  delete[] result;

  return 0;
}
