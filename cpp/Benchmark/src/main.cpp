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
BENCHMARK_MAIN();