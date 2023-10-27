class Solution {
public:
    int solve(int i,int j,string &s,int &maxi,int 
              &ind)
    {
        int n=s.size();
            int left=i;
            int right=j;
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
        return 0;
    }
    string longestPalindrome(string s) {
        int last=0;
        int maxi=0;
        for(int i=0;i<s.size();i++)
        {
            int  p=solve(i,i,s,maxi,last);
          p=solve(i,i+1,s,maxi,last);
        }
        return s.substr(last,maxi);
    }
};