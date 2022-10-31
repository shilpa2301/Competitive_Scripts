class Solution {
    public String intToRoman(int num) {
        String [] rVal = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int [] iVal = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int index = 0;
        StringBuilder b = new StringBuilder();

        for(int i = 0;i< iVal.length && num > 0;i++){
            while(num >= iVal[i]){
                num-= iVal[i];
                b.append(rVal[i]);
            }
           
        }

        return b.toString();
    }
}