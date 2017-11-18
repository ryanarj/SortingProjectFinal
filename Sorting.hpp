//
//  Sorting.hpp
//  SortingCompare
//


#ifndef Sorting_hpp
#define Sorting_hpp



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

template <typename T>
class Sorting{
    
    public:
        void selectionsort(T* data, int size);
        void insertionsort(T* data, int size);
        void quicksort(T* data, int low, int high);
        bool checksort(T* data, int size);

};

template <typename T>
void Sorting<T>::selectionsort(T* data, int size){
    
    for (int i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i+1; j < size; j++)
            if (data[j] < data[min_idx])
                min_idx = j;
        
        // Swap the found minimum element with the i-th element
        T temp=data[min_idx];
        data[min_idx]=data[i];
        data[i]=temp;
        
        
    }
}

template <class T>
int partition(T *data, const int low, const int high)
{
    T pivotValue = data[(high+ low)/2]; // Middle value
    std::swap(data[(high+low)/2], data[low]); // Swap the middle to the front
    int left = low;
    int right = high;
    bool done = false;
    
  TailRecurse:
    while(left <= right){
        // Keep moving to the middle
        while  (left <= right && data[left] <= pivotValue){
            left = left + 1; goto TailRecurse;
        }
        // Keep moving to the middle
        while  (data[right] > pivotValue && right >= left){
            right = right - 1;  goto TailRecurse;
        }
        
        // left is less than right then swap values from left to right
        if (left < right){
            done = true;
            std::swap(data[left], data[right]);
        }
    }
    std::swap(data[left-1], data[low]);
    return left-1;
}

template <class T>
void quickSortHelper(T *data, const int low,  const int high){
    if (low < high){
        // Return the split of the array
        int split = partition(data,  low,  high);
        
        // Recursively check the left and then right
        quickSortHelper(data, low,  split-1);
        quickSortHelper(data, split+1, high);
    }
}

template <class T>
void Sorting<T>::quicksort(T *data, int low, int high)
{
    quickSortHelper(data, low,  high);
}

template <typename T>
bool Sorting<T>::checksort(T* data, int size){
    for (int i = 0; i <size-1; i++)
        if (data[i] > data[i+1])
            return false;
    return true;
}


#endif /* Sorting_hpp */
