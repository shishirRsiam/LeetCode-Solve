class MovieRentingSystem {
public:
    set<tuple<int,int,int>> rented;
    unordered_map<long long, int> price;
    unordered_map<int, set<pair<int,int>>> available;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            long long key = ((long long)shop << 32) | movie;
            price[key] = p;
            available[movie].insert({p, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto &[p, shop] : available[movie]) {
            if (res.size() == 5) break;
            res.push_back(shop);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int p = price[key];
        available[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        long long key = ((long long)shop << 32) | movie;
        int p = price[key];
        rented.erase({p, shop, movie});
        available[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &[p, shop, movie] : rented) {
            if (res.size() == 5) break;
            res.push_back({shop, movie});
        }
        return res;
    }
};