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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		TreeNode * node = root;
		DFS(root,1,res);
		return res;
	}
	void DFS(TreeNode * node, int level, vector<int> & res) {
		if(!node)
			return;
		if(level>res.size())
			res.push_back(node->val);
		DFS(node->right,level+1,res);
		DFS(node->left,level+1,res);
	}
};

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(4);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->left->left = new TreeNode(5);
	root->left->left->left = new TreeNode(6);
	Solution s;
	vector<int> res;
	res = s.rightSideView(root);
	for(int i = 0; i < res.size(); ++i)
		cout<<res[i]<<endl;
	return 0;
}
