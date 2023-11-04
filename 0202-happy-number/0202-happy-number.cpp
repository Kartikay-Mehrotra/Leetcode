class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;
        while(n!=1)
        {
            int ans=0;
            int current=n;
            while(current>0)
            {
                ans+=pow(current%10,2);
                current/=10;
            }
            if(mp.find(ans)!=mp.end())
                return false;
            mp[ans]++;
            n=ans;
        }
        return true;
    }
};