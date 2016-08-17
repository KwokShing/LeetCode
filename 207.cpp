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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> deg(numCourses,0);
        vector<vector<int> > graph(numCourses,vector<int>());
        queue<int> q;
        int count = 0;
        for(auto pre:prerequisites) {
            graph[pre.first].push_back(pre.second);
            deg[pre.second]++;
        }
        for(int i = 0; i < deg.size(); ++i) {
            if(deg[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            int zero = q.front();
            q.pop();
            count++;
            for(int node:graph[zero])
                if(--deg[node] == 0)
                    q.push(node);
        }
        if(count == numCourses)
            return true;
        return false;
    }
};

int main()
{
    return 0;
}
