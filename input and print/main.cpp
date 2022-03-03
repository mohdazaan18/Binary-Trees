

#include <iostream>

using namespace std;

#include"Binary.cpp"

BinaryTreeNode<int>* TakeInput(){
    int rootdata;
    cout<<"Enter data : ";
    cin>>rootdata;

    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *leftChild = TakeInput();
    BinaryTreeNode<int> *rightChild = TakeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}


void printBinaryTree(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<",";
    }
    cout<<endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);

}
int main()
{
   /* BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;*/

    BinaryTreeNode<int> *root = TakeInput();
    printBinaryTree(root);

    return 0;
}
