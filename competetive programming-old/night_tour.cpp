#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
int n;
int board[10][10];

void printBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool check(int r,int c){
if(r<0 || r>=n || c<0 ||c>=n || board[r][c]!=0)
    return false;
return true;
}

bool knight_tour(int row,int col,int mov){
    if(mov==n*n)
        return true;

    int rdir[8]={+2,+1,-1,-2,-2,-1,+1,+2};
    int cdir[8]={+1,+2,+2,+1,-1,-2,-2,-1};

    for(int i=0;i<8;i++){
        int newrow=row+rdir[i];
        int newcol=col+cdir[i];

        if(check(newrow,newcol)==true){
            board[newrow][newcol]=mov+1;
            //system("CLS");
            //printBoard();
            bool ans=knight_tour(newrow,newcol,mov+1);
            if(ans==true)
                return true;
            board[newrow][newcol]=0;
        }
    }
    return false;
}

int main(){

cout<<"enter the dimension of square matrix : ";
cin>>n;

board[0][0]=1;
if(knight_tour(0,0,1))
    printBoard();
else
    cout<<"not possible";


return 0;
}
