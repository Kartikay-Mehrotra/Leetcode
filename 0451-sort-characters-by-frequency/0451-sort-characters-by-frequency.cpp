class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int> mp;
        for(auto i:s)
            mp[i]++;
        priority_queue<pair<int,char>> pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        string temp="";
        while(pq.size())
        {
            int t=temp.size();
            temp.insert(t,pq.top().first,pq.top().second);
            pq.pop();
        }
        return temp;
        
        
    }
};