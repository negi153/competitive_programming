//implementation of ordered_set--policy based data structure

#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int main(){

cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);

ordered_set s;
s.insert(3);
s.insert(2);
s.insert(6);

/*
ordered_set :: iterator it;
for(it=s.begin();it !=s.end();it--){
    cout<<*it<<" ";
}
*/

/*
for(int i=0;i<s.size();i++){
    cout<<*(s.find_by_order(i))<<" ";
}
*/

//finding 2nd smallest element
cout<<"2nd smallest element in ordered set : "<<*(s.find_by_order(1))<<endl;
//find no. of elements strictly less than 5
cout<<"no. of elements strictly less than 5 :"<<s.order_of_key(5)<<endl;

if(s.find(6) != s.end()){
    s.erase(6);
    cout<<"6 deleted";
}
else
    cout<<"not present";

return 0;
}

