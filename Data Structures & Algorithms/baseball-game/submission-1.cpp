#include <stack>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int result = 0;
        for(int i = 0; i < (int)operations.size(); i++){
            if(operations[i] == "+"){
                int top1 = scores.top(); scores.pop();
                int top2 = scores.top(); scores.pop();
                int sum = top1 + top2;
                scores.push(top2);
                scores.push(top1);
                scores.push(sum);
                result += sum;
            } else if(operations[i] == "D"){
                int doubled = scores.top() * 2;
                scores.push(doubled);
                result += doubled;
            } else if(operations[i] == "C"){
                result -= scores.top();
                scores.pop();
            } else {
                int val = stoi(operations[i]);
                scores.push(val);
                result += val;
            }
        }
        return result;
    }
};