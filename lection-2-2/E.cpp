//
// Created by Артемий on 13/09/2026.
//

#include "E.h"

#include <list>

void E::solve() {
    int n;
    std::cin >> n;

    std::list<int> deq;
    std::list<int>::iterator mid = deq.end();

    std::vector<int> res;
    res.reserve(n);

    for (int i = 0; i < n; i++) {
        std::string sign;
        std::cin >> sign;

        if (sign == "-") {
            res.push_back(deq.front());

            if (mid == deq.begin()) {
                mid = deq.erase(deq.begin());
            } else {
                deq.erase(deq.begin());
                if (deq.size() % 2 == 1) ++mid;
            }

            continue;
        }

        int id;
        std::cin >> id;
        bool wasEmpty = deq.empty();

        if (sign == "+") {
            deq.push_back(id);
            if (wasEmpty) mid = deq.begin();
            else if (deq.size() % 2 == 1) ++mid;
        } else {
            if (wasEmpty) {
                deq.push_back(id);
                mid = deq.begin();
            } else {
                auto it = deq.insert(std::next(mid), id);
                if (deq.size() % 2 == 1) mid = it;
            }
        }
    }

    for (int v : res) std::cout << v << '\n';
}
