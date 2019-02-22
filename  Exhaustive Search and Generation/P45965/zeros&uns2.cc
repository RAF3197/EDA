#include <vector>
#include <iostream>
using namespace std;

void escriu(const vector<int>& resultat){
  for (int i=0;i<resultat.size();++i){
    if (i==resultat.size()-1)cout<<resultat[i]<<endl;
    else cout<<resultat[i]<<" ";
  }
}

void back(int zeros,int uns,vector<int>& resultat,int m,int n,int q){
  if (resultat.size()==zeros+uns)escriu(resultat);
  else{
    if (n-m!=zeros){
      resultat[q]=0;
      back(zeros+1,uns,resultat,m,n,q+1);
    }
    if (m!=uns){
      resultat[q]=1;
      back(zeros,uns+1,resultat,m,n,q+1);
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int>resultat(n);
  back(0,0,resultat,m,n,0);
}
