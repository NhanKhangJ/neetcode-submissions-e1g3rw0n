class Solution {
public:
    bool isValid(string s) {
        if((int)s.length() % 2 != 0) return false;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        if(s[s.length()-1] == '(' || s[s.length()-1] == '[' || s[s.length()-1] == '{') return false;
        stack<char> oprt;

        for(int i = 0; i < (int)s.length(); i++){
            if(s[i] == '(') oprt.push('(');
            if(s[i] == '[') oprt.push('[');
            if(s[i] == '{') oprt.push('{');
            if(s[i] == ')'){
                if(!oprt.empty() && oprt.top() == '(') oprt.pop();
                else return false;
            }
            if(s[i] == ']'){
                if(!oprt.empty() && oprt.top() == '[') oprt.pop();
                else return false;
            }
            if(s[i] == '}'){
                if(!oprt.empty() && oprt.top() == '{') oprt.pop();
                else return false;
            }
        }
        return oprt.size() == 0;
    }
};