class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=-1;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            int left=i;
            int right=i;
            while(left>=0 && right<n && s[left]==s[right])
            {
                if(right-left+1 >maxi)
                {
                    maxi=max(maxi,right-left+1);
                    ind=left;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right])
            {
                if(right-left+1 > maxi)
                {
                    maxi=max(maxi,right-left+1);
                    ind=left;
                }
                left--;
                right++;
            }
        }
        return s.substr(ind,maxi);
    }
};