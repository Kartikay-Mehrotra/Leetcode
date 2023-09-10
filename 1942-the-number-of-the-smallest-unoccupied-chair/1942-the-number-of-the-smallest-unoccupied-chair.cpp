class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int t_arrival=times[targetFriend][0];
        sort(times.begin(),times.end());
        int n=times.size();
        priority_queue<int,vector<int>,greater<int>> chairs;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> inuse;
        
        for(int i=0;i<n;i++)
        {
            chairs.push(i);
        }
        
        for(auto t:times)
        {
            int arr=t[0],dep=t[1];
            while(inuse.size() && inuse.top().first<=arr)
            {
                chairs.push(inuse.top().second);
                inuse.pop();
            }
            int ch=chairs.top();
            chairs.pop();
            inuse.push({dep,ch});
            
            if(arr==t_arrival)
                return ch;
        }
        return -1;
        
    }
};