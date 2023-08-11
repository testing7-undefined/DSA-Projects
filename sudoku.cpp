#include<bits/stdc++.h>
using namespace std;


bool isOk(vector<vector<int>> &v,int i,int j,int l){
    //checking row and column simultaneously
    for(int y=0;y<9;y++)if(v[i][y]==l || v[y][j]==l)return 0;

    i=i-i%3;j=j-j%3;

    //check sub matrix of 3 x 3
    for(int y=0;y<3;y++)for(int k=0;k<3;k++)if(v[i+y][j+k]==l)return 0;
    return 1;
}

void f(vector<vector<int>> &v,string &s){
    if(s=="11")return ;
    int i,j;
    for(i=0;i<9;i++){
	    int z=0;
        for(j=0;j<9;j++)if(v[i][j]==0){
		z=1;break;
	}
	if(z)break;
    }

    if(i>=9 && j>=9){s="11";return ;}

    for(int l=1;l<=9;l++){
        if(isOk(v,i,j,l)){
            v[i][j]=l;
            f(v,s);
           // cout<<"** // ";
        }
        if(s=="11")return ;
        else v[i][j]=0;
    }
}

//@1****34$1*

int main(){
    int t;cin>>t;
    while(t--){
        vector<vector<int>>v(9,vector<int>(9));
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)cin>>v[i][j];
        string s="00";
        f(v,s);

        if(s=="00"){
            cout<<"Lol! ,we regret to inform you that , there is no solution for your input ";return 0;
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)cout<<v[i][j]<<" ";
            cout<<"\n";
        }
    }
}
