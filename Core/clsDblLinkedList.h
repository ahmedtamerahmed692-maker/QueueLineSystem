#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;
private:
    class Node {
    public:
        T Value;
        Node* Next;
        Node* Prev;
    };
    Node* Head;

    Node* findNode(T target) {
        Node* current = Head;
        while (current != NULL) {
            if (current->Value == target)
                return current;
            current = current->Next;
        }
        return NULL;
    }

public:
    clsDblLinkedList() {
        Head = NULL;
    }

    ~clsDblLinkedList() {
        Clear();
    }

    void InsertAtBeginning(T Value) {
        Node* NewNode = new Node();
        NewNode->Value = Value;
        NewNode->Next = Head;
        NewNode->Prev = NULL;
        if (Head != NULL) Head->Prev = NewNode;
        Head = NewNode;
        _Size++;
    }

    void InsertAfter(Node* node, T NewValue)
    {
        if (node == NULL)
            return;

        Node* nextNode = node->Next;

        Node* NewNode = new Node();
        NewNode->Value = NewValue;
        NewNode->Next = nextNode;
        NewNode->Prev = node;

        if (nextNode != NULL)
            nextNode->Prev = NewNode;

        node->Next = NewNode;

        _Size++;
    }
    void InsertAfter(T TargetValue, T NewValue)
    {
        InsertAfter(findNode(TargetValue), NewValue);
    }

    void InsertAtEnd(T NewValue) {
        Node* newNode = new Node();
        newNode->Value = NewValue;
        newNode->Next = NULL;
        if (Head == NULL) {
            newNode->Prev = NULL;
            Head = newNode;
        }
        else {
            Node* current = Head;
            while (current->Next != NULL)
                current = current->Next;
            current->Next = newNode;
            newNode->Prev = current;
        }
        _Size++;

    }

    void DeleteNode(Node* target)
    {
        if (target == NULL)
            return;

        Node* prevNode = target->Prev;
        Node* nextNode = target->Next;

        if (prevNode == NULL)
            Head = nextNode;
        else
            prevNode->Next = nextNode;

        if (nextNode != NULL)
            nextNode->Prev = prevNode;

        delete target;
        _Size--;
    }
    void DeleteNode(T Value)
    {
        DeleteNode(findNode(Value));
    }
    void DeleteFirstNode() {
        if (Head == NULL) return;
        Node* temp = Head;
        Head = Head->Next;
        if (Head != NULL)
            Head->Prev = NULL;
        delete temp;
        _Size--;

    }

    void DeleteLastNode() {
        if (Head == NULL) return;
        if (Head->Next == NULL) {
            delete Head;
            _Size--;
            Head = NULL;
            return;
        }
        Node* current = Head;
        while (current->Next->Next != NULL)
            current = current->Next;
        Node* temp = current->Next;
        current->Next = NULL;
        delete temp;
        _Size--;

    }


    void PrintList() {
        Node* current = Head;
        cout << "NULL <--> ";
        while (current != NULL) {
            cout << current->Value << " <--> ";
            current = current->Next;
        }
        cout << "NULL\n";
    }

    void PrintListDetails() {
        Node* current = Head;
        cout << "\n\n";
        while (current != NULL) {
            if (current->Prev != NULL)
                cout << current->Prev->Value;
            else
                cout << "NULL";
            cout << " <--> " << current->Value << " <--> ";
            if (current->Next != NULL)
                cout << current->Next->Value << "\n";
            else
                cout << "NULL\n";
            current = current->Next;
        }
    }

    void Clear() {
        while (Head != NULL) {
            Node* temp = Head;
            Head = Head->Next;
            delete temp;
        }
        _Size = 0;
    }
    int Size()
    {
        return _Size;
    }
    
    bool IsEmpty()
    {
        return  (Head == NULL); 
   
    }

    void Reverse()
    {
        Node* current = Head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->Prev;          // احفظ الـ Prev القديم
            current->Prev = current->Next; // Prev بقى الـ Next القديم
            current->Next = temp;          // Next بقى الـ Prev القديم
            current = current->Prev;       // تحرك للأمام (Prev = Next القديم)
        }
        if (temp != nullptr) {
            Head = temp->Prev; // temp = آخر node قبل NULL، prev بتاعه = آخر node ✅
        }
    }
   /** void Reverse()
    {
        if (Head == NULL) return;

        Node* current = Head;
        while (current->Next != NULL) {
            current = current->Next;
        }
        Node* Left = Head;
        Node* Right = current;
        while (Left != Right && Right->Next != Left)
        {
            T temp = Left->Value;// حفظت 1
            Left->Value = Right->Value; // Left = 5
            Right->Value = temp;        // Right = 1 ✅

            Left = Left->Next;
            Right = Right->Prev;
        }
    }*/
    /*void Reverse()
   {
    if (Head == NULL) return;
    
    Node* Current = Head;
    
    // خطوة 1: ضيف كل قيمة في الأول
    while (Current != NULL)
    {
        InsertAtBeginning(Current->Value);
        Current = Current->Next;
    }
    
    // خطوة 2: امسح النص التاني
    for (int i = 0; i < _Size / 2; i++)
    {
        DeleteLastNode();
    }

    }*/

    Node* GetNode(int index)
    {
        if (index<0 || index >= _Size)
            return NULL;

        Node* current = Head;

        for (int i = 0; i < index; i++)
        {
            current = current->Next;
        }

        return current;
    }
   /* Node* GetNode(int Index)
    {

        int Counter = 0;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node* Current = head;
        while (Current != NULL && (Current->next != NULL)) {

            if (Counter == Index)
                break;

            Current = Current->next;
            Counter++;

        }

        return Current;
    }*/
    T GetItem(int Index)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return T();   

        return ItemNode->Value;
    }
    Node* FindNodeByIndex(int Index)
    {
        return GetNode(Index);
    }
    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode == NULL)
            return false;

        ItemNode->Value = NewValue;
        return true;
    }

    bool InsertAfterIndex(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else
            return false;  
    }
    


};
