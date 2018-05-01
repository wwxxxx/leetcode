#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> vec;
        for (auto str : words) {
            bool r1 = str.find_first_of("QWERTYUIOPqwertyuiop") == string::npos ? false : true;
            bool r2 = str.find_first_of("ASDFGHJKLasdfghjkl") == string::npos ? false : true;
            bool r3 = str.find_first_of("ZXCVBNMzxcvbnm") == string::npos ? false : true;
            if (r1 + r2 + r3 == 1)
                vec.push_back(str);
        }
        return vec;
    }
};