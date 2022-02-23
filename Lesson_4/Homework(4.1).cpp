//  1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
//     • для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//     • для удаления первого элемента массива(аналог pop_front() в векторах)
//     • для сортировки массива
//     • для вывода на экран элементов.


#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayInt.h"


void Task1()
{
    ArrayInt array;
    array.push_back(5);
    array.push_back(3);
    array.push_back(2);
    array.push_back(16);
    array.push_back(8);
    array.push_back(7);
    array.push_back(9);
    array.push_back(9);
    array.push_back(8);
    array.push_back(8);


    std::cout << "Initial array:";
    array.print();

    array.pop_back();
    std::cout << "Array after pop_back:";
    array.print();

    array.pop_front();
    std::cout << "Array after pop_front:";
    array.print();

    array.sort();
    std::cout << "Sorted array:";
    array.print();
}


int main()
{
  
}
