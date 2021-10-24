// 705. Design HashSet
// https://leetcode.com/problems/design-hashset/


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// using hashing function with chaining technique by using vector of lists to solve collisions.

class MyHashSet
{
public:
    vector<list<int>> m;
    int size;
    MyHashSet()
    {
        size = 1e2;
        m.resize(size);
    }

    int funcHash(int key)
    {
        return key % size;
    }

    list<int>::iterator search(int key)
    {
        int i = funcHash(key);
        return find(m[i].begin(), m[i].end(), key);
    }

    void add(int key)
    {
        if (contains(key))
            return;
        int i = funcHash(key);
        m[i].push_back(key);
    }

    void remove(int key)
    {
        if (contains(key))
        {
            int i = funcHash(key);
            m[i].erase(search(key));
        }
    }

    bool contains(int key)
    {
        int i = funcHash(key);
        if (search(key) != m[i].end())
            return true;
        return false;
    }
};
