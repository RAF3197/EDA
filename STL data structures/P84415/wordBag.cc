#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string,int> bossa;
	string a;
	while (cin>>a){
		if (a=="maximum?"){
			if (not bossa.empty()){
				auto it=bossa.end();
				--it;
				cout<<"maximum: "<<it->first<<", "<<it->second<<" time(s)"<<endl;
			}
			else cout<<"indefinite maximum"<<endl;
		}
		else if (a=="minimum?"){
			auto it=bossa.begin();
			if (it!=bossa.end()) cout<<"minimum: "<<it->first<<", "<<it->second<<" time(s)"<<endl;
			else cout<<"indefinite minimum"<<endl;
		}
		else if (a=="store"){
			auto it=bossa.begin();
			cin>>a;
			it=bossa.find(a);
			if (it!=bossa.end()) ++bossa[a];
			else bossa[a]=1;
		}
		else if (a=="delete"){
			auto it=bossa.begin();
			cin>>a;
			it=bossa.find(a);
			if (it!=bossa.end()){
				if (it->second==1) bossa.erase(it);
				else --it->second;
			}
		}
	}
}
