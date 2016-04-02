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


 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mmap;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(mmap.find(nums[i]) == mmap.end()) {
                mmap[target-nums[i]] = i;
            } else {
                res.push_back(mmap[nums[i]]);
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};

int main()
{
    ListNode * head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    //while(head) {
    //    cout<<head->val<<endl;
    //    head = head->next;
    //}
    int v[3] = {3,2,4};
    vector<int> vv(v,v+3);
    Solution s;
    vector<int> res;
    res = s.twoSum(vv,7);
    cout<<res[0]<<endl<<res[1]<<endl;
    
}
