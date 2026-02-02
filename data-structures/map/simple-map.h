#pragma once

#include <vector>
#include <list>
#include <utility>
#include <stdexcept>

class SimpleMap {
private:
    static const int BUCKET_COUNT = 101;
    std::vector<std::list<std::pair<int, int>>> buckets;

    int hash(int key) const {
        return key % BUCKET_COUNT;
    }

public:
    SimpleMap() : buckets(BUCKET_COUNT) {}

    void put(int key, int value) {
        int index = hash(key);
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        buckets[index].push_back({key, value});
    }

    int get(int key) const {
        int index = hash(key);
        for (const auto& kv : buckets[index]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        throw std::out_of_range("Key not found");
    }

    bool contains(int key) const {
        int index = hash(key);
        for (const auto& kv : buckets[index]) {
            if (kv.first == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
