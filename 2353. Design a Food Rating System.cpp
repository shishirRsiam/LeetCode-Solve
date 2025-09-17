class cmp {
    public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) 
    {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
class FoodRatings {
public:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> storeCountry;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> heaps;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n = foods.size();
        for (int i = 0; i < n; i++) 
        {
            string food = foods[i];
            int rating = ratings[i];
            string cuisine = cuisines[i];

            foodRating[food] = rating;
            storeCountry[food] = cuisine;
            heaps[cuisine].push({rating, food});
        }
    }

    void changeRating(string food, int newRating) 
    {
        foodRating[food] = newRating;
        string cuisine = storeCountry[food];
        heaps[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine) 
    {
        auto &pq = heaps[cuisine];
        while (!pq.empty()) 
        {
            auto [rating, food] = pq.top();
            if (foodRating[food] == rating) return food;
            pq.pop();
        }
        return "";
    }
};