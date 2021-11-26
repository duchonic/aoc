#pragma once

#include <vector>

void show(std::vector<std::pair<int,int>> pixel, int screenX, int screenY) {
    for (int y = 0; y < screenY; y++) {
        for (int x = 0; x < screenX; x++) {
            bool found = false;
            for (auto p : pixel) {
                if (x == p.first && y == p.second) {
                    found = true; 
                }
            }
            if (found) {
                std::cout << 'X';
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

template<typename T>T shwo(T blub){
    return blub;
}
