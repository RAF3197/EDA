#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int/*pes*/,pair<int/*origen*/,int/*fi*/> > WEorig;

int prim(vector<vector<pair<int,int> > >& graf){
  vector<bool>visitats(graf.size(),false);
  priority_queue<WEorig,vector<WEorig>,greater<WEorig> > cua;
  vector<int>pares(graf.size(),-1);
  cua.push(make_pair(0,make_pair(0,0)));
  int pestot=0;
  while (not cua.empty()){
    WEorig aux=cua.top();
    cua.pop();
    int pes=aux.first;
    int origen=aux.second.first;
    int fi=aux.second.second;
    if (not visitats[fi]){
      pestot+=pes;
      visitats[fi]=true;
      pares[fi]=origen;
      for (int i=0;i<graf[fi].size();++i){
        int p=graf[fi][i].second;
        int adj=graf[fi][i].first;
        cua.push(make_pair(p,make_pair(fi,adj)));
      }
    }
  }
  return pestot;
}

int main(){
  int n,m;
  while (cin>>n>>m){
    vector<vector<pair<int,int> > >graf(n);
    for (int i=0;i<m;++i){
      int u,v,c;
      cin>>u>>v>>c;
      --u;--v;
      graf[u].push_back(make_pair(v,c));
      graf[v].push_back(make_pair(u,c));
    }
    cout<<prim(graf)<<endl;
  }
}
