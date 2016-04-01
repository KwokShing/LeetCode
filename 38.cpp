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
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; ++i) {
            res = helper(res);
        }
        return res;
    }
        
        
    string helper(string num) {
        string res;
        char pre = 'a';
        int count = 0;
        for(int i = num.size()-1; i >= 0; --i) {
            if(num[i] == pre)
                count++;
            else {
                if(count>0)
                    res = to_string(count) + pre + res;
                count = 1;
            }
            pre = num[i];
        }
        res = to_string(count) + pre + res;
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
    Solution s;
    cout<<s.countAndSay(5)<<endl;
    
}
