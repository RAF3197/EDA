#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define inf 0x7FFFFFFF
typedef pair<double,int> WArc;


void dijkstra(const vector<vector<WArc> >& graf,int vertex_inicial,vector<double>& distancia,vector<int>& pares){
  priority_queue<WArc,vector<WArc>,greater<WArc> > cua;
  cua.push(WArc(0,vertex_inicial));
  distancia[vertex_inicial]=0;
  int n=distancia.size();
  vector<bool> visitats(n,false);
  while(not cua.empty()){
    WArc vertex=cua.top();cua.pop();
    int v=vertex.second;
    if (not visitats[v]){
      visitats[v]=true;
      for (int i=0;i<graf[v].size();++i){
        int vertex_vei=graf[v][i].second;
        double cost_per_vei=graf[v][i].first;
        if (not visitats[vertex_vei]){
          if (distancia[vertex_vei]>distancia[v]+cost_per_vei){
            distancia[vertex_vei]=distancia[v]+cost_per_vei;
            pares[vertex_vei]=v;
            cua.push(WArc(distancia[vertex_vei],vertex_vei));
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
    for (int i=0;i<m;++i){
      int u,v,c;
      cin>>u>>v>>c;
      graf[u].push_back(WArc(c,v));
    }
    int vertex_inicial,vertex_final;
    cin>>vertex_inicial>>vertex_final;
    vector<double>distancia(n,inf);
    vector<int>pares(n,-1);
    dijkstra(graf,vertex_inicial,distancia,pares);
    if (distancia[vertex_final]==inf)cout<<"no path from "<<vertex_inicial<<" to "<<vertex_final<<endl;
    else cout<<distancia[vertex_final]<<endl;
  }
}
