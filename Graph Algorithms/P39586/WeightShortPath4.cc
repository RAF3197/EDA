#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define inf 0x7FFFFFFF
typedef pair<double,int>WArc;

void dijkstra(vector<vector<WArc> >& graf,vector<WArc>& distancia,vector<bool>& visitats,vector<int>& pares,int x){
  int n=graf.size();
  distancia=vector<WArc>(n,WArc(inf,-1));
  pares=vector<int>(n,-1);
  visitats=vector<bool>(n,false);
  priority_queue<WArc,vector<WArc>,greater<WArc> >cua;
  cua.push(WArc(0,x));
  distancia[x].first=0;
  distancia[x].second=1;
  while(not cua.empty()){
    WArc vertex=cua.top();cua.pop();
    int v=vertex.second;
    if(not visitats[v]){
      visitats[v]=true;
      for(int i=0;i<graf[v].size();++i){
        int vertex_vei=graf[v][i].second;
        int cost_per_vei=graf[v][i].first;
        if(not visitats[vertex_vei]){
          if (distancia[vertex_vei].first>distancia[v].first+cost_per_vei){
            distancia[vertex_vei].first=distancia[v].first+cost_per_vei;
            distancia[vertex_vei].second=distancia[v].second;
            pares[vertex_vei]=v;
            cua.push(WArc(distancia[vertex_vei].first,vertex_vei));
          }
          else if(distancia[vertex_vei].first==distancia[v].first+cost_per_vei){
            distancia[vertex_vei].second+=distancia[v].second;
            pares[vertex_vei]=v;
            cua.push(WArc(distancia[vertex_vei].first,vertex_vei));
          }
        }
      }
    }
  }
}

int main(){
  int n,m;
  while(cin>>n>>m){
    vector<vector<WArc> >graf(n);
    for(int i=0;i<m;++i){
      int u,v;
      double c;
      cin>>u>>v>>c;
      graf[u].push_back(WArc(c,v));
    }
    vector<WArc> distancia;
    vector<bool> visitats;
    vector<int> pares;
    int x,y;
    cin>>x>>y;
    dijkstra(graf,distancia,visitats,pares,x);
    if(distancia[y].first!=inf)cout<<"cost "<<distancia[y].first<<", "<<distancia[y].second<<" way(s)"<<endl;
    else cout<<"no path from "<<x<<" to "<<y<<endl;
  }
}
