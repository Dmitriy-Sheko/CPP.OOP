#include <iostream>
#include <vector>
#include "BlackJack.h"

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    std::vector<std::string> playerNames = { "Игрок" };
    Game* game = new Game(playerNames);
    bool isInProgress = true;
    while (isInProgress)
    {
        game->Play();
        std::cout << "\nСыграть ещё раз? (Y/N): ";
        bool formatCheck = true;
        std::string input;
        std::getline(std::cin, input);
        if (std::cin && (input == "N" || input == "n")) isInProgress = false;
        else if (std::cin && (input == "Y" || input == "y")) isInProgress = true;
        else
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Введите y или n!";
        }
    }
    delete game;
    return 0;
}
