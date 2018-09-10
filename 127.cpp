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
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        if (hash.count(endWord) == 0)
            return 0;
        unordered_set<string> q1, q2;
        q1.insert(beginWord);
        q2.insert(endWord);
        int step = 0;
        while (!q1.empty() && !q2.empty())
        {
            ++step;
            unordered_set<string> temp;
            if (q1.size() > q2.size())
                swap(q1, q2);
            for (auto word : q1)
            {
                for (int i = 0; i < beginWord.size(); ++i)
                {
                    string tempWord = word;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        tempWord[i] = c;
                        if (q2.count(tempWord))
                            return step + 1;
                        if (hash.count(tempWord))
                        {
                            temp.insert(tempWord);
                            hash.erase(tempWord);
                        }
                    }
                }
            }
            swap(temp, q1);
        }
        return 0;
    }
};