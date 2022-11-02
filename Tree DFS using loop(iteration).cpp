#include <iostream>
#include<stack>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data=-9999)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class Tree
{
  public:
  Node* root;
  
  Tree()
  {
      root=NULL;
  }
  bool isEmpty()
  {
      return (root==NULL);
  }
  bool isLeaf(Node* apex)
  {
      return (apex->left==NULL && apex->right==NULL);
  }
  void insert(int val)
  {
      if(isEmpty())
      {
          root=new Node(val);
          return;
      }
      Node *t=new Node(val);
      Node *temp=root;
      while(true)
      {
          if(val<temp->data)
          {
              if(temp->left == NULL)
              {
                  temp->left=t;
                  return ;
              }
              temp=temp->left;
          }
          else
          {
              if(temp->right == NULL)
              {
                  temp->right=t;
                  return ;
              }
              temp=temp->right;
            }
              
        }
    }
  void preOrderTraverse(Node* apex)
  {
      stack<Node*> st;
      st.push(apex);
      
      while(!st.empty())
      {
          apex=st.top();
          st.pop();
          cout<<apex->data<<"\t";
          
          if(apex->right != NULL)
            st.push(apex->right);
            
          if(apex->left != NULL)
            st.push(apex->left);        
      }
  }
};
int main()
{
    Tree t;
    t.insert(7);
    t.insert(5);
    t.insert(9);
    t.insert(4);
    t.insert(6);
    t.insert(8);
    t.insert(10);
    t.insert(1);

    t.preOrderTraverse(t.root);
    return 0;
}
