#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTNode.hpp"

template <class T>
class BST {
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot();

    void insert(const T &data);
    void remove(const T &data);
    BSTNode<T> *find(const T &data);
    void printInorder();

    BST<T> &operator=(const BST<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void printInorder(BSTNode<T> *node);
    void copyHelp(BSTNode<T> * node); //RECURSIVE HELPER FOR COPY CONSTRUCTOR AND OPERATOR=
    BSTNode<T> *findHelp(BSTNode<T>* root, const T &data); //RECURSIVE HELPER FOR FIND
    void removeHelp(BSTNode<T> *&r, const T &data); //RECURSIVE HELPER FOR REMOVE
    void removeAllNodes(BSTNode<T> *root); //RECURSIVE HELPER TO REMOVE ALL NODES

private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_HPP

template <class T>
BST<T>::BST() {
    /* TODO */
    root=NULL;
}

template <class T>
BST<T>::BST(const BST<T> &obj) {
    /* TODO */
    root = NULL;
    copyHelp(obj.root);
}

template <class T>
BST<T>::~BST() {
    /* TODO */
    removeAllNodes(root);
    //root=NULL;
}

template <class T>
BSTNode<T> *BST<T>::getRoot() {
    /* TODO */
    return root;
}

template <class T>
void BST<T>::insert(const T &data) {
    /* TODO */
    BSTNode<T> *n,*nprev;
    n=root;
    nprev=NULL;

    while(n != NULL){
      nprev=n;
      if(data > n->data){
        n=n->right;
      }
      else{
        n=n->left;
      }
    }
    if(nprev==NULL){
      root = new BSTNode<T>(data,NULL,NULL);
      /*nprev = new BSTNode<T>;
      nprev->data=data;
      nprev->right=NULL;
      nprev->left=NULL;
      root=nprev;*/
    }
    else{
      if(data > nprev->data){
        /*nprev->right = new BSTNode<T>;
        nprev->right->data=data;
        nprev->right->right=NULL;
        nprev->right->left=NULL;*/
        n = new BSTNode<T>(data,NULL,NULL);
        nprev->right=n;
      }
      else if(data < nprev->data){
        /*nprev->left = new BSTNode<T>;
        nprev->left->data=data;
        nprev->left->right=NULL;
        nprev->left->left=NULL;*/
        n = new BSTNode<T>(data,NULL,NULL);
        nprev->left=n;
      }
      else{

      }
    }
}

template <class T>
void BST<T>::remove(const T &data) {
    /* TODO */
    if(find(data) != NULL){
        if(root->data==data){
            removeHelp(root,data);
        }
        else{
            if(root->data > data){
                removeHelp(root->left,data);
            }
            else{
               removeHelp(root->right,data);
            }
        }
    }
    
}

template <class T>
BSTNode<T> *BST<T>::find(const T &data) {
    /* TODO */
    findHelp(this->root,data);
}

template <class T>
void BST<T>::printInorder() {

    if (root == NULL) {
        std::cout << "{}" << std::endl;
    } else {
        std::cout << "{" << std::endl;
        printInorder(root);
        std::cout << std::endl << "}" << std::endl;
    }
}

template <class T>
void BST<T>::printInorder(BSTNode<T> *node) {

    if (node == NULL)
        return;

    printInorder(node->left);
    if (node->left) {
        std::cout << "," << std::endl;
    }
    std::cout << "\t" << node->data;
    if (node->right) {
        std::cout << "," << std::endl;
    }
    printInorder(node->right);
}

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    /* TODO */
    removeAllNodes(root);
    copyHelp(rhs.root);
    return *this;
}

// HELPERS BELOW

template <class T>
void BST<T>::copyHelp(BSTNode<T> * node){
     if(node != NULL){
         insert(node->data);
         copyHelp(node->left);
         copyHelp(node->right);
     }
}

template <class T>
BSTNode<T> *BST<T>::findHelp(BSTNode<T>* root, const T &data) {
    if(root == NULL || root->data == data){
        return root;
    }

    if(root->data < data){
        return findHelp(root->right, data);
    }

    return findHelp(root->left, data);
}

template <class T>
void BST<T>::removeHelp(BSTNode<T> *&r, const T &data){
    if(r == NULL){
        return;
    }

    if(data < r->data){
        removeHelp(r->left, data);
    }

    else if(data > r->data){
        removeHelp(r->right, data);
    }

    else{
        if(r->right != NULL && r->left != NULL){
            BSTNode<T> *temp = r->right;

            while(temp->left!=NULL){
                temp = temp->left;
            }

            r->data = temp->data;
            removeHelp(r->right, r->data);
        }
        else{
            BSTNode<T> *tempNode = r;

            if(r->left == NULL){
                r=r->right;
            }
            else if(r->right == NULL){
                r=r->left;
            }
            delete tempNode;
        }
    }
}

template <class T>
void BST<T>::removeAllNodes(BSTNode<T> *root){
    /*if(root == NULL){
        return;
    }*/
    if(root != NULL){
        removeAllNodes(root->left);
        removeAllNodes(root->right);

        delete root;
    }


}

