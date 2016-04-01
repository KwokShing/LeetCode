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
    int maxPathSum(TreeNode* root) {                    
        int maxVal = 0;
        DFS(root);
        //DFS2(root,maxVal,0);
        return maxVal;
    }
    int DFS(TreeNode* node) {
        if(node) {
            int left = DFS(node->left);
            int right = DFS(node->right);
            if(0==right & 0==left) {
                return node->val;
            }
            else if(left > right) {
                cout<<"left > right: left: "<<left<<" right: "<<right<<endl;
                node->left->val = 0;
                node->val = max(left + node->val, left);
                return node->val;
            }
            else {
                node->right->val = 0;
                node->val = max(right + node->val, right);
                return node->val;
            }
        }
        else
            return 0;
    }

    void DFS2(TreeNode* node, int & maxVal, int preVal) {
        if(node) {
            int curVal = node->val + preVal;
            if(curVal > maxVal)
                maxVal = curVal;
            DFS2(node->left,maxVal,curVal);
            DFS2(node->right,maxVal,curVal);
        }
        else
            return;
    }
};

int main()
{
	TreeNode * root = new TreeNode(-2);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
//	root->right->left = new TreeNode(13);
//	root->right->right = new TreeNode(4);
//	root->right->right->left = new TreeNode(5);
//	root->right->right->right = new TreeNode(1);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->left->left = new TreeNode(-1);
	root->left->right->right = new TreeNode(-2);
	Solution s;
    cout<<s.maxPathSum(root)<<endl;
    return 0;
}
