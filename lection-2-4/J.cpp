//
// Created by Артемий on 15/09/2026.
//

#include "J.h"

void J::solve() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;

    std::vector<int> res(n);

    for (int i = 0; i < n; i++) {
        int x = a[i];

        if (lower.empty() || x <= lower.top()) {
            lower.push(x);
        } else {
            upper.push(x);
        }


        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }

        res[i] = lower.top();
    }

    for (int i = 0; i < n; i++) {
        std::cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }

    if (n == 0) std::cout << '\n';
}
