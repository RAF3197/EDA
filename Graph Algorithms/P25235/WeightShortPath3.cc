#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define inf 0x7FFFFFFF
typedef pair<double,pair<int,int> >WArc;
typedef pair<double,int> dist;

void dijkstra(const vector<vector<WArc> >& graf,vector<int>& pares,vector<dist>& distancia,vector<bool>& visitats,int x,int y,int& min_step){
  int n=graf.size();
  visitats=vector<bool>(n,false);
  pares=vector<int>(n,-1);
  distancia=vector<dist>(n,dist(inf,0));
  priority_queue<WArc,vector<WArc>,greater<WArc> >cua;
  cua.push(WArc(0,make_pair(x,0)));
  distancia[x].first=0;
  distancia[x].second=0;
  while(not cua.empty()){
    WArc vertex=cua.top();cua.pop();
    int v=vertex.second.first;
    int steps_v=vertex.second.second;
    if (not visitats[v]){
      visitats[v]=true;
      for (int i=0;i<graf[v].size();++i){
        int vertex_vei=graf[v][i].second.first;
        double cost_per_vei=graf[v][i].first;
        if (not visitats[vertex_vei]){
          if (distancia[vertex_vei].first>distancia[v].first+cost_per_vei){
            distancia[vertex_vei].first=distancia[v].first+cost_per_vei;
            distancia[vertex_vei].second=steps_v+1;
            pares[vertex_vei]=v;
            cua.push(WArc(distancia[vertex_vei].first,make_pair(vertex_vei,steps_v+1)));
          }//fero tot amb un pair, ja que aquest en cas de empat es mira el second
          else if (distancia[vertex_vei].first==distancia[v].first+cost_per_vei and steps_v+1<distancia[vertex_vei].second){
            distancia[vertex_vei].second=steps_v+1;
            pares[vertex_vei]=v;
            cua.push(WArc(distancia[vertex_vei].first,make_pair(vertex_vei,steps_v+1)));
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
      int u,v;double c;
      cin>>u>>v>>c;
      graf[u].push_back(WArc(c,make_pair(v,0)));
    }
    vector<pair<double,int> > distancia;//pasa a ser un pair de distancia i steeps;
    vector<int> pares;
    vector<bool> visitats;
    int x,y;
    cin>>x>>y;
    int min_step=inf;
    dijkstra(graf,pares,distancia,visitats,x,y,min_step);
    if (distancia[y].first!=inf) cout<<"cost "<<distancia[y].first<<", "<<distancia[y].second<<" step(s)"<<endl;
    else cout<<"no path from "<<x<<" to "<<y<<endl;
  }
}
