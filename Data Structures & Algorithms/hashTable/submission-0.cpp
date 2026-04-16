class HashTable {
public:
    int size;
    int capacity;
    vector<vector<pair<int,int>>> map;
    // [
    //     [{key: value}],
    //     [{key: value}]
    // ]
    HashTable(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->map = vector<vector<pair<int,int>>>(capacity);
    }

    void insert(int key, int value) {
        int index = key % this->capacity;
        for(auto& p: map[index]){
            if(p.first == key) {
                p.second = value;
                return;
            }
        }
        map[index].push_back({key, value});
        this->size++;
        if((float)this->size / this->capacity >= 0.5) resize();
    }

    int get(int key) {
        int index = key % this->capacity;
        for(auto& p: map[index]){
            if(p.first == key) {
                return p.second;
            }
        }
        return -1;
    }

    bool remove(int key) {
        int index = key % this->capacity;
        for(int i = 0; i < (int)map[index].size(); i++){
            if(map[index][i].first == key) {
                map[index].erase(map[index].begin() + i);
                this->size--;
                return true;
            }
        }
        return false;
    }

    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }

    void resize() {
        this->capacity *= 2;
        vector<vector<pair<int,int>>> newMap(this->capacity);
        for(auto& bucket : this->map){
            for(auto& p : bucket){
                int newIndex = p.first % this->capacity;
                newMap[newIndex].push_back(p);
            }
        }
        this->map = newMap;
    }
};
