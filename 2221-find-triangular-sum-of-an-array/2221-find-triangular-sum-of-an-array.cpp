class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int> newNums(n-1);
        int i;
        for(i=0; i<n-1; i++)
        {
            newNums[i]=(nums[i] + nums[i+1])%10;
        }
        nums.clear();
        nums.resize(n-1);
        nums=newNums;
        return triangularSum(nums);
        
    }
};