#include <iostream>
#include"Binary.cpp"
using namespace std;
#include<queue>
BinaryTreeNode<int>* takeinputlevel(){
    int rootdata;
    cout<<"Enter data : ";
    cin>>rootdata;

    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<"Left child : ";
        int leftc;
        cin>>leftc;
        if(leftc!=-1){
        BinaryTreeNode<int> *leftch = new BinaryTreeNode<int>(leftc);
        front->left = leftch;
        q.push(leftch);
        }
        cout<<"Right child : ";
        int rightc;
        cin>>rightc;
        if(rightc!=-1){
            BinaryTreeNode<int> *rightch = new BinaryTreeNode<int>(rightc);
            front->right = rightch;
            q.push(rightch);
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
        BinaryTreeNode<int> * front = q.front();
        q.pop();
        cout<<front->data<<":";
        cout<<"L";
        if(front->left!=NULL){
            cout<<front->left->data<<",";
            q.push(front->left);
        }
        else{
            cout<<-1<<",";
        }
        cout<<"R";
        if(front->left!=NULL){
            cout<<front->right->data;
             q.push(front->right);

        }
        else {
            cout<<-1;
        }

        cout<<endl;
    }



}

BinaryTreeNode<int> *buildtreehelper(int *preorder,int prs,int pre,int *inorder,int ins,int ine){
    if(ins>ine || prs>pre){
        return NULL;
    }

    int rootdata = preorder[prs];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    int index = 0;
    for(int i = ins;i<=ine;i++){
        if(rootdata == inorder[i]){
            index = i;
            break;
        }
    }
    int leftine = index-1;
    int leftins = ins;
    int leftpres = prs+1;
    int leftpree = (leftine-leftins)+leftpres;

    int rightins = index+1;
    int rightine = ine;
    int rightpre = pre;
    int rightprs = rightpre - (rightine - rightins);


     root->left = buildtreehelper(preorder,leftpres,leftpree,inorder,leftins,leftine);
   root->right = buildtreehelper(preorder,rightprs,rightpre,inorder,rightins,rightine);


    return root;




}


BinaryTreeNode<int> *buildTree(int *preorder,int presize,int *inorder,int insize){


    BinaryTreeNode<int> *root = buildtreehelper(preorder,0,presize-1,inorder,0,insize-1);
    return root;

}




int main()
{
    BinaryTreeNode<int> *root = takeinputlevel();
    printlevel(root);

    return 0;
}
