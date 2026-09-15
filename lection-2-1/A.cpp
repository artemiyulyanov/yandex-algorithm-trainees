//
// Created by Артемий on 12/09/2026.
//

#include "A.h"

void A::solve() {
    std::queue<int> q = {};

    std::string command;
    while (std::cin >> command) {
        if (command == "push") {
            int number;
            std::cin >> number;

            q.push(number);

            std::cout << "ok" << std::endl;
        } else if (command == "pop") {
            if (q.empty()) {
                std::cout << "error" << std::endl;
                continue;
            }

            std::cout << q.front() << std::endl;

            q.pop();
        } else if (command == "front") {
            if (q.empty()) {
                std::cout << "error" << std::endl;
                continue;
            }

            std::cout << q.front() << std::endl;
        } else if (command == "size") {
            std::cout << q.size() << std::endl;
        } else if (command == "clear") {
            q = {};

            std::cout << "ok" << std::endl;
        } else if (command == "exit") {
            std::cout << "bye" << std::endl;
            break;
        }
    }
}