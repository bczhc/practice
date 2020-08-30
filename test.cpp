#include "LinearList.hpp"
#include <cstdio>

using namespace bczhc::linearlist;
using Node = LinkedList<int>::Node;
bool hasLoop(bczhc::linearlist::LinkedList<int>::Node *first) {
    Node *slow = first, *fast = slow;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next, fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {
    bczhc::linearlist::LinkedList<int>::Node n1(1, nullptr);
    bczhc::linearlist::LinkedList<int>::Node n2(2, nullptr);
    bczhc::linearlist::LinkedList<int>::Node n3(3, nullptr);
    bczhc::linearlist::LinkedList<int>::Node n4(4, nullptr);
    bczhc::linearlist::LinkedList<int>::Node n5(5, nullptr);
    bczhc::linearlist::LinkedList<int>::Node n6(6, nullptr);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n3;
    LinkedList<int>::Node *first = &n1;
    bool r = hasLoop(first);
    printf("%s\n", r ? "true" : "false");
}
