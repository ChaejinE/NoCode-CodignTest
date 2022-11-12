#include <iostream>

struct Node
{
    Node(int val) : val(val){};
    ~Node()
    {
        std::cout << val << " 값을 갖고 있던 노드 소멸자 호출" << std::endl;
    };

    int val;
    Node *next = nullptr;
};

class MyLinkedList
{
public:
    MyLinkedList() = default;
    MyLinkedList(Node *head) : head(head){};
    ~MyLinkedList()
    {
        std::cout << "Linked List 소멸자 호출" << std::endl;
        Node *curNode = this->head;
        Node *next;

        while (curNode)
        {
            next = curNode->next;
            delete curNode;
            curNode = next;
        }
    };

    void addAtHead(int val) // O(1)
    {
        Node *newNode = new Node(val);
        newNode->next = this->head;
        this->head = newNode;
    }

    void addBack(int val) // O(n)
    {
        if (!this->head)
            return;

        Node *newNode = new Node(val);
        Node *curNode = this->head;

        while (curNode->next)
            curNode = curNode->next;

        curNode->next = newNode;
    }

    Node *findNode(int val) // O(n)
    {
        Node *curNode = this->head;
        while (curNode)
        {
            if (curNode->val == val)
            {
                std::cout << val << " is exist" << std::endl;
                return curNode;
            }
            else
                curNode = curNode->next;
        }

        throw std::runtime_error("Not Exist Node that has value");
    }

    void addAfter(Node *node, int val) // O(1)
    {
        Node *newNode = new Node(val);
        newNode->next = node->next;
        node->next = newNode;
    }

    void deleteAfter(Node *prevNode) // O(1)
    {
        if (!prevNode->next)
            return;

        Node *deleteNode = prevNode->next;
        prevNode->next = prevNode->next->next;
        delete deleteNode;
    }

    Node *getHead()
    {
        return head;
    }

private:
    Node *head = nullptr;
};

void printNodes(Node *currentNode)
{
    while (currentNode)
    {
        std::cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}
int main()
{
    MyLinkedList linkedList = MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtHead(2);
    linkedList.addBack(3);

    try
    {
        Node *node = linkedList.findNode(1);
        linkedList.addAfter(node, 4);
        node = linkedList.findNode(4);
        linkedList.deleteAfter(node);
    }
    catch (std::runtime_error err)
    {
        std::cout << err.what() << std::endl;
    }

    printNodes(linkedList.getHead());

    return 0;
}