// this is similar to 0/1 knapsac but here we can takes partital values as well.
// logic - greedy
    // 1. sort the array in decreasing order by value/weight. (value/weight means price of 1 weight)
    // 2. iterate on sorted array, 
    //     - if current weight is <= capacity, then include it and add value in answer
    //     - if current weight is > capacity, then we can only include capacity amount of value in knapsack

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){

    int ratio1 = ((a.first * 1.0) / a.second);
    int ratio2 = ((b.first * 1.0) / b.second);

    return ratio1 > ratio2;

}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int n=3,capacity = 50;

    vector<pair<int,int>> data;
    for(int i=0;i<n;i++){
        data.push_back({val[i],wt[i]});
    }

    // sort the data based on value/weight ratio in decreasing order. value/weight is the value of weight 1
    sort(data.begin(),data.end(),cmp);

    int ans = 0;
    for(int i=0;i<n;i++){
        int value = data[i].first;
        int weight = data[i].second;

        if(weight <= capacity){
            ans += value;
            capacity -= weight;
        }
        else{
            ans += ((value * 1.0)/ weight) * capacity;
            capacity = 0;
            break;
        }
    }

    cout<<"Fractional kanpsack maximum value : "<<ans<<endl;
    return 0;
}