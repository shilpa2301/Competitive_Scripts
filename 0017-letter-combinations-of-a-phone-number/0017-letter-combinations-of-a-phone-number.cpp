class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string table[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.length();
        vector<string> result;
        if (digits.length()==0)
            return result;
        queue<string> q;
        q.push("");
        string s;

        while(!q.empty())
        {
            s=q.front();
            q.pop();
            
            if (s.length()==n)
            {
                result.push_back(s);
            }
            else
            {
                for(auto i: table[digits[s.length()]-'0'])
                {
                    q.push(s+i);
                }
            }
        }
        return result;
        
    }
};