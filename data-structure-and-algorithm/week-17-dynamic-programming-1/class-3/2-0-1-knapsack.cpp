// 0/1 knapsack problem
// https://leetcode.com/discuss/post/1152328/01-knapsack-problem-and-dynamic-programm-4had/
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// problem - we have a bag of capacity c, we have an array of n elelents, each elelents has it's own vaule and weight. place elemnts in bag in such a way that value will be maxium and total wight of bag doesn't exceed capacity c.

// it follows include/exclude pattern

#include<iostream>
#include<vector>
using namespace std;

// here index is the index of last element , we are going from n to 0
int recursion(int weight[], int value[], int index, int capacity){
    // base case
    if (index == 0){ // if we are at first element
        
        // check if weight of first element is less than equal to capacity, then only it will get into bag, otherwise will not get into bag
        if (weight[index] <= capacity)
            return value[index];
        else
            return 0;
    }

    // include the last element if possible
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + recursion(weight,value,index-1,capacity-weight[index]);

    // exclude the element
    int exclude = 0 + recursion(weight,value,index-1,capacity);

    return max(include,exclude);

}

int  top_down_dp(int weight[], int value[], int index, int capacity, vector<vector<int> >& dp){
    // base case
    if (index == 0){ // if we are at first element
        
        // check if weight of first element is less than equal to capacity, then only it will get into bag, otherwise will not get into bag
        if (weight[index] <= capacity)
            return value[index];
        else
            return 0;
    }
    
    if (dp[index][capacity] != -1)
        return dp[index][capacity];
        
    // include the last element if possible
    int include = 0;
    if (weight[index] <= capacity)
        include = value[index] + top_down_dp(weight,value,index-1,capacity-weight[index],dp);

    // exclude the element
    int exclude = 0 + top_down_dp(weight,value,index-1,capacity,dp);
    
    dp[index][capacity] = max(include,exclude);
    return dp[index][capacity];

}

int bottom_up_dp(int weight[],int value[],int n, int capacity){
    vector<vector<int> > dp(n,vector<int>(capacity+1,-1));    
    
    // base
    for(int wt = 0;wt<=capacity; wt++){
        // check if weight of first element is less than equal to capacity, then only it will get into bag, otherwise will not get into bag
        if (weight[0] <= wt)
            dp[0][wt] = value[0];
        else
            dp[0][wt] = 0;
    }
    
    
    
    for(int index = 1;index <n;index++){
        
        for(int wt=0;wt<=capacity;wt++){
            
            int include = 0;
            if (weight[index] <= wt)
                include = value[index] + dp[index-1][wt-weight[index]];
        
            // exclude the element
            int exclude = 0 + dp[index-1][wt];
            
            dp[index][wt] = max(include,exclude);
            
        }
        
    }
    
    return dp[n-1][capacity];
    
}

   int space_optimize_dp(int weight[], int value[],int n, int capacity){
        // as bottom up approach depends on the previous row, then we only need previous and current array
        
        vector<int> prev(capacity+1,0);
        vector<int> curr(capacity+1,0);
        
        // base
        for(int wt = 0;wt<=capacity; wt++){
            // check if weight of first element is less than equal to capacity, then only it will get into bag, otherwise will not get into bag
            if (weight[0] <= wt)
                prev[wt] = value[0];
            else
                prev[wt] = 0;
        }
        
        
        for(int index = 1;index <n;index++){
            

            for(int wt=0;wt<=capacity;wt++){
                
                int include = 0;
                if (weight[index] <= wt)
                    include = value[index] + prev[wt-weight[index]];
            
                // exclude the element
                int exclude = 0 + prev[wt];
                
                curr[wt] = max(include,exclude);
               
            }
             prev = curr;
            
        }
        
        return curr[capacity];
        
    }

    int single_optimize_dp(int weight[], int value[],int n, int capacity){
        // here we are using previous array and current array in a single array.
        // so we are going from right to left, as our answer depends on the left side of the previous row.
        // so if we will go from right to left, we will not oveerride the old vlaue
        // as bottom up approach depends on the previous row, then we only need previous and current array
        
        vector<int> curr(capacity+1,0);
        
        // base
        for(int wt = 0;wt<=capacity; wt++){
            // check if weight of first element is less than equal to capacity, then only it will get into bag, otherwise will not get into bag
            if (weight[0] <= wt)
                curr[wt] = value[0];
            else
                curr[wt] = 0;
        }
        
        
        for(int index = 1;index <n;index++){
            

            for(int wt=capacity;wt>=0;wt--){
                
                int include = 0;
                if (weight[index] <= wt)
                    include = value[index] + curr[wt-weight[index]];
            
                // exclude the element
                int exclude = 0 + curr[wt];
                
                curr[wt] = max(include,exclude);
               
            }
            
        }
        
        return curr[capacity];
        
    }

int main(){

    int weight[] = {4,5,1};
    int value[] = {1,2,3};
    int n= 3;
    int capacity = 4;

    int ans = recursion(weight,value,n-1,capacity); // time - exponential
    cout<<"recursion ans: "<<ans<<endl;
    
    // dp[i][j] = maximum value of knapsack when elements are from 0 to i and capacity is j
    vector<vector<int> > dp(n,vector<int>(capacity+1,-1));
    int top_down_ans = top_down_dp(weight,value,n-1,capacity,dp); // time - o(elements * capacity), space - o(element * capacity)
    cout<<"top down DP : "<<top_down_ans<<endl;

    int bottom_up_ans = bottom_up_dp(weight,value,n,capacity); // time - o(element * capacity), sapce - o(element * capacity)
    cout<<"bottom up DP : "<<bottom_up_ans<<endl;
    
    int ans1 = space_optimize_dp(weight,value,n,capacity); // time - o(element * capacity), space - o(capcity)
    cout<<"space optimization : "<<ans1<<endl;

    // single array space optimizatrion
    int ans1 = single_optimize_dp(weight,value,n,capacity); // time - o(element * capacity), space - o(capcity)
    cout<<"space optimization : "<<ans1<<endl;

    return 0;

}