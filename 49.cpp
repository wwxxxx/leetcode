#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> mp;
        vector<vector<string>> ret;
        int id = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp(strSort(strs[i]));
            if (mp.find(temp) == mp.end())
            {
                mp[temp] = id++;
                ret.push_back(vector<string>(1, strs[i]));
            }
            else
                ret[mp[temp]].push_back(strs[i]);
        }
        return ret;
    }

    /*
    vector<vector<string>> groupAnagrams(vector<string>& arr) 
    {
        unordered_map<int, vector<string>>mp;
        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        for(auto s : arr)
        {
            int sum = 1;
            for(int i=0; i<s.size(); i++)
            {
                sum *= prime[s[i] - 'a'];
            }
            mp[sum].push_back(s);
        }
        vector<vector<string>>res;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            res.push_back((*it).second);
        }
        
        return res;
    }
    */

  private:
    string strSort(string &s)
    {
        int count[26] = {0};
        int n = s.size();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    }
};