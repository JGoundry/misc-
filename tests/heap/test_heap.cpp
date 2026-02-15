#include "heap.hpp"

#include <algorithm>
#include <gtest/gtest.h>

#include <span>

namespace testing {
namespace {

constexpr bool debug = false;

template <typename T> void print(std::span<T> s) {
  for (const auto &e : s) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}

} // anonymous namespace

class TestHeap : public ::testing::TestWithParam<std::vector<int>> {};

TEST_P(TestHeap, MakeHeap) {
  auto h = GetParam();

  if constexpr (debug)
    print(std::span(h));

  msc::make_heap(h);

  if constexpr (debug)
    print(std::span(h));

  EXPECT_TRUE(std::ranges::is_heap(h));
}

INSTANTIATE_TEST_SUITE_P(, TestHeap,
                         Values(std::vector<int>{},
                                std::vector<int>{5, 7, 3, 9},
                                std::vector<int>{9, 2, 12, 2, 9},
                                std::vector<int>{3, 9, 4, 7, 5, 2},
                                std::vector<int>{-3, 1, 9, 12, 5, 9},
                                std::vector<int>{9, 0, 22, 29, 15, 19, 59}));

} // namespace testing
