class Solution {
public:
    int minimumKeypresses(string s) {
        int i;
        vector<int> alpha_freq(26, 0);
        for(i=0; i<s.size(); i++)
        {
            alpha_freq[s[i]-'a']++;
        }
        sort(alpha_freq.begin(), alpha_freq.end(), greater<int>());
        
        int ret=0;
        //int x=1;
        for(i=0; i<alpha_freq.size(); i++)
        {
            if(i<9)
            {
                ret+=alpha_freq[i];
            }
            else if(i<18)
            {
                ret+=2*alpha_freq[i];
            }
            else
            {
                ret+=3*alpha_freq[i];
            }
        }
        return ret;
    }
};