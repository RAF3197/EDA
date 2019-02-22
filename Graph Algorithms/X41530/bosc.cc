#include <iostream>
#include <vector>
using namespace std;

void hiha_cicle(vector<bool>& visitats,const vector<vector<int> >& graf,int adj_ant,int x,bool& cicle){
  if (not visitats[x]){
    visitats[x]=true;
    for (int j=0;j<graf[x].size();++j){
      if (graf[x][j]!=adj_ant) hiha_cicle(visitats,graf,x,graf[x][j],cicle);
      if (cicle)return;
    }
  }
  else cicle=true;
}

void Boscos(const vector<vector<int> >&Bosc){
  vector<bool> visitats(Bosc.size(),false);
  int components=0;
  for (int i=0;i<Bosc.size();++i){
    if (not visitats[i]){
      bool cicle=false;
      hiha_cicle(visitats,Bosc,i,i,cicle);
      if(cicle){
        cout<<"no"<<endl;
        return;
      }
      else {
        ++components;
      }
    }
  }
  cout<<components<<endl;
}

int main(){
  int n,m;
  while (cin>>n>>m){
    vector<vector<int> >Bosc(n);
    int x,y;
    for (int i=0;i<m;++i){
      cin>>x>>y;
      Bosc[x].push_back(y);
      Bosc[y].push_back(x);
    }
    if (m==0)cout<<n<<endl;
    else Boscos(Bosc);
  }
}
