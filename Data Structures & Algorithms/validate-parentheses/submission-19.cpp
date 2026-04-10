class Solution {
public:
    bool isValid(string s) {
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