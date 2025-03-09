
#include <iostream>
#include "stack.h"

using namespace std;




int main(int argc, char* argv[])
{
    Stack<int> stack;

    cout << "is stack empty:" << stack.empty() << endl;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    cout << "stack top:" << stack.top() << endl;
    
    stack.pop();
    cout << "stack top:" << stack.top() << endl;
    
    stack.pop();
    cout << "stack top:" << stack.top() << endl;
    
    try {
        stack.pop();
    } catch (const std::underflow_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        stack.top();
        std::cout << "stack top:" << stack.top() << std::endl;
    } catch (const std::underflow_error& e) {}
    
    return 0;

}
