#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void tractar(const vector<vector<char> >& mapa,vector<vector<bool> >& visitats,int x,int y,queue<pair<int,int> >& cola){
  if (x>=0 and x<=mapa.size()-1 and y>=0 and y<=mapa[0].size()-1){
    if (not visitats[x][y]){
      visitats[x][y]=true;
      if (mapa[x][y]!='X')cola.push(make_pair(x,y));
    }
  }
}

void bfs(const vector<vector<char> >& mapa,vector<vector<bool> >& visitats){
  int x,y;
  cin>>x>>y;
  queue<pair<int,int> > cola;
  --x;--y;
  cola.push(make_pair(x,y));
  visitats[x][y]=true;
  bool trobat=false;
  int tresors=0;
  while(not cola.empty() and not trobat){
    pair<int,int> coord;
    coord=cola.front();
    cola.pop();
    if (mapa[coord.first][coord.second]=='t') tresors++;
    tractar(mapa,visitats,coord.first+1,coord.second,cola);//down
    tractar(mapa,visitats,coord.first-1,coord.second,cola);//up
    tractar(mapa,visitats,coord.first,coord.second+1,cola);//right
    tractar(mapa,visitats,coord.first,coord.second-1,cola);//left
  }
  if (tresors!=0)cout<<tresors<<endl;
  else cout<<0<<endl;
}


int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<char> > matriu(n,vector<char>(m));
  vector<vector<bool> > visitats(n,vector<bool>(m,false));
  for (int i=0;i<n;++i){
    for (int j=0;j<m;++j){
      cin>>matriu[i][j];
    }
  }
  bfs(matriu,visitats);
}
