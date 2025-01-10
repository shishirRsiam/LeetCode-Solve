void recursion(vector<string> &store, int idx, string &characters, string &cur, int &combinationLength)
{
    if(cur.size() == combinationLength)
    {
        cout<<cur<<endl;
        store.push_back(cur);
        return;
    }
    if(idx >= characters.size()) return;

    cur += characters[idx];
    recursion(store, idx + 1, characters, cur, combinationLength);
    cur.pop_back();
    recursion(store, idx + 1, characters, cur, combinationLength);
}

class CombinationIterator {
public:
    int i = 0;
    vector<string>store;
    CombinationIterator(string characters, int combinationLength) 
    {
        string cur;
        recursion(store, 0, characters, cur, combinationLength);
    }
    
    string next() {
        return store[i++];
    }
    
    bool hasNext() {
        return i < store.size();
    }
};