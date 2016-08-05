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
    int getSum(int a, int b) {
        int c = 0;
        do {
            c = a&b;
            a = a^b;
            b = c<<1;
            //c = b<<1;
        } while(b);
        cout<<a<<endl;
        return a;
    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a>>b;
    s.getSum(a,b);
}