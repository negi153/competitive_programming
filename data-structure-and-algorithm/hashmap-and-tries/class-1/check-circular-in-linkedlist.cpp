
// to check if linked list has loop, store each node in map, if new nodes is already presnet in map, then it has loop
bool checkCircular(Node* head){

    unordered_map<Node* , bool> vis;

    Node* temp = head;

    while(temp != NULL){
        
        // if node is not present in map, then insert it
        if(vis.find(temp) != vis.end())
            vis[temp] = true;
        else
            return true; // if node is prensent in map, then loop is there 

        temp = temp->next;
    }

    return false; // loop is not present

}