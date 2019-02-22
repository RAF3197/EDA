#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void tractar(queue<pair<int,pair<int,int> > >& cua,vector<vector<char> >& mapa,vector<vector<bool> >& visitats,int x,int y,int distancia){
  if (x>=0 and x<mapa.size() and y>=0 and y<mapa[0].size()){
    if (not visitats[x][y]){
      visitats[x][y]=true;
      if (mapa[x][y]!='X')cua.push(make_pair(x,make_pair(y,distancia+1)));
    }
  }
}

void BFS(vector<vector<char> >& mapa){
  vector<vector<bool> >visitats(mapa.size(),vector<bool>(mapa[0].size(),false));
  queue<pair<int,pair<int,int> > > cua;
  int x,y;
  cin>>x>>y;
  --x;--y;
  cua.push(make_pair(x,make_pair(y,0)));
  int distancia=0;
  while(not cua.empty()){
    pair<int,pair<int,int> > aux=cua.front();
    cua.pop();
    if (mapa[aux.first][aux.second.first]=='t' && distancia<aux.second.second)distancia=aux.second.second;
    tractar(cua,mapa,visitats,aux.first+1,aux.second.first,aux.second.second);//nord
    tractar(cua,mapa,visitats,aux.first-1,aux.second.first,aux.second.second);//sud
    tractar(cua,mapa,visitats,aux.first,aux.second.first+1,aux.second.second);//est
    tractar(cua,mapa,visitats,aux.first,aux.second.first-1,aux.second.second);//oest
  }
  if (distancia==0)cout<<"no es pot arribar a cap tresor"<<endl;
  else cout<<"distancia maxima: "<<distancia<<endl;
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
  BFS(mapa);
}
