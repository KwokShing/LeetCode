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


class Solution {
public:
    //int count = 0;
    unordered_map<string, bool> mmap;
    bool backtracking(string s, bool first) {
        //cout<<count++<<endl;
        if(mmap.find(s) != mmap.end()) {
            return mmap[s];
        }
        bool t = true;
        if(first)
            t = false;
        else
            t = true;
        for(int i = 0; i < s.size()-1; ++i) {
            string tmp = s;
            if(s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                if(first) {
                    t |= backtracking(s, !first);
                    if(t) {
                        mmap[tmp] = t;
                        return true;
                    }
                }
                else {
                    t &= backtracking(s, !first);
                }
            }
            s = tmp;
        }
        mmap[s] = t;
        return t;
    }
    bool canWin(string s) {
        if(s.size() == 0)
            return false;
        return backtracking(s, true);
    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a>>b;
    s.getSum(a,b);
}