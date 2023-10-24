#include "Ejercicio01.h"

Node<char>* Ejercicio01::rotateRight(Node<char>* head, int k)
{
    int n = 1;
    Node<char>* last = head;
    Node<char>* newHead = head;

    while (last->next != nullptr)
    {
        n++;
        last = last->next;
    }

    last->next = head;
    int steps = n - (k % n);

    for (int i = 0; i < steps; i++)
    {
        newHead = newHead->next;
    }

    Node<char>* newLast = newHead;

    while (newLast->next != newHead)
    {
        newLast = newLast->next;
    }

    newLast->next = nullptr;
}
