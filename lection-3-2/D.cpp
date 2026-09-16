//
// Created by Артемий on 16/09/2026.
//

#include "D.h"

int D::random(int start, int end) {
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(start, end);

    int randomIndex = dist(gen);

    return randomIndex;
}

void D::quick_sort_median_c(std::vector<Ship> &arr, int start, int end, int mid) {
    if (start >= end || start >= arr.size()) return;

    int x = random(start, end);
    int pivot = arr[x].c;

    int eq = start, gr = start, none = start;

    while (none <= end) {
        if (arr[none].c == pivot) {
            std::swap(arr[gr], arr[none]);
            gr++;
        } else if (arr[none].c < pivot) {
            std::swap(arr[gr], arr[none]);
            std::swap(arr[gr], arr[eq]);

            eq++;
            gr++;
        }

        none++;
    }

    if (mid < eq) {
        quick_sort_median_c(arr, start, eq - 1, mid);
    } else if (mid >= gr) {
        quick_sort_median_c(arr, gr, end, mid);
    }
}

void D::solve() {
    int n;
    std::cin >> n;

    std::vector<Ship> ships(n);

    for (int i = 0; i < n; i++) {
        std::cin >> ships[i].r >> ships[i].c;
    }

    int mid = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    mid--;

    quick_sort_median_c(ships, 0, n - 1, mid);

    int mid_c = ships[mid].c;

    if (n % 2 == 0) {
        int upper_c = INT_MAX;

        for (int i = mid + 1; i < n; i++) {
            upper_c = std::min(upper_c, ships[i].c);
        }

        mid_c = (mid_c + upper_c) / 2;
    }

    std::sort(ships.begin(), ships.end(), [&](Ship a, Ship b) {
        return a.r < b.r;
    });

    int total = 0;

    for (int r = 1; r <= n; r++) {
        Ship nearest = ships[0];

        ships.erase(ships.begin());

        total += std::abs(nearest.r - r) + std::abs(nearest.c - mid_c);
    }

    std::cout << total << std::endl;
}