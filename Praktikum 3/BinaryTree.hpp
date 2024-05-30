#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree(): numChildren(0) {}
        // Copy constructor
        BinaryTree(const BinaryTree<T>& bt) {
            value = bt.value;
            numChildren = bt.numChildren;
            for (auto i = bt.children.begin (); i != bt.children.end(); i++){
                children.push_back(*i);
            }
        }
        // Destruktor
        ~BinaryTree() {}

        // Setter untuk value
        void setValue(const T& other){
            value = other;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T val){
            if (numChildren >= 2){
                throw "Tidak bisa memiliki lebih dari dua children\n";
            } else {
                BinaryTree<T> newChild;
                newChild.setValue(val);
                children.push_back(newChild);
                numChildren++;
                return children[numChildren-1];
            }
        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& out, BinaryTree<T> t){
            out << t.value;
            out << "(";
            if (t.numChildren > 0){
                out << t.children[0];
            }
            out << ")";
            out << "(";
            if (t.numChildren > 1){
                out << t.children[1];
            }
            out << ")";
            return out;
        }


};

#endif