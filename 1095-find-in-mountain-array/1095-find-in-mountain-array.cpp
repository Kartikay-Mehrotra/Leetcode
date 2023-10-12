/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(MountainArray &mountainArr)
    {
        int low=0;
        int high=mountainArr.length()-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
    int searchL(MountainArray &mountainArr,int l,int r,int target)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    int searchR(MountainArray &mountainArr,int l,int r,int target)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=findpeak(mountainArr);
        int left=searchL(mountainArr,0,peak,target);
        if(left!=-1)
            return left;
        if(mountainArr.get(peak)==target)
            return peak;
        int right=searchR(mountainArr,peak,mountainArr.length()-1,target);
        if(right!=-1)
            return right;
        
        return -1;
        return peak;
    }
};