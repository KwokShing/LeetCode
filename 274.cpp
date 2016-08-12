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
    int hIndex(vector<int>& citations) {
        vector<int> count(99999,0);
        int range = 0;
        for(int num:citations) {
            if(num>=range)
                range = num;
            count[num]++;
        }
        count.resize(range+1);
        if(count[range] >= range)
            return range;
        for(int i = range-1; i >= 0; --i) {
            count[i] += count[i+1];
            if(count[i] >= i)
                return i;
            
        }
        return 0;
    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a>>b;
    s.getSum(a,b);
}