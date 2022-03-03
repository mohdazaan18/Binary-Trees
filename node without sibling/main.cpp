#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include"Binary.cpp"
using namespace std;

void Nodewithoutsibling(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<< " ";
    }
    if(root->left!=NULL && root->right==NULL){
        cout<<root->left->data << " ";
    }

    Nodewithoutsibling(root->left);
    Nodewithoutsibling(root->right);




}



BinaryTreeNode<int> *takeinput(){

    cout<<"Enter data : ";
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        int leftc,rightc;
        cout<<"Enter left child of "<<front->data<<":";
        cin>>leftc;
        if(leftc!=-1){
            BinaryTreeNode<int> *leftch = new BinaryTreeNode<int>(leftc);
            q.push(leftch);
            front->left = leftch;
        }
        cout<<"Enter right child of "<<front->data<<":";
        cin>>rightc;
        if(rightc!=-1){
            BinaryTreeNode<int> *rightch = new BinaryTreeNode<int>(rightc);
            q.push(rightch);
            front->right = rightch;
        }


    }
    return root;


}


void printlevel(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front  = q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<",";
            q.push(front->left);
        }
        else {
            cout<<"L"<<-1<<",";
        }
        if(front->right !=NULL){
            cout<<"R"<<front->right->data<<endl;
            q.push(front->right);
        }
        else {
            cout<<"R"<<-1<<endl;

    }




}
}

int main()
{
    BinaryTreeNode<int> *root = takeinput();

    printlevel(root);
    Nodewithoutsibling(root);
    return 0;
}
