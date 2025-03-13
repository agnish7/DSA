class LRUCache {
    int cap;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;
    std::list<std::pair<int, int>> cacheList;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto mapIt = cacheMap.find(key);
        if (mapIt == cacheMap.end()) {
            return -1;
        } else {
            auto listIt = mapIt->second; // Get the list iterator from the map
            int value = listIt->second;  // Extract the value from the pair
            cacheList.splice(cacheList.begin(), cacheList, listIt); // Move to front
            return value;
        }
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            // If cache is full, evict the least recently used item
            if (cacheList.size() == cap) {
                int lruKey = cacheList.back().first; // Get key of LRU item
                cacheMap.erase(lruKey);              // Remove from map
                cacheList.pop_back();                // Remove from list
            }
            // Insert new key-value pair
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        } else {
            // Update existing key
            auto listIt = it->second;         // Get the list iterator
            listIt->second = value;           // Update the value
            cacheList.splice(cacheList.begin(), cacheList, listIt); // Move to front
        }
    }
};
