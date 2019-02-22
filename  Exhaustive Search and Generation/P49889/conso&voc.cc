#include <iostream>
#include <vector>
using namespace std;

void escriure(const vector<char>& aux){
  for (int i=0;i<aux.size();++i){
    cout<<aux[i];
  }
  cout<<endl;
}

void back(vector<char>& vocal,vector<char>& conso,int ite,vector<char>& aux,vector<bool>& con_vist,vector<bool>& voc_vist){
  //cout<<ite<<endl;
  if (ite==conso.size()){
    escriure(aux);
  }
  else{
      for (int i=0;i<conso.size();++i){
        if (not con_vist[i]){
          con_vist[i]=true;
          aux[2*ite]=conso[i];
          for (int j=0;j<vocal.size();++j){
            if (not voc_vist[j]){
            voc_vist[j]=true;
            aux[(2*ite)+1]=vocal[j];
            back(vocal,conso,ite+1,aux,con_vist,voc_vist);
            voc_vist[j]=false;
          }
        }
        con_vist[i]=false;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<char>conso(n);
  for (int i=0;i<n;++i){
    char x;
    cin>>x;
    conso[i]=x;
  }
  vector<char> vocal(n);
  for (int i=0;i<n;++i){
    char x;
    cin>>x;
    vocal[i]=x;
  }
  int ite=0;
  vector<char>aux(2*n);
  vector<bool>con_vist(n,false);
  vector<bool>voc_vist(n,false);
  back(vocal,conso,ite,aux,con_vist,voc_vist);
}
