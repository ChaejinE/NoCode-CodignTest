#include <iostream>
#include <memory>
#include <vector>

class ListNode
{
public:
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(const ListNode &node)
    {
        this->val = node.val;
        this->next = node.next;
    }
    ~ListNode(){};

    int val;
    std::shared_ptr<ListNode> next;
};

void printNodes(ListNode currentNode)
{
    while (true)
    {
        std::cout << currentNode.val << std::endl;

        if (currentNode.next == nullptr)
            break;

        currentNode = *currentNode.next;
    }
}

int main()
{
    ListNode head = ListNode(1);
    head.next = std::make_shared<ListNode>(ListNode(2));
    head.next->next = std::make_shared<ListNode>(ListNode(3));
    head.next->next->next = std::make_shared<ListNode>(ListNode(4));

    printNodes(head);
    return 0;
}
