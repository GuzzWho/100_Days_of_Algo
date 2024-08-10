#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node *createNode(int key)
{
    return new Node(key);
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return createNode(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

Node *minVal(Node *root)
{
    Node *current = root;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node *maxVal(Node *root)
{
    Node *current = root;
    while (current && current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}

Node *search(Node *root, int key)
{
    if (root == nullptr || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inorder(Node *root, vector<int> &result)
{
    if (root != nullptr)
    {
        inorder(root->left, result);
        result.push_back(root->key);
        inorder(root->right, result);
    }
}


void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void deleteTree(Node *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

Node *deleteNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minVal(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

Node *balanceTree(Node *root, vector<int> &inorder_list, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = (start + end) / 2;
    Node *node = createNode(inorder_list[mid]);
    node->left = balanceTree(root, inorder_list, start, mid - 1);
    node->right = balanceTree(root, inorder_list, mid + 1, end);
    return node;
}

bool isBST(Node *root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->key < min || root->key > max)
    {
        return false;
    }
    return isBST(root->left, min, root->key - 1) && isBST(root->right, root->key + 1, max);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 18);

    vector<int> inorder_list;
    inorder(root, inorder_list);
    balanceTree(root,inorder_list,0,inorder_list.size()-1);
    cout << endl;
    deleteNode(root, 15);
    postorder(root);
    cout << endl;   
    preorder(root);
    cout << endl;
    cout << isBST(root, minVal(root)->key, maxVal(root)->key) << endl;
    return 0;
}
