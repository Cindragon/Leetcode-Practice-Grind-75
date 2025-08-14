class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    MyLinkedList() {
        dummyhead=new LinkedNode(0);
        size=0;
    }
    
    int get(int index) {
        if(index>size-1||index<0){
            return -1;
        }
        LinkedNode* curr=dummyhead->next;
        while(index--){
            curr=curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* ptr=new LinkedNode(val);
        ptr->next=dummyhead->next;
        dummyhead->next=ptr;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* curr=dummyhead;
        LinkedNode* ptr=new LinkedNode(val);
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size || index<0)  return;
        LinkedNode* ptr=new LinkedNode(val);
        LinkedNode* curr=dummyhead;
        while(index--){
            curr=curr->next;
        }
        ptr->next=curr->next;
        curr->next=ptr;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0) return;
        LinkedNode* curr=dummyhead;
        while(index--){
            curr=curr->next;
        }
        LinkedNode*temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
        temp=NULL;
        size--;
    }
private:
    int size;
    LinkedNode* dummyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */