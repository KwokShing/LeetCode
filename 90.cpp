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
    void backtracking(int idx, int target, vector<int> & combo, vector<int> &nums, vector<vector<int> > &res) {
        res.push_back(combo);
        
        for(int i = idx; i < nums.size(); ++i) {
            if(idx == i || nums[i] != nums[i-1]) {
                combo.push_back(nums[i]);
                backtracking(i+1, target-1, combo, nums, res);
                combo.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        vector<int> combo;
        backtracking(0, 1, combo, nums, res);
        return res;
    }
};

int main()
{
    return 0;
}
