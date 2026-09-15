//
// Created by Артемий on 13/09/2026.
//

#include "F.h"

void F::solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) std::cin >> vec[i];

    std::deque<int> dq;
    std::vector<int> res;
    res.reserve(n - k + 1);

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && vec[dq.back()] >= vec[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            res.push_back(vec[dq.front()]);
        }
    }

    for (auto& i : res) std::cout << i << std::endl;
}