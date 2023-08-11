#include<bits/stdc++.h>
using namespace std;

bool isOk(vector<vector<int>> &a,int i,int j,int l){
for(int x=0;x<3;x++)if(a[i][x]==l || a[x][j]==l)return 0;
return 1;
}

void f(vector<vector<int>> &a,string &s){
	//cout<<"$ ";
if(s=="11")return ;
int i,j;
for(i=0;i<3;i++){
	int z=0;
	for(j=0;j<3;j++)if(a[i][j]==0){
		z=1;break;
	}
	if(z)break;
}
if(i>=3 && j>=3){
    s="11";return ;
}
//cout<<i<<" "<<j<<" \n";
for(int l=1;l<=3;l++){
    if(isOk(a,i,j,l)){
        a[i][j]=l;
        f(a,s);
    }
    if(s=="11")return;
    else a[i][j]=0;
}

}


int main(){
    int n;cin>>n;
    vector<vector<int>>a(3,vector<int>(3));
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>a[i][j];
    //for(int i=0;i<3;i++)for(int j=0;j<3;j++)cout<<a[i][j]<<" ";
    string s="00";
    f(a,s);
    if(s=="00"){cout<<"Lol we regret to infrom to you! that , there is no answer Bro !!!";return 0;}
    for(int i=0;i<3;i++){
    	for(int j=0;j<3;j++)cout<<a[i][j]<<" ";
    	cout<<"\n";
    }
}
