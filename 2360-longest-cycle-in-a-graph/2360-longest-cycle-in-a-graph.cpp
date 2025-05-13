class Solution {
public:
    int cycleLength=-1;
    void dfs(int node,vector<int> &adj,vector<int>&vis,vector<int>&pathVis,int curDepth){
        vis[node]=1;
        pathVis[node]=curDepth;
        int nextNode=adj[node];
        if(nextNode!=-1){
            if(vis[nextNode]==0){
                dfs(nextNode,adj,vis,pathVis,curDepth+1); 
            }
            else if(pathVis[nextNode]!=0){
                int maxi=curDepth-pathVis[nextNode]+1;
                /*EXAMPLE:
                Node visited in order: A → B → C → D → E → C
                We've detected a cycle:
                C → D → E → C
                The node C was first visited at depth[C] = 3
                The current node E is at currDepth = 5
                So the number of steps from C to E is 5 - 3 = 2.
                */
                cycleLength=max(cycleLength,maxi);
            }
        }
        pathVis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               dfs(i,edges,vis,pathVis,1);
            }
        }
        return cycleLength;
    }
};