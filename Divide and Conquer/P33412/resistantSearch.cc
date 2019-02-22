#include <iostream>
#include <vector>
using namespace std;

bool dico(double x,const vector<double>& v,int esq,int dre){
  if (dre<esq) return false;
  int m=(esq+dre)/2;
  double y=v[m];//Y==element k esta en m
  if (m<v.size()-1 and v[m+1]<y) y=v[m+1];
  if (m>0 and v[m-1]>y) y=v[m-1];
  if (y<x) return dico(x,v,m+1,dre);//aqui y es el element k tindria k anar a m;
  if (y>x) return dico(x,v,esq,m-1);
  return true;
}

bool resistant_search(double x, const vector<double>& v){
  return dico(x,v,0,v.size()-1);
}

int main(){}
