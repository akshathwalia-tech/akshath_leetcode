class Solution {
public:
    bool sumequaltoindex(int number , int i){
        int n = 0;
        while(number>0){
            n+=number%10;
            number = number/10;
        }
        if(n==i){
            return true;
        }
        return false;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            if(sumequaltoindex(nums[i],i)){
                return i;
            }
        }
        return -1;
    }
};