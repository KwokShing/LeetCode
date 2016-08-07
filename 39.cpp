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
    void dfs(int idx, int target, vector<int>& candidates, vector<int> &path, vector<vector<int> > &res) {
        if(target < 0)
            return;
        else if(target == 0) {
            res.push_back(path);
            return;
        }
        else {
            for(size_t i = idx; i < candidates.size() && candidates[i] <= target; ++i) {
                path.push_back(candidates[i]);
                dfs(i, target - candidates[i], candidates, path, res);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(0,target, candidates, path, res);
        return res;
    }
};

int main()
{
    Solution s;
    int num[] = {2,3,6,7};
    vector<int> can(num,num+4);
    vector<vector<int> > t = s.combinationSum(can, 7);
    for(auto v:t) {
        for(auto vv:v)
            cout<<vv<<" ";
        cout<<endl;
    }
}