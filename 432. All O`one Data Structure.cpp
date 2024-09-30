class AllOne
{
public:
    AllOne() {}

    map<string, int> count;
    map<int, set<string>> store;
    void inc(string key)
    {
        int curCount = count[key];
        count[key]++;

        if (curCount)
        {
            store[curCount].erase(key);
            if (store[curCount].empty())
                store.erase(curCount);
        }
        store[count[key]].insert(key);
    }

    void dec(string key)
    {
        if (count.find(key) == count.end())
            return;
        int curCount = count[key];
        count[key]--;

        store[curCount].erase(key);
        if (store[curCount].empty())
            store.erase(curCount);

        if (count[key] == 0)
            count.erase(key);
        else
            store[count[key]].insert(key);
    }

    string getMaxKey()
    {
        if (store.empty())
            return "";
        return *(store.rbegin()->second.begin());
    }

    string getMinKey()
    {
        if (store.empty())
            return "";
        return *(store.begin()->second.begin());
    }
};