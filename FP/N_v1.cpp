#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int value)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return _avl_createNode(value);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _preorder(AVLNode *node)
    {
        if (node)
        {
            printf("%d ", node->data);
            _preorder(node->left);
            _preorder(node->right);
        }
    }

    void _depth_search(AVLNode *node, vector<vector<int>> &list_enemy, int depth)
    {
        if (node)
        {
            if (list_enemy.size() <= (long unsigned int)depth)
                list_enemy.resize(depth + 1);
            list_enemy[depth].push_back(node->data);
            _depth_search(node->left, list_enemy, depth + 1);
            _depth_search(node->right, list_enemy, depth + 1);
        }
    }

public:
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void preorder()
    {
        this->_preorder(_root);
    }

    void depth_search(vector<vector<int>> &list_enemy)
    {
        this->_depth_search(_root, list_enemy, 0);
    }
};

int main(int argc, char const *argv[])
{
    AVL set;
    map<int, int> monster_code;
    set.init();

    int loop_monter;
    double charac_str;
    string place, charac_name, charac_power;

    cin >> charac_name >> loop_monter >> charac_power >> charac_str >> place;

    int monster_kode, monster_str;
    for (int i = 0; i < loop_monter; i++)
    {
        cin >> monster_kode >> monster_str;
        monster_code[monster_kode] = monster_str;
        set.insert(monster_kode);
    }

    int stage = 1;

    vector<vector<int>> list_enemy;
    set.depth_search(list_enemy);

    int atck_comb = 0, winnner = 1, loss_stage = 0;

    cout << "*****************************************************************************" << endl;
    cout << "Honkai Star Rail Region " << place << endl
         << endl;
    cout << "Trailblazer : " << charac_name << endl;
    cout << "Element : " << charac_power << " - " << charac_str << endl;

    cout << "----------------------------------------------------------------------------" << endl;
    for (auto i = list_enemy.rbegin(); i != list_enemy.rend(); ++i)
    {
        if ((int)charac_str % 2 == 0)
        {
            charac_str = charac_str * 108 / 100;
        }
        else
        {
            charac_str = charac_str * 115 / 100;
        }

        if ((long unsigned int)stage != list_enemy.size())
        {
            cout << "Stage " << stage << ":" << endl;
        }
        else
        {
            cout << "Final Stage:" << endl;
        }

        atck_comb = 0;
        int monster_counter = 1;
        for (auto j = i->begin(); j != i->end(); ++j)
        {
            if ((long unsigned int)stage < list_enemy.size())
            {
                cout << "Monster " << char(monster_counter + 64) << *j << "_" << stage << "_" << monster_counter << ": " << monster_code[*j] << endl;
                atck_comb += monster_code[*j];
            }
            else
            {
                cout << "Final Boss " << place << "_" << *j << ": " << monster_code[*j] << endl;
                atck_comb += monster_code[*j];
            }
            monster_counter++;
        }

        charac_str -= atck_comb;
        // cout << "our character is at " << charac_str << endl;

        if (charac_str <= 0 && winnner != 0)
        {
            winnner = 0;
            loss_stage = stage;
        }
        cout << endl;
        stage++;
    }
    cout << "Result:" << endl;

    if (winnner)
    {
        cout << charac_name << " menang melawan Final Boss dan memenangkan game di Honkai Star Rail Region " << place << endl;
    }
    else if (winnner == 0 && (long unsigned int)loss_stage != list_enemy.size())
    {
        cout << charac_name << " kalah dan mati di Region " << place << " pada Stage " << loss_stage << endl;
    }
    else
    {
        cout << charac_name << " kalah dan mati di Region " << place << " pada Final Stage" << endl;
    }

    cout << "*****************************************************************************";
    // cout << list_enemy.size();
    // printf("\n");
    return 0;
}
