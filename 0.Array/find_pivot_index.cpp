#include <iostream>
#include <vector>
#include <numeric>

int findPivotIdx(const std::vector<int> &v)
{
    int allSum = std::accumulate(v.begin(), v.end(), 0);
    int rightSum = allSum;
    int leftSum = 0;
    int prevPivot = 0;

    for (int pivot = 0; pivot < v.size(); ++pivot)
    {
        rightSum -= v[pivot];
        leftSum += prevPivot;

        if (rightSum == leftSum)
            return pivot;

        prevPivot = v[pivot];
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