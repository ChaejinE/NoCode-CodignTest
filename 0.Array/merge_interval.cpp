#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeInterval(const std::vector<int> &v1, const std::vector<int> &v2)
{
    std::vector<int> mergedInterval;

    if (v1[1] > v2[0])
    {
        mergedInterval.emplace_back(v1[0]);
        mergedInterval.emplace_back(v2[1]);
    }

    return mergedInterval;
}

int main()
{
    std::vector<std::vector<int>> v = {{1, 5}, {8, 16}, {3, 7}, {10, 15}};
    sort(v.begin(), v.end(), [](std::vector<int> &v1, std::vector<int> &v2) -> bool
         { if (v1[0] < v2[0]) return true; else return false; });

    std::vector<int> v1 = v[0];
    std::vector<int> v2;
    std::vector<int> mergedVector;
    std::vector<std::vector<int>> resultVector;
    v2.reserve(2);
    mergedVector.reserve(2);
    for (int idx = 1; idx < v.size(); ++idx)
    {
        v2 = v[idx];
        mergedVector = mergeInterval(v1, v2);

        if (!mergedVector.empty())
        {
            v1 = mergedVector;
        }
        else
        {
            resultVector.emplace_back(v1);
            v1 = v2;
        }
    }

    if (!resultVector.empty())
        resultVector.emplace_back(mergedVector);

    for (auto vec : resultVector)
    {
        std::cout << "{";
        for (auto e : vec)
        {
            std::cout << " " << e << " ";
        }
        std::cout << "}," << std::endl;
    }
    return 0;
}