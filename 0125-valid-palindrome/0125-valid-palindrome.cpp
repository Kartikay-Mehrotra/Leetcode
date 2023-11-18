class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i=0;
        int j=s.size()-1;
       string temp="";
        for(auto i:s)
        {
            if(i>='a' && i<='z' || i>='0' && i<='9')
                temp+=i;
        }
        j=temp.size()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};