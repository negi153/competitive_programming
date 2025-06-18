// we have arrivaal and departure time of a train. we have only 1 platform. how many trains we can support on our platform
//logic - 
    // 1. sort the trains by departture time in ascending order.
    // 2. take train by greedy approach if it's arrival time >= departure time of previous train

    // this will give the non-overlapping intervals

    // - why sorting by departure time works ? 
    //     - You want to select the maximum number of non-overlapping intervals (train schedules here).

    //     - To achieve this, you sort by the earliest possible finish time (departure) to leave the platform free for as many future trains as possible.

    //     - By always picking the train that frees the platform earliest, you maximize the number of future compatible trains.

    // - why sorting by arrival time fails?
    //     - If you sort by  arrival time, you're not considering how long a train occupies the platform. A train that arrives early but departs late could block shorter trains that could have fit in otherwise.

    // time - nlogn

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
void solve(int n,int arr[],int dept[]){
    vector<pair<int,int>> data;
    for(int i=0;i<n;i++)
        data.push_back({arr[i],dept[i]});

    sort(data.begin(),data.end(),cmp);

    int cnt= 1; // take first train
    int lastDept= data[0].second;
    for(int i=1;i<n;i++){
        if(data[i].first >= lastDept) // check if arriaval time of current train is >= departure time of previous train
            {
                cnt++; // current train can be included
                lastDept=data[i].second;
            }
    }

    cout<<"number of train - "<<cnt;
}

int main(){
    int n=4;
    int a[]={5,8,2,4};
    int b[] = {7,11,6,5};

    solve(n,a,b);
}
