#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct Node{
  int data;
  struct Node *left, *right;

};

struct Node *newNode(int item){
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}
//In-order traversal visits the left branch and the current node, and finally, the right branch
void inOrder(struct Node *root) {
  if (root != NULL){
    inOrder(root->left);
    cout<<root->data;
    cout<<" --->";
    inOrder(root->right);
  }
}

//Pre-order traversal visits the current node before its child nodes. After the current node visits
//the left node and then the right node
void preOrder(struct  Node *root){
  if (root != NULL){
    cout<<root->data;
    cout<< " --- >";
    preOrder(root->left);
    preOrder(root->right);
  } 
}

//Post-order trversal visits the left child node and then the right node and last the current node
void postOrder(struct Node *root){
  if (root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
    cout<<" --->";
  }
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}


struct Node* insert(struct Node* Node, int key){

  if(Node == NULL){
    return newNode(key);
  }
  if(key<Node->data){
    Node->left = insert(Node->left, key);
  }else{
    Node->right = insert(Node->right, key);
  }

  return Node;
}

bool searchNode(struct Node* Node, int value){
  if(Node==NULL || value == 0) {return false;}

  if(value < Node->data){
    searchNode(Node->left, value);
  }else if(value > Node->data){
    searchNode(Node->right, value);
  }else if(value == Node->data){
    return true;
  }
}

int main(int argc, char** argv) {
  struct Node* root = newNode(10);
  root = insert(root, 20);
  root = insert(root, 13);
  root = insert(root, 40);
  root = insert(root, 15);
  root = insert(root, 60);
  root = insert(root, 17);

  cout<<"The tree to print"<<endl;
  inOrder(root);
  cout<<"\n";
  preOrder(root);
  cout<<"\n";
  postOrder(root);
  cout<<"\n";
  std::cout <<"The total length of nodes are: "<< countNodes(root) << '\n';
  std::cout << searchNode(root, 107) << '\n';

  return 0;
}
