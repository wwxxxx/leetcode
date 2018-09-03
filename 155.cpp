#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class MinStack
{
  public:
    /** initialize your data structure here. */
    MinStack() : stk(), minStk() {}

    void push(int x)
    {
        stk.push(x);
        if (minStk.empty() || x <= getMin())
            minStk.push(x);
    }

    void pop()
    {
        if (stk.top() == getMin())
            minStk.pop();
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return minStk.top();
    }

  private:
    stack<int> stk;
    stack<int> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */