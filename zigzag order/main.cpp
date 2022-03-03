#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include"Binary.cpp"
using namespace std;
template <typename T>
class Node{
  public :
  T data;
  Node<T> *next;

  Node(T data){
      this->data = data;
      next = NULL;
  }
};
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
void zigZagOrder(BinaryTreeNode<int> *root) {
      if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    int childc = 0;
    int currentlevel = 1;
    bool flag = true;
    while(!s1.empty() || !s2.empty()){
       if(flag) {
        BinaryTreeNode<int> *tope = s1.top();
        s1.pop();
        cout<<tope->data<<" ";
        currentlevel--;
        if(tope->left!=NULL){
            s2.push(tope->left);
            childc++;
        }
        if(tope->right!=NULL){
            s2.push(tope->right);
            childc++;
        }

        if(currentlevel == 0){
            cout<<endl;
            currentlevel = childc;
            childc = 0;
            flag = false;
        }

       }
       else {
         BinaryTreeNode<int> *tope = s2.top();
        s2.pop();
        cout<<tope->data<<" ";
        currentlevel--;
        if(tope->right!=NULL){
            s1.push(tope->right);
            childc++;
        }
        if(tope->left!=NULL){
            s1.push(tope->left);
            childc++;
        }

        if(currentlevel == 0){
            cout<<endl;
            currentlevel = childc;
            childc = 0;
            flag = true;
        }


       }




    }



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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
      vector<Node<int>*> v;
   if(root == NULL){
       return v;
   }
   queue<BinaryTreeNode<int>*> q;
   q.push(root);

   Node<int> *head = NULL;
   Node<int> *tail = NULL;
   int childc = 0;
   int currentlevel = 1;

   while(!q.empty()){
       BinaryTreeNode<int> *front = q.front();
       q.pop();
       Node<int> *newNode = new Node<int>(front->data);

       if(head == NULL){
           head = newNode;
           tail = newNode;
       }
       else {
          tail->next = newNode;
          tail = newNode;

       }
       if(front->left!=NULL){
           q.push(front->left);
           childc++;

       }
       if(front->right!=NULL){
           q.push(front->right);
           childc++;
       }
       currentlevel--;

       if(currentlevel == 0){
           v.push_back(head);
           head = NULL;
           tail =NULL;
           currentlevel = childc;
           childc = 0;


       }

   }

   return v;
}
void printLL(Node<int> *head){
    if(head == NULL){
        return;
    }
    Node<int> *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}
int main()
{
    BinaryTreeNode<int> *root = takeinput();

    printlevel(root);
    zigZagOrder(root);
    return 0;
}
