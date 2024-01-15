// In sorting of O(n^2) : i indicates number of iterations whereas j represents number of comparisons

#include <iostream>

using std :: cout;
using std :: endl;

// function to swap 2 elements
template <typename T> void swap_nums(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// function to print an array of size N
template<typename T,size_t N> 
void print(T (&arr)[N]){
    for(T i = 0; i<N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
selection sort --> In this sort , we find the smallest number and then bring it to it's proper index and repeat the same for N-1 times
(push the smallest number to the start)
Space complexity = O(1)
Time complexity = O(n^2)
*/
template<typename T,size_t N> 
void selection_sort(T (&arr)[N])
{
    for(T i = 0; i < N-1; ++i)
    {
        T min = i;
        for(T j = i+1; j< N ; ++j)
        {
            if( arr[min] > arr[j]){
                min = j;
            }
        }
        if(min != i)
            swap_nums(arr[min],arr[i]);
        else
            return;
    }
}

/*
bubble sort --> In this sort , we compare every 2 consecutive elements and swap the smaller number with the bigger one until the biggest element doesn't reach 
to the end, nd we repeat the same process N-1 nmbr of times (push the biggest number to the end)
Space complexity = O(1)
Time complexity = O(n^2)
*/ 
template<typename T,size_t N> 
void bubble_sort(T (&arr)[N])
{
    bool swap = false;
    for(T i = 0; i < N-1; ++i)
    {
        for(T j = 0; j< N-i-1 ; ++j)
        {
            if( arr[j] > arr[j+1]){
                swap_nums(arr[j],arr[j+1]);
                swap = true;
            }
        }
        if (not swap)
            return;
    }
}

/*
insertion sort --> Divided the array into 2 subarrays as sorted and unsorted where we set a pivot , which draws the line for sorted and unsorted subarrays
meaning the subarray before pivot is sorted and after is unsorted
Space complexity = O(1)
Time complexity = O(n^2)
*/ 
template<typename T,size_t N> 
void insertion_sort(T (&arr)[N])
{
    for(T i = 1; i < N; ++i)
    {
        T pivot = arr[i];
        T j = i-1;
        
        while( j>=0 and arr[j]>pivot)
        {
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = pivot;
    }
}

/*
Hash sort --> Create an array of size equals to the biggest element of the unsorted array
Then fill only those indices with 1 which numbers are present in the unsorted array and remaining with 0
Then again populate the unsorted array with the sorted arrays indices marked as 1 
Note : use it in case of unsigned datatypes only otherwise will have to write more logic to handle negative numbers
Space complexity = O(n)
Time complexity = O(n)
*/ 
template<typename T,size_t N> 
void count_sort(T (&arr)[N])
{   
    // Finding smallest element
    T min = arr[0];
    for (T arr_index = 1; arr_index < N ; arr_index++)
    {
        if(min > arr[arr_index])    
            min = arr[arr_index];
    }

    // cout << max << endl;
    // cout << min << endl;

    // If min is a negative number , then subtracting same number from each element to make the array positive
    if(min < 0)
    {
        for (T arr_index = 0; arr_index < N ; arr_index++)
        {
            arr[arr_index] -= min;
        }
    }

    // From the positive array , finding the biggest element
    T max = arr[0];
    for (T arr_index = 1; arr_index < N ; arr_index++)
    {
        if(max < arr[arr_index])
            max = arr[arr_index];
    }

    // creating hash array of max element length
    T* hash_arr = new T[max+1];

    // populating all the elements to 0
    for(T hash_arr_index = 0 ; hash_arr_index<= max; hash_arr_index++)
    {
        hash_arr[hash_arr_index] = 0;
    }

    // Incrementing only those indices of hash array , which is an element of of our positive array
    for(T arr_index = 0 ; arr_index < N; arr_index++)
    {
        hash_arr[arr[arr_index]] += 1;
    }

    // for(T hash_arr_index =0; hash_arr_index <= max; ++hash_arr_index)
    // {
    //     cout << hash_arr[hash_arr_index] << " ";
    // }
    // cout << endl;

    
    // Now populting our positive array with the non zero indices of our hash array
    T hash_arr_index = 0;
    T arr_index = 0;
    while (true)
    {
        // if the hash array index becomes greater than it's length, that means our positive array is sorted
        if(hash_arr_index == max+1)
            break;
        
        // Retrieving our values from the non zero indices of hash array until the each and every element of hash array becomes zero
        if(hash_arr[hash_arr_index] > 0)
        {
            arr[arr_index] = hash_arr_index;
            hash_arr[hash_arr_index]--;
            arr_index++;
        }
        else
        {
            hash_arr_index++;
        }

    }

    // Retrieving our original array from the positive array if the min element was negative
    if(min < 0)
    {
        for (T arr_index = 0; arr_index < N ; arr_index++)
        {
            arr[arr_index] += min;
        }
    }
}


// merge sort will be added soon
