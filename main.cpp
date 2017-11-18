//
//  main.cpp
//  SortingCompare
//

#include "Sorting.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    srand((unsigned)time(0));
    
    if(argc!=4){
        cout<<"Error in parameters in command line: which sorting algorithm, size, and type of data (sorted, constant, or random)\n";
        return 0;
    }
    char method=argv[1][0];
    int size=stoi(argv[2]);
    char howFill=argv[3][0];
    
    
    int* data=new int[size];
    
    
    switch(howFill){
        //sorted data
        case 's':
            for(int i=0;i<size;i++)
                data[i]=i+1;
            break;
        //random data
        case 'r':
            for(int i=0;i<size;i++)
                data[i]=rand()%10000;
            break;
        //constant data
        case 'c':
            for(int i=0;i<size;i++)
                data[i]=0;
            break;
        default:
            break;
    }
    
    
    //start sorting
    clock_t begin = clock();
    
    Sorting<int> sorting;
    switch(method){
        case 's':
            sorting.selectionsort(data,size);
            break;
        //other methods...
        case 'q':
            sorting.quicksort(data, 0, size-1);
            break;
            //other methods...
        default:
            break;
    }
    
    //end sorting
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Method: "<<method<<" Size: "<<size<<" Fill: "<<howFill<<" Time: "<<elapsed_secs<<endl;

    
    if(sorting.checksort(data,size))
        cout<<"Success!\n";
    else
        cout<<"Error!\n";
    
    /*for(int i=0;i<size;i++)
        cout<<data[i]<<" ";
    cout<<endl;
    */
     
    delete[] data;
    return 0;
}
