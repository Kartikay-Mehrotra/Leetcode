class Solution {
public:
    long long minimumCost(string s) {
        vector<long long>pre(s.size(),0),suf(s.size(),0);
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])pre[i]=pre[i-1];
            else pre[i]=i+pre[i-1];
          
        }
        
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]==s[i+1])suf[i]=suf[i+1];
            else suf[i]=s.size()-i-1+suf[i+1];
       
        }
       
        long long ans=1e18;
        for(int i=0;i<s.size();i++){
            if(i==0)ans=min(ans,suf[i]);
            else if(i==s.size()-1)ans=min(ans,pre[i]);
            else ans=min(ans,pre[i]+suf[i]);
        }
        return ans;
    }
};