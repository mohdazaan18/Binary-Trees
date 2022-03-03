

#include <iostream>
#include<queue>
using namespace std;

#include"Binary.cpp"


int countnodes(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int small1 = countnodes(root->left);
    int small2 = countnodes(root->right);
    return 1+small1+small2;

}

BinaryTreeNode<int> *Inputlevelwise(){
    int rootdata;
    cout<<"Enter data : ";
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
        cout<<"Left child : ";
        int lefchild;
        cin>>lefchild;
        if(lefchild!=-1){
            BinaryTreeNode<int> *lchild = new BinaryTreeNode<int>(lefchild);
            front->left = lchild;
            q.push(lchild);
        }
        cout<<"Right Child : ";
        int rigchild;
        cin>>rigchild;
        if(rigchild!=-1){
           BinaryTreeNode<int> *rchild = new BinaryTreeNode<int>(rigchild);
           front->right = rchild;
           q.push(rchild);
        }

    }
return root;
}
void printBinaryTreeLevelwise(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> * front = q.front();
        q.pop();
        cout<<front->data<<":";
        cout<<"L";
        if(front->left){
            cout<<front->left->data<<",";
            q.push(front->left);

        }
        else {
            cout<<-1<<",";
        }
        cout<<"R";
        if(front->right){
            cout<<front->right->data<<endl;
            q.push(front->right);
        }
        else{
            cout<<-1<<endl;
        }



    }


}
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

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if(root == NULL){
        return false;
    }
 if(root->data == x){
     return true;
 }
 bool ans1 = isNodePresent(root->left,x);
 bool ans2 = isNodePresent(root->right,x);

 bool answer = false;

 if(ans1 == true || ans2 == true){
     answer = true;
 }
 return answer;

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

    BinaryTreeNode<int> *root = Inputlevelwise();
    printBinaryTreeLevelwise(root);
    cout<<countnodes(root);
    return 0;
}
