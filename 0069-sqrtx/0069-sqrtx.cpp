class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        while(low<=high)
        {
            long long mid=low+(-low+high)/2;
            long long val=mid*mid;
            if(val<=x)
                low=mid+1;
            else
                high=mid-1;
        }
        return low-1;
    }
};