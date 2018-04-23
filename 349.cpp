#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        /*
        unordered_set<int> s;
        for (int i : nums1)
            s.insert(i);
        vector<int> vec;
        for (int i : nums2)
            if (s.find(i) != s.end()) {
                vec.push_back(i);
                s.erase(i);
            }
        return vec;
        */
        unordered_map<int, int> m;
        for (int n : nums1)
            m[n]++;
        vector<int> vec;
        for (int n : nums2)
        {
            if (m[n])
            {
                vec.push_back(n);
                m[n] = 0;
            }
        }
        return vec;
    }
};