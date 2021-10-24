// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/
#include <bits/stdc++.h>;
using namespace std;

class MyHashMap
{
public:
    vector<list<pair<int, int>>> m;
    int size;
    MyHashMap()
    {
        size = 1000;
        m.resize(size);
    }

    int funcHash(int key)
    {
        return key % size;
    }

    list<pair<int, int>>::iterator search(int key)
    {
        int index = funcHash(key);
        list<pair<int, int>>::iterator it = m[index].begin();

        // searching for value by itertaing in the list using the iterator
        for (; it != m[index].end(); it++)
        {   
            // return the corresponding value to the key 
            if (it->first == key)
                return it;
        }
        return it;
    }

    void put(int key, int value)
    {
        int index = funcHash(key);
        remove(key);
        // putting the {key,value} pair at index from hash function in the list. 
        m[index].push_back({key, value});
    }

    int get(int key)
    {
        int index = funcHash(key);
        list<pair<int, int>>::iterator it = search(key);

        // if iterator points to end of list that means that key dosen't exist , return -1  
        if (it == m[index].end())
            return -1;

        // else return the value at that key in the lsi of pairs.
        return it->second;
    }

    void remove(int key)
    {
        // find the index 
        int index = funcHash(key);

        list<pair<int, int>>::iterator it = search(key);

        // if iterator from search func dosen't points to end of list then erase data at that iterator.  
        if (it != m[index].end())
            m[index].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */