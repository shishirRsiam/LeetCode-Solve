class Router {
public:
    int maxLimit;
    deque<vector<int>> deq;
    unordered_set<string> seen;
    unordered_map<int, deque<int>> storeDes;
    Router(int memoryLimit) {
        maxLimit = memoryLimit;
    }

    string getCode(int source, int destination, int timestamp) {
        return to_string(source) + "+" + to_string(destination) + "+" + to_string(timestamp);
    }

    bool addPacket(int source, int destination, int timestamp) {
        auto code = getCode(source, destination, timestamp);

        if(seen.count(code)) return false;
        seen.insert(code);
        deq.push_back({source, destination, timestamp});
        storeDes[destination].push_back(timestamp);

        while(maxLimit < deq.size())
        {
            source = deq[0][0], destination = deq[0][1], timestamp = deq[0][2];
            code = getCode(source, destination, timestamp);
            deq.pop_front();
            seen.erase(code);
            storeDes[destination].pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> ans;
        if(deq.size()) {
            ans = deq[0];
            int source = deq[0][0], destination = deq[0][1], timestamp = deq[0][2];
            auto code = getCode(source, destination, timestamp);
            seen.erase(code);

            deq.pop_front();
            storeDes[ans[1]].pop_front();
        }
        return ans;
    }
    int binarySearch(deque<int> &arr, int target)
    {
        int i = 0, j = arr.size() - 1, ans = arr.size();
        while(i <= j)
        {
            auto mid = i + (j - i) / 2;
            if(target <= arr[mid]) ans = mid, j = mid - 1;
            else i = mid + 1;
        }
        return ans;
    }
    int getCount(int destination, int startTime, int endTime) {
        int lower = binarySearch(storeDes[destination], startTime);
        int upper = binarySearch(storeDes[destination], endTime + 1);
        return upper - lower;
    }
};