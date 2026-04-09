class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> scores;
        int result = 0;
        for(auto const& op : operations){
            if(op == "+"){
                int top1 = scores.top(); scores.pop();
                int top2 = scores.top(); scores.pop();
                int sum = top1 + top2;
                scores.push(top2);
                scores.push(top1);
                scores.push(sum);
                result += sum;
            } else if(op == "D"){
                int doubled = scores.top() * 2;
                scores.push(doubled);
                result += doubled;
            } else if(op == "C"){
                result -= scores.top();
                scores.pop();
            } else {
                int val = std::stoi(op);
                scores.push(val);
                result += val;
            }
        }
        return result;
    }
};