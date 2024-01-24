#include <iostream>
template <typename T> 
class Node
{
    public:
        T data;
        Node<T>* next;
        Node() : data(0),next(nullptr) {}
        Node(T data) : data(data), next(nullptr) {}

};

template <typename T> 
class Linked_list
{
    public : 
        Node<T>* head;
        Linked_list() : head(nullptr) {}
        Linked_list(T data) : head(new Node<T>(data)) {}


        // function to insert an element at the begin
        void insert_at_begin(T data){
            Node<T>* new_node = new Node<T>(data);
            new_node->next = head;
            head = new_node;
        }


        // function to insert a node at the end of the linked list
        void insert_at_end(T data){
            Node<T>* new_node = new Node<T>(data);
            if(head == nullptr){
                head = new_node;
                new_node->next = nullptr;
                return;
            }
            Node<T>* iter = head;
            while(iter->next != nullptr)
            {
                iter = iter->next;
            }
            iter->next = new_node;
            new_node->next = nullptr;
        }


        // function to insert a node at a specific index
        void insert_at(long index, T data)
        {
            if(index == 0)
            {
                this->insert_at_begin(data);
            }
            else{
                Node<T>* new_node = new Node<T>(data);
                Node<T>* iter = head;
                for(long i = 1; i < index ; ++i)
                {
                    iter = iter->next;
                }
                new_node->next = iter->next;
                iter->next = new_node;
            }
            
        }


        // function to traverse the linked list
        void traverse_linked_list() const{
            if(head != nullptr){
                Node<T>* iter = head;
                while(iter != nullptr)
                {
                    std :: cout << iter->data << std :: endl;
                    iter = iter->next;
                }
            }
            else{
                std :: cout << "List is Empty" << std :: endl;
            }
            std :: cout << '\n';
        }


        // function to traverse the linked list in reverse
        void traverse_in_reverse(Node<T>* head) const{
            if(head == nullptr)
                return;
            traverse_in_reverse(head->next);
            std :: cout << head->data << std :: endl;
        }


        // function to clone a linked list , it returns a new cloned LL
        Linked_list<T> clone() const
        {
            Node<T> copied_ll;
            if (head == nullptr)
                return copied_ll;
            Node<T>* current = head;
            while(current != nullptr)
            {
                copied_ll.insert_at_end(current->data);
                current = current->next;
            }
            return copied_ll;
        } 


        // function to delete a particular node
        void delete_el(T data)
        {
            if(head == nullptr){
                std :: cout << "List is Empty!!" << '\n';
                return;
            }
            Node<T>* prev = nullptr;
            Node<T>* iter = head;
            while(iter != nullptr)
            {
                if(iter->data == data)
                {
                    if(prev == nullptr)   // when prev is null indicating deleting first node itself
                    {
                        head = iter->next;
                        delete iter;
                    }
                    else{
                        prev->next = iter->next;
                        delete iter;
                    }
                }
                prev = iter;       // storing previous node
                iter = iter->next; // moving one step
            }
        }


        // function to delete from start
        void delete_from_begin()
        {
            if(head == nullptr)
                std :: cout << "List is already empty" << '\n';
            else
            {
                Node<T>* begin = head;
                head = begin->next;
                delete begin;
            }
        }


        // function to delete from end
        void delete_from_end()
        {
            if(head == nullptr)
                std :: cout << "List is already empty" << '\n';
            else
            {
                Node<T>* iter = head;
                Node<T>* prev = nullptr;
                if(head->next == nullptr)
                {
                    prev = head;
                    delete prev;
                    head = nullptr;
                }
                while(iter->next != nullptr)
                {
                    prev = iter;
                    iter = iter->next;
                }
                prev->next = nullptr;
                delete iter;
            }
        }

        // functions to remove the duplicate Nodes from the sorted linked list
        void removeDuplicates() {
            if (head != nullptr)
            {
                Node<T>* curr = head;
                Node<T>* prev = head;
                while (curr != nullptr) {
                    prev = curr;
                    curr = curr->next;

                    // Check if curr is not nullptr before accessing its data
                    if (curr != nullptr and curr->data == prev->data) {
                        Node<T>* temp = curr;
                        prev->next = curr->next;
                        curr = prev; // Reset curr to prev to recheck for consecutive duplicates
                        delete temp;
                    }
                }
            }
        }


        // get a node data of nth node from the tail
        T getNode(Node<T>* head, int positionFromTail) {
            if (head == nullptr or positionFromTail < 0)
                return -1;
            
            Node<T>* curr = head;
            Node<T>* next = nullptr;
            Node<T>* prev = nullptr;
            while(curr != nullptr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            Node<T>* tail = prev;
            int j = 0;
            while(j<positionFromTail and tail != nullptr){
                tail = tail->next;
                j++;
            }
            if(tail == nullptr)
                return -1;
            return tail->data;
        }


        // function to compare two linked lists
        bool compare_lists(Node<T>* head1, Node<T>* head2) {
            Node<T>* iter1 = head1;
            Node<T>* iter2 = head2;
            while(iter1 != nullptr and iter2!= nullptr){
                if(iter1->data != iter2->data)
                    return 0;
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
            return iter1 == nullptr && iter2 == nullptr;
        }

        //operator overriding to compare two lists
        bool operator == (Node<T>* head1, Node<T>* head2) {
            Node<T>* iter1 = head1;
            Node<T>* iter2 = head2;
            while(iter1 != nullptr and iter2!= nullptr){
                if(iter1->data != iter2->data)
                    return 0;
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
            return iter1 == nullptr && iter2 == nullptr;
        }


        // function to reverse the linked list
        void reverse()
        {
            if (head == nullptr)
                std :: cout << "List is Empty!!" << '\n';
            else
            {
                Node<T>* prev = nullptr;
                Node<T>* next_node = nullptr;
                Node<T>* current = head;
                while(current != nullptr)
                {
                    next_node = current->next;  // saving next node
                    current->next = prev;       // reversing the links
                    prev = current;             // moving prev
                    current = next_node;        // moving current
                }
                head = prev;
            }
            
        }

        //function to merge to sorted linked lists which returns a new head pointer
        Node<T>* mergeLists(Node<T>* head1, Node<T>* head2) {
            if (head1 == nullptr) {
                return head2;
            }
            if (head2 == nullptr) {
                return head1;
            }

            // Determine the head of the merged list
            Node<T>* head = (head1->data < head2->data) ? head1 : head2;
            Node<T>* current = head;

            // Move to the next node in the selected list
            (head == head1) ? (head1 = head1->next) : (head2 = head2->next);

            // Iterate while both lists have elements
            while (head1 != nullptr && head2 != nullptr) {
                // Compare the values of the current nodes in both lists
                if (head1->data < head2->data) {
                    current->next = head1;
                    head1 = head1->next;
                } else {
                    current->next = head2;
                    head2 = head2->next;
                }

                // Move the current pointer to the last node in the merged list
                current = current->next;
            }

            // If one list is not empty, append the remaining nodes to the merged list
            current->next = (head1 != nullptr) ? head1 : head2;

            return head;
        }

        //boolean function to check whether there's a cycle in linked list or not
        bool has_cycle(Node<T>* head) {
            if(head == nullptr)
                return false;
            Node<T>* fast = head;
            Node<T>* slow = head;
            while(fast!= nullptr and fast->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)
                    return true;
                
            }
            return false;
        }


        // function to return merging node of 2 merged Linked Lists
        T findMergeNode(Node<T>* head1, Node<T>* head2) {
            Node<T>* iter1 = head1;
            Node<T>* iter2 = head2;
            while(iter1 != iter2){
                if(iter1 == nullptr)
                    iter1 = head1;
                else
                    iter1 = iter1->next;
                    
                if(iter2 == nullptr)
                    iter2 = head2;
                else
                    iter2 = iter2->next;
                    
                if (iter1 == nullptr && iter2 == nullptr) {
                    break;
                }
            }
            
            if(iter1 != nullptr)
                return iter1->data;
            return -1;
        }


        // Destructor to free allocated memory
        ~Linked_list() {
            Node<T>* current = head;
            while (current != nullptr) {
                Node<T>* next_node = current->next;
                delete current;   // deleting all dynamically created nodes
                current = next_node;
            }
        }

};
