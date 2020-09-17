#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://lx5475.github.io/2017/07/24/algorithm/algorithm-bianry-search-tree/

vector<int> order;

template <typename T>
class Tree;

template <typename T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    T x;
    T y;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(T x, T y, T data = 0, TreeNode *left = NULL, TreeNode *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
        this->x = x;
        this->y = y;
    }
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;

public:
    Tree(T x, T y, T data = 0)
    {
        root = new TreeNode<T>(x, y, data);
    }

    void insert(TreeNode<T> *node)
    {
        // 중복이 없다면
        if (find(root, node->data) == NULL)
        {
            TreeNode<T> *parent = NULL;
            TreeNode<T> *current = root;

            // 삽입할 위치까지 찾아들어간다.
            while (current != NULL)
            {
                parent = current;
                if (node->x < parent->x)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }

            // 찾아들어간후
            // 해당 위치에 값을 삽입
            if (node->x < parent->x)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
        }
    }

    TreeNode<T>* find(TreeNode<T> *current, T data)
    {
        if (current == NULL)
        {
            return NULL;
        }
        
        if (data == current->data)
        {
            return current;
        }
        else if (data < current->data)
        {
            return find(current->left, data);
        }
        else
        {
            return find(current->right, data);
        }
    }

    void preOrder(TreeNode<T> *current)
    {
        if (current != NULL)
        {
            order.push_back(current->data);
            preOrder(current->left);
            preOrder(current->right);
        }
    }

    void postOrder(TreeNode<T> *current)
    {
        if (current != NULL)
        {
            postOrder(current->left);
            postOrder(current->right);
            order.push_back(current->data);
        }
    }

    TreeNode<T> *getRoot()
    {
        return root;
    }
};

class Info {
public:
    int i;
    int x;
    int y;

    Info(int i, int x, int y)
    {
        this->i = i;
        this->x = x;
        this->y = y;
    }
};

bool comp(Info a, Info b)
{
    return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer(2);
    int nodeinfo_size = nodeinfo.size();

    vector<Info> copy_info;

    for (int i = 0; i < nodeinfo_size; ++i)
    {
        copy_info.push_back(Info(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
    }

    // y 좌표가 큰 순으로 정렬
    sort(copy_info.begin(), copy_info.end(), comp);

    Tree<int> tree(copy_info[0].x, copy_info[0].y, copy_info[0].i);
    copy_info.erase(copy_info.begin());
    
    for (int idx = 0; idx < copy_info.size(); ++idx)
    {
        tree.insert(new TreeNode<int>(copy_info[idx].x, copy_info[idx].y, copy_info[idx].i));
    }

    order.clear();
    tree.preOrder(tree.getRoot());
    answer[0] = order;
    order.clear();
    tree.postOrder(tree.getRoot());
    answer[1] = order;
    
    return answer;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> nodeinfo(n, vector<int>(2));

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        nodeinfo[i][0] = x;
        nodeinfo[i][1] = y;
    }

    vector<vector<int>> result = solution(nodeinfo);

}