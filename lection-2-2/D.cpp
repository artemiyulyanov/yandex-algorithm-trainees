//
// Created by Артемий on 13/09/2026.
//

#include "D.h"

void D::solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int maxVal = 0, maxPos = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > maxVal) {
            maxVal = a[i];
            maxPos = i;
        }
    }

    int q;
    std::cin >> q;
    std::vector<long long> K(q);
    for (int i = 0; i < q; i++) std::cin >> K[i];

    long long t0 = std::max((long long)maxPos, 1LL);

    std::deque<int> deq(a.begin(), a.end());
    std::vector<std::pair<int,int>> ans(t0 + 1);

    for (long long k = 1; k <= t0; k++) {
        int first = deq.front(); deq.pop_front();
        int second = deq.front(); deq.pop_front();

        ans[k] = {first, second};

        deq.push_front(std::max(first, second));
        deq.push_back(std::min(first, second));
    }

    std::vector<int> cycle(deq.begin() + 1, deq.end());
    int cycleLen = (int)cycle.size();

    std::vector<std::pair<int,int>> result(q);
    for (int i = 0; i < q; i++) {
        long long k = K[i];
        if (k <= t0) {
            result[i] = ans[k];
        } else {
            long long idx = (k - t0 - 1) % cycleLen;
            result[i] = {maxVal, cycle[idx]};
        }
    }

    for (int i = 0; i < q; i++) {
        std::cout << result[i].first << ' ' << result[i].second << '\n';
    }
}
