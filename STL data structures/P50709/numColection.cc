#include <iostream>
#include <queue>
using namespace std;

int main(){
	char x;
	priority_queue<int> num;
	while (cin>>x){
		if (x=='S'){
			int a;
			cin>>a;
			num.push(a);
		}
		else if (x=='A'){
			if (num.empty()) cout<<"error!"<<endl;
			else cout<<num.top()<<endl;
		}
		else if (x=='R'){
			if (num.empty()) cout<<"error!"<<endl;
			else num.pop();
		}
		else if (x=='I'){
			if (num.empty()) cout<<"error!"<<endl;
			else{
				int a;
				cin>>a;
				a=num.top()+a;
				num.pop();
				num.push(a);
			}
		}
		else if (x=='D'){
			if (num.empty()) cout<<"error!"<<endl;
			else{
				int a;
				cin>>a;
				a=num.top()-a;
				num.pop();
				num.push(a);
			}
		}
	}
}
