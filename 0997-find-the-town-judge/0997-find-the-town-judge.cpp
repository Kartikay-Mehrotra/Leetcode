class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //the person with outdegree 0 is the town judge
        vector<int> outdegree(n+1,0);
        vector<int> indegree(n+1,0);

        for(auto edge:trust){
            outdegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        int ans=-1;
        for(int i=1;i<=n;i++){
            if(outdegree[i]==0 && indegree[i]==n-1)
            ans = i;
        }
        return ans;
    }
};