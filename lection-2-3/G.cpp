//
// Created by Артемий on 15/09/2026.
//

#include "G.h"

void G::solve() {
    int n;
    std::cin >> n;

    Heap heap{};

    for (int i = 0; i < n; i++) {
        int command;
        std::cin >> command;

        if (command == 1) {
            std::cout << heap.extract() << std::endl;
        } else {
            int k;
            std::cin >> k;
            heap.insert(k);
        }
    }
}
