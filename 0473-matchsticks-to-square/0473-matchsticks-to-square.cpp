class Solution {
public:
    int solve(vector<int>& matchsticks,int sum,int i,vector<int> &v)
    {
        if(i==matchsticks.size())
        {
            if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3] )
            return true;

            return false;
        }

        for(int k=0;k<4;k++)
        {
            if(v[k]+matchsticks[i]>sum)
            continue;

            v[k]+=matchsticks[i];
           if( solve(matchsticks,sum,i+1,v))
           return true;
            v[k]-=matchsticks[i];

        }

        return false;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        int sum=0;
        for(auto i:matchsticks)
        sum+=i;
        if(sum%4)
        return false;
        sum/=4;
    vector<int> sides(4);
       return solve(matchsticks,sum,0,sides);
    }
};