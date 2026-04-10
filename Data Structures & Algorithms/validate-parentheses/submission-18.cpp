class Solution {
public:
    bool isValid(string s) {
        // if((int)s.length() % 2 != 0) return false;
        // if(s[0] == '}' || s[0] == ')' || s[0] == ']') return false;
        // if(s[s.length()-1] == '{' || s[s.length()-1] == '(' || s[s.length()-1] == '[') return false;
        std::stack<char> openStackList;
        for(int i = 0; i < (int)s.length(); i++){
            if(s[i] == '(') openStackList.push(s[i]);
            else if(s[i] == ')'){
                if(!openStackList.empty() && openStackList.top() == '(') openStackList.pop();
                else return false;
            }
            if(s[i] == '{') openStackList.push(s[i]);
            else if(s[i] == '}'){
                if(!openStackList.empty() && openStackList.top() == '{') openStackList.pop();
                else return false;
            }
            if(s[i] == '[') openStackList.push(s[i]);
            else if(s[i] == ']'){
                if(!openStackList.empty() && openStackList.top() == '[') openStackList.pop();
                else return false;
            }
        }
        return openStackList.empty();
    }
};