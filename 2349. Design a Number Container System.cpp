class NumberContainers {
public:
    unordered_map<int, set<int>> store;
    unordered_map<int, int> index_filled;
    NumberContainers() {}

    void change(int index, int number)
    {
        if (index_filled.count(index))
            store[index_filled[index]].erase(index);

        store[number].insert(index);
        index_filled[index] = number;
    }

    int find(int number)
    {
        if (store[number].empty())
            return -1;

        return *store[number].begin();
    }
};