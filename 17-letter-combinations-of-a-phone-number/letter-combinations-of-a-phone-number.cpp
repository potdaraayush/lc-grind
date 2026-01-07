class Solution {
public:
    void solve(int idx, string digits, string& curr, vector<string>& res, unordered_map<char, string>& mpp) {
        if(idx == digits.size()) {
            res.push_back(curr);
            return;
        }

        string l = mpp[digits[idx]];

        for(char c: l) {
            curr.push_back(c);
            solve(idx+1, digits, curr, res, mpp);
            curr.pop_back();
        }
    } 
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        unordered_map<char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        vector<string> res;
        string curr;
        
        solve(0, digits, curr, res, mpp);
        return res;
    }
};