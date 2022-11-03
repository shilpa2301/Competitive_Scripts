class Solution {
public:
    int max(int a, int b)
    {
        return (a>=b)?a:b;
    }
        int rob(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        int result[n+1];
        result[n]=0;
        result[n-1]=nums[n-1];
      //  result[1]=nums[0];
        int i,k;
        for(i=n-2; i>=0; i--)
        {
            
            result[i]=max((result[i+1]),(nums[i]+result[i+2]));
        }
            return result[0];
    }
};