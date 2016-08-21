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
    class Calculator {
    public:
        int type;
        int val;
        char op;
        Calculator(int type, int val, char op) {
            this->type = type;
            if(type == 1)
                this->val = val;
            else
                this->op = op;
        }
        static bool priority(char a, char b) {
            if((a == '*' || a == '/') && (b == '+' || b == '-'))
                return true;
            else
                return false;
        }
    };
    
    int calculate(string s) {
        vector<Calculator> v;
        stack<Calculator> ss;
        for(int i = 0; i < s.size();i++) {
            if(s[i] == ' ')
                continue;
            if(isdigit(s[i])) {
                int curIdx = i;
                while(i+1 < s.size() && isdigit(s[i+1]))
                    i++;
                int a = stoi(s.substr(curIdx, i-curIdx+1));
                v.push_back(Calculator(1,a,0));
            }
            else {
                if(ss.empty())
                    ss.push(Calculator(0,0,s[i]));
                else {
                    bool priority = Calculator::priority(s[i], ss.top().op);
                    if(priority)
                        ss.push(Calculator(0,0,s[i]));
                    else {
                        while(!ss.empty() && Calculator::priority(s[i], ss.top().op) == false) {
                            v.push_back(ss.top());
                            ss.pop();
                        }
                        ss.push(Calculator(0,0,s[i]));
                    }
                }
            }
        }
        while(!ss.empty()) {
            v.push_back(ss.top());
            ss.pop();
        }
        stack<int> val;
        stack<char> op;
        for(int i = 0; i < v.size(); ++i) {
            if(v[i].type == 1)
                val.push(v[i].val);
            else {
                int a = val.top(); val.pop();
                int b = val.top(); val.pop();
                switch (v[i].op) {
                    case '+':
                        val.push(a+b); break;
                    case '-':
                        val.push(b-a); break;
                    case '*':
                        val.push(a*b); break;
                    case '/':
                        val.push(b/a); break;
                }
            }
        }
        
        return val.top();
    }
};

int main()
{
    return 0;
}
