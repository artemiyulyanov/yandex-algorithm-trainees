//
// Created by Артемий on 16/09/2026.
//

#include "A.h"

void A::solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    int x;
    std::cin >> x;

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < x) left++;
        else right++;
    }

    std::cout << left << ' ' << right << std::endl;
}