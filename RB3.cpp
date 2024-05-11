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
    char animal;
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

    void insert(char value)
    {

        _root = __insert(_root, value);
        _size++;
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
    BSTNode *__createNode(char value)
    {
        BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
        newNode->animal = value;
        // sprintf(newNode->animal, value);
        // newNode->animal = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *__insert(BSTNode *root, char value)
    {
        if (root == NULL)
            return __createNode(value);

        if ((int)root->animal > (int)value)
            root->left = __insert(root->left, value);
        else if ((int)root->animal < (int)value)
            root->right = __insert(root->right, value);

        // if (strcmp(value, root->animal) < 0)
        //     root->left = __insert(root->left, value);
        // else if (strcmp(value, root->animal) > 0)
        //     root->right = __insert(root->right, value);

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
            int temp = root->animal - 48;
            if (!(temp >= 0 && temp <= 9))
            {
                if ((int)root->animal == '37')
                {
                    cout << "% ";
                }
                else
                {
                    cout << (char)root->animal << " ";
                }
            }
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root)
    {
        if (root)
        {
            __postorder(root->left);
            __postorder(root->right);
            int temp = root->animal - 48;
            if (!(temp >= 0 && temp <= 9))
            {
                if ((int)root->animal == 37)
                {
                    cout << "% ";
                }
                else
                {
                    cout << (char)root->animal << " ";
                }
            }
        }
    }

    void __preorder(BSTNode *root)
    {
        if (root)
        {
            int temp = root->animal - 48;
            if (!(temp >= 0 && temp <= 9))
            {
                if ((int)root->animal == 37)
                {
                    cout << "% ";
                }
                else
                {
                    cout << (char)root->animal << " ";
                }
            }
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
    char move;

    cin >> n_move;

    for (int i = 0; i < n_move; i++)
    {
        cin >> move;

        // cout << "inserted\n";
        set.insert(move);
        // cout << move << "inserted";
    }
    // cout << "\npreorder\n";
    set.traversePreorder();
    cout << "\n";
    // cout << "\ninorder\n";
    set.traverseInorder();
    cout << "\n";
    // cout << "\npostorder\n";
    set.traversePostorder();
    cout << "\n";
    return 0;
}