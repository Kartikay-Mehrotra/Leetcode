class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int maxi=0;
        int ans=0;
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>> pq;
        
        for(auto e:events)
        {
            while(pq.size() && -pq.top().first<e[0])
            {
                maxi=max(maxi,pq.top().second);
                pq.pop();
            }
            ans=max(ans,maxi+e[2]);
            pq.push({-e[1],e[2]});
        }
        return ans;
    }
};