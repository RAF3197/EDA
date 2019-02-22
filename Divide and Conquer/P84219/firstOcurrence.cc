#include <iostream>
#include <vector>
using namespace std;

int dico(double x,const vector<double>& v,int esq,int dre){
  if(dre<esq)return -1;
  int m=(esq+dre)/2;
  if(v[m]<x)return dico(x,v,m+1,dre);
  if(v[m]>x)return dico(x,v,esq,m-1);
  if (v[m]==x){
    int aux=dico(x,v,esq,m-1);
    if(aux==-1)return m;
  }
}

int first_occurrence(double x, const vector<double>& v){
  return dico(x,v,0,v.size()-1);
}

int main(){
  int n;cin>>n;
  vector<double> v(n);
  for(int i=0;i<n;++i){
    cin>>v[i];
  }
  int x;cin>>x;
  int r=first_occurrence(x,v);
  cout<<r<<endl;
}
