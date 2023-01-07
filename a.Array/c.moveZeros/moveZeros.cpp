#include <iostream>
#include <vector>

// https://leetcode.com/problems/move-zeroes/description/

void moveZeros(std::vector<int> &nums)
{
    int zeroIdx = 0;
    for (int idx = 0; idx < nums.size(); ++idx)
    {
        if (nums[idx] != 0)
        {
            std::swap(nums[zeroIdx], nums[idx]);
            ++zeroIdx;
        }
    }
}

int main()
{
    std::vector<int> v = {0, 5, 4, 0, 3, 0, 2, 1};

    moveZeros(v);

    for (auto n : v)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
