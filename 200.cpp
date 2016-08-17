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
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int total = m*n;
        int visit = 0;
        int res = 0;
        //while(visit <= total) {
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    q.push(make_pair(i, j));
                    grid[i][j] = '#';
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        int x = cur.first; int y = cur.second;
                        q.pop();
                        
                        if(x >= 1 && grid[x-1][y] == '1') {q.push(make_pair(x-1,y)); grid[x-1][y] = '#';}
                        if(x < m-1 && grid[x+1][y] == '1') {q.push(make_pair(x+1,y)); grid[x+1][y] = '#';}
                        if(y >= 1 && grid[x][y-1] == '1') {q.push(make_pair(x,y-1)); grid[x][y-1] = '#';}
                        if(y < n-1 && grid[x][y+1] == '1') {q.push(make_pair(x,y+1)); grid[x][y+1] = '#';}
                    }
                    res++;
                }
                
            }
        //}
        return res;
    }
};

int main()
{
    return 0;
}
