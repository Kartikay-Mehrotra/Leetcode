class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' or s[i]=='[' or s[i]=='{')
            {
                check.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(check.empty()) return false;
                else if(check.top()=='(') check.pop();
                else return false;
            }
            else if(s[i]==']')
            {
                if(check.empty()) return false;
                else if(check.top()=='[') check.pop();
                else return false;
            }
            else if(s[i]=='}')
            {
                if(check.empty()) return false;
                else if(check.top()=='{') check.pop();
                else return false;
            }
        }
        if(check.empty()) return true;
        else return false;
    }
};