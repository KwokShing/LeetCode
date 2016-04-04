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
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1)
            return 0;
        vector<int> have(size,0);
        vector<int> nothave(size,0);
        have[0] = -prices[0];
        have[1] = max(have[0],-prices[1]);
        nothave[0] = 0;
        nothave[1] = max(nothave[0],have[0]+prices[1]);
        cout<<"1:  "<<nothave[1]<<endl;
        for(int i = 2; i < size; ++i) {
            have[i] = max(have[i-1],nothave[i-2]-prices[i]);
            nothave[i] = max(nothave[i-1],have[i-1]+prices[i]);
        }
        for(int x:nothave)
            cout<<x<<" ";
        return nothave[size-1];
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
    int r[5] = {1,2,3,0,2};
    vector<int> rr(r,r+5);
    Solution s;
    s.maxProfit(rr);
    
}
