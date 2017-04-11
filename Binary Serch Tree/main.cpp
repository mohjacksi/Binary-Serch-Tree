//
//  main.cpp
//  Binary Serch Tree
//
//  Created by Mohammed Jacksi on 2/8/17.
//  Copyright © 2017 Mohammed Jacksi. All rights reserved.
//

#include <iostream>
using namespace std;
struct node{
    int data;
    node* R;
    node* L;
};
node* Root=NULL;

/*---------------------------------------------------------------------*/
/* FUNCTION TO FIND MINIMUM VALUE IN THE TREE */
/*---------------------------------------------------------------------*/
node * minValueNode(struct node* node)
{
    struct node* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->L != NULL)
        current = current->L;
    
    return current;
}
/*---------------------------------------------------------------------*/
/* FUNCTION TO INSERT A NODE IN THE TREE */
/*---------------------------------------------------------------------*/

void insertion(node* root,int data){
    node* temp = new node;
    temp->data = data;
    temp->R=NULL;
    temp->L=NULL;
    
    if (root == NULL)
    {
        Root=temp;
    }
    else
    {
        node* q=root;
        node* parent=NULL;
        
        
        while (q!=NULL) {
            parent=q;
            if (data > q->data) {
                q=q->R;
            }else{
                q=q->L;
            }
        }
        if(data > parent->data)
            parent->R=temp;
        else
            parent->L=temp;
    }
}

/* ------------------------------------------------*/
/*INORDER RECURSIVE TRAVERSAL (IN ORDER)*/
/*-------------------------------------------------*/

void inOrder(node* root){
    if (root==NULL)
        return;
    
    inOrder(root->L);
    cout<<root->data;
    inOrder(root->R);
}

/* ------------------------------------------------*/
/*IDELET VALUE FROME TREE*/
/*-------------------------------------------------*/
node* del(node* R,int val)
{
    node* temp;
    if (R == NULL)
        return R;
    else if (val < R->data)
        R->L = del(R->L,val);
    else if (val > R->data)
        R->R = del(R->R,val);
    
    
        // case1 no child
        if (R->L == NULL && R->R == NULL) {
            temp = R->L;
            free(R);
            return temp;
        }
        // case 2 one chiled

        else if (R->L == NULL) {
            temp = R->R;
            free(R);
            return temp;
        }else if (R->R == NULL) {
            temp = R->L;
            free(R);
            return temp;
        }
        // case 3 two chiled

        temp = minValueNode(R->R);
        R->data = temp ->data;
        R->R = del(R->R, R->data);
        return R;
    
}
/* ------------------------------------------------*/
/*RETURN THE NUMBER OF NUDES IN TREE*/
/*-------------------------------------------------*/
int Counter(node* R)
{
    if(R==NULL)
        return 0;
    
    return 1+Counter(R->L)+Counter(R->R);
}
int size(node *n)
{
    if(!n)
        return 0;
    else
        return size(n->R) + 1 + size(n->L);
}

int main(int argc, const char * argv[]) {

    insertion(Root, 5);
    insertion(Root, 4);
    insertion(Root, 6);
    insertion(Root, 7);
    //del(Root, 5);

    inOrder(Root);
   // cout<<endl<<size(Root);

    cout<<endl<<Counter(Root)<<endl;
    
    return 0;
}
