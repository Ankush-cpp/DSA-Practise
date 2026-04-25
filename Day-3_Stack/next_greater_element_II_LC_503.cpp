#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; // stores indices

    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            ans[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,1};
    vector<int> res = nextGreaterElements(nums);

    for (int x : res) cout << x << " ";
    return 0;
}