# MySTL 
```
Simplifying C++ Programming
MySTL customizes containers for efficient data storage and introduces purposeful algorithms. 
Open-source and user-friendly, it enhances C++ coding by optimizing performance. 
Join the MySTL community to simplify and elevate your programming experience.
```

## Singly Linked List Key Features (singly_linked_list.hxx)
```
Node Structure: 
The Node class represents a node in the linked list, with a data field and pointers to the next and previous nodes.

Singly Linked List Class: 
The Linked_list class encapsulates the linked list operations.

Constructor: 
There are two constructors, one for an empty list and another for a list with an initial element.

Insertion Operations: 
Functions to insert nodes at the beginning, end, or a specific index of the linked list.

Traversal Operations: 
Functions to traverse the linked list in forward and reverse order, printing the data of each node.

Cloning Operation: 
A function to create a clone of the linked list.

Deletion Operations: 
Functions to delete a node with a specific value, delete from the beginning or end of the list.

Remove Duplicates: 
A function to remove duplicate nodes from a sorted linked list.

Reverse Operation: 
A function to reverse the linked list.

Merge Operation: 
A function to merge two sorted linked lists.

Cycle Detection: 
A function to check if there's a cycle in the linked list.

Find Merge Node: 
A function to find the node where two linked lists merge.

Destructor: 
Ensures proper memory deallocation when the linked list object goes out of scope.
```

## Doubly Linked List Key Features (double_linked_list.hxx)
```
Node Structure: 
The Node class represents a node in the doubly-linked list, with a data field and pointers to the next and previous nodes.

Doubly Linked List Class: 
The Doubly_linked_list class encapsulates the doubly-linked list operations.

Constructor: 
There are two constructors, one for an empty list and another for a list with an initial element.

Insertion Operations:
    insert_at_begin: Inserts a new node at the beginning of the list.
    insert_at_end: Inserts a new node at the end of the list.
    insert_at: Inserts a new node at a specific index in the list.

Traversal Operations:
    traverse_doubly_linked_list: Prints the elements of the list in forward order.
    reverse_traverse_doubly_linked_list: Prints the elements of the list in reverse order.

Sorted Insert Operation: 
    sortedInsert inserts a new node in sorted order.

Reverse Operation: 
    reverse reverses the doubly-linked list.

Destructor: 
Ensures proper memory deallocation when the linked list object goes out of scope.

Memory Management: 
The code appropriately allocates and deallocates memory for nodes during insertion, reversal, and destruction, preventing memory leaks.

Exception Handling: 
The code includes some basic error checking, such as checking for an out-of-range index during insertion.
```

## Sorting Algorithms (sorting_algos.hxx)

```
Selection Sort (selection_sort): 
Finds the smallest number and brings it to its proper index. Repeats this process for N-1 iterations. Time complexity: O(n^2).

Bubble Sort (bubble_sort): 
Compares every two consecutive elements and swaps them if they are in the wrong order. Repeats this process for N-1 iterations. Time complexity: O(n^2).

Insertion Sort (insertion_sort): 
Divides the array into a sorted and an unsorted subarray, and repeatedly inserts elements from the unsorted subarray into the sorted subarray. Time complexity: O(n^2).

Count Sort (count_sort): 
Creates a hash array and populates it with the counts of each element in the input array. Then, repopulates the input array using the non-zero indices of the hash array. Note: Suitable for unsigned data types. Time complexity: O(n).
```