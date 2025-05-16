#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "game_of_life.h"

using namespace std;

int main()
{
    game_of_life game_of_life;
    bool again;

    do
    {
        game_of_life.draw();
        game_of_life.next_generation();

        cout << "Again (1/0): ";
        cin >> again;
    }
    while (again);

    return 0;
}