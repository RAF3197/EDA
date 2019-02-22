#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void escriu(vector<int>& solucion,int tope,int x){
    cout<<x<<" = ";
    bool primer= true;
    for (int i=0;i<tope;i++){
        if (solucion[i]!=0){
            if (primer){
                primer= false;
                if (i%2!=0) cout<<solucion[i]<<'p';
                else cout<<solucion[i];
            }
            else {
                if (i%2!=0) cout<<" + "<<solucion[i]<<'p';
                else cout<<" + "<<solucion[i];
            }
        }
    }
    cout<<endl;
}

void back(int ite,int valor,int x,vector<int>& numeros,vector<int>& solucion){
    if (valor==x) escriu(solucion,ite,x);
    else if(ite<2*numeros.size()){//2*n pk es la medida maxima de la solucion
        if (valor<x){
            int aux=solucion[ite];
            solucion[ite]=numeros[ite/2];
            valor+=numeros[ite/2];
            back(ite+1,valor,x,numeros,solucion);
            valor-=numeros[ite/2];
            solucion[ite]=aux;
            back(ite+1,valor,x,numeros,solucion);
        }

    }
}

int main(){
    int x,n;
    while (cin>>x>>n){
        vector<int>numeros(n);
        for (int i=0;i<n;++i){
            cin>>numeros[i];
        }
        sort(numeros.begin(),numeros.end());
        //cada numero se puede usar 2 veces
        //->como maximo se usaran todos 2 veces
        vector<int>solucion(2*n);
        back(0,0,x,numeros,solucion);
        cout<<"----------"<<endl;
    }
}
