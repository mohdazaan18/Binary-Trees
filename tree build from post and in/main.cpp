#include <iostream>
#include"Binary.cpp"
#include<queue>
using namespace std;

BinaryTreeNode<int> *buildtreehelper(int *postorder,int ps,int pe,int *inorder,int is,int ie){
    if(ps>pe || is>ie){
        return NULL;
    }
    int rootdata = postorder[pe];
    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(rootdata);
    int index = 0;
    for(int i = 0;i<=ie;i++){
        if(rootdata == inorder[i]){
            index=i;
            break;
        }
    }
    int leftins = is;
    int leftine = index-1;
    int leftpos = ps;
    int leftpoe = (leftine-leftins)+leftpos;
    BinaryTreeNode<int> *lefttree = buildtreehelper(postorder,leftpos,leftpoe,inorder,leftins,leftine);
    int rightins = index+1;
    int rightine = ie;
    int rightpoe = pe-1;
    int rightpos = rightpoe - (rightine - rightins);
    BinaryTreeNode<int> *righttree = buildtreehelper(postorder,rightpos,rightpoe,inorder,rightins,rightine);

    root->left = lefttree;
    root->right = righttree;

    return root;

}



BinaryTreeNode<int> *buildtree(int *postorder,int postlen,int *inorder,int inlen){
    BinaryTreeNode<int> *ans = buildtreehelper(postorder,0,postlen-1,inorder,0,inlen-1);
    return ans;
}



BinaryTreeNode<int> *takeinput(){
    int rootdata;
    cout<<"Enter data : ";
    cin>>rootdata;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);

    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int> *leftch = takeinput();
    BinaryTreeNode<int> *rightch = takeinput();
    root->left = leftch;
    root->right = rightch;

    return root;
}

BinaryTreeNode<int> *inputlevel(){
    int rootdata;
    cout<<"Enter data : ";
    cin>>rootdata;
    BinaryTreeNode<int> *root= new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout<<"Left child of "<<front->data<<":";
        int leftch;
        cin>>leftch;
        if(leftch!=-1){
            BinaryTreeNode<int> *leftc = new BinaryTreeNode<int>(leftch);
            front->left = leftc;
            q.push(leftc);
        }
        cout<<"Right child of "<<front->data<<":";
        int rightch;
        cin>>rightch;
        if(rightch!=-1){
            BinaryTreeNode<int> *rightc = new BinaryTreeNode<int>(rightch);
            front->right = rightc;
            q.push(rightc);
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
        cout<<"L";
        if(front->left !=NULL){
            cout<<front->left->data<<",";
            q.push(front->left);
        }
        else {
        cout<<-1<<",";

        }
        cout<<"R";
        if(front->right !=NULL){
            cout<<front->right->data<<",";
            q.push(front->right);
        }
        else {
            cout<<-1;
        }
        cout<<endl;


    }




}
void printtree(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);





}


int main()
{
    BinaryTreeNode<int> *root = inputlevel();
    printtreelevel(root);
    return 0;
}
