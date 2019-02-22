#include <vector>
#include <iostream>
using namespace std;

void escriure(vector<bool>& sumat,vector<int>& numeros){
  bool first=true;
  cout<<"{";
  for (int i=0;i<numeros.size();++i){
    if(sumat[i] and first){
      cout<<numeros[i];
      first=false;
    }
    else if(sumat[i] and not first){
      cout<<","<<numeros[i];
    }
  }
  cout<<"}"<<endl;
}

void back(vector<int>& numeros,int q,vector<bool>& sumat,int x,int suma){
  if(q==numeros.size()){
    if(suma==x){
      escriure(sumat,numeros);
    }
  }
  else{
    sumat[q]=false;
    back(numeros,q+1,sumat,x,suma);
    sumat[q]=true;
    back(numeros,q+1,sumat,x,suma+numeros[q]);
    sumat[q]=false;
  }
}


int main(){
  int x;cin>>x;
  int n;cin>>n;
  vector<int> numeros(n);
  for(int i=0;i<n;++i){
    cin>>numeros[i];
  }
  int q=0;
  vector<bool> v(n,false);
  back(numeros,q,v,x,0);
}
