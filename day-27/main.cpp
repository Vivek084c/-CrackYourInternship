// Flattening a Linked List


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        // handling the edge case
        if (!root) return NULL;
        
        //declaring vector to store the data
        std::vector<int> numbers;
        Node* head = root;
        
        // traversing the data to collect data into numbers vector
        while (head != NULL){
            Node* t = head;
            while (t!=NULL){
                numbers.push_back(t->data);
                t = t->bottom;
            }
            head = head->next;
        }
        
        // sorting the given vector
        std::sort(numbers.begin(), numbers.end());
        // converting the given vector into linked list
        head = cvt(numbers);
        return head;
    }
    Node* cvt(const std::vector<int>& numbers){
        if (numbers.size() == 0){
            return NULL;
        }
        else{
            Node* head = new Node(numbers[0]);
            Node* temp = head;
            for( int i=1; i<numbers.size(); i++){
                Node* temphead = new Node(numbers[i]);
                head->bottom = temphead;
                head = head->bottom;
            }
            return temp;
        }
    }
};