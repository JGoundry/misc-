#pragma once

#include <vector>

namespace msc {

// TODO: make_heap(Iter begin, Iter end)

template <typename T> constexpr void heapify_down(std::vector<T> &r, size_t i) {
  using std::swap;

  const auto n = r.size();
  const auto first_non_leaf_idx = n / 2 - 1;
  const auto left_child_idx = i * 2 + 1;
  const auto right_child_idx = i * 2 + 2;

  const auto max_child_idx = [&]() {
    if (right_child_idx < n && r[right_child_idx] > r[left_child_idx])
      return right_child_idx;
    return left_child_idx;
  }();

  if (r[i] < r[max_child_idx]) {
    swap(r[i], r[max_child_idx]);
    if (max_child_idx <= first_non_leaf_idx)
      heapify_down(r, max_child_idx);
  }
}

template <typename T> constexpr void make_heap(std::vector<T> &r) {
  const auto first_non_leaf_idx = r.size() / 2 - 1;
  for (long i = first_non_leaf_idx; i >= 0; --i) {
    heapify_down(r, i);
  }
}

} // namespace msc
