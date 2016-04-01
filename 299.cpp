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
    string getHint(string secret, string guess) {
        //unordered_map<char,int> mmap;
        int *mmap = new int[10]();
        int A = 0, B = 0;
        for(int i = 0; i < secret.size(); ++i) {
            int num = secret[i]-48;
            mmap[num]++;
        }
        for(int i = 0; i < guess.size(); ++i) {
            int num = guess[i]-48;
            if(guess[i] == secret[i]) {
                if(mmap[num] > 0)
                    mmap[num]--;
                else if(mmap[num] == 0)
                    B--;
                A++;
            } else {
                if(mmap[num] > 0) {
                    mmap[num]--;
                    B++;
                }
            }
        }
        return to_string(A) + "A" + to_string(B) + "B"; 
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
