#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue(){
        this->size = 0;
    }
    /*
        Destructor
    */
    ~PriorityQueue(){
    }   
    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value){
        int idx = 0;
        while (idx < this->size && value <= this->content[idx]){
            idx++;
        }
        this->content.insert(this->content.begin() + idx, value);
        this->size++;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue(){
        T front_elem;
        front_elem = this->content.front();
        this->content.erase(this->content.begin());
        this->size--;
        return front_elem;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front(){
        T front_elem;
        front_elem = this->content.front();
        return front_elem;
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(PriorityQueue<T> pq){
        while (!pq.content.empty()){
            this->Enqueue(pq.Dequeue());
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize(){
        return this->size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& out, PriorityQueue<T> t){
        out << "(";
        for (auto it = t.content.begin(); it != t.content.end(); ++it){
            out << *it;
            if (it != t.content.end() - 1) out << ", ";
        }
        out << ")" << endl;
        return out;
    }
};



#endif