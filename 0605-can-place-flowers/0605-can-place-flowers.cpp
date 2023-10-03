class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       flowerbed.push_back(0);
       flowerbed.insert(flowerbed.begin(),0);
       for(int i=1;i<flowerbed.size()-1;i++)
       {
           int t=-1;
           //if(i+3<flowerbed.size())
           t=flowerbed[i-1]+flowerbed[i+1]+flowerbed[i];
           cout<<t;
           if(t==0)
           {
               n--;
               i++;
              
           }
          
       }
      return n<=0;
    }
};