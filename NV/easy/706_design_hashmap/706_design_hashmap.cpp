#include <iostream>
#include <unordered_map>
using namespace std;

class MyHashMap {
private:
    unordered_map<int, int> map;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        map[key] = value;    
    }
    
    int get(int key) {
        if (map.find(key) != map.end()){
            return map[key];
        } else {
            return -1;
        }
        
    }
    
    void remove(int key) {
        map.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    obj->put(2, 1);
    cout << obj->get(2) << endl;
    obj->remove(2);
    cout << obj->get(2) << endl;
    return 0;
}