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
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        unordered_map<int, vector<int> > graph;
        vector<int> path;
        vector<int> targetPath;
        queue<int> q;
        for(int i = 0; i < n; ++i)
            path.push_back(i);

        for(pair<int, int> edge:edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        
        int curNode = 0;
        int target = 0;
        unordered_set<int> s;
        for(int i = 0; i < 2; ++i) {
            if(graph.empty())
                break;
            if(i==0)
                q.push(graph.begin()->first);
            else
                q.push(target);
            while(!q.empty()) {
                curNode = q.front();
                q.pop();
                s.insert(curNode);
                target = curNode;
                for(int child:graph[curNode]) {
                    if(s.find(child) == s.end()) {
                        q.push(child);
                        if(i == 1) {
                            path[child] = curNode;
                        }
                    }
                }
            }
            s.clear();
        }
        
        while(target != path[target]) {
            targetPath.push_back(target);
            target = path[target];
        }
        targetPath.push_back(target);
        //cout<<targetPath[targetPath.size()/2]<<endl;
        

        //even
        if((targetPath.size()&1) == 0)
            res.push_back(targetPath[(targetPath.size()>>1)-1]);

        res.push_back(targetPath[targetPath.size()>>1]);
        
        return res;
    }
};

int main()
{
    return 0;
}
