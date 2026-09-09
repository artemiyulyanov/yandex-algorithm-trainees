//
// Created by Артемий on 09/09/2026.
//

#include "H.h"

void H::solve() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> h(n + 1, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }

    std::stack<int> st;
    long long total = 0;

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            long long height = h[st.top()];
            st.pop();

            long long width = st.empty() ? i : i - st.top() - 1;
            total = std::max(total, height * width);
        }
        st.push(i);
    }

    std::cout << total << std::endl;
}