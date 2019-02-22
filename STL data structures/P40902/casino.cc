#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string,int> casino;
	string a;
	while (cin>>a){
		string b;
		cin>>b;
		if (b=="enters"){
			if (casino.find(a)==casino.end()) casino[a]=0;
			else cout<<a<<" is already in the casino"<<endl;
		}
		else if (b=="wins"){
			int x;cin>>x;
			if (casino.find(a)==casino.end()) cout<<a<<" is not in the casino"<<endl;
			else casino[a]=casino[a]+x;
		}
		else if (b=="leaves"){
			if (casino.find(a)==casino.end()) cout<<a<<" is not in the casino"<<endl;
			else {
				cout<<a<<" has won "<<casino[a]<<endl;
				casino.erase(a);
			}
		}
	}
	cout<<"----------"<<endl;
	map<string,int>::iterator it;
	for (it=casino.begin();it!=casino.end();++it){
		cout<<it->first<<" is winning "<<it->second<<endl;
	}
}
