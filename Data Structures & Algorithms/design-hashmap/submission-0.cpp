class MyHashMap {
    vector<vector<pair<int, int>>> buckets;  
    int size = 10007;  

public:
    MyHashMap() {
        buckets.resize(size);
    }

    void put(int key, int value) {
        int idx = key % size;
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = value;  
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = key % size;
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;  
    }

    void remove(int key) {
        int idx = key % size;
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};