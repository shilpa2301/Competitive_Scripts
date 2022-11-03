class Solution {
public:
    int countHousePlacements(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 4;
        long long array[n+1];
        array[0]=1;
        array[1]=2;
        long long i;
        for(i=2; i<=n; i++)
        {
            if(i<=1)
                array[i-2]=1;
            array[i]=(array[i-1]+array[i-2]) % 1000000007;
        }
        return (array[n]*array[n])%1000000007;
    }
};