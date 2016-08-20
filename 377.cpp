#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <list>
#include <cstring>
#include <sstream>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;



class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        vector<int> opt(target+1, 0);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= target; ++i)
            opt[nums[i]] = 1;
        for(int i = 1; i <= target; ++i)
            for(int j = 0; j < nums.size() && nums[j] < i; ++j) {
                opt[i] += opt[i-nums[j]];
            }
        return opt[target];
    }
};

int main()
{
    return 0;
}
