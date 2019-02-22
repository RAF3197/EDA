#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool colors(const vector<vector<int> >& graf){
  queue<int> cua;
  vector<int> colors(graf.size(),-1);
  for(int i=0;i<graf.size();++i){
    if (colors[i]<0){
      cua.push(i);
      colors[i]=1;
      while(not cua.empty()){
        int n=cua.front();
        cua.pop();
        for (int j=0;j<graf[n].size();++j){
          if (colors[graf[n][j]]<0){
            cua.push(graf[n][j]);
            colors[graf[n][j]]=1-colors[n];
          }
          else if (colors[graf[n][j]]==colors[n]){
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main(){
  int n,m;
  while(cin>>n>>m){
    vector<vector<int> >graf(n);
    int x,y;
    for(int i=0;i<m;++i){
      cin>>x>>y;
      graf[x].push_back(y);
      graf[y].push_back(x);
    }
    if(colors(graf))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}
