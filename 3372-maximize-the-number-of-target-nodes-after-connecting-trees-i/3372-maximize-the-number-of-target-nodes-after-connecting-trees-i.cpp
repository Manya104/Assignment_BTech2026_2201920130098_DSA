#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define llmax LLONG_MAX
#define llmin LLONG_MIN
const ll mod =1e9+7;
#define endl "\n"
#define vll vector<long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define svi set<vector<int>>
#define all(x) x.begin(),x.end()
#define sll set<ll> s;
#define range (lower_bound(all(arr),val)-upper_bound(all(arr),val));
using namespace std;
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
         //tree2 number of nodes for each node they are at distance<=k-1 (1 for connection) -- max it +1(self)
        //tree1 numbre ow nodes <=k +1 self
        //easy
       // int n = e1.size(); XXXXXX
       int maxNode = 0;
        for (auto& e : e1) {
            maxNode = max({maxNode, e[0], e[1]});
        }
        int n = maxNode + 1;
        vi ans(n, 0);//not 1 as in queue it did also counts for both
        vector<vi> adj1(n);
        for(auto i:e1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        //bfs for nodes nearer than k of each node
        for(int i=0;i<n;i++){
            queue<pair<int,int>> q;//node,dis
            vector<int> vis(n,0);
            q.push({i,0});
            vis[i]=1;
            while (!q.empty())
            {
                auto t=q.front();q.pop();
                
                int node=t.first,dis=t.second;
                
                if(dis>k)continue;
               
                    ans[i]++;
                    for(auto k2:adj1[node]){
                        if(!vis[k2]){q.push({k2,dis+1});vis[k2]=1;}
                    

                }
            }
            
        }
        //now tree2
        maxNode = 0;
        for (auto& e : e2) {
            maxNode = max({maxNode, e[0], e[1]});
        }
        int m= maxNode + 1;
        vector<vi> adj2(m);
        for(auto i:e2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        vi ans2(m, 0);//not 1 as in queue it did also counts for both
        for(int i=0;i<m;i++){
            queue<pair<int,int>> q;//node,dis
            vector<int> vis(m,0);
            q.push({i,0});
            vis[i]=1;
            while (!q.empty())
            {
                auto t=q.front();q.pop();
                
                int node=t.first,dis=t.second;
                
                if(dis>k-1)continue;//***k-1 */
               
                    ans2[i]++;
                    for(auto k2:adj2[node]){
                        if(!vis[k2]){q.push({k2,dis+1});vis[k2]=1;}
                    

                }
            }
            

        }
        int connection=*max_element(ans2.begin(), ans2.end());
        for(int i=0;i<n;i++){
            ans[i]+=connection;
        }
        // for(int i=0;i<n;i++){cout<<ans[i]<<" ";if(i==n-1){cout<<"\n";}}
        return ans;


    }
};