#include <iostream>
#include <vector>

int binarySearch(std::vector<int> nums, int target)
{
    if (!nums.size())
        return -1;

    int left = 0;
    int right = nums.size() - 1;
    int pivot;
    while(left <= right)
    {
        pivot = (left + right) / 2;

        if (nums[pivot] == target)
        {
            return pivot;
        }
        else if (nums[pivot] < target)
        {
            left = pivot + 1;
        }
        else
        {
            right = pivot - 1;
        } 
    }

    return -1;
}

int main()
{
    std::vector<int> nums = {1, 3, 5, 6, 7, 15, 20, 25};

    int result = binarySearch(nums, 5);
    if (result != -1)
        std::cout << "Found !" << std::endl;
    else
        std::cout << "Not Exist !" << std::endl;

    result = binarySearch(nums, 21);
    if (result != -1)
        std::cout << "Found !" << std::endl;
    else
        std::cout << "Not Exist !" << std::endl;
}