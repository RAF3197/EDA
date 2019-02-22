#include <vector>
#include <queue>
#include <iostream>
#include <list>
using namespace std;
#define inf 0x7FFFFFFF
typedef pair<double,int> WArc;

void dijkstra(const vector<vector<WArc> >& graf,int x,vector<double>& distancia,vector<int>& pares,vector<bool>& visitats){
  int n=graf.size();
  visitats=vector<bool>(n,false);
  pares=vector<int>(n,-1);
  distancia=vector<double>(n,inf);
  priority_queue<WArc,vector<WArc>,greater<WArc> > cua;
  cua.push(WArc(0,x));
  distancia[x]=0;
  while (not cua.empty()){
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

void imprimir_cami(const vector<int>& pares,int y,const vector<double>& distancia,int x){
  vector<int> resultat;
  resultat.push_back(y);
  while(pares[y]!=-1){
    y=pares[y];
    resultat.push_back(y);
  }
  if (distancia[y]==inf)cout<<"no path from "<<x<<" to "<<y<<endl;
  else{
    bool last=false;
    for (int i=resultat.size()-1;i>-1;--i){
      if (i==0)last=true;
      if (not last) cout<<resultat[i]<<" ";
      else if (last)cout<<resultat[i]<<endl;
    }
  }
}

int main(){
  int n,m;
  while (cin>>n>>m){
    vector<vector<WArc> > graf(n);
    for (int i=0;i<m;++i){
      int u,v;
      double c;
      cin>>u>>v>>c;
      graf[u].push_back(WArc(c,v));
    }
    vector<double> distancia;
    vector<int> pares;
    vector<bool> visitats;
    int x,y;
    cin>>x>>y;
    dijkstra(graf,x,distancia,pares,visitats);
    imprimir_cami(pares,y,distancia,x);
  }
}
