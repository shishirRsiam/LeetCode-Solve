class Solution {
    public:
        unordered_set<int> store;
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
        {
            vector<string> ans;
            unordered_set<string> supply(begin(supplies), end(supplies));
    
            int n = recipes.size();
            for(int i = 0; i < n; i++)
            {
                bool flag = true;
                for(auto ingredient : ingredients[i])
                {
                    if(not supply.count(ingredient))
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    ans.push_back(recipes[i]);
                    if(not store.count(i)) supplies.push_back(recipes[i]);
                    store.insert(i);
                }
            }
            if(supply.size() != supplies.size())
                ans = findAllRecipes(recipes, ingredients, supplies);
    
            return ans;
        }
    };