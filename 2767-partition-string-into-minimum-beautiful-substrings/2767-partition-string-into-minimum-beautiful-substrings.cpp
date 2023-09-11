class Solution 
{
public:
    bool powerOf5(string s)
    {
        if(s[0]=='0') return false;
        if(s=="1") return true;
        int i=0, num=0;
        for(int x=s.size()-1; x>=0; x--)
        {
            num+=(s[x]-'0')*pow(2,i);
            i++;
        }
        while(num>1)
        {
            if(num%5) return false;
            num/=5;
        }
        return num==1;
    }
    int f(int st, int en, string s)
    {
        if(st>en) return 0;
        string str="";
        int ans=INT_MAX;
        int flag=0;
        for(int x=st; x<=en; x++)
        {
            str+=s[x];
            if(powerOf5(str))
            {
                ans=min(ans,1+f(x+1,en,s));
                flag=1;
            }
        }
        if(!flag) return 10000;
        return ans;
    }
    int minimumBeautifulSubstrings(string s) 
    {
        int ans=f(0,s.size()-1,s);
        if(ans>s.size()) return -1;
        return ans;
    }
};