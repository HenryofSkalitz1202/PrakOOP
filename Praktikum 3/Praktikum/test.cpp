#include "Restaurant.cpp"
#include <iostream>

using namespace std;

int main(){
    Restaurant r;
    r.Push(7);
    r.Push(6);
    r.Push(5);
    r.Push(4);
    r.Push(3);
    cout << "resto: " << r << endl;
    r.AddMenu(9, 10);
    cout << "resto: " << r << endl;
    r.Reorder(3);
    cout << "resto: " << r << endl;
}