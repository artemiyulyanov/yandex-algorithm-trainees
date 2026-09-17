//
// Created by Артемий on 18/09/2026.
//

#include "H.h"

void H::merge(std::vector<int> &arr, int start, int mid, int end, long long& permutations) {
    std::vector<int> a(arr.begin() + start, arr.begin() + mid + 1);
    std::vector<int> b(arr.begin() + mid + 1, arr.begin() + end + 1);

    int first = 0, second = 0, k = start;

    while (first < a.size() && second < b.size()) {
        if (a[first] < b[second]) {
            arr[k++] = a[first++];
        } else {
            permutations += a.size() - first;
            arr[k++] = b[second++];
        }
    }

    std::vector<int>& larger = (first < a.size()) ? a : b;
    int& pointer = (first < a.size()) ? first : second;

    for (int i = pointer; i < larger.size(); i++) {
        arr[k++] = larger[i];
    }
}

void H::merge_sort(std::vector<int> &arr, int start, int end, long long& permutations) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid, permutations);
    merge_sort(arr, mid + 1, end, permutations);
    merge(arr, start, mid, end, permutations);
}

void H::solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) std::cin >> arr[i];

    long long ans = 0;

    merge_sort(arr, 0, n - 1, ans);

    std::cout << ans << std::endl;
}