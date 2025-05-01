class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(begin(tasks), end(tasks));
        sort(rbegin(workers), rend(workers));
        int n = tasks.size(), m = workers.size();

        auto canSolveTasks = [&](int k)
        {
            int usedPills = 0;
            multiset<int> cp_task, cp_worker;
            for(int i = 0; i < k; i++)
            {
                cp_task.insert(tasks[i]);
                cp_worker.insert(workers[i]);
            }

            for(auto it = cp_task.rbegin(); it != cp_task.rend(); it++)
            {
                auto wit = cp_worker.lower_bound(*it);
                if(wit != cp_worker.end())
                    cp_worker.erase(wit);
                else 
                {
                    if(usedPills == pills) return false;
                    auto pit = cp_worker.lower_bound(*it - strength);
                    if(pit == cp_worker.end() or *pit + strength < *it) return false;
                    usedPills += 1;
                    cp_worker.erase(pit);
                }
            }
            return true;
        };


        int left = 0, right = min(n, m), ans = 0, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(canSolveTasks(mid)) ans = mid, left = mid + 1;
            else right = mid - 1;
        }
        return ans; 
    }
};