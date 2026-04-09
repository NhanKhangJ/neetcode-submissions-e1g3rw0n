class MinStack {
public:
    vector<int> stack;
    vector<int> minMaxStack;
    MinStack() {
        this->stack = vector<int>();
        this->minMaxStack = vector<int>();
    }
    
    void push(int val) {
        this->stack.push_back(val); 
        if(minMaxStack.empty()) {
            minMaxStack.push_back(val);
        } else {
            int currentMin = minMaxStack.back();
            minMaxStack.push_back(val < currentMin ? val : currentMin);
        }
    }
    
    void pop() {
        if(!stack.empty()){
            stack.pop_back();
            minMaxStack.pop_back();
        }
    }
    
    int top() {
       return this->stack.back();
    }
    
    int getMin() {
        return this->minMaxStack.back();
    }
};
