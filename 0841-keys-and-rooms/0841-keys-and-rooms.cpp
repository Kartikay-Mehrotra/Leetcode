class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(q.size())
        {
            int room=q.front();
            q.pop();
            for(auto i:rooms[room])
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++)
            if(vis[i]!=1)
                return false;
        
        return true;
        
    }
};