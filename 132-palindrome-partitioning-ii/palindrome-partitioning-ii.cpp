class Solution {
public:
    bool ispalindrome(const string&s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--; 
        }
        return true;
    }
    int mincuts(const string&s,int ind,vector<int> &dp){
        int n = (int)s.size();

        if(ind == n || ispalindrome(s,ind,n-1)){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int minicuts = INT_MAX;
        for(int end = ind ; end<n;end++){
            if(ispalindrome(s,ind,end)){
                int cuts = 1 + mincuts(s,end+1,dp);
                minicuts = min(minicuts,cuts);
            }
        }
        return dp[ind] = minicuts;
    }
    int minCut(string s) {
     int n = (int)s.size();
        vector<int> dp(n,-1);
        return mincuts(s,0,dp);
    }
};