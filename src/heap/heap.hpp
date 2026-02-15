#pragma once

#include <vector>

namespace msc {

// TODO: make_heap(Iter begin, Iter end)

template <typename T> constexpr void heapify_down(std::vector<T> &r, size_t i) {
  using std::swap;
  const auto n = r.size();

  while (true) {
    const auto left_child_idx = i * 2 + 1;
    const auto right_child_idx = i * 2 + 2;

    auto largest_idx{i};

    if (left_child_idx < n && r[left_child_idx] > r[largest_idx])
      largest_idx = left_child_idx;

    if (right_child_idx < n && r[right_child_idx] > r[largest_idx])
      largest_idx = right_child_idx;

    if (largest_idx == i)
      break;

    swap(r[i], r[largest_idx]);
    i = largest_idx;
  }
}

template <typename T> constexpr void make_heap(std::vector<T> &r) {
  const auto n = r.size();
  if (n < 2) return;

  // Start from first non leaf idx
  for (size_t i = n / 2; i-- > 0;) {
    heapify_down(r, i);
  }
}

} // namespace msc
