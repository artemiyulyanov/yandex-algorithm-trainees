//
// Created by Артемий on 09/09/2026.
//

#include "G.h"

void G::solve() {
    int n;
    std::cin >> n;

    std::stack<std::pair<int, int>> st;

    std::vector<int> vec(n, -1);
    std::vector<int> res(n, -1);

    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];

        while (!st.empty() && st.top().first > vec[i]) {
            std::pair<int, int> numToIdx = st.top();
            st.pop();

            res[numToIdx.second] = i;
        }

        st.emplace(vec[i], i);
    }

    for (auto& i : res) std::cout << i << ' ';
    std::cout << std::endl;
}