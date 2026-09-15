//
// Created by Артемий on 15/09/2026.
//

#include "H.h"

void H::solve() {
    int n, w;
    std::cin >> n >> w;

    std::vector<Brick> bricks(n);

    for (int i = 0; i < n; i++) {
        std::cin >> bricks[i].a >> bricks[i].w;
        bricks[i].index = i+1;
    }

    std::sort(
        bricks.begin(),
        bricks.end(),
        [](const Brick& x, const Brick& y) {
            return x.a < y.a;
        }
    );

    Heap heap{};

    std::vector<std::vector<int>> rows();

    for (auto& brick : bricks) {
        Row* row;
        if (!heap.empty()) row = heap.front();

        if (!heap.empty() && row->right_corner <= brick.a) {
            row->right_corner = brick.a + brick.w;
            row->bricks.push_back(brick.index);

            heap.push_root();
        } else {
            Row newRow{brick.a + brick.w};
            newRow.bricks.push_back(brick.index);

            heap.insert(newRow);
        }
    }

    std::cout << heap.arr.size() << std::endl;

    std::string output;

    for (auto& row : heap.arr) {
        for (auto& brick : row.bricks) {
            if (!output.empty()) output += " ";
            output += std::to_string(brick);
        }
    }

    std::cout << output << std::endl;
}
