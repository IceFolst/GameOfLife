//
// Created by alexandre on 11/05/25.
//
#include <ctime>
#include "game_of_life.h"

bool game_of_life::random_value()
{
    int myrand = rand() % (100 - 0 + 1);
    return myrand < 25;
}

int game_of_life::how_many_neighbours(int i, int j)
{
    int neighbours = 0;
    for (int x= -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            if (i+x >= 0 && i+x < ROWS && j+y >= 0 && j+y < COLS)
            {
                if (x != 0 && y != 0)
                {
                    neighbours += (_generation[x+i][y+j] == true) ? 1 : 0;
                }
            }
        }
    }
    return neighbours;
}

game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            _generation[i][j] = random_value();
        }
    }
    generation = 0;
}

void game_of_life::next_generation()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbours = how_many_neighbours(i, j);
            if (_generation[i][j] == true && (neighbours == 2 || neighbours == 3))
            {
                _next_generation[i][j] = true;
            }
            else if (_generation[i][j] == true)
            {
                _next_generation[i][j] = false;
            }
            else if (_generation[i][j] == false && neighbours == 3)
            {
                _next_generation[i][j] = true;
            }
            else
            {
                _next_generation[i][j] = false;
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            _generation[i][j] = _next_generation[i][j];
        }
    }
    generation += 1;
}

void game_of_life::draw()
{
    cout << "<======================================>" << endl;
    cout << "Generation: " << generation << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << (_generation[i][j] ? "*" : "_") << " ";
        }
        cout << endl;
    }
}
