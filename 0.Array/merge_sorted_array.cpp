#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &v1, int m, std::vector<int> &v2, int n)
{
    int idx1 = m - 1;
    int idx2 = n - 1;
    int idx3 = v1.size() - 1;

    if (v2.size() <= 0)
        return;

    while (idx1 >= 0 && idx2 >= 0)
    {
        if (v1[idx1] >= v2[idx2])
        {
            v1[idx3] = v1[idx1];
            --idx1;
        }
        else
        {
            v1[idx3] = v2[idx2];
            --idx2;
        }

        --idx3;
    }

    if (idx2 >= 0)
        std::copy(v2.begin(), v2.begin() + idx2 + 1, v1.begin());
}

int main()
{
    // std::vector<int> v1 = {1, 3, 5, 0, 0, 0};
    // std::vector<int> v2 = {2, 4, 8};

    std::vector<int> v1 = {4, 5, 6, 0, 0, 0};
    std::vector<int> v2 = {1, 2, 3};

    merge(v1, 3, v2, 3);

    for (int e : v1)
        std::cout << e << ", ";

    std::cout << std::endl;

    return 0;
}