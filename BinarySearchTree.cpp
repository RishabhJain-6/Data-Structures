#include <iostream>
using namespace std;

class BST {
    public:
        int data;
        BST* left;
        BST* right;
        
        BST (int a)
        {
            data = a;
            left = right = NULL;
        }
};

BST* insert(BST* root, int value)
{
    if (root==NULL)
    {
        return new BST(value);
    }
    
    if (value>root->data)
    {
        root->right=insert(root->right,value);
    }
    else if (value<root->data)
    {
        root->left=insert(root->left,value);
    }
    return root;
}

BST* delete_node(BST* root,int key)
{
    if (root)
    {
        if (key<root->data)
        {
            root->left = delete_node(root->left,key);
        }
        else if (key>root->data)
        {
            root->right = delete_node(root->right,key);
        }
        else
        {
            if (!root->left && !root->right)
            {
                return NULL;
            }
            else if (!root->left || !root->right)
            {
                return root->left ? root->left : root->right;
            }
            BST* temp = root->left;
            while (temp->right != NULL)
            {
                temp=temp->right;
            }
            root->data=temp->data;
            root->left=delete_node(root->left,temp->data);
        }
    }
    return root;
}

BST* search(BST* root,int target)
{
    if (root==NULL || root->data==target)
    {
        return root;
    }
    else if (root->data<target)
    {
        return search(root->right,target);
    }
    else
    {
        return search(root->left,target);
    }
}

int height(BST* root)
{
    if (root==NULL)
    {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    if (left_height>right_height)
    {
        return left_height+1;
    }
    else
    {
        return right_height+1;
    }
}

void printCurrentLevel(BST* root,int level)
{
    if (root==NULL)
    {
        return;
    }
    if (level==1)
    {
        cout<<root->data<<"  ";
    }
    else if (level>1)
    {
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void levelOrderTraversal(BST* root)
{
    int h = height(root);
    for (int i=1;i<=h;i++)
    {
        printCurrentLevel(root,i);
        cout<<endl;
    }
}

void preOrder(BST* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"  ";
    preOrder(root->left);
    preOrder(root->right);
}
       
void inOrder(BST* root)
{
    if (root==NULL)
    {
        return;
        
    }
    inOrder(root->left);
    cout<<root->data<<"  ";
    inOrder(root->right);
}

void postOrder(BST* root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"  ";
}

int main()
{
    BST* root = NULL;
    char ch='y';
    while (ch=='y' || ch=='Y')
    {
        cout<<"Available options on the BST -->"<<endl;
        cout<<"1.\tInsert n elements"<<endl;
        cout<<"2.\tDelete an element x"<<endl;
        cout<<"3.\tSearch an element x"<<endl;
        cout<<"4.\tSearch an element x and change its value to y and adjust the BST accordingly"<<endl;
        cout<<"5.\tPreOrder Traversal"<<endl;
        cout<<"6.\tInOrder Traversal"<<endl;
        cout<<"7.\tPostOrder Traversal"<<endl;
        cout<<"8.\tLevel Wise Traversal"<<endl;
        cout<<"9.\tDisplay height of BST"<<endl;
        cout<<"Enter your Selection: ";
        int choice;
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter number of values you want to insert: ";
                int n;
                cin>>n;
                for (int i=0;i<n;i++)
                {
                    cout<<"Enter value you want to insert: ";
                    int x;
                    cin>>x;
                    root = insert(root,x);
                }
                break;
            }
            case 2:
            {
                cout<<"Enter value you want to delete: ";
                int x;
                cin>>x;
                BST* temp = search(root,x);
                if (temp==NULL)
                {
                    cout<<"Element "<<x<<" not present in the BST";
                    break;
                }
                root = delete_node(root,x);
                break;
            }
            case 3:
            {
                cout<<"Enter value you want to search: ";
                int x;
                cin>>x;
                BST* temp = search(root,x);
                if (temp==NULL)
                {
                    cout<<"Element "<<x<<" not present in the BST";
                }
                else
                {
                    cout<<"Element found";
                }
                break;
            }
            case 4:
            {
                cout<<"Enter value you want to search: ";
                int x;
                cin>>x;
                BST* temp = search(root,x);
                if (temp==NULL)
                {
                    cout<<"Element "<<x<<" not present in the BST";
                }
                else
                {
                    cout<<"Enter value you want to replace "<<x<<" with: ";
                    int y;
                    cin>>y;
                    root = delete_node(root,x);
                    root = insert(root,y);
                }
                break;
            }
            case 5:
            {
                if (root==NULL)
                {
                    cout<<"No BST tree exists"<<endl;
                    break;
                }
                cout<<"\nPreOrder Traversal->"<<endl;
                preOrder(root);
                break;
            }
            case 6:
            {
                if (root==NULL)
                {
                    cout<<"No BST tree exists"<<endl;
                    break;
                }
                cout<<"\nInOrder Traversal->"<<endl;
                inOrder(root);
                break;
            }
            case 7:
            {
                if (root==NULL)
                {
                    cout<<"No BST tree exists"<<endl;
                    break;
                }
                cout<<"\nPostOrder Traversal->"<<endl;
                postOrder(root);
                break;
            }
            case 8:
            {
                if (root==NULL)
                {
                    cout<<"No BST tree exists"<<endl;
                    break;
                }
                cout<<"\nLevel Wise Traversal->"<<endl;
                levelOrderTraversal(root);
                break;
            }
            case 9:
            {
                int h = height(root);
                cout<<"Current height of tree: "<<h<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid Selection"<<endl;
                break;
            }
        }
        
        cout<<"\nEnter y to continue or press any key to exit: ";
        cin>>ch;
    }
}
