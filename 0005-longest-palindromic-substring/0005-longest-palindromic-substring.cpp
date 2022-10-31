class Solution {
public:
    string longestPalindrome(string s) {
         int n=s.length();
        int start=0, max_length=0;
        bool table[n][n];
        memset(table, 0, sizeof(table));
        
        int i;
        for (i=0; i<n; i++)
        {
            table[i][i]=true;
        }
        max_length=1;
       // int start=0;
        
        for(i=0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                table[i][i+1]=true;
                max_length=2;
                start=i;
            }
        }
        int j, k;
        for(k=3; k<=n; k++)
        {
            for(i=0; i<n-k+1; i++)
            {
                j=i+k-1;
                if (table[i+1][j-1] && s[i]==s[j])
                {
                    table[i][j]=true;
                    start=i; max_length=k;
                }
            }
        }
        
        string ret_str;
        ret_str.assign(s, start, max_length);
        return ret_str;
        
    }
};