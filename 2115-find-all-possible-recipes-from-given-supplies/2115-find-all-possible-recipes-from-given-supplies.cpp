class Solution {
    unordered_map<string, vector<string>> adj;
    unordered_map<string, bool> ready;
    unordered_set<string> is_processing;
    bool dfs(string &recipe){
        if( is_processing.find(recipe) != is_processing.end() ){
            return false; // this is a cylic dependency
        }

        if( ready.find(recipe) != ready.end() ){ 
            return ready[recipe]; //this is cache for quick answers to already done computations
        }

        if ( adj.find(recipe) == adj.end() ) { 
            //if ur here means its checking a leaf/supply which is not present in supplies
            return false;
        }
        
        bool isPossibleToMake = true;
        is_processing.insert(recipe);
        for (auto &ingredient : adj[recipe]) {
            if (dfs(ingredient) == false) {
                isPossibleToMake = false;
                break;
            }
        }
        is_processing.erase(recipe);
        
        return ready[recipe] = isPossibleToMake;

    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        adj.clear(), ready.clear();

        for (const auto &supply : supplies) ready[supply] = true;
        for (int i = 0; i < recipes.size(); i++) adj[ recipes[i] ] = ingredients[i];

        vector<string> ans;
        for (auto &recipe : recipes) 
            if (dfs(recipe)) ans.push_back(recipe);

        return ans;
    }
};