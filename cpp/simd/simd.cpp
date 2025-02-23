#include <xmmintrin.h>  // Header for SSE

#include <array>
#include <iostream>
#include <vector>
void addVectors(const float* a, const float* b, float* result, size_t size) {
  for (size_t i = 0; i < size; i += 4) {
    __m128 vecA = _mm_load_ps(&a[i]);           // Load 4 floats from a
    __m128 vecB = _mm_load_ps(&b[i]);           // Load 4 floats from b
    __m128 vecResult = _mm_add_ps(vecA, vecB);  // Perform SIMD addition
    _mm_store_ps(&result[i], vecResult);        // Store the result
  }
}

int main() {
  float a[]{1, 2, 3, 4, 5, 6, 7, 8};
  float b[]{1, 2, 3, 4, 5, 6, 7, 8};

  float result[8];
  addVectors(a, b, result, 8);

  std::cout << result[0] << " " << result[1] << '\n';
}