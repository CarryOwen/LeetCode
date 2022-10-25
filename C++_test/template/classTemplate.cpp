#include "iostream"
#include "algorithm"
#include "stdio.h"
using namespace std;
template <class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPerson()
    {
        cout << "name:" << this->m_name << " age:" << this->m_age << endl;
    }
    NameType m_name;
    AgeType m_age;
};
int main()
{
    Person<string, int> p1("zhugong", 999);
    p1.showPerson();
    Person<char, int> p2('a', 7);
    p2.showPerson();
    getchar();
}