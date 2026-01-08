class Solution {
public:
    void helper(int idx, int k, int n, int cnt, vector<int>& currComb, vector<vector<int>>& ans, int currSum) {
        if(currSum > n || cnt > k) return;

        if(currSum == n && cnt == k) {
            ans.push_back(currComb);
            return;
        }

        for(int i=idx; i<9; i++) {
            currComb.push_back(i+1);
            helper(i+1, k, n, cnt+1, currComb, ans, currSum+i+1);
            currComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currComb;

        helper(0, k, n, 0, currComb, ans, 0);
        return ans;
    }
};