class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
     if(sx==fx && sy==fy)
     {
         if(t==1)
             return false;
         return true;
     }
        int n=max((abs(sx-fx)),abs(sy-fy));
        if(n<=t)
            return true;
        
        return false;
    }
};