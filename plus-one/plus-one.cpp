class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int>output;
        int carry = 1;
        int n = digits.size();
        
        
        for(int i=n-1;i>=0;i--){
            
            int sum = digits[i]+carry;
            if(sum<=9){
                carry = 0;
                output.push_back(sum);
            }else{
                carry = 1;
                output.push_back(0);
            }
        }
        
        if(carry) output.push_back(carry);
        reverse(output.begin(),output.end());
        return output;
    }
};