//here we didnt use pop_back because the string digit is being passed by value instead of reference hence it creates a copy of the string in the new function  and when we baktrack the string s does no tcontaiain the value we passed to it in the recursive call. but we can also do that by using reference also.
class Solution {
private:
    void func(int ind, string digits, string s, vector<string> &ans, string combos[]) {
        if(ind == digits.size()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < combos[digit].size(); i++) {
            // s.push_back(combos[digit][i]);
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
            //s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; 
        string s = "";
        func(0, digits, s, ans, combos);
        return ans;
    }
};