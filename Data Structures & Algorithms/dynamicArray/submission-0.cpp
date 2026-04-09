class DynamicArray {
public:
    vector<int> arr;
    int size;
    int capacity;
    DynamicArray(int capacity) {
        if(capacity > 0) {
            this->arr = vector<int>(capacity, 0);
            this->size = 0;
            this->capacity = capacity;
        }
    }

    int get(int i) {
        if(i < this->size) {
            return this->arr[i];
        }
        return -1;
    }

    void set(int i, int n) {
        if(this->size > 0) {
           this->arr[i] = n;
        }
    }

    void pushback(int n) {
        // block first insert if vector size = 0;
        if(this->size >= 0) {
           if(this->size == this-> capacity) resize();
           this->arr[this->size] = n;
           // need to increase the size;
           this->size++;
        }
    }

    int popback() {
        if(this->size > 0) {
            // if(this->size == this->capacity) this->capacity--;
            int lastElement = this->arr[this->size - 1];
            vector<int> newArr = vector<int>(this->size - 1, 0);
            for(int i = 0; i < newArr.size(); i++){
                newArr[i] = this->arr[i];
            }
            this->size--;
            this->arr = newArr;
            return lastElement;
        }
        return -1;
    }

    void resize() {
        this->capacity = this->capacity * 2;
        vector<int> newArr = vector<int>(this->capacity, 0);
        for(int i = 0; i < this->size; i++){
            newArr[i] = this->arr[i];
        }
        this->arr = newArr;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};
