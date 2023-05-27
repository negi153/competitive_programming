hard leetcode - https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class compare{
  public:
    bool operator()(ListNode* a, ListNode* b){
      return a->val > b->val;
    }
};


class Solution {
public:

  ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap; // create min heap

  // insert first element of each array in min heap
  for(int i=0;i<lists.size();i++){
      if(lists[i]!=NULL)
        minHeap.push(lists[i]);
  }

    ListNode* head = NULL;
    ListNode* tail= NULL;

  while(!minHeap.empty()){ // untill heap is empty, insert value, row and col in heap
    ListNode* temp = minHeap.top();
    
    minHeap.pop(); // pop top element

    if(head==NULL){
        head = temp;
        tail = temp;
    }
    else
        {
            tail->next = temp;
            tail = temp;
        }

    if(tail->next != NULL){ // if element exist in same array, insert that in array
        minHeap.push(tail->next);
    }

  }

  return head;

    }
};