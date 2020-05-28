#include<bits/stdc++.h>
using namespace std;
 
vector < pair<int,int> > v[550];
unordered_map <int,int> dis;
vector <int> parent(550,0);
vector <int> color(550,0);
 
int node,edge;
 
void span(int start)
{
    for(int i=0; i<node; i++) dis[i] = INT_MAX;
 
    dis[start] = 0;
    parent[start] = -1;
 
    set < pair<int,int> > s;
    s.insert({dis[start],start});
 
    while(!s.empty()){
 
        auto it = s.begin();
        int Node = it->second;
        int weight = it->first;
        s.erase(it);
        color[Node] = 1;
 
        for(int i=0; i<v[Node].size(); i++){
            int n1 = v[Node][i].first;
            int cost = v[Node][i].second;
 
            if(cost<dis[n1] && !color[n1]){
 
                auto finder = s.find({dis[n1],n1});
 
                if(finder!=s.end()){
                    s.erase(finder);
                }
 
                dis[n1] = cost;
                s.insert({cost,n1});
                parent[n1] = Node;
 
 
 
            }
 
        }
 
 
 
 
    }
 
 
 
 
 
}
 
int main()
{
//    freopen("weight1.txt", "r", stdin);
//   // freopen("text.txt", "w", stdout);
//
////    ios_base::sync_with_stdio(0);
////    cin.tie(0);
////    cout.tie(0);
 
    int t,kk=0;
    //cin >> t;
    scanf("%d", &t);
 
    while(t--){
 
    //cin >> node >> edge;
    scanf("%d %d",&node,&edge);
 
    for(int i=0; i<edge; i++){
 
        int a1,a2,w;
 
        cin >> a1 >> a2 >> w;
 
        v[a1].push_back({a2,w});
        v[a2].push_back({a1,w});
 
    }
    int des;
    cin >> des;
 
    span(des);
   
    return 0;
}
