#include <iostream>

template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : next(nullptr),prev(nullptr) {}
    Node(T data) : data(data),next(nullptr),prev(nullptr) {}
};

template <typename T>
class Doubly_linked_list
{
    Node<T>* head;
    Node<T>* tail;
    long count = 0;
    public:
        Doubly_linked_list() : head(nullptr),tail(nullptr) {}
        Doubly_linked_list(T data): head(new Node<T>(data)), tail(head) {
            head->prev = nullptr;
            head->next = nullptr;
            count++;
        }


        // function to insert an element at the beginning
        void insert_at_begin(T data)
        {
            Node<T>* new_node = new Node<T>(data);
            count++;
            if(head == nullptr)
            {
                head = new_node;
                tail = new_node;   
            }
            else if(head == tail){
                new_node->next = tail;
                head = new_node;
                tail->prev = new_node;
            }
            else{
                new_node->next = head;
                head = new_node;
            }
        }


        // function to insert an element at the end
        void insert_at_end(T data)
        {
            Node<T>* new_node = new Node<T>(data);
            count++;
            if(head == nullptr){
                head = new_node;
                tail = new_node;
            }
            else if(head == tail){
                head->next = new_node;
                tail = new_node;
                tail->prev = head;
            }
            else{
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }


        // function to insert an element at the given index
        void insert_at(long index, T data)
        {
            if(index > count){
                throw std::out_of_range("Index out of range.");
            }
            else{
                Node<T>* new_node = new Node<T>(data);
                Node<T>* iter = head;
                count++;
                for(long i = 1; i<index; ++i)
                {
                    iter = iter->next;
                }
                new_node->next = tail;
                tail->prev = new_node;
                iter->next = new_node;
                new_node->prev = iter;
            }
        }


        // To traverse a doubly linked list
        void traverse_doubly_linked_list()
        {
            if(head == nullptr){
                std :: cout << "List is Empty" << std :: endl;
                return;
            }

            if(head == tail)
            {
                std :: cout << head->data << std :: endl;
                return;
            }

            Node<T>* iter = head;
            while(iter != nullptr)
            {
                std :: cout << iter->data << " ";
                iter = iter->next;
            }
            std :: cout << std :: endl;
        }


        // To traverse a doubly linked list in reverse order
        void reverse_traverse_doubly_linked_list()
        {
            if(head == nullptr){
                std :: cout << "List is Empty" << std :: endl;
                return;
            }

            if(head == tail)
            {
                std :: cout << head->data << std :: endl;
                return;
            }

            Node<T>* iter = tail;
            while(iter != nullptr)
            {
                std :: cout << iter->data << " ";
                iter = iter->prev;
            }
            std :: cout << std :: endl;
        }


        // function to add a new_node in sorted order
        void sortedInsert(T data) {
            Node<T>* new_node = new Node<T>(data);
            // Handling empty LL and only one element LL cases
            if(head == nullptr || head -> data > data){
                new_node -> next = head;
                if(head != nullptr)
                {
                    head->prev = new_node;
                }
                head = new_node;
            }

            Node<T>* iter = head;

            // Loop will continue until either iter reaches the last element or iter's next elements value is greater than new data
            while(iter->next!= nullptr and iter->next->data < data)
            {
                iter = iter->next;
                // cout << iter->data << endl;
            }

            // Handling the case if iter->next is not nullptr
            if (iter->next != nullptr) {
                new_node->next = iter->next;
                iter->next->prev = new_node;
            }
            iter->next = new_node;
            new_node->prev = iter;
        }


        // Reverse a doubly linked list (Note : Make a clone first of the original LL)
        void reverse() {
            if(head == nullptr or head->next == nullptr)
                return;
            Node<T>* iter = head;
            Node<T>* temp = nullptr;
            while(iter != nullptr){
                temp = iter->prev;
                iter->prev = iter->next;
                iter->next = temp;
                
                temp = iter;
                iter = iter->prev; 
            }
            
            head = temp;
        }


        // destructor to free memory and prevent memory leak
        ~Doubly_linked_list()
        {
            Node<T>* current = head;
            while(current != nullptr)
            {
                Node<T>* next_node = current->next;
                delete current;
                current = next_node;
            }
        }
};
