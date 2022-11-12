#include <iostream>
#include <vector>
#include <algorithm>

void sortColors(std::vector<int> &v)
{
    auto iter0 = v.begin();
    auto iter2 = v.end() - 1;
    auto iter1 = v.begin();

    while (iter1 <= iter2)
    {
        if (*iter1 == 0)
        {
            std::iter_swap(iter1, iter0);
            ++iter0;
        }
        else if (*iter1 == 2)
        {
            std::iter_swap(iter1, iter2);
            --iter2;
        }
        else
        {
            ++iter1;
        }
    }
}

int main()
{
    std::vector<int> v = {1, 0, 2, 2, 0, 1, 2, 1, 0};

    sortColors(v);

    for (int e : v)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}