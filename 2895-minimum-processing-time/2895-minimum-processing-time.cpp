class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end());
        for(auto i:tasks)
            cout<<i<<' ';
        int j=0;
        int ans=0;
        for(int i=0;i<processorTime.size();i++)
        {
            
            int t=max({tasks[j],tasks[j+1],tasks[j+2],tasks[j+3]});
            ans=max(ans,(t+processorTime[i]));
            j+=4;
        }
        return ans;
    }
};