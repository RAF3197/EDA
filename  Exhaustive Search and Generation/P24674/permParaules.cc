#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<string>& resultat){
  for(int i=0;i<resultat.size();++i){
    if (resultat.size()==1 and i==0)cout<<"("<<resultat[i]<<")"<<endl;
    else if (i==0)cout<<"("<<resultat[i]<<",";
    else if (resultat.size()-1==i)cout<<resultat[i]<<")"<<endl;
    else cout<<resultat[i]<<",";
  }
}

void back(int q,vector<string>& resultat,const vector<string>& paraules,vector<bool>& visitats){
  if (resultat.size()==q) escriu(resultat);
  else{
    for (int i=0;i<resultat.size();++i){
      if (not visitats[i]){
        visitats[i]=true;
        resultat[i]=paraules[q];
        back(q+1,resultat,paraules,visitats);
        visitats[i]=false;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<string>paraules(n);
  for (int i=0;i<n;++i){
    cin>>paraules[i];
  }
  vector<string>resultat(n);
  vector<bool>visitats(n,false);
  back(0,resultat,paraules,visitats);
}
