class TaskManager {
public:
    priority_queue<pair<int, int>> maxHeap;
    unordered_map<int, int> taskUser, taskPriority;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks)
        {
            auto userId = task[0], taskId = task[1], priority = task[2];
            taskUser[taskId] = userId;
            taskPriority[taskId] = priority;
            maxHeap.push({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskUser[taskId] = userId;
        taskPriority[taskId] = priority;
        maxHeap.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        maxHeap.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskUser.erase(taskId);
        taskPriority.erase(taskId);
    }
    
    int execTop() {
        while (not maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();
            if (taskPriority.count(taskId) and taskPriority[taskId] == priority) {
                int userId = taskUser[taskId];
                rmv(taskId);
                return userId;
            }
        }
        return -1;
    }
};