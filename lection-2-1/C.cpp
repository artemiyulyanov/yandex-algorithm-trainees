#include "C.h"

bool C::isCrossRoadEquivalent(int a, int b) {
    if (a > b) {
        std::swap(a, b);
    }

    return (a == 1 && b == 3) ||
           (a == 2 && b == 4);
}

int C::getRightIndexFor(int direction) {
    return direction == 1 ? 4 : direction - 1;
}

bool C::isMain(int direction) {
    return direction == mainA || direction == mainB;
}

bool C::mustGiveWay(const Rover& x, const Rover& y) {
    bool xMain = isMain(x.direction);
    bool yMain = isMain(y.direction);

    
    if (!xMain && yMain) {
        return true;
    }

    
    if (xMain && !yMain) {
        return false;
    }

    
    return getRightIndexFor(x.direction) == y.direction;
}

void C::solve() {
    int n;
    std::cin >> n;

    std::cin >> mainA >> mainB;

    result.resize(n);

    for (int i = 0; i < n; ++i) {
        int d, t;
        std::cin >> d >> t;

        roads[d].push_back({
            d,
            t,
            i
        });
    }
    
    for (int d = 1; d <= 4; ++d) {
        std::sort(
            roads[d].begin(),
            roads[d].end(),
            [](const Rover& x, const Rover& y) {
                return x.arrivalTime < y.arrivalTime;
            }
        );
    }

    int remaining = n;
    int currentTime = 1;

    while (remaining > 0) {
        std::vector<int> front;
        
        for (int d = 1; d <= 4; ++d) {
            if (!roads[d].empty() &&
                roads[d].front().arrivalTime <= currentTime) {

                front.push_back(d);
            }
        }
        
        if (front.empty()) {
            int nextTime = 1e9;

            for (int d = 1; d <= 4; ++d) {
                if (!roads[d].empty()) {
                    nextTime = std::min(
                        nextTime,
                        roads[d].front().arrivalTime
                    );
                }
            }

            currentTime = nextTime;
            continue;
        }

        std::vector<int> canPass;
        
        for (int d : front) {
            const Rover& rover = roads[d].front();

            bool can = true;

            for (int otherD : front) {
                if (d == otherD) {
                    continue;
                }

                const Rover& other = roads[otherD].front();
                
                if (mustGiveWay(rover, other)) {
                    can = false;
                    break;
                }
            }

            if (can) {
                canPass.push_back(d);
            }
        }
        
        if (canPass.empty()) {
            currentTime++;
            continue;
        }
        
        for (int d : canPass) {
            Rover rover = roads[d].front();

            result[rover.id] = currentTime;

            roads[d].pop_front();
            --remaining;
        }

        ++currentTime;
    }

    for (int time : result) {
        std::cout << time << '\n';
    }
}