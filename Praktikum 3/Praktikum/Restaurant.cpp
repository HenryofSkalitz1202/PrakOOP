#include "Restaurant.hpp"

Restaurant::Restaurant() {}

Restaurant::~Restaurant() {}

void Restaurant::Push(int val) {
    order.push(val);
}

void Restaurant::Pop(int val) {
    if (val > order.size()) {
        cout << "Proses tidak valid" << endl;
        return;
    }
    while (val--) {
        order.pop();
    }
}

void Restaurant::AddMenu(int k, int val) {
    Restaurant temp;
    if(k > this->order.size()){
        k = this->order.size();
    }

    int initial_length = this->order.size();
    for(int i = 0; i < initial_length - k; i++){
        temp.Push(this->order.top());
        this->order.pop();
    }

    while(!this->order.empty()){
        temp.Push(this->order.top() + val);
        this->order.pop();
    }

    while(!temp.order.empty()){
        this->order.push(temp.order.top());
        temp.Pop(1);
    }
}

void Restaurant::Reorder(int k) {
    Restaurant temp;
    Restaurant temp2;
    if(k > this->order.size()){
        k = this->order.size();
    }

    while(!this->order.empty()){
        temp.Push(this->order.top());
        this->order.pop();
    }

    for(int i = 0; i < k; i++){
        temp2.Push(temp.order.top());
        temp.Pop(1);
    }

    while(!temp2.order.empty()){
        this->order.push(temp2.order.top());
        temp2.Pop(1);
    }

    while(!temp.order.empty()){
        this->order.push(temp.order.top());
        temp.Pop(1);
    }
}

ostream& operator<<(ostream& out, Restaurant r) {
    out << "(";
    while (!r.order.empty()) {
        out << r.order.top();
        r.order.pop();
        if (!r.order.empty()){
            out << ", ";
        }
    }
    out << ")" << endl;
    return out;
}

// int main(){
//     Restaurant r;
//     r.Push(5);
//     r.Push(4);
//     r.Push(3);
//     cout << r;
//     r.Push(2);
//     r.Push(1);
//     r.Reorder(3);
//     cout << r;
//     r.AddMenu(2, 3);
//     cout << r;
// }