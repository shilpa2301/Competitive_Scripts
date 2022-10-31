class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     vector<string> temp1, temp2;
        temp1=strs;
        temp2=strs;
        
        string word;
        unordered_map<string, int> hash_t;
        int x=0;
        unordered_multimap<string, int>::iterator it;
        int i;
        for(i=0; i<temp1.size(); i++)
        {
            word.assign(temp1[i]);
            sort(word.begin(), word.end());
            temp1[i].assign(word);
            it=hash_t.find(word);
            if(it==hash_t.end())
            {
                hash_t.insert(pair<string, int> (word, x++));
            }
        }
        vector<vector<string>> ret;
        string backup;
        vector<string> individual[x];
        for(i=0; i<temp2.size(); i++)
        {
            backup.assign(temp2[i]);
            sort(temp2[i].begin(), temp2[i].end());
            it=hash_t.find(temp2[i]);
            
            if(it!=hash_t.end())
            {
                cout<<it->second<<" "<<backup<<endl;
                individual[it->second].push_back(backup);
                //cout<<
               // ret[it->second].insert();
            }
        }
        for(int j=0; j<x; j++)
        {
            ret.push_back(individual[j]);
        }
        
        return ret;
    }
};