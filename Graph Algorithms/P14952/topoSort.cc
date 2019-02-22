#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topo(const vector<vector<int> >& graf){
  vector<int> llista;
  priority_queue<int,vector<int>,greater<int> >cua;
  vector<int>graus(graf.size(),0);
  for (int i=0;i<graf.size();++i){
    for (int j=0;j<graf[i].size();++j){
      ++graus[graf[i][j]];
    }
  }
  for (int i=0;i<graf.size();++i){
    if (graus[i]==0)cua.push(i);
  }
  while(not cua.empty()){
    int u=cua.top();
    cua.pop();
    llista.push_back(u);
    for (int i=0;i<graf[u].size();++i){
      --graus[graf[u][i]];
      if (graus[graf[u][i]]==0)cua.push(graf[u][i]);
    }
  }
  for (int i=0;i<llista.size();++i){
    if (i==llista.size()-1)cout<<llista[i]<<endl;
    else cout<<llista[i]<<" ";
  }
}

int main(){
  int n,m;
  while(cin>>n>>m){
    vector<vector<int> >graf(n);
    int x,y;
    for (int i=0;i<m;++i){
      cin>>x>>y;
      graf[x].push_back(y);
    }
    topo(graf);
  }
}
