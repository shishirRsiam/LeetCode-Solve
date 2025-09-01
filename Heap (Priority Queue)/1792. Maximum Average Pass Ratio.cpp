#define pi pair<double, int>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        // Lambda to compute delta (gain in ratio)
        auto delta = [&](int pass, int total) -> double {
            return (double(pass + 1) / (total + 1)) - (double(pass) / total);
        };
        
        int n = classes.size();
        priority_queue<pi> maxHeap;
        for (int i = 0; i < n; i++) 
        {
            int pass = classes[i][0], total = classes[i][1];
            maxHeap.push({delta(pass, total), i});
        }

        while (extraStudents--) 
        {
            auto [gain, idx] = maxHeap.top(); maxHeap.pop();
            int pass = classes[idx][0], total = classes[idx][1];
            
            classes[idx][0]++, classes[idx][1]++;
            maxHeap.push({delta(classes[idx][0], classes[idx][1]), idx});
        }

        double passRatio = 0.0;
        for (auto &cls : classes) 
            passRatio += double(cls[0]) / cls[1];

        return passRatio / n;
    }
};