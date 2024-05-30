#include "A.hpp"

int main() {
    A obj1('1');  
    A obj2('2');  
    A obj3 = obj1; 
    obj3 = obj2;
    obj3.show();
    
    return 0;
}