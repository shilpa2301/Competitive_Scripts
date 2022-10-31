class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1, index2;
        vector<int> ret;
        
        vector<int> temp;
        temp=nums;
        
        unordered_multimap<int,int> hash_table;
        int i;// x=0;
        for(i=0; i< temp.size(); i++)
        {
            hash_table.insert( pair<int, int>(temp[i],i));
        }
        
        int data1, data2, flag=0;
       // unordered_map<int,int>::iterator it;
        for(i=0; i<temp.size(); i++)
        {
            if (flag==1)
                break;
            if (flag==0){
                data1=temp[i];
                index1=i;
                data2=target-data1;
                //hash_table hf;
               // unordered_multimap<int, int>::hasher fn = hash_table.hash_function();
               // hash_table.erase(hash_table.begin()+i);
                // unordered_multimap<int, int>::iterator it;
                // it=hash_table.find(data2);
                if(hash_table.find(data2)!=hash_table.end() && hash_table.find(data2)->second !=i)
                {
                    // cout << "Inside: " <<it->second<<endl;
                   
                        flag=1;
                        break;
                    
                }
              //  if(hash_table.find(data2)!=hash_table.end() )
               //{
                //    flag=1;
                //    break;
                //}
             //   if(flag==0)
             //   {
                  //  hash_table[data1]=i;
              //      hash_table.insert( pair<int, int>(data1,i));
              //  }
                
            }
        }
            
            if (flag==1){
             for(i=index1+1; i<temp.size(); i++)
                {
                    if (temp[i]==data2)
                    {
                        index2=i;
                        break;
                    }
                 }
            }
            else
                return ret;
          /*  if (index2<index1)
            {
                int swap_var=index1;
                index1=index2;
                index2=swap_var;
            }*/
            ret.push_back(index1);
            ret.push_back(index2);
            return ret;
            
                
      //  }
    //
    }
};