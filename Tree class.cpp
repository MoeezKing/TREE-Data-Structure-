#include <iostream>
using namespace std;
class Node
{
    int value;
    Node* left;
    Node* right;
public:
    void setValue(int value)
    {
        this->value = value;
    }
    void setLeft(Node* left)
    {
        this->left = left;
    }
    void setRight(Node* right)
    {
        this->right = right;
    }
    int getValue()
    {
        return value;
    }
    Node* getLeft()
    {
        return left;
    }
    Node* getRight()
    {
        return right;
    }
    Node(int value=-9999, Node* left=NULL, Node* right=NULL)
    {
        setValue(value);
        setLeft(left);
        setRight(right);
    }
};
class Tree
{
    Node* root;
public:
    /*
    void insert(Node* apex,int val)     //insertion through recursion
    {
        if(isEmpty())
        {
            root=new Node(val);
            return;
        }
        if(apex->getValue()>val)
        {
            if(apex->getLeft()==NULL)
            {
                Node* temp=new Node(val);
                apex->setLeft(temp);
                return;
            }
            return(insert(apex->getLeft(),val));
        }
        else{
           if(apex->getRight()==NULL)
            {
                Node* temp=new Node(val);
                apex->setRight(temp);
                return;
            }
            return(insert(apex->getRight(),val)); 
        }
    }
    void insert(int val)
    {
        insert(root,val);
    }
    */
    void setRoot(Node* root)
    {
        this->root = root;
    }
    Node* getRoot()
    {
        return root;
    }
    Tree(Node* root = NULL)
    {
        setRoot(root);
    }
    bool isEmpty()
    {
        return (root == NULL);
    }
    void insert(int value)
    {
        Node* temp = new Node(value);
        if (isEmpty())
        {
            root = temp;
            return;
        }

        Node* current = root;
        while (true)
        {
            if (value < current->getValue())
            {
                if (current->getLeft() == NULL)
                {
                    current->setLeft(temp);
                    break;
                }
                current = current->getLeft();
            }
            else
            {
                if (current->getRight() == NULL)
                {
                    current->setRight(temp);
                    break;
                }
                current = current->getRight();
            }
        }
    }
    bool find(int value)
    {
        Node* current = root;
        while (current != NULL)
        {
            if (value < current->getValue())
            {
                current = current->getLeft();
            }
            else if (value > current->getValue())
            {
                current = current->getRight();
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void traversePreOrder(Node* current)
    {
        if (current == NULL)
            return;

        cout << current->getValue() << "\t";
        traversePreOrder(current->getLeft());
        traversePreOrder(current->getRight());
    }
    void traversePreOrder()//overloading the function
    {
        cout << "\nPreOrder traverse of the tree is  ";
        traversePreOrder(root);
        cout << endl;
    }
    void traverseInOrder(Node* current)
    {
        if (current == NULL)
            return;

        traverseInOrder(current->getLeft());
        cout << current->getValue() << "\t";
        traverseInOrder(current->getRight());
    }
    void traverseInOrder()//overloading
    {
        cout << "\nInOrder traverse of the tree is  ";
        traverseInOrder(root);
        cout << endl;
    }
    void traversePostOrder(Node* current)
    {
        if (current == NULL)
            return;

        traversePostOrder(current->getLeft());
        traversePostOrder(current->getRight());
        cout << current->getValue() << "\t";
    }
    void traversePostOrder()//overloading
    {
        cout << "\nPostOrder traverse of the tree is  ";
        traversePostOrder(root);
        cout << endl;
    }
    int max(int m1, int m2)//return maximum value
    {
        if (m1 > m2)
            return m1;
        else
            return m2;
    }
    int min(int m1, int m2)//return minimum number
    {
        if (m1 < m2)
            return m1;
        else
            return m2;
    }
    bool isLeaf(Node* current)
    {
        return (current->getLeft()==NULL && current->getRight()==NULL);
    }
    int height(Node* current)
    {
        if (isLeaf(current))
            return 0;

        return 1 + max(height(current->getLeft()), height(current->getRight()));
    }
    void height()//overloading
    {
        cout << "\nHeight of the tree is ";
        cout << height(root)<<endl;
    }
    int minValue(Node* current)
    {
        if (isLeaf(current))
            return current->getValue();

        return min(min(minValue(current->getLeft()), minValue(current->getRight())), current->getValue());
    }
    void minValue()//overloading
    {
        cout << "\nMinimum value of the tree is " << minValue(root)<<endl;
    }
    int maxValue(Node* current)
    {
        if (isLeaf(current))
            return current->getValue();

        return max(max(maxValue(current->getLeft()), maxValue(current->getRight())), current->getValue());
    }
    void maxValue()//overloading
    {
        cout << "\nMaximum value of the tree is " << maxValue(root) << endl;
    }
    int countLeaf(Node* current)
    {
        if (isLeaf(current))
            return 1;
        if (current == NULL)
            return 0;

        return 0 + countLeaf(current->getLeft()) + countLeaf(current->getRight());
    }
    void countLeaf()
    {
        cout << "\nNumber of leaf in this tree is " << countLeaf(root);
    }
    int size(Node* current)//Size of a tree is the number of elements present in the tree
    {
        if (current == NULL)
            return 0;

        return 1 + size(current->getLeft()) + size(current->getRight());
    }
    void size()
    {
        cout << "\nSize of the tree is " << size(root) << endl;
    }
    bool isEqual(Node* first, Node* second)
    {
        if (first == NULL && second == NULL)
            return true;
        if (first != NULL && second != NULL)//value && left && right . PreOder trversal
            return (first->getValue() == second->getValue()&&isEqual(first->getLeft(),second->getLeft())&&isEqual(first->getRight(),second->getRight()));
        return false;
    }
    void isEqual(Tree* other)
    {
        if (other == NULL)
            cout<<"\nNot equal\n";
        if (isEqual(root, other->getRoot()))
            cout << "\nThe both trees are equal\n";
        else
            cout << "\nThe both trees are not equal\n";

    }
     bool validBST(Node* current, int lower, int upper)
    {
        if (current->getLeft() == NULL && current->getRight() == NULL)
        {
            return (current->getValue() > lower && current->getValue() < upper);
        }
        else if (current->getLeft() == NULL)
        {
            return (current->getValue() > lower && current->getValue() < upper && validBST(current->getRight(), current->getValue(), upper));
        }
        else if (current->getRight() == NULL)
        {
            return (current->getValue() > lower && current->getValue() < upper && validBST(current->getLeft(), lower, current->getValue()));
        }
        else
        {
            return (current->getValue() > lower && current->getValue() < upper && validBST(current->getLeft(), lower, current->getValue())&& validBST(current->getRight(), current->getValue(), upper));
        }

    }
    bool validBST()//overloading
    {
        if (root == NULL)
            return true;
        int max = maxValue(root);
        max++;//increment in maximum value for getting upper bound of tree (upper).
        int min = minValue(root);
        min--;//decrement in minimum value for getting lower bound of tree (lower).
        return (validBST(root, min, max));
    }
    void swapRoot()//just swap the left and right childs of tree's root.
    {
        Node* temp = root->getLeft();
        root->setLeft(root->getRight());
        root->setRight(temp);
    }
    void nodeAtKDistance(Node* current, int k)
    {
        if (k == 0)
        {
            cout << current->getValue() << "\t";
            return;
        }
        if (current == NULL)
            return;

        nodeAtKDistance(current->getLeft(), k - 1);
        nodeAtKDistance(current->getRight(), k - 1);
    }
    void nodeAtKDistance(int k)//overloading
    {
        nodeAtKDistance(root, k);
    }
    void traverseLevelOrder()
    {
        cout << "\nLevel order travesal of the tree\n";
        int h = height(root);
        for (int i = 0; i <= h; i++)
        {
            nodeAtKDistance(i);
            cout << endl;
        }
    }
    Node* contains(Node* current,int value)//similar to find() ,but it returns the Node object as node of tree
    {
        if (current == NULL)
            return current;
        if (current->getValue() == value)
            return current;
        if (value > current->getValue())
        {
            return (contains(current->getRight(), value));
        }
        else
        {
            return (contains(current->getLeft(), value));
        }
    }
    Node* contains(int value)//overloading
    {
        Node* temp = contains(root, value);
        if (temp == NULL)
            cout << "\nNumber not found returning NULL\n";
        return temp;
    }
    Node* getAncestor(Node* current,Node* child)
    {
        if (current == NULL)
            return current;
        if (current->getLeft() == child || current->getRight()==child)
            return current;
        if (child->getValue() > current->getValue())
        {
            return (getAncestor(current->getRight(), child));
        }
        else
        {
            return (getAncestor(current->getLeft(), child));
        }
    }
    Node* getAncestor(int value)//overloading
    {
        if (value == root->getValue())
        {
            cout << "\nthis is Root of tree, therfore return NULL\n";
            return NULL;
        }
        Node* apex = contains(value);
        if (apex == NULL)
            return apex;
        return (getAncestor(root, apex));

    }
    bool areSiblings(int v1, int v2)
    {
        Node* c1 = contains(root, v1);
        Node* c2 = contains(root, v2);
        if (c1 == NULL || c2 == NULL || c1->getValue()==root->getValue()|| c2->getValue() == root->getValue())
            return false;
        int p1 = (getAncestor(root, c1))->getValue();
        int p2 = (getAncestor(root, c2)->getValue());
        
        return (p1 == p2)?true:false;
    }
};
int main()
{
    Tree t1;
    t1.insert(7);
    t1.insert(4);
    t1.insert(9);
    t1.insert(1);
    t1.insert(6);
    t1.insert(8);
    t1.insert(10);

    Tree t2;
    t2.insert(7);
    t2.insert(4);
    t2.insert(9);
    t2.insert(1);
    t2.insert(6);
    t2.insert(8);
    t2.insert(11);

    t1.traversePreOrder();
    t1.traverseInOrder();
    t1.traversePostOrder();
    t1.height();
    t1.minValue();
    t1.maxValue();
    t1.countLeaf();
    t1.size();
    t1.isEqual(&t2);
    
    t1.swapRoot();
    if (t1.validBST())
        cout << "valid BST\n";
    else
        cout << "Not valid BST\n";

    if (t2.validBST())
        cout << "valid BST\n";
    else
        cout << "Not valid BST\n";
    
    cout << endl;
    t1.nodeAtKDistance(t1.height(t1.getRoot()));

    t1.traverseLevelOrder();
    t2.traverseLevelOrder();
    
    cout<<endl<<(t2.contains(9))->getValue();
    cout << endl << (t2.getAncestor(4))->getValue();

    if (t2.areSiblings(10, 8))
        cout << "\n they are siblings\n";
    else
        cout << "\n they are not siblings";


    return 0;
}
