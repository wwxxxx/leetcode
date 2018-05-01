#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> countBits(int num)
    {
        /*
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i <= num; i++)
            vec.push_back(vec[i & (i - 1)] + 1);
        return vec;
        */
        vector<int> vec(num + 1, 0);
        for (int i = 1; i <= num; i++)
            vec[i] = i & 1 ? vec[i - 1] + 1 : vec[i >> 1];
        return vec;
    }
};