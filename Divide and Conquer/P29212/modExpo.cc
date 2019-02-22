#include <vector>
#include <iostream>
using namespace std;

void expo(int& n,int& k,int& m){
  int resultat=1;
  while(k!=0){
    if(k%2==0){
      k/=2;
      n=((n%m)*(n%m))%m;
    }
    else if(k%2!=0){
      --k;
      resultat=(resultat*n)%m;
    }
  }
  cout<<resultat<<endl;
}

int main(){
  int n,k,m;
  while (cin>>n>>k>>m){
    expo(n,k,m);
  }
}
