#include <iostream>
using namespace std;
class Tree
{
public:
    int* root;
    int length;
    Tree(int* root = NULL, int length = 0)
    {
        this->root = root;
        this->length = length;
    }
    bool isEmpty()
    {
        return (root == NULL);
    }
    int leftIndex(int index)
    {
        return ((2 * index) + 1);
    }
    int rightIndex(int index)
    {
        return ((2 * index) + 2);
    }
    int parentIndex(int index)
    {
        return ((index - 1) / 2);
    }
    bool isleaf(int index)
    {
        return ((root[leftIndex(index)] == -9999) && (root[rightIndex(index)]));
    }
    void increaseSize(int num)
    {
        int* temp = new int[length + num];
        for (int i = 0; i < (length + num); i++)
            temp[i] = -9999;

            if (isEmpty())
            {
                root = temp;
                length = length + num;
                return;
            }

            for (int i = 0; i < length; i++)
                temp[i] = root[i];

            length = length + num;
            delete root;
            root = temp;

    }
    void insert(int val)
    {
        if (isEmpty())
        {
            increaseSize(3);
            root[0] = val;
            return;
        }
        increaseSize(2);
        int index=0;

        while (index<length)
        {
            if (root[index] == -9999)
            {
                root[index]=val;
                break;
            }
            else if (root[index] < val)
            {
                index = rightIndex(index);
            }
            else
            {
                index = leftIndex(index);
            }
        }
    }
    void traversePreOrder(int index)
    {
        if (root[index] == -9999)
            return;

        cout << root[index] << "\t";
        traversePreOrder(leftIndex(index));
        traversePreOrder(rightIndex(index));
    }
    void traversePreOrder()//overloading
    {
        if (!(isEmpty()))
        {
            cout << "\nPreOrder of the tree is ";
            traversePreOrder(0);
            cout << endl;
        }
        else
        {
            cout << "\nTree is empty therefore no preorder traverse";
        }
    }
    void traverseInOrder(int index)
    {
        if (root[index] == -9999)
            return;

        traverseInOrder(leftIndex(index));
        cout << root[index] << "\t";
        traverseInOrder(rightIndex(index));
    }
    void traverseInOrder()//overloading
    {
        if (!(isEmpty()))
        {
            cout << "\nInOrder of the tree is ";
            traverseInOrder(0);
            cout << endl;
        }
        else
        {
            cout << "\nTree is empty therefore no inorder traverse";
        }
    }
    void traversePostOrder(int index)
    {
        if (root[index] == -9999)
            return;

        traversePostOrder(leftIndex(index));
        traversePostOrder(rightIndex(index));
        cout << root[index] << "\t";
    }
    void traversePostOrder()//overloading
    {
        if (!(isEmpty()))
        {
            cout << "\nPreOrder of the tree is ";
            traversePostOrder(0);
            cout << endl;
        }
        else
        {
            cout << "\nTree is empty therefore no postorder traverse";
        }
    }
    int levelOfTree()
    {
        if (!(isEmpty()))
        {
            int elements = 0, level = 0;
            for (int i = 0; elements != length; i++)
            {
                level++;
                elements = elements + pow(2, i);
            }
            level--;
            return level;
        }

        cout << "\nNo element in tree ,return -9999(junck value)\n";
        return -9999;
    }
    void levelOrderTraverse()
    {
        int index = 0;
        int levels = levelOfTree();

        if (levels == -9999)
            return;
        
        for(int i = 0; i <= levels; i++)
        {
            for (int j = 1; j <= pow(2, i); j++)
            {
                if (root[index] != -9999)
                    cout << root[index] << "\t";
                index++;
            }
            cout << endl;
        }
    }
    int countLeaf(int index)
    {
        if (isleaf(index))
            return 1;

        return 0 + countLeaf(leftIndex(index)) + countLeaf(rightIndex(index));
    }
    void countLeaf()//overloading
    {
        if (isEmpty())
        {
            cout << "\nEmpty tree\n";
            return ;
        }

        cout << "\nThere are " << countLeaf(0) << " leaf in this tree\n";

    }
    int countElements(int index)
    {
        if (root[index] == -9999)
            return 0;

        return 1 + countElements(leftIndex(index)) + countElements(rightIndex(index));
    }
    void countElements()//overloading
    {
        if (isEmpty())
        {
            cout << "\nZero elements\n";
            return;
        }
        cout << "\nThere are " << countElements(0) << " elements in the Tree";
    }
    int maxValue(int index)
    {
        if (root[rightIndex(index)] == -9999)
            return root[index];

        return maxValue(rightIndex(index));
    }
    void maxValue()//overloading
    {
        if (isEmpty())
        {
            cout << "\n Tree is empty\n";
            return;
        }
        cout << "\n Maximum value is " << maxValue(0);
    }
    int minValue(int index)
    {
        if (root[leftIndex(index)] == -9999)
            return root[index];

        return minValue(leftIndex(index));
    }
    void minValue()//overloading
    {
        if (isEmpty())
        {
            cout << "\n Tree is empty\n";
            return;
        }
        cout << "\n Minimum value is " << minValue(0);
    }
};
int main()
{
    Tree t1;
    t1.insert(7);
    t1.insert(5);
    t1.insert(9);
    t1.insert(6);
    t1.insert(4);
    t1.insert(8);
    t1.insert(10);

    
    t1.traversePreOrder();
    t1.traverseInOrder();
    t1.traversePostOrder();

    t1.levelOrderTraverse();
    
    t1.countLeaf();
    t1.countElements();
    t1.maxValue();
    t1.minValue();
    return 0;
}
