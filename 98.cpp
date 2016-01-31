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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> order;
        inorder(root,order);
        for(int i = 1; i < order.size(); ++i) {
            if(order[i] <= order[i-1])
                return false;
        }
        return true;
    }
    void inorder(TreeNode* node, vector<int> & order) {
        if(node) {
            inorder(node->left,order);
            order.push_back(node->val);
            inorder(node->right,order);
        }
    }
};

int main()
{
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);
	//root->left->left = new TreeNode(5);
	//root->left->left->left = new TreeNode(6);
	Solution s;
	cout<<s.isValidBST(root)<<endl;
    return 0;
}
