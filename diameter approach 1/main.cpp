#include <iostream>
#include<queue>
#include"Binary.cpp"
using namespace std;

BinaryTreeNode<int> *takeinputlevel(){
    cout<<"Enter rootdata : ";
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        int leftchild,rightchild;
        cout<<"Enter left child of "<<front->data<<":";
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTreeNode<int> *leftch = new BinaryTreeNode<int>(leftchild);
            q.push(leftch);
            front->left = leftch;
        }
        cout<<"Enter right child of "<<front->data<<":";
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTreeNode<int> *rightch = new BinaryTreeNode<int>(rightchild);
            q.push(rightch);
            front->right = rightch;
        }




    }


    return root;


}

void printtreelevel(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<",";
            q.push(front->left);
        }
        else{
            cout<<"L"<<-1<<",";
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data<<endl;
            q.push(front->right);
        }
        else{
            cout<<"R"<<-1<<endl;
        }






    }



}

int height(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left),height(root->left))+1;

}

int diameter(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    int leftd = diameter(root->left);
    int rightd = diameter(root->right);
    return max(lheight+rheight+1,max(leftd,rightd));




}




int main()
{
   BinaryTreeNode<int> *root= takeinputlevel();
   printtreelevel(root);
   cout<<height(root)<<endl;
 cout<<diameter(root);
    return 0;
}
