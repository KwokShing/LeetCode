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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    int v[5] = {0,0,0,0,0};
    return v[version-1];

}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid = (left+right)/2;
        bool f=false,ff=false;
        while((f = isBadVersion(mid)) or (ff=!isBadVersion(mid+1))) {
            if(f){
                right = mid;
                mid = (left+right)/2;
                if(mid==right)
                    return mid;
                continue;
            }
            if(ff) {
                left = mid;
                mid = (left+right)/2;
                if(mid==left)
                    return mid;
            }
                
        }
        
        return mid+1;
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
    cout<<s.firstBadVersion(5)<<endl; 
}
