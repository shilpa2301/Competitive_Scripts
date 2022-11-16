class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        
        
        spread=0
        
        people_who_spread=[(1+delay,1)]
        
        people_who_forget=[(1+forget,1)]
        
        
        for i in range(2,n+1):
            
            if people_who_spread[0][0]==i:
                _,people=people_who_spread.pop(0)
                
                spread+=people
            if people_who_forget[0][0]==i:
                _,people=people_who_forget.pop(0)
                
                spread-=people
                
            people_who_spread.append((i+delay,spread))
            people_who_forget.append((i+forget,spread))
            
        
        for _,i in people_who_spread:
            spread+=i
        
        spread%=(10**9+7)
        return spread
        