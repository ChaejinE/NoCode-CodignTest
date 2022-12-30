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
        // pivot 갱신
        pivot = (left + right) / 2;
        
        if (nums[pivot] == target) // pivot과 target이 같으면 return
        {
            return pivot;
        }
        else if (nums[pivot] < target) // pivot 값보다 target이 크면 찾는 값은 pivot 오른쪽에 있다는 의미
        {
            left = pivot + 1; // left index를 pivot 오른쪽으로 갱신
        }
        else // pivot 값보다 target이 작으면 pivot 왼쪽에 있다는 의미
        {
            right = pivot - 1; // right index를 pivot 왼쪽으로 갱신
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