class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        if(seats[0]==0){
            left[0]=-1;
        }
        else{
            left[0]=0;
        }
        for(int i=1;i<n;i++){
            if(seats[i]==0){
                left[i]=left[i-1];
            }
            else{
                left[i]=i;
            }
        }
        if(seats[n-1]==0){
            right[n-1]=-1;
        }
        else{
            right[n-1]=n-1;
        }
        for(int i=n-2;i>=0;i--){
            if(seats[i]==0){
                right[i]=right[i+1];
            }
            else{
                right[i]=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0 && left[i]!=-1 && right[i]!=-1){
                ans=max(ans,min(abs(i-left[i]),abs(i-right[i])));
            }
            else if(left[i]!=-1){
                ans=max(ans,abs(i-left[i]));
            }
            else if(right[i]!=-1){
                ans=max(ans,abs(i-right[i]));
            }
        }
    return ans;
        
    }
};