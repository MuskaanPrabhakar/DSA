/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Step 1: Create new nodes and insert them next to original nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied list
        curr = head;
        Node* copyHead = head->next;
        Node* copyCurr = copyHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
    private:
    void insertattail(Node*&head,Node*&tail,int d){
        Node*newnode=new Node(d);
       if(head==NULL){
       head=newnode;
       tail=newnode;
       }
       else{
        tail->next = newnode;
        tail=newnode;
       }
    }
public:
    Node* copyRandomList(Node* head) {
        Node*clonehead=NULL;
         Node*clonetail=NULL;
         Node*temp=head;
         while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp=temp->next;
         }
         unordered_map<Node*, Node*>oldtonew;
         Node*originalnode=head;
         Node*clonenode=clonehead;
         while(originalnode!=NULL){
            oldtonew[originalnode]=clonenode;
            originalnode=originalnode->next;
            clonenode=clonenode->next;
         }
         originalnode=head;
         clonenode=clonehead;
          while(originalnode!=NULL){
            clonenode->random=oldtonew[originalnode->random];
             originalnode=originalnode->next;
            clonenode=clonenode->next;
          }
          return clonehead;
    }
};*/
