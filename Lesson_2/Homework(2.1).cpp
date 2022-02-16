//1. Создать класс Person(человек) с полями : имя, возраст, пол и вес.
//   Определить методы переназначения имени, изменения возраста и веса.
//   Создать производный класс Student(студент), имеющий поле года обучения.
//   Определить методы переназначения и увеличения этого значения.
//   Создать счетчик количества созданных студентов.
//   В функции main() создать несколько(не больше трёх) студентов.Вывести информацию о них.


#include <iostream>
#include <string>

using namespace std;
class Person
{
private:
    static int count;
protected:
    string n_name;
    int n_age;
    string n_sex;
    int n_wight;


public:
    static int GetCount() 
    { 
        return count; 
    }
    Person(const string& name, const int& age, const string& sex, const int& wight)
        : n_name(name), n_age(age), n_wight(wight), n_sex(sex)
    {
        count++;
    }

    string GetName() 
    { 
        return n_name; 
    }
    int GetAge() 
    { 
        return n_age; 
    }
    int GetWighr() 
    { 
        return n_wight; 
    }
    virtual void Print() 
    {
        cout << n_name << ' ' << n_age << ' ' << n_sex << ' ' << n_wight << endl;
    }
};

class Student : public Person
{
private:
    int n_year;
public:
    Student(int year, const string& name, const int age, const string& sex, const int wight)
        :Person(name, age, sex, wight), n_year(year)
    {
    }
    int GetYear() 
    { 
        return n_year; 
    }
    void AddYear(int addValue)
    {
        n_year += addValue;
    }
    void AddYear()
    {
        n_year++;
    }
    void Print()
    {
        cout << n_year << ' ';
        Person::Print();
    }
};
int Person::count = 0;

int main()
{
    setlocale(LC_ALL, "rus");

    const int N = 3;
    Person* pers[N];
    for (int i = 0; i < N; i++)
    {
        int year, wight, age;
        string name, sex;
        cout << "Введите Имя, Возраст, Пол, Вес: " << endl;
        cin >> name >> age >> sex >> wight >> year;
        pers[i] = new Student(year, name, age, sex, wight); 
        cout << "Подсчет: " << pers[i]->GetCount() << endl; 
    }
    for (int i = 0; i < N; i++)
        pers[i]->Print();
    Student* s1 = static_cast<Student*>(pers[0]);
    s1->AddYear(2);
    cout << "Обучение: " << s1->GetName() << " = "
        << s1->GetAge() << endl;
    for (int i = 0; i < N; i++)
        delete pers[i];
    return 0;
}