//
// Created by Артемий on 12/09/2026.
//

#include "B.h"

void B::solve() {
    std::vector<std::queue<int>> queues(2);

    for (int i = 0; i < 5; i++) {
        int number;
        std::cin >> number;

        queues[0].push(number);
    }

    for (int i = 0; i < 5; i++) {
        int number;
        std::cin >> number;

        queues[1].push(number);
    }

    int h = 0;

    while (!queues[0].empty() && !queues[1].empty() && h < 1000000) {
        int x = queues[0].front();
        int y = queues[1].front();

        int winner = -1;

        queues[0].pop();
        queues[1].pop();

        if (std::min(x, y) == 0 && std::max(x, y) == 9) {
            if (x == 0) winner = 0;
            else winner = 1;
        } else if (x < y) {
            winner = 1;
        } else winner = 0;

        queues[winner].push(x);
        queues[winner].push(y);

        h++;
    }

    if (h >= 1000000) {
        std::cout << "botva" << std::endl;
    } else if (queues[0].empty()) {
        std::cout << "second " << h << std::endl;
    } else {
        std::cout << "first " << h << std::endl;
    }
}
