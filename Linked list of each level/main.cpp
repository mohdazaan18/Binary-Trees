#include <iostream>
#include<queue>
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
    vector<Node<int>*> r = constructLinkedListForEachLevel(root);
    for(int i = 0;i<r.size();i++){
        printLL(r[i]);

    }
    return 0;
}
