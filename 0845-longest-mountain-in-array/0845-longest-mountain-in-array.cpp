class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int n=arr.size();
       vector<int> dp1(n,1),dp2(n,1);
       for(int i=1;i<n;i++){
           if(arr[i]>arr[i-1]) dp1[i]=dp1[i-1]+1;
       }
         for(int i=n-2;i>=0;i--){
           if(arr[i]>arr[i+1]) dp2[i]=dp2[i+1]+1;
       }
       int max_ct=0;
       for(int i=0;i<n;i++){
           if(dp1[i]!=1 && dp2[i]!=1){
               max_ct=max(max_ct,dp1[i]+dp2[i]-1);
           }
       }
       return max_ct;
    }
};