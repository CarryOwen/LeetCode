#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)
        {
            if (nums[0] == target)
                return 0;
            else {
                return nums[0] > target ? 0 : 1;
            }
        }
        if (target<=nums[0])
        {
            return 0;
        }
        else if (target > nums[n - 1])
        {
            return n;
        }
        else if (target == nums[n - 1])
        {
            return n - 1;
        }
        int left = 0, right = n - 1;
        int flag = 3;
        while (left<=right)
        {
            
            int mid = (left + right + 1) / 2;
            if (nums[mid]==target)
            {
                return mid;
            }
            if (left == right)
                if (left == right && flag == 1)
                    return left + 1;
                else if (left == right && flag == 0)
                    return right;
        
            if (target>=nums[left]&&target<=nums[mid])//说明在左侧
            {
                right = mid - 1;
                flag = 1;
            }
            else//在右侧
            {
                if (target <= nums[left])
                {
                    return left;
                }
                else if (nums[right] < target)
                    return right + 1;
                else if (nums[right] == target)
                    return right - 1;
                left = mid + 1;
                flag = 0;
            }
        }
        return 0;
    }
};

int main()
{
    Solution so;
    vector<int> vec = {3,5,7,9,10};
    cout <<so.searchInsert(vec,8);
	return 0;
}