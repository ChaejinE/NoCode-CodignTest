#include <iostream>
#include <vector>
#include <numeric>

int pivotIndex(std::vector<int> &nums)
{
    int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    int pastPivot;

    for (int idx = 0; idx < nums.size(); ++idx)
    {
        rightSum -= nums[idx];

        if (rightSum == leftSum)
        {
            return idx;
        }
        else
        {
            pastPivot = nums[idx];
            leftSum += pastPivot;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> v = {1, 8, 2, 9, 2, 3, 6};
    int pivot = pivotIndex(v);

    std::cout << "Pivot is : " << pivot << std::endl;

    return 0;
}