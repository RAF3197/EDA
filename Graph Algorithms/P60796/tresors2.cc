#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void tractar(vector<vector<char> >& mapa,vector<vector<bool> >& visitats,queue<pair<int,pair<int,int> > >& cua,int x,int y,int dist){
  if(x>=0 and x<mapa.size() and y>=0 and y<mapa[0].size()){
    if (not visitats[x][y]){
      visitats[x][y]=true;
      if(mapa[x][y]!='X')cua.push(make_pair(x,make_pair(y,dist+1)));
    }
  }
}

void BFS(vector<vector<char> >& mapa){
  int x,y;cin>>x>>y;
  --x;--y;
  vector<vector<bool> >visitats(mapa.size(),vector<bool>(mapa[0].size(),false));
  queue<pair<int,pair<int,int> > >cua;
  cua.push(make_pair(x,make_pair(y,0)));
  visitats[x][y]=true;
  int distancia=9999;
  while (not cua.empty()){
    pair<int,pair<int,int> > aux=cua.front();cua.pop();
    if(mapa[aux.first][aux.second.first]=='t' and distancia>aux.second.second)distancia=aux.second.second;
    tractar(mapa,visitats,cua,aux.first+1,aux.second.first,aux.second.second);
    tractar(mapa,visitats,cua,aux.first-1,aux.second.first,aux.second.second);
    tractar(mapa,visitats,cua,aux.first,aux.second.first+1,aux.second.second);
    tractar(mapa,visitats,cua,aux.first,aux.second.first-1,aux.second.second);
  }
  if(distancia==9999)cout<<"no es pot arribar a cap tresor"<<endl;
  else cout <<"distancia minima: "<<distancia<<endl;
}


int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<char> >mapa(n,vector<char>(m));
  for (int i = 0; i < n; i++) {
    for(int j=0;j<m;++j){
      cin>>mapa[i][j];
    }
  }
  BFS(mapa);
}
