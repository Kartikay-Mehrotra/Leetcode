class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(auto i:arr)
            m[i]++;
        priority_queue<pair<int,int>> pq;
        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }
        if(m.size()==arr.size())
            return arr.size()/2;
        int ans=0;
        int n=arr.size()/2;
        while(pq.size() && n>0)
        {
                n-=pq.top().first;
                ans++;
                pq.pop();
        }
        return ans;
        
    }
};