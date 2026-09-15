//
// Created by Артемий on 15/09/2026.
//

#ifndef YANDEX_ALGORITHM_TRAINEES_H_H
#define YANDEX_ALGORITHM_TRAINEES_H_H

#include <iostream>
#include <vector>

struct Brick {
    int a, w, index;

    Brick() : a(0), w(0), index(0) {}

    Brick(int a, int w, int index) : a(a), w(w), index(index) {}
};

struct Row {
    int right_corner;
    std::vector<int> bricks;

    Row() : right_corner(0), bricks(0) {
    }

    Row(int right_corner) : right_corner(right_corner), bricks(0) {
    }
};

struct Heap {
    std::vector<Row> arr;

    Heap() : arr(0) {}

    bool empty() {
        return arr.empty();
    }

    void insert(Row row) {
        arr.push_back(row);

        int child = arr.size() - 1;
        int parent = (child - 1) / 2;

        while (child > 0 && arr[parent].right_corner > arr[child].right_corner) {
            std::swap(arr[child], arr[parent]);

            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void push_root() {
        int parent = 0;

        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int smallest = parent;

            if (left < (int)arr.size() && arr[left].right_corner < arr[smallest].right_corner) smallest = left;
            if (right < (int)arr.size() && arr[right].right_corner < arr[smallest].right_corner) smallest = right;

            if (smallest == parent) break;

            std::swap(arr[parent], arr[smallest]);
            parent = smallest;
        }
    }

    void pop_front() {
        if (arr.empty()) return;

        arr[0] = arr.back();
        arr.pop_back();

        push_root();
    }

    Row* front() {
        return &arr[0];
    }
};

class H {
public:
    static void solve();
};


#endif //YANDEX_ALGORITHM_TRAINEES_H_H
