// https://www.spoj.com/problems/DEFKIN/
//logic - 
    // 1. store the row index of the towers in vector
    // 2. store the col index of towers in vector
    // 3. sort both the vector
    // 4. find the nuber of cells between consecutive towers and find the max in row and column
    // 5. find the area

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int main (){
    int n,m,k;
    cin>>n>>m>>k;

    // below are input values
    // 15 8 3
    // 3 8
    // 11 2
    // 8 6 

    vector<int> row;
    vector<int> col;


    row.push_back(-1);
    col.push_back(-1);
    while(k--){
        int a,b;
        cin>>a>>b;
        row.push_back(a);
        col.push_back(b);
    }
    row.push_back(n+1);
    col.push_back(m+1);

  sort(row.begin(),row.end());
  sort(col.begin(),col.end());

    // find the maxlength
    int maxLen = INT_MIN;
    for(int i=1;i<row.size();i++){
        maxLen = max(maxLen,row[i]-row[i-1]-1); // distance between 3 and 5 = 5-3+1
    }

    // find the maxHeight
    int maxHeight = INT_MIN;
    for(int i=1;i<col.size();i++){
        maxHeight = max(maxHeight,col[i]-col[i-1]-1); // distance between 3 and 5 = 5-3+1
    }

    cout<<maxLen<<" "<<maxHeight<<endl;
    cout<<"max area is : "<<maxLen * maxHeight<<endl;
    return 0;
}