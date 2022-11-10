#include <iostream>
#include <vector>
#include <numeric>

int findPivotIdx(const std::vector<int> &v)
{
    int rightSum = std::accumulate(v.begin(), v.end(), 0);
    int leftSum = 0;
    int prevPivot = 0;

    for (int idx = 0; idx < v.size(); ++idx)
    {
        rightSum -= v[idx];
        leftSum += prevPivot;

        if (rightSum == leftSum)
            return idx;

        prevPivot = v[idx];
    }

    return -1;
}

int main()
{
    std::vector<int> v = {1, 8, 2, 9, 2, 3, 6};

    int pivotIdx = findPivotIdx(v);

    std::cout << "Pivot Index is : " << pivotIdx << std::endl;

    return 0;
}