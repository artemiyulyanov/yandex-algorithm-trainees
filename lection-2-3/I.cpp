//
// Created by Артемий on 15/09/2026.
//

#include "I.h"

void I::solve() {
    double res = 0;

    Heap heap;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;

        heap.insert(num);
    }

    while (heap.arr.size() >= 2) {
        int x = heap.extract(), y = heap.extract();

        res += 0.05 * (x + y);

        heap.insert(x + y);
    }

    std::cout << std::fixed << std::setprecision(2) << res << std::endl;
}
