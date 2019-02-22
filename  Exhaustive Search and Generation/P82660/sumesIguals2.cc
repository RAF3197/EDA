#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int i,int j){
  return j<i;
}

void escriure(const vector<int>& num,const vector<bool>& sumat){
  bool first=true;
  cout<<"{";
  for (int i=0;i<num.size();++i){
    if (sumat[i] and first){
       cout<<num[i];
       first=false;
     }
    else if (sumat[i] and not first) cout<<","<<num[i];
  }
  cout<<"}"<<endl;
}

void back(bool& stop,vector<int>& num,int ite,vector<bool>& sumat,int x,int suma){
  if (ite==num.size() and not stop){
    if (suma==x){
      escriure(num,sumat);
      stop=true;
    }
  }
  else if (not stop){
    sumat[ite]=true;
    back(stop,num,ite+1,sumat,x,suma+num[ite]);
    sumat[ite]=false;
    back(stop,num,ite+1,sumat,x,suma);
  }
}


int main(){
  int x;cin>>x;
  int n;cin>>n;
  vector<int> num(n);
  for(int i=0;i<n;++i){
    cin>>num[i];
  }
  sort(num.begin(),num.end(),comp);
  int ite=0;
  vector<bool> v(n,false);
  bool stop=false;
  back(stop,num,ite,v,x,0);
  if (stop==false){
    cout<<"no solution"<<endl;
  }
}
