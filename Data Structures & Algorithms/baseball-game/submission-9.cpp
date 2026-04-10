class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> scores;
        for(int i = 0; i < (int)operations.size(); i++){
            if(operations[i] == "+")
            {
                int top = scores.top(); 
                scores.pop();
                int prevTop = scores.top();
                scores.push(top);
                int sum  = top + prevTop;
                scores.push(sum);
            } 
            else if (operations[i] == "D")
            {
                int doubleTop = scores.top() * 2;
                scores.push(doubleTop);
            }
            else if(operations[i] == "C")
            {
                scores.pop();
            }
            else 
            {
                scores.push(stoi(operations[i]));
            }
        }
        int result = 0;
        while(!scores.empty()){
            result += scores.top();
            scores.pop();
        }
        return result;
    }
};