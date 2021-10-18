#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int l = 0 : int r = nums.size()-1;
    int x;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == key)
        {
            return mid;
        }
        if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
    return nums;
}

int main()
{
    vector<int> nums = {27, 35, 14, 5, 16, 32, 45, 78, 98, 35};
    int target = 37;
    vector<int> sorted = twoSum(nums, target);
    for (auto x : sorted)
    {
        cout << x << " ";
    }

    return 0;
}
