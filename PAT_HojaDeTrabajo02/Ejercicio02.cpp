#include "Ejercicio02.h"

Node<int>* Ejercicio02::addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
    int carry;
    int value = carry;

    if (l1 != nullptr) 
    {
        value += l1->value;
    }

    if (l2 != nullptr)
    {
        value += l2->value;
    }

    Node<int>* result = new Node<int>();
    result->value = value % 10;
    carry = value / 10;

    if (l1 != nullptr) 
    {
        l1 = l1->next;
    }

    if (l2 != nullptr)
    {
        l2 = l2->next;
    }

    result->next = addTwoNumbers(l1, l2);
    return result;
}
