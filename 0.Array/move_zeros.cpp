#include <iostream>
#include <vector>
#include <algorithm>

void moveZeros(std::vector<int> &v)
{
    auto iter1 = v.begin();

    for (auto iter2 = v.begin(); iter2 != v.end(); ++iter2)
    {
        if (*iter2 != 0)
        {
            std::iter_swap(iter1, iter2);
            ++iter1;
        }
    }
}

int main()
{
    std::vector<int> v = {0, 5, 0, 7, 6, 3};

    moveZeros(v);

    for (int e : v)
        std::cout << e << std::endl;

    return 0;
}
