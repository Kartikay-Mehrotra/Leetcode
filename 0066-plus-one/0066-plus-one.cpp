class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int j=digits.size()-1;
        int carry=1;
        while(j>=0 )
        {
            int sum=carry;
            sum+=digits[j];
            digits[j]=sum%10;
            carry=sum/10;
            j--;
        }
        if(carry)
        {
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};