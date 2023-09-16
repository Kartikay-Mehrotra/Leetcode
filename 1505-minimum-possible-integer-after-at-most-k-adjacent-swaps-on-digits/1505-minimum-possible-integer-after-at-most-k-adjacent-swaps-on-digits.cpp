class Solution {
public:
    string minInteger(string num, int k) {
        int n=num.size();
        if(k>n*(n+1)/2)
        {
            sort(num.begin(),num.end());
            return num;
        }
        
        for(int i=0;i<n-1 && k>0;i++)
        {
            int j;
            int pos=i;
            for(j=i+1;j<n;j++)
            {
                if(j-i >k)
                    break;
                 if(num[j]<num[pos])
                     pos=j;
            }
            for(j=pos;j>i;j--)
            {
                char t=num[j];
                num[j]=num[j-1];
                num[j-1]=t;
            }
            k-=pos-i;
        }
        return num;
    }
};