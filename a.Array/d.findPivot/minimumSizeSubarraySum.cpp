#include <iostream>
#include <vector>
#include <limits.h>

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int leftIdx = 0;
    int sum = 0;
    int subArrayLength = INT_MAX;

    for (int rightIdx = 0; rightIdx < nums.size(); ++rightIdx)
    {
        sum += nums[rightIdx];
        while (sum >= target)
        {
            subArrayLength = std::min(subArrayLength, rightIdx - leftIdx + 1);
            sum -= nums[leftIdx];
            ++leftIdx;
        }
    }

    return (subArrayLength != INT_MAX) ? subArrayLength : 0;
}

int main()
{
    std::vector<int> v = {2, 3, 1, 2, 4, 3};
    int minLength = minSubArrayLen(7, v);

    std::cout << "subArray min length : " << minLength << std::endl;
    return 0;
}