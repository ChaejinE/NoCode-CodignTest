#include <iostream>
#include <vector>
#include <stack>
#include <queue>

struct Node
{
    Node(int val) : val(val), right(nullptr), left(nullptr){};
    ~Node(){};
    int val;
    Node *right;
    Node *left;
};

void recursivePreOrder(Node *node)
{
    if (!node)
        return;

    std::cout << node->val << " ";
    recursivePreOrder(node->left);
    recursivePreOrder(node->right);
}

void iterativePreorder(Node *node)
{
    std::stack<Node *> stk;
    stk.push(node);
    Node *currentNode = nullptr;
    while (!stk.empty())
    {
        currentNode = stk.top();
        std::cout << currentNode->val << " ";
        stk.pop();

        if (currentNode->right)
            stk.push(currentNode->right);
        if (currentNode->left)
            stk.push(currentNode->left);
    }
}

void recursiveInorder(Node *node)
{
    if (!node)
        return;

    recursiveInorder(node->left);
    std::cout << node->val << " ";
    recursiveInorder(node->right);
}

void iterativeInorder(Node *node)
{
    if (!node)
        return;

    std::stack<Node *> stk;
    Node *currentNode = node;
    while (true)
    {
        if (currentNode)
        {
            stk.push(currentNode);
            currentNode = currentNode->left;
        }
        else if (!stk.empty())
        {
            currentNode = stk.top();
            stk.pop();
            std::cout << currentNode->val << " ";
            currentNode = currentNode->right;
        }
        else
            break;
    }
}

void recursivePostOrder(Node *node)
{
    if (!node)
        return;

    recursivePostOrder(node->left);
    recursivePostOrder(node->right);
    std::cout << node->val << " ";
}

void interativePostOrder(Node *node)
{
    std::stack<Node *> stk;
    Node *lastVisitedNode = nullptr;
    Node *currentNode = node;

    while (true)
    {
        if (currentNode)
        {
            stk.push(currentNode);
            currentNode = currentNode->left;
        }
        else if (!stk.empty())
        {
            if (stk.top()->right && lastVisitedNode != stk.top()->right)
            {
                currentNode = stk.top()->right;
            }
            else
            {
                std::cout << stk.top()->val << " ";
                lastVisitedNode = stk.top();
                stk.pop();
            }
        }
        else
            break;
    }
}

void iterativeLevelOrder(Node *node)
{
    std::queue<Node *> q;
    q.push(node);
    Node *currentNode = nullptr;
    while (!q.empty())
    {
        currentNode = q.front();
        std::cout << currentNode->val << " ";
        q.pop();

        if (currentNode->left)
            q.emplace(currentNode->left);

        if (currentNode->right)
            q.emplace(currentNode->right);
    }
}

int main()
{
    std::vector<Node *> nodes;
    Node *node1 = new Node(1);
    nodes.emplace_back(node1);
    Node *node2 = new Node(2);
    nodes.emplace_back(node2);
    Node *node3 = new Node(3);
    nodes.emplace_back(node3);
    Node *node4 = new Node(4);
    nodes.emplace_back(node4);
    Node *node5 = new Node(5);
    nodes.emplace_back(node5);
    Node *node6 = new Node(6);
    nodes.emplace_back(node6);
    Node *node7 = new Node(7);
    nodes.emplace_back(node7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    std::cout << "Pre-order" << std::endl;
    // recursivePreOrder(node1);
    iterativePreorder(node1);
    std::cout << std::endl;

    std::cout << "In-order" << std::endl;
    // recursiveInorder(node1);
    iterativeInorder(node1);
    std::cout << std::endl;

    std::cout << "Post-order" << std::endl;
    // recursivePostOrder(node1);
    interativePostOrder(node1);
    std::cout << std::endl;

    std::cout << "Level-order" << std::endl;
    iterativeLevelOrder(node1);
    std::cout << std::endl;

    for (auto node : nodes)
        delete node;

    return 0;
}