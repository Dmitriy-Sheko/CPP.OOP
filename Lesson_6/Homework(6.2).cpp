// 2. Создать собственный манипулятор endll для стандартного потока вывода, 
//    который выводит два перевода строки и сбрасывает буфер.

#include <iostream>
#include <cstdlib>
#include <string>

std::ostream& endll(std::ostream& stream)
{
    stream << "\n\n";
    stream.clear();
    return stream;
}

int main()
{
    std::cout << "string " << endll << "string";
}