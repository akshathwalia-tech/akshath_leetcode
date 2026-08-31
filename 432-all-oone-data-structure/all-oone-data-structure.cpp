#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class AllOne {
private:
    struct Bucket {
        int count;
        unordered_set<string> keys;
    };

    list<Bucket> bucketList; // Doubly linked list of buckets
    unordered_map<string, list<Bucket>::iterator> keyToBucket;

public:
    AllOne() {}

    void inc(string key) {
        if (keyToBucket.find(key) == keyToBucket.end()) {
            // Case 1: Key does not exist
            if (bucketList.empty() || bucketList.front().count > 1) {
                bucketList.push_front({1, {key}});
            } else {
                bucketList.front().keys.insert(key);
            }
            keyToBucket[key] = bucketList.begin();
        } else {
            // Case 2: Key exists, increment its count
            auto curBucket = keyToBucket[key];
            auto nextBucket = next(curBucket);
            int newCount = curBucket->count + 1;

            if (nextBucket == bucketList.end() || nextBucket->count > newCount) {
                nextBucket = bucketList.insert(nextBucket, {newCount, {}});
            }

            nextBucket->keys.insert(key);
            keyToBucket[key] = nextBucket;

            // Remove key from the old bucket
            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) {
                bucketList.erase(curBucket);
            }
        }
    }

    void dec(string key) {
        auto curBucket = keyToBucket[key];
        int newCount = curBucket->count - 1;

        if (newCount == 0) {
            // Key removed completely
            keyToBucket.erase(key);
        } else {
            // Move key to the previous bucket (count - 1)
            auto prevBucket = prev(curBucket);
            if (curBucket == bucketList.begin() || prevBucket->count < newCount) {
                prevBucket = bucketList.insert(curBucket, {newCount, {}});
            }
            prevBucket->keys.insert(key);
            keyToBucket[key] = prevBucket;
        }

        // Remove key from current bucket
        curBucket->keys.erase(key);
        if (curBucket->keys.empty()) {
            bucketList.erase(curBucket);
        }
    }

    string getMaxKey() {
        if (bucketList.empty()) return "";
        return *(bucketList.back().keys.begin());
    }

    string getMinKey() {
        if (bucketList.empty()) return "";
        return *(bucketList.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */