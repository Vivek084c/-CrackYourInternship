// 138. Copy List with Random Pointer

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
        // creating a hash map for mapping
        std::unordered_map<Node*, Node*> hashMap;
        // maping the null value to null
        hashMap[NULL] = NULL;
        // getting the head of the lsit
        Node* cur = head;
        while (cur != nullptr){
            // creating a copy of the node
            Node* newNode = new Node(cur->val);

            //adding this node to hashmap
            hashMap[cur] = newNode;
            cur = cur->next;
        }

        cur = head;
        while (cur != nullptr){
            Node* copyNode = hashMap[cur];
            copyNode->next = hashMap[cur->next];
            copyNode->random = hashMap[cur->random];
            cur = cur->next;
        }

        return hashMap[head];
    }
};