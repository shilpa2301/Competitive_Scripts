class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string input;
        input.assign(paragraph);
        for(int i=0; i<input.size(); i++)
        {
            if (!isalpha(input[i]))
                input[i]=' ';
            if(isupper(input[i]))
               input[i]=tolower(input[i]);
        }
        string word;
        stringstream inp(input);
        unordered_map<string, int> str_var;
        int flag;
        if(banned.size()>0){
        while(inp>>word )
               {
            flag=0;
            for(int j=0; j<banned.size(); j++)
            {
                if(word.compare(banned[j])==0)
                {
                    flag=1;
                }
            }
            if(flag==0){
                   unordered_map<string, int>::iterator it=str_var.find(word);
                   if(it!=str_var.end())
                   {
                       it->second++;
                   }
                   else
                   {
                       str_var.insert(make_pair(word,1));
                   }
            }
                
              // }
        }
        }
        else{
         while(inp>>word )
               {
            
                   unordered_map<string, int>::iterator it=str_var.find(word);
                   if(it!=str_var.end())
                   {
                       it->second++;
                   }
                   else
                   {
                       str_var.insert(make_pair(word,1));
                   }
            
        }
        }
       pair<string,int> max_val;
        max_val.first=" ";
        max_val.second=0;
        unordered_map<string,int>::iterator itr=str_var.begin();
        while(itr!=str_var.end())
               {
                   if(itr->second > max_val.second)
                   {
                       max_val.first=itr->first;
                       max_val.second=itr->second;
                   }
            itr++;
               }
               
        return max_val.first;
    }
};