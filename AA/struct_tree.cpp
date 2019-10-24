#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int key;
    struct node
        *left,
        *right;
};

void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
struct node *add(int key);
struct node *insert(node *node, int key);
struct node *search(node *node, int key);
void showRightSibling(node *node, int key);
struct node *digLeft(node *node);
struct node *deleteNode(node *root, int key);

int main()
{
    struct node *root = NULL;
    unsigned short int
        option,
        key;

    while (1)
    {
        cout << "\n0. Exit";
        cout << "\n1. Insert a node";
        cout << "\n2. Display preorder";
        cout << "\n3. Display inorder";
        cout << "\n4. Display postorder";
        // cout << "\n6. Get parent of";
        cout << "\n7. Get right sibling";
        cout << "\n5. Delete a node";
        cout << "\nOption: ";
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "\nExecution terminated";
            return 0;
            break;
        case 1:
            cout << "Node key: ";
            cin >> key;
            root = insert(root, key);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        // case 6:
        //     searchParentOf(keys, parents, n);
        //     break;
        case 7:
            cout << "Node key: ";
            cin >> key;
            showRightSibling(root, key);
            break;
        case 5:
            cout << "Node key: ";
            cin >> key;
            deleteNode(root, key);
            break;
        default:
            cout << "\nInvalid option";
            break;
        }
    }
}

void preorder(struct node *head)
{
    if (head != NULL)
    {
        cout << head->key << " ";
        preorder(head->left);
        preorder(head->right);
    }
}
void inorder(struct node *head)
{
    if (head != NULL)
    {
        inorder(head->left);
        cout << head->key << " ";
        inorder(head->right);
    }
}
void postorder(struct node *head)
{
    if (head != NULL)
    {
        postorder(head->left);
        postorder(head->right);
        cout << head->key << " ";
    }
}

struct node *add(int key)
{
    struct node *clone = (struct node *)malloc(sizeof(struct node));
    clone->key = key;
    clone->left = NULL;
    clone->right = NULL;
    return clone;
}

struct node *insert(struct node *head, int key)
{
    if (head == NULL)
        return add(key);
    if (key < head->key)
        head->left = insert(head->left, key);
    else if (key > head->key)
        head->right = insert(head->right, key);
    else
        cout << "This node already exists";
    return head;
}

struct node *search(node *head, int key)
{
    if (head == NULL || head->key == key)
        return head;
    else if (key > head->key)
        return search(head->right, key);
    else
        return search(head->left, key);
}

void showRightSibling(struct node *head, int key)
{
    head = search(head, key);
    if (head)
        cout << "Sibling key is: " << head -> key;
    else
        cout << "This node does not have a right sibling";
}

node *digLeft(node *head)
{
    node *current = head;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(node *head, int key)
{
    if (head == NULL)
        return head;

    if (key < head->key)
        head->left = deleteNode(head->left, key);

    else if (key > head->key)
        head->right = deleteNode(head->right, key);

    else
    {
        if (head->left == NULL)
        {
            struct node *temp = head->right;
            free(head);
            return temp;
        }
        else if (head->right == NULL)
        {
            struct node *temp = head->left;
            free(head);
            return temp;
        }

        struct node *temp = digLeft(head->right);

        head->key = temp->key;

        head->right = deleteNode(head->right, temp->key);
    }
    return head;
}
