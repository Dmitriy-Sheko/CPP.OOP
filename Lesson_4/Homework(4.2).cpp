// 2. Дан вектор чисел, требуется выяснить, сколько среди них различных.Постараться использовать максимально быстрый алгоритм.

#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int>& input)
{
    std::cout << "\n";
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
        std::cout << *it << " ";
}
int countUniqueNumbers(std::vector<int> input)
{
    std::sort(input.begin(), input.end());
    std::vector<int>::iterator it;
    it = std::unique(input.begin(), input.end());
    input.resize(std::distance(input.begin(), it));
    //printVector(input); - test
    return input.size();
}

int main()
{
    std::vector<int> array = { 2, 3, 5, 6, 6, 6, 7, 6, 1, 1, 2, 11, 24, 5311 };
    std::cout << "\nInitial array:";
    printVector(array);
    int count = countUniqueNumbers(array);
    std::cout << "\nUnique numbers: " << count;   
}
