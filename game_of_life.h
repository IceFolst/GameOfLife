//
// Created by alexandre on 11/05/25.
//

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class game_of_life {
private:
    static const unsigned int COLS = 40;
    static const unsigned int ROWS = 20;
    bool _generation[ROWS][COLS];
    bool _next_generation[ROWS][COLS];
    bool random_value();
    int how_many_neighbours(int i, int j);

public:
    game_of_life();
    void next_generation();
    void draw();
    int generation;
};

#endif /* !GAME_OF_LIFE_H */
