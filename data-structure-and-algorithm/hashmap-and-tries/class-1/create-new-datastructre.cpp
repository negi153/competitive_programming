
home work - create a datastructure which does insertion,deletion,searching,get random in o(1)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>  // for rand()
#include <ctime>    // for srand()

using namespace std;

class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> indexMap;  // value -> index in vector

public:
    RandomizedSet() {
        srand(time(0));  // seed for random
    }

    // Insert x into the set
    bool insert(int x) {
        if (indexMap.count(x)) return false;  // already exists

        data.push_back(x);
        indexMap[x] = data.size() - 1;
        return true;
    }

    // Delete x from the set
    bool remove(int x) {
        if (!indexMap.count(x)) return false;

        int idx = indexMap[x];
        int lastElement = data.back();

        // Move last element to idx
        data[idx] = lastElement;
        indexMap[lastElement] = idx;

        // Remove last element
        data.pop_back();
        indexMap.erase(x);

        return true;
    }

    // Search x in the set
    bool search(int x) {
        return indexMap.count(x) > 0;
    }

    // Get a random element
    int getRandom() {
        if (data.empty()) throw runtime_error("Set is empty");
        int randomIndex = rand() % data.size();
        return data[randomIndex];
    }
};


int main() {
    RandomizedSet rs;

    rs.insert(10);
    rs.insert(20);
    rs.insert(30);
    rs.insert(40);

    cout << rs.getRandom() << endl;
    rs.remove(20);
    cout << rs.search(20) << endl;  // 0 (false)
    cout << rs.search(10) << endl;  // 1 (true)

    cout << rs.getRandom() << endl;

    return 0;
}
