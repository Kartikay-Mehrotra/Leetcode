class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long sum=0;
        for(auto i:nums)
            pq.push(i);
        
        while(k-- && pq.size())
        {
            cout<<pq.top()<<" ";
            sum+=pq.top();
            pq.push(ceil(pq.top()/3.0));
            pq.pop();
        }
     //  cout<<ceil(10/3)+1;
        return sum;
    }
};