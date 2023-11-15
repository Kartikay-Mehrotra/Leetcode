class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans=0;
        sort(arr.begin(),arr.end());
        int prev=-1;
       if(arr[0]!=1)
       {
           arr[0]=1;
        }
        prev=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-prev <=1)
            {
                prev=arr[i];
                continue;
            }
            else
            {
                arr[i]=prev+1;
                prev++;
            }
        }
        return *max_element(arr.begin(),arr.end());
    }
};