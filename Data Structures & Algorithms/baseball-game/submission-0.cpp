#include <stack>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int result = 0;
        for(int i = 0; i < (int)operations.size(); i++){
            if(operations[i] == "+"){
                int top1 = scores.top(); 
                scores.pop();
                int top2 = scores.top(); 
                scores.pop();
                scores.push(top2);
                scores.push(top1);
                scores.push(top1 + top2);
            } else if(operations[i] == "D"){
                scores.push(scores.top() * 2);
            } else if(operations[i] == "C"){
                scores.pop();
            } else {
                scores.push(stoi(operations[i]));
            }
        }
        while(!scores.empty()){
            result += scores.top();
            scores.pop();
        }
        return result;
    }
};