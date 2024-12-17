#include <benchmark/benchmark.h>

#include <cstdint>

namespace bm = benchmark;
static void i32_addition(bm::State &state) {
  int32_t a, b, c;
  for (auto _ : state) c = a + b;
}

BENCHMARK(i32_addition);

static void i32_addition_random(bm::State &state) {
  int32_t c = 0;
  for (auto _ : state) c = std::rand() + std::rand();
}
BENCHMARK(i32_addition_random)->Threads(4);

static void i32_addition_semi_random(bm::State &state) {
  int32_t sum = 0;
  int32_t left = std::rand(), right = std::rand();
  for (auto _ : state) bm::DoNotOptimize(sum = (++left) + (++right));
}

BENCHMARK(i32_addition_semi_random)->Threads(4);

constexpr size_t f32s_in_cache_line_k = 64 / sizeof(float);
constexpr size_t f32s_in_cache_line_half_k = f32s_in_cache_line_k / 2;

struct alignas(64) f32_array_t {
  float raw[f32s_in_cache_line_k * 2];
};

static void f32_pairwise_accumulation(bm::State &state) {
  f32_array_t a, b, c;
  for (auto _ : state)
    for (size_t i = f32s_in_cache_line_half_k;
         i != f32s_in_cache_line_half_k * 3; ++i)
      bm::DoNotOptimize(c.raw[i] = a.raw[i] + b.raw[i]);
}

BENCHMARK(f32_pairwise_accumulation);

static void f32_pairwise_accumulation_aligned(bm::State &state) {
  f32_array_t a, b, c;
  for (auto _ : state)
    for (size_t i = 0; i != f32s_in_cache_line_half_k; ++i)
      bm::DoNotOptimize(c.raw[i] = a.raw[i] + b.raw[i]);
}

BENCHMARK(f32_pairwise_accumulation_aligned);

BENCHMARK_MAIN();