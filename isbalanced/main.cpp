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
int sumOfNode(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int sum1 = sumOfNode(root->left);
    int sum2 = sumOfNode(root->right);
    return sum1+sum2+root->data;


}

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public :
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

class Pair{
  public :
  int heigh;
  bool blc;
};

Pair pairbalanced(BinaryTreeNode<int> *root){
    if(root == NULL){
        Pair base;
        base.heigh = 0;
        base.blc = true;
        return base;
    }

    Pair smallans1 = pairbalanced(root->left);
    Pair smallans2 = pairbalanced(root->right);
    bool temp;
    if(smallans1.blc == true && smallans2.blc == true){
        if(abs(smallans1.heigh - smallans2.heigh) >1){
        temp = false;
        }
        else {
        temp = true;

        }
    }
    Pair finalans;
    finalans.heigh = max(smallans1.heigh,smallans2.heigh)+1;
    finalans.blc = temp;
    return finalans;





}

bool isBalanced(BinaryTreeNode<int> *root){
   if(root == NULL){
       return true;
   }
    Pair answer = pairbalanced(root);
    return answer.blc;
}



int main()
{
   BinaryTreeNode<int> *root= takeinputlevel();
   printtreelevel(root);
   cout<< isbalanced(root);
    return 0;
}
