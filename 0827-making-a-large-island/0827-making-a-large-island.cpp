class Solution {
public:
    int n;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& id, int i, int j, int islandID, unordered_map<int, int>& islandSize) {
        //Initial validation
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0 || id[i][j] != 0) {
            return 0;
        }

        id[i][j] = islandID;
        int size = 1; //used so that the zero present acting as the bridge can also be included
        
        for (auto& dir : directions) {
            size += dfs(grid, id, i + dir[0], j + dir[1], islandID, islandSize);
        }
        //Finally we will return the final size of the combined portions of that node specific node and the neighbouring node as well
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> id(n, vector<int>(n, 0)); // Stores island ID
        unordered_map<int, int> islandSize; // Maps island ID to its size
        int islandID = 2; 
        int maxIsland = 0;

        // Identify all islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && id[i][j] == 0) {
                    int size = dfs(grid, id, i, j, islandID, islandSize);
                    islandSize[islandID] = size;
                    maxIsland = max(maxIsland, size);
                    islandID++;
                }
            }
        }

        // Try flipping each 0 and calculate the potential largest island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seenIslands;
                    int newSize = 1; // The flipped cell itself
                    
                    for (auto& dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && id[ni][nj] > 1) {
                            seenIslands.insert(id[ni][nj]);
                        }
                    }

                    for (int island : seenIslands) {
                        newSize += islandSize[island];
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};