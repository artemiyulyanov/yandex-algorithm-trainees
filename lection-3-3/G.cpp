//
// Created by Артемий on 17/09/2026.
//

#include "G.h"

void G::merge(std::vector<int> &arr, int start, int mid, int end) {
    std::vector<int> a(arr.begin() + start, arr.begin() + mid + 1);
    std::vector<int> b(arr.begin() + mid + 1, arr.begin() + end + 1);

    int first = 0, second = 0, k = start;

    while (first < a.size() && second < b.size()) {
        if (a[first] < b[second]) {
            arr[k++] = a[first++];
        } else {
            arr[k++] = b[second++];
        }
    }

    std::vector<int>& larger = (first < a.size()) ? a : b;
    int& pointer = (first < a.size()) ? first : second;

    for (int i = pointer; i < larger.size(); i++) {
        arr[k++] = larger[i];
    }
}

void G::merge_sort(std::vector<int> &arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void G::solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) std::cin >> arr[i];

    merge_sort(arr, 0, n - 1);

    for (auto& el : arr) std::cout << el << ' ';
    std::cout << std::endl;
}
