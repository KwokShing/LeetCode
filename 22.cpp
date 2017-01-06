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
    void backtracking(int l, int r, string combo, vector<string> &res) {

        if(l)
            backtracking(l-1, r, combo+'(', res);
        if(l<r)
            backtracking(l, r-1, combo+')', res);
        if(!r && !l)
            res.push_back(combo);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string combo;
        backtracking(n, n, combo, res);
        return res;
    }
};

int main()
{
    Solution s;
    int num[] = {2,3,6,7};
    vector<int> can(num,num+4);
    //s.generateParenthesis(3);
    int t = 5;
    t = t<<0;
    cout<<t<<endl;
}