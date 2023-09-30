class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string temp="";
        for(auto i:s)
        {
            if(i=='(' && c==0)
                c=1;
            else if(i=='(')
            {
                temp+=i;
                c++;
            }
            else if(i==')' && c>1)
            {
                temp+=i;
                c--;
            }
            else if(i==')' && c==1)
            {
                c--;
            }
        }
        return temp;
    }
};