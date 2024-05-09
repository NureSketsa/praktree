/**
 * Implementasi Binary Search Tree (ADT: BST)
 * yakni BST yang tidak menyimpan key duplikat (unique key)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 29 Februrari 2019
 * Struktur Data 2020
 *
 * Implementasi untuk Bahasa C++
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* Node structure */

struct BSTNode
{
    BSTNode *left, *right;
    char *animal;
};

/* uniqueBST */

struct BST
{
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
    void init()
    {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(char *value)
    {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (strcmp(value, temp->animal) == 0)
            return true;
        else
            return false;
    }

    void insert(char *value)
    {
        if (!find(value))
        {
            cout << value;
            _root = __insert(_root, value);
            _size++;
        }
    }

    void traverseInorder()
    {
        __inorder(_root);
    }

    void traversePreorder()
    {
        __preorder(_root);
    }

    void traversePostorder()
    {
        __postorder(_root);
    }

private:
    // Utility Function
    BSTNode *__createNode(char *value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->animal = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, char *value)
    {
        while (root != NULL)
        {
            if (strcmp(value, root->animal) < 0)
                root = root->left;
            else if (strcmp(value, root->animal) > 0)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode *__insert(BSTNode *root, char *value)
    {
        if (root == NULL)
            return __createNode(value);

        if (strcmp(value, root->animal) < 0)
            root->left = __insert(root->left, value);
        else if (strcmp(value, root->animal) > 0)
            root->right = __insert(root->right, value);

        return root;
    }

    BSTNode *__findMinNode(BSTNode *node)
    {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;

        return currNode;
    }

    void __inorder(BSTNode *root)
    {
        if (root)
        {
            __inorder(root->left);
            printf("%s ", root->animal);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            printf("%s ", root->animal);
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            printf("%s ", root->animal);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    BST set;
    set.init();

    int n_move;
    char *move;

    cin >> n_move;

    for (int i = 0; i < n_move; i++)
    {
        cin >> move;

        cout << "inserted\n";
        set.insert(move);
        // cout << move << "inserted";
    }

    cout << "\nanswer\n";
    set.traverseInorder();

    return 0;
}