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



class NumArray {
public:
    int lowbit(int x) {
        return x&(-x);
    }
    
    NumArray(vector<int> &nums) {
        size = nums.size();
        c.resize(size+1);
        ori = nums;
        for(int i = 0; i < size; ++i) {
            add(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        add(i, val-ori[i]);
        ori[i] = val;
    }
    
    void add(int i, int val) {
        i++;
        while(i <= size) {
            c[i] += val;
            i += lowbit(i);
        }
    }
    
    int getSum(int i) {
        i++;
        int isum = 0;

        while(i>0) {
            isum += c[i];
            i -= lowbit(i);
        }
        return isum;
    }
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
private:
    vector<int> c;
    vector<int> ori;
    int size;
};


int main()
{
    return 0;
}
