#include<bits/stdc++.h>
using namespace std;
int n;
map<string,string> m;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s,t;
		cin>>s>>t;
		if(m[s]!="")m[t]=m[s];
		else m[t]=s;
		//m.erase(s);
	}
	cout<<m.size()<<endl;
	for(auto i:m)cout<<i.second<<" "<<i.first<<endl;
}