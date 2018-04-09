#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        //hash
        unordered_map<int, int> absum;
        for (int a : A)
        {
            for (int b : B)
            {
                absum[a + b]++;
            }
        }
        int count = 0;
        for (int c : C)
        {
            for (int d : D)
            {
                auto it = absum.find(0 - c - d);
                if (it != absum.end())
                    count += it->second;
            }
        }
        return count;
    }
};