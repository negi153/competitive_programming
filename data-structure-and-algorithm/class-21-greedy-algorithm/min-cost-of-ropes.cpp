// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// Ques- we have n ropes with their specific length. we need to join all the ropes. to join 2 ropes with length 5m and 10m, 5+10=15ruppes will cost, find the minimum cost to join all the ropes

// logic - greedy
    // - store all the ropes in min heap(priority queue). 
    // - get top 2 ropes which has lowest lengths and delete from heap
    // - join those 2 ropes and push back to heap

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>, greater<int>> pq; // this is min heap
        // priority_queue<int> pq; // this is max heap by default
        
        // insert all elements into min heap
        for(auto x: arr)
            pq.push(x);
            
        //find the minimumn amount by greedy method
        int ans = 0;
        while(pq.size()>1){
            // get first 2 ropes and get the amount
            int firstRope = pq.top();
            pq.pop();
            int secondRope = pq.top();
            pq.pop();
            
            int amount = firstRope + secondRope;
            ans += amount;
            
            pq.push(amount); // add new rope to priority queue
        }
        
        return ans;
        
            
    }
};