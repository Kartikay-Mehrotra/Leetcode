class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s=0;
        for(int i=0;i<k;i++)
        {
            s+=cardPoints[i];
        }
        int maxsum=s;
        int n=cardPoints.size();
        for(int i=k-1;i>=0;i--)
        {
            s-=cardPoints[i];
            s+=cardPoints[n-k+i];
            maxsum=max(s,maxsum);
        }
        return maxsum;
    }
};