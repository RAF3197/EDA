#include <vector>
#include <iostream>
#include <stack>
using namespace std;

void tractar(vector<vector<char> >& mapa,vector<vector<bool> >& visitats,int x,int y,stack<pair<int,int> >& pila){
  if(x>=0 and x<mapa.size() and y>=0 and y<mapa[0].size()){
    if(not visitats[x][y]){
      visitats[x][y]=true;
      if(mapa[x][y]!='X')pila.push(make_pair(x,y));
    }
  }
}

bool DFS(vector<vector<char> >& mapa,int x,int y){
  --x;--y;
  vector<vector<bool> >visitats(mapa.size(),vector<bool>(mapa[0].size(),false));
  stack<pair<int,int> >pila;
  visitats[x][y]=true;
  pila.push(make_pair(x,y));
  while(not pila.empty()){
    pair<int,int> posicio=pila.top();pila.pop();
    if(mapa[posicio.first][posicio.second]=='t')return true;
    else{
      tractar(mapa,visitats,posicio.first+1,posicio.second,pila);
      tractar(mapa,visitats,posicio.first-1,posicio.second,pila);
      tractar(mapa,visitats,posicio.first,posicio.second+1,pila);
      tractar(mapa,visitats,posicio.first,posicio.second-1,pila);
    }
  }
  return false;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<char> >mapa(n,vector<char>(m));
  for (int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cin>>mapa[i][j];
    }
  }
  int x,y;
  cin>>x>>y;
  if(DFS(mapa,x,y))cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}
