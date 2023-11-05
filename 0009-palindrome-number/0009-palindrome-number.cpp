class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        long long rev=0;
        while(num>0)
        {
            if(rev<INT_MIN || rev>INT_MAX)
                return false;
            rev=rev*10+num%10;
            num/=10;
        }
        return rev==x;
    }
};