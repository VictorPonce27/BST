//
// Victor Ponce 
//
#ifndef BST_h 
#define BST_h 

#include "Node.h"
#include "queue.h"
template<class T> 
class BST{
private:
    Node<T>  *root;  
    Node<T>* find_node(T data); 
    int child_num(Node<T> *node); 
    void pre_orderp(Node<T> *temp); 
    void in_orderp(Node<T> * temp); 
    void post_orderp(Node<T>* temp);
    int heightp(Node<T> *temp);
public:
    BST();
    void insert(T newData); 
    void print_tree(Node<T> *aux, int level); 
    void delete_data(T data); 
    void print(); 
    bool find(T data);
    void pre_order(); 
    void in_order();
    void post_order();
    void by_level(); 
    int height(); 
    void ancestors(T data); 
    int what_level(T data); 
    void visit(int choice); 


};


template<class T>
BST<T>::BST(){
    root = NULL; 
}

template<class T> 
void BST<T>::insert(T newData){
    if(root == NULL){
        root = new Node<T>(newData); 
    }
    else{
        Node<T> *aux = root;
        while(aux != NULL){
            if(aux->data <= newData){
                if(aux->right == NULL){
                    aux->right = new Node<T>(newData); 
                    return; 
                }
                else{
                    aux = aux->right;
                }
            }
            else{
                if(aux->left == NULL){
                    aux->left = new Node<T>(newData); 
                    return;
                }
                else{
                    aux = aux->left;
                }
            }
        }
    }
}

template<class T> 
void BST<T>::print(){
    int level = 0; 
    cout<<endl;
    print_tree(root,level);
    cout<<endl;
}

template<class T> 
void BST<T>::print_tree(Node<T> *aux, int level){
    if(aux != NULL){
        print_tree(aux->right,level+1); 
        for(int i =0;i<level;i++){
            cout<<"  "; 
        }
       cout<<aux->data<<endl; 
       print_tree(aux->left,level+1);
    }
}



template<class T> 
int BST<T>::child_num(Node<T> *node){
    if(node -> left == nullptr && node->right == nullptr){
        return 0; 
    }
    else if((node -> left == nullptr && node->right != nullptr) || (node -> left != nullptr && node->right == nullptr)){
        return 1; 
    }
    else{
        return 2;
    }
}

template<class T> 
Node<T>* BST<T>::find_node(T data){
    if(root != nullptr){
        Node<T> *temp = root; 
        while(temp != nullptr){
            if(data == temp->data){
                return temp; 
            }
            else{
                data < temp->data ? temp = temp->left : temp = temp->right;
            }
        }
    }
    return nullptr; 
}

template<class T> 
bool BST<T>::find(T data){
    if(root != nullptr){
        Node<T> *temp = root; 
        while(temp != nullptr){
            if(data == temp->data){
                return true; 
            }
            else{
                data < temp->data ? temp = temp->left : temp = temp->right;
            }
        }
    }
    return false; 
}

template<class T> 
void BST<T>::delete_data(T data){
    Node<T> *temp = find_node(data); 
    int kids = child_num(temp); 
    if(temp == nullptr){
        return; 
    }
    else{
        if(kids == 2){
            Node<T> *aux =temp->left; 
            int auxKids = child_num(aux); 
            if(auxKids == 2){
               if(aux->right != nullptr){
                    temp->data = aux->right->data;
                    if(aux->right->right != nullptr){
                        aux->right = aux->right->right;
                        delete aux->right->right;
                    } 
                    else{
                        aux->right = aux->right->left; 
                        if(aux->right == nullptr){
                            delete aux->right; 
                        }
                        else{
                            delete aux->right->left; 
                        }
                    }
                    return; 
                }
                else{
                    temp->data = aux->data;
                    temp->left = nullptr; 
                    delete aux; 
                    return; 
                }
            }
            else if (auxKids == 1){
                if(temp->right == nullptr){
                Node<T> *aux = temp->left;
                temp->data = aux->data;
                temp->left = nullptr; 
                aux = nullptr; 
                delete aux; 
                return; 
            }
                else{
                    Node<T> *aux = temp->right;
                    temp->data = aux->data;
                    aux = nullptr;
                    delete aux;
                    return; 
                }
            }
            else{
                Node<T> *at = root; 
                if(at->data == temp->data){
                    at = nullptr; 
                    delete at; 
                    return; 
                }
                while(at!= nullptr){
                    if(at->right != nullptr && at->right->data == temp->data){
                        at->right = nullptr; 
                        delete temp; 
                        return; 
                    }
                    else if(at->left != nullptr && at->left->data == temp->data){
                        at->left = nullptr;
                        delete temp; 
                        return; 
                    }
                    else{
                        at->data > temp->data ? at = at->left : at = at->right;
                    }
                    
                }
            }
        }
        else if(kids == 1){
            if(temp->right == nullptr){
                Node<T> *aux = temp->left;
                temp->data = aux->data;
                temp->left = nullptr; 
                aux = nullptr; 
                delete aux; 
                return; 
            }
            else{
                Node<T> *aux = temp->right;
                temp->data = aux->data;
                aux = nullptr;
                delete aux;
                return; 
            }
        }
        else{
            Node<T> *at = root; 
            if(at->data == temp->data){
                at = nullptr; 
                delete at; 
                return; 
            }
            while(at!= nullptr){
                if(at->right != nullptr && at->right->data == temp->data){
                    at->right = nullptr; 
                    delete temp; 
                    return; 
                }
                else if(at->left != nullptr && at->left->data == temp->data){
                    at->left = nullptr;
                    delete temp; 
                    return; 
                }
                else{
                    at->data > temp->data ? at = at->left : at = at->right;
                }
                
            }
        }
    }

}     

template<class T> 
void BST<T>::pre_order(){
    pre_orderp(root); 
}

template<class T> 
void BST<T>::pre_orderp(Node<T> *temp){
   if(temp!= nullptr){
       cout<<temp->data<<" "; 
       pre_orderp(temp->left); 
       pre_orderp(temp->right); 
   }
}

template<class T> 
void BST<T>::in_order(){
    in_orderp(root); 
}

template<class T> 
void BST<T>::in_orderp(Node<T> *temp){
   if(temp!= nullptr){
       in_orderp(temp->left); 
       cout<<temp->data<<" "; 
       in_orderp(temp->right); 
   }
}

template<class T> 
void BST<T>::post_order(){
    post_orderp(root); 
}

template<class T> 
void BST<T>::post_orderp(Node<T> *temp){
   if(temp!= nullptr){
       post_orderp(temp->left);
       post_orderp(temp->right);
       cout<<temp->data<<" ";
   }
}

template<class T> 
void BST<T>::by_level(){
    if(root == nullptr) return; 
    Queue<Node<T>*> nums; 
    nums.enqueue(root); 
    while(nums.get_size() > 0){
        Node<T> *n = nums.dequeue(); 
        cout<<n->data<<" ";
        if(n->left != nullptr){
            nums.enqueue(n->left); 
        }
        if(n->right != nullptr){
            nums.enqueue(n->right); 
        }
    }
}


template<class T> 
int BST<T>::heightp(Node<T> *temp){
    if(temp == nullptr){
        return -1;
    }
    int l = heightp(temp->left); 
    int r = heightp(temp->right); 
    return l>r ? l+1:r+1; 
}


template<class T> 
int BST<T>::height(){
    return heightp(root)+1; 

}

template<class T> 
void BST<T>::ancestors(T data){ 
    Node<T> *subject = find_node(data); 
    if(subject == nullptr) return; 
    Node<T> *temp = root; 

    while(temp != nullptr && temp != subject){
        if(temp->data>subject->data){
            cout<< temp->data <<" "; 
            temp = temp->left; 
        }
        else{
            cout<<temp->data<<" "; 
            temp = temp->right; 
        }
    }
}

template<class T> 
int BST<T>::what_level(T data){
    Node<T> *temp = root; 
    int count = 0; 

    while(temp != nullptr){
        if(temp->data == data) return count; 
        
        if(temp->data < data){ 
            temp = temp->right;
            count++;  
        }
        else{
            temp = temp->left; 
            count++; 
        }
        
    }
    return -1; 
}

template<class T> 
void BST<T>::visit(int choice){
    switch (choice){
    case 1:
        pre_orderp(root); 
        break;
    
    case 2:
        in_orderp(root);
        break;

    case 3: 
        post_orderp(root); 
        break;
    case 4: 
        by_level(); 
        break;
    }
}


#endif //BST_h 

