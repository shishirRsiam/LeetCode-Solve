class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
        {
            int n = fruits.size();
            vector<bool> placedBaskets(n);
            for(auto &fruit : fruits)
            {
                for(int i = 0; i < n; i++)
                {
                    if(placedBaskets[i]) continue;
                    if(fruit <= baskets[i])
                    {
                        placedBaskets[i] = true;
                        break;
                    }
                }
            }
            
            int unplacedFruits = 0;
            for(int i = 0; i < n; i++)
                unplacedFruits += not placedBaskets[i];
            return unplacedFruits;
        }
    };