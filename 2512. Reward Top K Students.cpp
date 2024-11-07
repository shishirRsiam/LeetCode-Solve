class cmp {
    public:
    bool operator()(auto a, auto b)
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) 
    {
        unordered_set<string>pos_feed, neg_feed;
        for(auto feed:positive_feedback) 
            pos_feed.insert(feed);
        for(auto feed:negative_feedback) 
            neg_feed.insert(feed);

        int n = student_id.size();
        vector<pair<int, int>>studentScore;
        for(int i = 0; i < n; i++)
        {
            string word;
            stringstream reportWord(report[i]);
            
            int score = 0, id = student_id[i];
            while(reportWord >> word)
            {
                if(pos_feed.count(word)) score += 3;
                else if(neg_feed.count(word)) score -= 1;
            }
            studentScore.push_back({score, id});
        }
        sort(begin(studentScore), end(studentScore), cmp());

        vector<int>ans;
        for(int i = 0; i < k; i++)
        {
            auto [score, id] = studentScore[i];
            ans.push_back(id);
        }
        return ans;
    }
};