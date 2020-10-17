#include <iostream>
using namespace std;

#include "BST.h"

int main(){
    BST<int> list;

    list.insert(12);
    list.insert(7);
    list.insert(21);
    list.insert(4);
    list.insert(9);
    list.insert(2);
    list.insert(8);

    cout<<"Preorder view"<<endl;
    list.visit(1);
    cout<<endl;

    cout<<"Inorder view"<<endl;
    list.visit(2);
    cout<<endl;

    cout<<"postorder view"<<endl;
    list.visit(3);
    cout<<endl;

    cout<<"by level view"<<endl;
    list.visit(4);
    cout<<endl;

    cout<<"size: "<<list.height()<<endl;;

    cout<<"ancestors of 8"<<endl;
    list.ancestors(8);
    cout<<endl;

    cout<<"find level of 8 "<<endl;
    cout<<list.what_level(8)<<endl;
    return 0;
}
