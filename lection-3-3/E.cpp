//
// Created by Артемий on 16/09/2026.
//

#include "E.h"

void E::solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; i++) std::cin >> a[i];

    int m;
    std::cin >> m;

    std::vector<int> b(m);

    for (int j = 0; j < m; j++) std::cin >> b[j];

    if (n == 0) {
        print_array(b);
        return;
    }

    if (m == 0) {
        print_array(a);
        return;
    }

    int first = 0, second = 0;
    std::vector<int> res;

    while (first < n && second < m) {
        if (a[first] < b[second]) {
            res.push_back(a[first]);
            first++;
        } else {
            res.push_back(b[second]);
            second++;
        }
    }

    int& pointer = (first < n) ? first : second;
    std::vector<int>& larger = (first < n) ? a : b;

    while (pointer < std::max(n, m)) {
        res.push_back(larger[pointer]);
        pointer++;
    }

    print_array(res);
}

void E::print_array(std::vector<int> &arr) {
    for (auto& el : arr) std::cout << el << ' ';
    std::cout << std::endl;
}