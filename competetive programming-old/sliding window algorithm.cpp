//Q-> calculate subarray max for every subarray of size k in O(n). this is sliding window algorithm which uses
//deque

#include<bits/stdc++.h>

using namespace std;

const int N=1e5+7;
int A[N];
deque<pair<int,int> > dq;//deque stores first part as element and second part as index

void push(int i){
    //it maintains the property i.e deque is decreasing order
    while(!dq.empty()){
        if(dq.back().first < A[i])
            dq.pop_back();
        else
            break;

    }
    dq.push_back({A[i],i});//{} is making a pair
}

int query(int l,int r){
    while(!dq.empty()){
        if(dq.front().second < l)
            dq.pop_front();
        else
            break;
    }
    return dq.front().first;
}

int main(){
int n,k;

cout<<"enter no. of elements and size of subarray : ";
cin>>n>>k;
cout<<"enter elements : ";
for(int i=1;i<=n;i++)
    cin>>A[i];

for(int i=1;i<=k;i++){
    push(i);
}

int l=1,r=k;
cout<<query(l,r)<<" ";

for(r=k+1;r<=n;r++){
    l++;
    push(r);
    cout<<query(l,r)<<" ";
}


return 0;
}
