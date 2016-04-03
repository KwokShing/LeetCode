#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
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
    unordered_map<TreeNode *, int> mmap;
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(mmap.find(root) != mmap.end())
            return mmap[root];
        int lval = root->left?rob(root->left->left)+rob(root->left->right):0;
        int rval = root->right?rob(root->right->left)+rob(root->right->right):0;
        int res = max(root->val + lval + rval, rob(root->left)+rob(root->right));
        mmap[root] = res;
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
    cout<<s.getHint("1123","0111")<<endl;
    
}
