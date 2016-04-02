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
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<int> wbit(size,0);
        vector<int> wsize(size,0);
        int i = 0, j = 0;
        for(i = 0; i < size; ++i) {
            for(j = 0; j < (wsize[i] = words[i].size()); ++j) {
                wbit[i] |= 1<<(words[i][j]-'a');
            }
        }
        int product = 0;
        int maxproduct = 0;
        for(i = 0; i < size; ++i) {
            for(j = i+1; j < size; ++j) {
                if((wbit[i]&wbit[j]) == 0){
                    product = wsize[i]*wsize[j];
                }
                if(product>maxproduct)
                    maxproduct = product;
            }
        }
        return maxproduct;
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
