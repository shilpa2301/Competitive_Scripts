/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool is_celebrity(int celebrity, int n)
    {
        int j;
        for(j=0; j<n; j++)
        {
            if(celebrity==j)
            {
                
            }
            else if(knows(celebrity,j) || (!knows(j,celebrity)))
            {
                cout<<"false_candidate= "<<celebrity<<endl;
                return false;
            }
        }
        return true;
    }
    
    int findCelebrity(int n) {
        int celebrity_candidate=0;
        int i;
        for(i=1; i<n; i++)
        {
            if(knows(celebrity_candidate,i))
                celebrity_candidate=i;
        }
        
        if(is_celebrity(celebrity_candidate,n))
        {
            return celebrity_candidate;
        }
        else
            return -1;
    }
};