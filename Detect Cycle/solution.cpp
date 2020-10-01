//function 
/*bool has_cycle(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && slow != NULL && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return 1;
        }
    }
    
    return 0;
}*/