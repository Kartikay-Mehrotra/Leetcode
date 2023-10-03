class Solution {
public:
    int lastRemaining(int n) {
        bool left=1;
        int rem=n;
        int head=1;
        int step=1;
        while(rem>1)
        {
            if(left|| rem&1)
            head=head+step;
            step*=2;
            rem/=2;
            left=!left;

        }
        return head;
    }
};