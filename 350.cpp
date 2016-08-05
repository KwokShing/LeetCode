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
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        //v3
        unordered_map<int, int> mmap;
        for(vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it) {
            if(mmap.find(*it) == mmap.end()) {
                mmap[*it] = 1;
            } else
                mmap[*it]+=1;
        }
        for(vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it) {
            if(mmap.find(*it) != mmap.end()) {
                res.push_back(*it);
                if(mmap[*it] > 1)
                    mmap[*it]--;
                else
                    mmap.erase(*it);
            }
        }
        /*v2
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        
        while(it1 != nums1.end() && it2 != nums2.end()) {
            if(*it1 < *it2)
                it1++;
            else if(*it1 > * it2)
                it2++;
            else {
                res.push_back(*it1);
                it1++;
                it2++;
            }
        }
        */
        //v1        
        //unordered_set<int> s1(nums1.begin(), nums1.end());
        //unordered_set<int> s2(nums2.begin(), nums2.end());
        //set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(res));
        return res;
        
    }
};

int main()
{
    Solution s;
}