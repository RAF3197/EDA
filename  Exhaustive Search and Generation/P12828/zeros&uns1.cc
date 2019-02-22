#include <vector>
#include <iostream>
using namespace std;

void escriu(const vector<int>& resultat){
  for (int i=0;i<resultat.size();++i){
    if (i==resultat.size()-1)cout<<resultat[i]<<endl;
    else cout<<resultat[i]<<" ";
  }
}

void back(vector<int>& resultat,int q){
  if (resultat.size()==q)escriu(resultat);
  else{
    resultat[q]=0;
    back(resultat,q+1);
    resultat[q]=1;
    back(resultat,q+1);
  }
}

int main(){
  int n;
  cin>>n;
  vector<int>resultat(n);
  back(resultat,0);
}
