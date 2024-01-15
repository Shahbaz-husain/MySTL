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
    Node<T>* head;
    public : 
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

        // function to clone a linked list , it returns a new cloned LL
        Linked_list<T> clone() const
        {
            Linked_list<T> copied_ll;
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
