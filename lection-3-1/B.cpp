//
// Created by Артемий on 16/09/2026.
//

#include "B.h"

int B::random(int start, int end) {
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(start, end);

    int randomIndex = dist(gen);

    return randomIndex;
}

void B::quick_sort(std::vector<int> &arr, int start, int end) {
    if (start >= end || start >= arr.size()) return;

    int x = random(start, end);
    int pivot = arr[x];

    int eq = start, gr = start, none = start;

    while (none <= end) {
        if (arr[none] == pivot) {
            std::swap(arr[gr], arr[none]);
            gr++;
        } else if (arr[none] < pivot) {
            std::swap(arr[gr], arr[none]);
            std::swap(arr[eq], arr[gr]);

            eq++;
            gr++;
        }

        none++;
    }

    quick_sort(arr, gr, end);
    quick_sort(arr, start, eq - 1);
}

void B::solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    quick_sort(arr, 0, arr.size() - 1);

    for (auto& el : arr) std::cout << el << ' ';
    std::cout << std::endl;
}
