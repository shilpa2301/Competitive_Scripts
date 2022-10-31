class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        vector<int> temp;
        
        temp=nums;
        sort(temp.begin(), temp.end());
        int sz=temp.size()-1;
        if(temp[0]!=0)
            return 0;
        if (temp[sz]==sz)
            return sz+1;
        int ret;
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i]!=i)
            {
                ret=i;
                break;
            }
        }
        return ret;
    }
};