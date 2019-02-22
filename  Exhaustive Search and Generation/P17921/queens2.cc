#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& solucio){
  //cout<<"entro a escriu"<<endl;
  for (int i=0;i<solucio.size();++i){
    for(int j=0;j<solucio.size();++j){
      if(solucio[i]==j)cout<<"Q";
      else cout<<".";
    }
    cout<<endl;
  }
  cout<<endl;
}

void reines(int fila,int n,vector<int>& solucio,vector<bool>& col,vector<bool>& diagonal1,vector<bool>& diagonal2,bool& escrit){
  if (fila==n){escriu(solucio);escrit=true;}
  else{
    for (int columna=0;columna<n;++columna){
      int diag1=n-columna-1+fila;
      int diag2=columna+fila;
      if (not col[columna] and not diagonal1[diag1] and not diagonal2[diag2] and solucio[fila]==-1){
        solucio[fila]=columna;
        col[columna]=true;
        diagonal1[diag1]=true;
        diagonal2[diag2]=true;
        reines(fila+1,n,solucio,col,diagonal1,diagonal2,escrit);
        col[columna]=false;
        diagonal1[diag1]=false;
        diagonal2[diag2]=false;
        solucio[fila]=-1;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int>solucio(n,-1);
  vector<bool>columna(n,false);
  vector<bool>diagonal1(2*n-1,false);
  vector<bool>diagonal2(2*n-1,false);
  bool escrit=false;
  reines(0,n,solucio,columna,diagonal1,diagonal2,escrit);
  //if (not escrit)cout<<endl;
}
