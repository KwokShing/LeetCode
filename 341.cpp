#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <time.h>
#include <sstream>
using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    stack<int> s;
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    void helper(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; --i) {
            if(nestedList[i].isInteger())
                s.push(nestedList[i].getInteger());
            else {
                helper(nestedList[i].getList());
            }
                
        }
    }

    int next() {
        int res = s.top();
        s.pop();
        return res;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */