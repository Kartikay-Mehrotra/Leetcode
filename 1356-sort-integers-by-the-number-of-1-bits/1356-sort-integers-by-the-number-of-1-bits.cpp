class Solution {
public:
    int count(int n){    
        int ans=0;   
        while(n>0){     
            n=n&(n-1);     
            ans++;           
        }   
        return ans;   
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> c;
        for(auto i:arr)
        {
            c.push_back({count(i),i});
        }
        sort(c.begin(),c.end());
        vector<int> ans;
        for(auto i:c)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};