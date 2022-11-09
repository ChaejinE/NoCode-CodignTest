#include <iostream>
#include <vector>
#include <algorithm>

struct Employee
{
    int age;
    char name;
};

bool operator<(const Employee &lhs, const Employee &rhs)
{
    return lhs.age < rhs.age;
};

int main()
{
    std::vector<Employee> v{
        {200, 'A'},
        {200, 'B'},
        {200, 'C'},
        {200, 'D'},
        {200, 'F'},
    };

    for (int i = 9; i < 30; i++)
        v.emplace_back(Employee{i, 'Z'});

    // std::stable_sort(v.begin(), v.end());
    std::sort(v.begin(), v.end());

    for (const Employee &e : v)
        std::cout << e.age << ", " << e.name << std::endl;
}