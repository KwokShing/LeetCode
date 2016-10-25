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
    int numWays(int n, int k) {
        if(n<=1 || k == 0)
            return k*n;
        int same = k;
        int diff = k*(k-1);
        int tmp = 0;
        for(int i = 2; i < n; ++i) {
            tmp = same;
            same = diff;
            diff = (tmp + diff)*(k-1);
        }
        return same+diff;
    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a>>b;
    s.getSum(a,b);
}