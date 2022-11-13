class Solution {
public:
    void swap(int &a, int &b)
    {
        int t;
        t=a;
        a=b;
        b=t;
    }
    int quick_select(vector<int>& nums,int k, int l, int r)
    {
        int pivot=nums[r];
        int p=l;
        int i;
        for(i=l; i<=r-1; i++)
        {
            if(nums[i]<=pivot)
            {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[r]);
        int ret;
         if(p==k)
             return nums[p];
        else if(k<p)
            ret=quick_select(nums, k, l, p-1);
        else if(k>p)
            ret=quick_select(nums,k, p+1, r);
        return ret;
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        
        int ret;
        ret=quick_select(nums,k, 0, nums.size()-1);
        return ret;
    }
};