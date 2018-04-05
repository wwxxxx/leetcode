#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 1, b = 1;
		while (n--)
			a = (b += a) - a;
		return a;
		/*
		if (n <= 2)
			return n;
		vector<int> vec;
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		for (int i = 3; i <= n; i++)
			vec.push_back(vec[i - 1] + vec[i - 2]);
		return vec[n];
		*/
	}
};