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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *pre = head, *cur = head->next, *next = cur;
        while(next and next->next) {
            pre->next = pre->next->next;
            next->next = next->next->next;
            pre = pre->next;
            next = next->next;
        }
        pre->next = cur;
        return head;

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
    ListNode * tmp = s.oddEvenList(head);
    while(tmp) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    
}
