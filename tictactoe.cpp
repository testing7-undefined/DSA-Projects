#include<bits/stdc++.h>
using namespace std;

bool isWin(vector<vector<int>> &v,int n,int l,int r){
    int z=0;
    //checking row
    for(int i=0;i<3;i++)if(v[l][i]==n)z++;
    if(z==3)return 1;
    z=0;

    //checking column
    for(int i=0;i<3;i++)if(v[i][r]==n)z++;
    if(z==3)return 1;
    z=0;

    //checking left diagonal
    for(int i=0;i<3;i++)if(v[i][i]==n)z++;
    if(z==3)return 1;
    z=0;

    //checking right diagonal
    for(int i=0;i<3;i++)if(v[i][2-i]==n)z++;
    if(z==3)return 1;

    return 0;

}

void print(vector<vector<int>> &v){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(v[i][j]==1)cout<<"X ";
            else if(v[i][j]==-1)cout<<"O ";
            else cout<<"  ";
            if(j<2)cout<<"| ";
        }
        cout<<"\n";
        if(i<2)for(int j=0;j<3;j++)cout<<"---";
        cout<<"\n";
    }
}

bool input(vector<vector<int>> &v,int n){
	//cout<<"$ ";
	if(n%2)cout<<"Player 1 move : X \n";
	else cout<<"Player 2 Move : O \n";
    int l,r;cin>>l>>r;
    cout<<"\n";
    if(v[l][r]!=0){
        cout<<"try again with valid box : \n";
        print(v);
        return input(v,n);
    }
    if(n%2)v[l][r]=1;
    else v[l][r]=-1;

    if(isWin(v,v[l][r],l,r)){
    	if(v[l][r]==1)cout<<"Player 1 was won the game \n\n";
    	else cout<<"Player 2 was won the game \n\n";
    	return 1;
    }
    return 0;
}

int main(){

vector<vector<int>>v(3,vector<int>(3));
int n=9;
print(v);
for(n=1;n<=9;n++){
	//cout<<"k  ";
	int z=input(v,n);
    if(z){
    	print(v);
    	return 0;
    }
    print(v);
}
cout<<"\n It's a draw , try again \n ";
}
