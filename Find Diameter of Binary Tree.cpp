#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define ll long long
#define empb emplace_back

using namespace std;


template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

void printBinaryTree(BinaryTreeNode<ll>* root)
{
    if(root== nullptr)
    {
        return;
    }
    cout<<root->data<<" : ";
    if(root->left)
    {
        cout<<"L - "<<root->left->data<<", ";
    }
    else
    {
        cout<<"L - "<<"NULL"<<", ";
    }
    if(root->right)
    {
        cout<<"R - "<<root->right->data<<", ";
    }
    else
    {
        cout<<"R - "<<"NULL"<<", ";
    }
    cout<<"\n";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}


BinaryTreeNode<ll>* takeInputBinaryTreeRecursive()
{
    cout<<"Enter Data\n";
    ll rootData;
    cin>>rootData;
    if(rootData==-1)
    {
        return nullptr;
    }
    BinaryTreeNode<ll>* root = new BinaryTreeNode<ll>(rootData);
    BinaryTreeNode<ll>* leftChild = takeInputBinaryTreeRecursive();
    BinaryTreeNode<ll>* rightChild = takeInputBinaryTreeRecursive();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}


BinaryTreeNode<ll>* takeInputBinaryTreeLevelWise()
{
    ll rootData;
    cout<<"Enter Root Data\n";
    cin>>rootData;
    if(rootData==-1)
    {
        return nullptr;
    }
    BinaryTreeNode<ll>* root = new BinaryTreeNode<ll>(rootData);
    queue<BinaryTreeNode<ll>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<ll>* current = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<current->data<<"\n";
        ll node1;
        cin>>node1;
        if(node1!=-1)
        {
            BinaryTreeNode<ll>* leftChild = new BinaryTreeNode<ll>(node1);
            pendingNodes.push(leftChild);
            current->left = leftChild;
        }
        cout<<"Enter right child of "<<current->data<<"\n";
        ll node2;
        cin>>node2;
        if(node2!=-1)
        {
            BinaryTreeNode<ll>* rightChild = new BinaryTreeNode<ll>(node2);
            pendingNodes.push(rightChild);
            current->right = rightChild;
        }
    }
    return root;
}


pair<ll,ll> binaryTreeDiameter(BinaryTreeNode<ll>* root)
{
    if(root== nullptr)
    {
        return make_pair(0,0);
    }
    ll lheight = binaryTreeDiameter(root->left).first;
    ll rheight = binaryTreeDiameter(root->right).first;
    ll ldia = binaryTreeDiameter(root->left).second;
    ll rdia = binaryTreeDiameter(root->right).second;
    ll finalHeight = 1 +  max(lheight,rheight);
    ll finaldia = max(lheight+rheight,max(ldia,rdia));
    return make_pair(finalHeight,finaldia);
}




//--------------------------------------------------------------Main Function----------------------------------------------------------------------------------------------
int main()
{
    BOOST;
// I/O Text Files


//    BinaryTreeNode<ll>* root = takeInputBinaryTreeLevelWise();
    BinaryTreeNode<ll>* root = takeInputBinaryTreeLevelWise();
    cout<<binaryTreeDiameter(root).second;
    delete root;
    return 0;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------






