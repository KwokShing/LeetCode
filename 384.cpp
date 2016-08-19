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
    vector<int> nums;
    Solution(vector<int> nums) {
        srand (time(NULL));
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        sort(nums.begin(), nums.end());
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int j = 0;
        for(int i = nums.size()-1; i > 0; --i) {
            j = rand()%(i+1);
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};

int main()
{
    return 0;
}
