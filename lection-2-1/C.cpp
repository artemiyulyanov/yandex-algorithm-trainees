//
// Created by Артемий on 12/09/2026.
//

#include "C.h"

void C::solve() {
    int n;
    std::cin >> n;

    std::unordered_map<int, std::vector<Rover>> roversWithDirectionAtTimestamp;
    std::vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        int d, t;
        std::cin >> d >> t;

        roversWithDirectionAtTimestamp.try_emplace(t, std::vector<Rover>());

        roversWithDirectionAtTimestamp[t].push_back(Rover {
            d, t, i
        });
    }

    std::vector<std::queue<Rover>> directionQueues(5);

    int passed = 0;

    int timestamp = 1;

    while (passed < n) {
        if (roversWithDirectionAtTimestamp.contains(timestamp)) {
            for (auto& rover : roversWithDirectionAtTimestamp[timestamp]) {
                directionQueues[rover.direction].push(rover);
            }
        }



        timestamp++;
    }
}
