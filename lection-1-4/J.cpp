#include "J.h"

void J::moveDisks(int n, int x, int y) {
    if (n == 0) {
        return;
    }

    int z = 6 - x - y; 

    moveDisks(n - 1, x, z); 
    std::cout << n << " " << x << " " << y << std::endl; 
    moveDisks(n - 1, z, y);
}

void J::solve() {
    int n;
    std::cin >> n;

    moveDisks(n, 1, 3);
}
