//
// Created by Артемий on 17/09/2026.
//

#include "F.h"

void F::solve() {
    std::vector<std::vector<int>> a(4);

    for (int i = 0; i < 4; i++) {
        int n;
        std::cin >> n;

        a[i].resize(n);

        for (int j = 0; j < n; j++) std::cin >> a[i][j];
        std::sort(a[i].begin(), a[i].end());
    }

    int pointers[4] = {0, 0, 0, 0};
    int res[4] = {0, 0, 0, 0};

    int bestDiff = INT_MAX;

    while (true) {
        int mn = INT_MAX;
        int mn_i = 0;

        int mx = INT_MIN;

        for (int i = 0; i < 4; i++) {
            if (a[i][pointers[i]] < mn) {
                mn = a[i][pointers[i]];
                mn_i = i;
            }

            if (a[i][pointers[i]] > mx) {
                mx = a[i][pointers[i]];
            }
        }

        if (mx - mn < bestDiff) {
            bestDiff = mx - mn;

            for (int j = 0; j < 4; j++) res[j] = a[j][pointers[j]];
        }

        pointers[mn_i]++;

        if (pointers[mn_i] >= a[mn_i].size()) break;
    }

    for (auto& el : res) std::cout << el << ' ';
    std::cout << std::endl;
}