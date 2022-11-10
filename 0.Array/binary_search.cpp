#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &v, auto target)
{
    int leftIdx = 0;
    int rightIdx = v.size() - 1;
    int pivotIdx;

    while (leftIdx <= rightIdx)
    {
        pivotIdx = (leftIdx + rightIdx) / 2;

        if (v[pivotIdx] == target)
        {
            return pivotIdx;
        }
        else if (v[pivotIdx] < target)
        {
            leftIdx = pivotIdx + 1;
        }
        else
        {
            rightIdx = pivotIdx - 1;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    auto targetIdx = binarySearch(v, 5);

    if (targetIdx != -1)
        std::cout << "target Idx is : " << targetIdx << std::endl;
    else
        std::cout << "Not Exist" << std::endl;

    return 0;
}