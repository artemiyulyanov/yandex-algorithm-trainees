//
// Created by Артемий on 18/09/2026.
//

#include "I.h"

void I::solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) std::cin >> arr[i];

    Heap heap(arr);

    for (int i = n - 1; i >= 0; i--) heap.sift_down(i);

    std::cout << heap.swaps << std::endl;
}
