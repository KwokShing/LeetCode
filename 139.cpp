#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <time.h>
#include <sstream>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;



class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty() && wordDict.empty())
            return true;
        if(s.empty() || wordDict.empty())
            return false;
        vector<bool> opt(s.size(), false);
        //opt[0] = true;
        opt[0] = wordDict.find(s.substr(0,1)) != wordDict.end();
        for(int i = 1; i < s.size(); ++i)
            for(int j = i-1; j >= 0; --j) {
                if(opt[j]) {
                    string tmp = s.substr(j+1,i-j);
                    if(wordDict.find(s.substr(j+1,i-j)) != wordDict.end()) {
                        //cout<<tmp<<endl;
                        opt[i] = true;
                        break;
                    }
                }
                if(j == 0) {
                    string tmp = s.substr(j,i-j+1);
                    if(wordDict.find(s.substr(j,i-j+1)) != wordDict.end()) {
                        opt[i] = true;
                        //cout<<tmp<<endl;
                        break;
                    }
                }
            }
        
        return opt[s.size()-1];
    }
};


int main()
{
    return 0;
}
