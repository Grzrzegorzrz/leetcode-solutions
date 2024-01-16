#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
unordered_map<int, int> m;
vector<int> vect;
int size;
int randNum;
int temp;
    RandomizedSet() {
        size = 0;
        m.reserve(100000);
        vect.reserve(100000);
    }
    
    bool insert(int val) {
        if(!m[val]) {
            size++;
            vect.push_back(val);
            m[val] = size;

            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if(m[val]) {
            temp = vect.back();
            size--;
            m[temp] = m[val];
            vect.back() = val;
            vect.pop_back();
            vect[m[val]-1] = temp;
            m[val] = 0;

            return true;
        }

        return false;
    }
    
    int getRandom() {
        randNum = rand() % size;
        return vect[randNum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
