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
    class cmp {
        public:
        bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) {
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int,int> >, cmp > queue;
        unordered_map<int, int> mmap;
        for(size_t i = 0; i < nums.size(); ++i) {
            if(mmap.find(nums[i]) == mmap.end())
                mmap[nums[i]] = 1;
            else
                mmap[nums[i]]++;
        }
        for(unordered_map<int, int>::iterator it = mmap.begin(); it != mmap.end(); ++it) {
            cout<<it->first<<" "<<it->second<<endl;
            queue.push(make_pair(it->first, it->second) );
        }
        for(int i = 1; i <= k; ++i) {
            cout<<queue.top().first;
            res.push_back(queue.top().first);
            queue.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a,b;
    cin>>a>>b;
    s.getSum(a,b);
}