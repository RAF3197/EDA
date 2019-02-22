#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& resultat){
  for(int i=0;i<resultat.size();++i){
    if (i==0 and resultat.size()==1) cout<<"("<<resultat[i]<<")"<<endl;
    else if (i==0)cout<<"("<<resultat[i]<<",";
    else if (i==resultat.size()-1)cout<<resultat[i]<<")"<<endl;
    else cout<<resultat[i]<<",";
  }
}

void back(vector<int>& resultat,int q,vector<bool>& visitats){
  if (resultat.size()==q)escriu(resultat);
  else{
    for (int i=0;i<resultat.size();++i){
      if (not visitats[i]){
        visitats[i]=true;
        resultat[q]=i+1;
        back(resultat,q+1,visitats);
        visitats[i]=false;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int>resultat(n);
  vector<bool>visitats(n,false);
  back(resultat,0,visitats);
}
