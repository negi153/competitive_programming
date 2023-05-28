
// this fucntion will chaeck if there is a circle in linked list or linkedlist is looped

bool checkCircular(node* head){
    unordered_map<node*,bool> vis;

    node* temp = head;
    while(temp! NULL){
        if(vis.find(temp)!= vis.end()){
            vis[temp] = true;
        }
        else{
            return true;
        }

        temp = temp->next;
    }

    return false;
}