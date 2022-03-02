//1. Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
//   если пользователь вводит что-то кроме одного целочисленного значения, 
//   нужно вывести сообщение об ошибке и предложить ввести число еще раз.


#include <iostream>
#include <cstdlib>
#include <string>

int getInt()
{
    std::string input;
    int intInput = 0;

    while (true)
    {
        bool formatCheck = true;
        std::cout << "Введите число: ";
        std::getline(std::cin, input);
        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i])) formatCheck = false;
        }
        if (formatCheck)
        {
            intInput = std::stoi(input);
            return intInput;
        }
        else
        {
            system("cls");
            std::cerr << "Неверный формат!" << std::endl;
            std::cin.clear();                 
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int result = getInt();
}

