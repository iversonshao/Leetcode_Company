#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    list<pair<int,int>> d_list; //c++ linked list STL
    unordered_map<int, list<pair<int,int>>::iterator> cache; //hash table STL use unordered_map
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
		d_list.clear();
		cache.clear();        
    }
    
    int get(int key) {
        auto itr = cache.find(key);
        if (itr == cache.end()){
            return -1;
        }
        d_list.splice(d_list.begin(), d_list, itr->second);
        cache[key] = d_list.begin();

        return cache[key] -> second;
    }
    
    void put(int key, int value) {
        auto itr = cache.find(key);
        if (itr != cache.end()){
            itr->second->second = value;

            d_list.splice(d_list.begin(), d_list, itr->second);
        }else{
            if(d_list.size() == cap){
                cache.erase(d_list.back().first);
                d_list.pop_back();
                d_list.push_front(pair<int,int>(key, value));
            }else{
                d_list.push_front(pair<int,int>(key,value));
            }

        } 
        cache[key] = d_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl; // 1,2
    obj->put(3,3); //1,3
    cout << obj->get(2) << endl; //-1
    obj->put(4,4); //4,3
    cout << obj->get(1) << endl;//-1
    cout << obj->get(3) << endl; //3
    cout << obj->get(4) << endl; //4
    return 0;
}