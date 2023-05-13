#include<bits/stdc++.h>
using namespace std;

//range query sum

const int maxx =1e6+1;
int a[maxx];
vector<int> blocks(1000);//every block will store sum of sqrt(n) elements
int no_of_blocks,n,block_size;

void preprocessing(){

    block_size=sqrt(n);
    no_of_blocks=int(n/block_size)+1;

    for(int i=0;i<n;i++){
        blocks[i/block_size]+=a[i];
    }

    /*
    cout<<no_of_blocks<<endl;
    for(int i=0;i<no_of_blocks;i++)
        cout<<blocks[i]<<" ";
    */

}

int query(int l,int r){

    int sum=0;
    int block_start=l/block_size,block_end=r/block_size;

    //if block_start and block_end are from same block then directly loop in array a
    if(block_start==block_end){
        for(int i=l;i<=r;i++)
            sum+=a[i];

        return sum;
    }

    //middle blocks sum
    for(int i=block_start+1;i<block_end;i++)
        sum+=blocks[i];

    //left side sum from l to end of start block
    int right_indx=block_start*block_size+block_size-1;
    for(int i=l;i<=right_indx;i++)
        sum+=a[i];

    //right side sum from start of block_end to r
    int left=block_end*block_size;
    for(int i=left;i<=r;i++)
        sum+=a[i];

    return sum;
}

void update(int ind,int val){

    int block_indx=ind/block_size;
    blocks[block_indx]=blocks[block_indx]-a[ind]+val;

    a[ind]=val;

}

int main(){

cout<<"enter size of array : ";
cin>>n;

cout<<"enter elements of array : \n";
for(int i=0;i<n;i++)
    cin>>a[i];

preprocessing();

/*
int q;
cout<<"enter no. of queries : ";
cin>>q;

cout<<"for every query enter L and R index :\n";
while(q--){

    int l,r;
    cin>>l>>r;
    cout<<query(l,r)<<endl;

}
*/

for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        cout<<i<<" "<<j<<" "<<query(i,j)<<endl;
    }
}

return 0;
}
