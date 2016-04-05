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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode *pre = NULL, *next, *cur = head, *fast = NULL;
        int count = 0;
        do {
            if(count == 0)
                fast = head->next;
            if(count > 0)
                fast = fast->next->next;
            count++;
            //fast = fast->next->next;
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;

        }while(fast->next && fast->next->next);
        
        //n = count;
        //next = cur->next;
        if(fast->next)//odd
            cur = cur->next;
        while(pre) {
            if(pre->val != cur->val)
                return false;
            cur = cur->next;
            pre = pre->next;
        }
        return true;
    }
};



int main()
{
    ListNode * head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(0);
    //while(head) {
    //    cout<<head->val<<endl;
    //    head = head->next;
    //}
    int r[5] = {1,2,3,0,2};
    vector<int> rr(r,r+5);
    Solution s;
    cout<<s.isPalindrome(head);
    
}
