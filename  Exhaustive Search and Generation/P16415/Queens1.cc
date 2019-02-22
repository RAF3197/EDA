#include <iostream>
#include <vector>
using namespace std;

int resultat=0;

void reines(int fila,vector<int>& tauler,vector<bool>& col,vector<bool>& diagonal1,vector<bool>& diagonal2,int n){
  if(fila==n)++resultat;
  else{
    for(int columna=0;columna<n;++columna){
      int diag1=n-columna-1+fila;
      int diag2=columna+fila;
      tauler[fila]=columna;
      if (not col[columna] and not diagonal1[diag1] and not diagonal2[diag2]){
        col[columna]=true;
        diagonal1[diag1]=true;
        diagonal2[diag2]=true;
        reines(fila+1,tauler,col,diagonal1,diagonal2,n);
        col[columna]=false;
        diagonal1[diag1]=false;
        diagonal2[diag2]=false;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int>tauler(n);
  vector<bool>columna(n,false);
  vector<bool>diagonal1(2*n-1,false);
  vector<bool>diagonal2(2*n-1,false);
  reines(0,tauler,columna,diagonal1,diagonal2,n);
  cout<<resultat<<endl;
}
