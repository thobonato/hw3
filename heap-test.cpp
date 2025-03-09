
#include <iostream>
#include "heap.h"

using namespace std;


int main(int argc, char* argv[])
{
    Heap<int> heap(2);

    cout << "is stack empty:" << heap.empty() << endl;
    
    heap.push(9);
    heap.push(9);
    heap.push(20);
    
    cout << "heap top: " << heap.top() << endl;
    heap.pop();
    cout << "heap top: " << heap.top() << endl;
    heap.pop();
    cout << "heap top: " << heap.top() << endl;
    
    return 0;

}
