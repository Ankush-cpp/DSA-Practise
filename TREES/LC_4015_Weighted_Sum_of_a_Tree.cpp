
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> depth(n, 0);
        queue<int> q;

        q.push(0);
        depth[0] = 1;

        int h = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                depth[child] = depth[node] + 1;
                h = max(h, depth[child]);
                q.push(child);
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long weight = 1LL * nums[i] * (h - depth[i] + 1);
            ans += weight;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> parent = {-1, 0, 0, 1, 1};
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << sol.weightedSum(parent, nums) << endl;

    return 0;
}
