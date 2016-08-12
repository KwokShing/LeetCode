#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right) {
            if(nums[left] < nums[right])
                return left;
            int mid = left + ((right - left) >>1);
            if(nums[mid] >= nums[left])
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        int minIdx = findMin(nums);
        int size = nums.size();
        int left = 0;
        int right = size-1;
        while(left <= right) {
            int mid = left + ((right - left) >>1);
            int m = (mid+minIdx)%size;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                right = mid-1;
            else
                left = mid+1;
                
        }
        return -1;
    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a>>b;
    s.getSum(a,b);
}