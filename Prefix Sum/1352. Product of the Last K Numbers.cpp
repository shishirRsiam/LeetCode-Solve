class ProductOfNumbers {
    public:
        vector<long> pref;
        set<int> store_zero;
        ProductOfNumbers() {
            pref.push_back(1);
        }
        
        void add(int num) {
            if(num == 0)
            {
                store_zero.insert(pref.size() - 1);
                pref.push_back(1);
            }
            else pref.push_back(pref.back() * long(num));
        }
        
        int getProduct(int k) {
            int start_index = pref.size() - k - 1;
            auto find_zero = store_zero.lower_bound(start_index);
            if(find_zero != store_zero.end() and *find_zero <= pref.size() and *find_zero >= start_index) return 0;
            return pref.back() / pref[start_index];
        }
    };