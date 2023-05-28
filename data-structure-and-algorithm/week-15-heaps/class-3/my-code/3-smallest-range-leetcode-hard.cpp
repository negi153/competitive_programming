// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
class node{
    public:

    int data;
    int row;
    int col;
    node(int data,int row, int col){
        this->data = data;
        this->row=row;
        this->col=col;

    }
};

class compare{
  public:
    bool operator()(node* a, node* b){
      return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini = INT_MAX;
        int maxy = INT_MIN;

        priority_queue<node*, vector<node*>,compare> minHeap;

        int k=nums.size();

        for(int i=0;i<k;i++){
            int element = nums[i][0];
            maxy= max(maxy,element);
            mini=min(mini,element);

            minHeap.push(new node(element,i,0));
        }        


        int ansStart=mini;
        int ansEnd=maxy;

        while(!minHeap.empty()){
            node* top = minHeap.top();
            int topelement = top->data;
            int topRow = top->row;
            int topCol = top->col;

            minHeap.pop();

            //update mini
            mini = topelement;

            // check range
            if(maxy - mini < ansEnd - ansStart){
                ansStart = mini;
                ansEnd = maxy;
            }

            // check for new element in the same list
            if(topCol + 1 < nums[topRow].size()){
                
                maxy = max(maxy,nums[topRow][topCol+1]);

                node* newNode = new node(nums[topRow][topCol+1],topRow, topCol+1);
                minHeap.push(newNode);

            }
            else{
                    // if there is no element in the same array then break as 
                    // we found the range which contains atleast 1 element from each array
                break;
            }

        }


    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
    }
};