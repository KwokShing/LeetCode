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



class Solution {
public:
    Solution() {
        int n = 13;
        res = 0;
        col.resize(n+10,0);
        pb.resize(n*4,0);
        nb.resize(n*4,0);
    }
    void backtracking(int iidx, int queen, int n) {
        if(queen--==0) {
            res++;
            return;
        }
        for(int j = 1; j <= n; ++j) {
            if(col[j] || pb[iidx+j] || nb[iidx-j])
                continue;
            col[j] = 1;
            pb[iidx+j] = 1;
            nb[iidx-j] = 1;
            backtracking(iidx+1, queen, n);
            col[j] = 0;
            pb[iidx+j] = 0;
            nb[iidx-j] = 0;
        }
    }
    
    int totalNQueens(int n) {
        /*
        res = 0;
        col.resize(n+1,0);
        pb.resize(n*3,0);
        nb.resize(n*3,0);
         */
        backtracking(1, n, n);
        return res;
    }
private:
    vector<int> col;
    vector<int> pb;
    vector<int> nb;
    int res;
};

int main()
{
    Solution s;
    cout<<s.totalNQueens(13)<<endl;
    return 0;
}
