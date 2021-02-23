#include <bits/stdc++.h>
using namespace std;
 
class node
{
public:
    int val;
    node *next = nullptr;
};
 
class List
{
    node *head;
    node *tail;
 
public:
    List() {
        head = nullptr;
        tail = nullptr;
    }
    bool isEmpty ()
    {
        return (head == nullptr);
    }
    void insertAtFront (int val);
    void insertAtBack (int val);
    void removeFromFront ();
    void removeFromBack ();
    void removeEvens ();
    void removeOdds();
    void removePrimes ();
    void removeAllOcuurences (int value); //value can be max element or min element
    int getFront ();
    int getBack ();
    int getK_th (int k);
    int max_element ();
    int min_element ();
    int Size();
    void print ();
    void Sort();
    void Reverse();
    ~List();
};
 
bool isPrime (int value)
{
    for (int i=2; i*i <= value; i++)
    {
        if (value % i == 0)
            return false;
    }
    return !(value == 1 || !value);
}
 
int main()
{
    List l;
    cout << "Is the list empty? -->" << ((l.isEmpty()) ? "(YES)\n" : "(NO\n");
 
    l.insertAtFront(3);
    l.insertAtBack(4);
    l.insertAtFront(2);
    l.insertAtBack(5);
    l.insertAtFront(1);
    l.insertAtBack(6); // List elements : 1 2 3 4 5 6
 
    l.insertAtFront(9);
    l.insertAtBack(0); // List elements : 9 1 2 3 4 5 6 0
    l.print();
 
    cout << "Smallest element in the List is " << l.min_element() <<endl;
    cout << "Biggest element in the List is " << l.max_element() <<endl <<endl;
    cout << "5th element in the List is " << l.getK_th(5) <<endl <<endl;
 
    l.removeFromFront();
    l.removeFromBack();
    cout << "\n\n\n**Erased first and last**\n";
    cout << "First element in the List is " << l.getFront() <<endl;
    cout << "Last element in the List is " << l.getBack() <<endl;
 
    cout << "\n\n\nList is : ";
    l.print();
 
    l.removePrimes();
    cout << l.Size() <<endl;
    l.print();
 
    l.insertAtBack(19);
 
    cout << "\n\n\n";
    l.removeEvens();
    cout << l.Size() <<endl;
    l.print();
 
    cout << "\n\n\n";
    l.removeOdds();
    cout << l.Size() <<endl;
    l.print();
    //-------------------------------------------------------------------------//
    l.insertAtFront(4);
    l.insertAtBack(3);
    l.insertAtFront(5);
    l.insertAtBack(2);
    l.insertAtFront(6);
    l.insertAtBack(1);
    l.insertAtBack(1);
    l.insertAtFront(4);
    l.print();
    l.Sort();
    l.print();
    l.Reverse();
    l.print();
    l.removeAllOcuurences(l.min_element());
    l.print();
    return 0;
}
 
void List::insertAtFront (int val)
{
    node *temp_ptr = new node;
    temp_ptr->val = val;
 
    if (!isEmpty()) {
        temp_ptr->next = head;
        head = temp_ptr;
    }
    else
        head = tail = temp_ptr;
}
 
void List::insertAtBack (int val)
{
    node *temp_ptr = new node;
    temp_ptr->val = val;
 
    if (!isEmpty()) {
        tail->next = temp_ptr;
        tail = temp_ptr;
    }
    else
        head = tail = temp_ptr;
}
 
void List::removeFromFront()
{
    if (!isEmpty()){
        node *temp_ptr = head;
 
        if (head->next == nullptr)
            head = tail = nullptr;
        else
            head = head->next;
 
        delete(temp_ptr);
    }
    else
        cout << "The List is Empty!!\n";
}
 
void List::removeFromBack()
{
    if (!isEmpty()){
        node *prev = nullptr;
        node *traverse = head;
        while (traverse->next != nullptr)
        {
            prev = traverse;
            traverse = traverse->next;
        }
        tail = prev;
        if (prev == nullptr)
            head = nullptr;
        else
            prev->next = nullptr;
 
        delete(traverse);
    }
    else
        cout << "The List is Empty!!\n";
}
 
void List::removeEvens()
{
    node *prev = nullptr, *traverse = head;
    while (traverse != nullptr)
    {
        if (traverse->val % 2 == 0)
        {
            node *temp_ptr = traverse;
 
            if (prev == nullptr)
                head = traverse->next;
            else
                prev->next = traverse->next;
 
            traverse = traverse->next;
            delete (temp_ptr);
            continue;
        }
        prev = traverse;
        traverse = traverse->next;
    }
    tail = prev;
}
 
void List::removeOdds()
{
    node *prev = nullptr, *traverse = head;
    while (traverse != nullptr)
    {
        if (traverse->val % 2)
        {
            node *temp_ptr = traverse;
 
            if (prev == nullptr)
                head = traverse->next;
            else
                prev->next = traverse->next;
 
            traverse = traverse->next;
            delete (temp_ptr);
            continue;
        }
        prev = traverse;
        traverse = traverse->next;
    }
    tail = prev;
}
 
void List::removePrimes()
{
    node *prev = nullptr, *traverse = head;
    while (traverse != nullptr)
    {
        if (isPrime(traverse->val))
        {
            node *temp_ptr = traverse;
 
            if (prev == nullptr)
                head = traverse->next;
            else
                prev->next = traverse->next;
 
            traverse = traverse->next;
            delete (temp_ptr);
            continue;
        }
        prev = traverse;
        traverse = traverse->next;
    }
    tail = prev;
}
void List::removeAllOcuurences (int value)
{
    node *prev = nullptr, *traverse = head;
    while (traverse != nullptr)
    {
        if (traverse->val == value)
        {
            node *temp_ptr = traverse;
 
            if (prev == nullptr)
                head = traverse->next;
            else
                prev->next = traverse->next;
 
            traverse = traverse->next;
            delete (temp_ptr);
            continue;
        }
        prev = traverse;
        traverse = traverse->next;
    }
    tail = prev;
}
int List::getFront()
{
    if (!isEmpty())
        return head->val;
    else
        return -1;
}
 
int List::getBack()
{
    return ((!isEmpty()) ? tail->val : -1);
}
 
int List::getK_th (int k)
{
    int cnt = 1;
    node *traverse = head;
    while (traverse != nullptr)
    {
        if (cnt++ == k)
            return traverse->val;
        traverse = traverse->next;
    }
    return -1;
}
 
int List::max_element()
{
    int maxi = INT_MIN;
    node *traverse = head;
    while (traverse != nullptr)
    {
        if (maxi < traverse->val)
            maxi = traverse->val;
 
        traverse = traverse->next;
    }
    if (maxi == INT_MIN) {
        cout << "The List is Empty!!\n";
        return 0;
    }
    return maxi;
}
 
int List::min_element ()
{
    int mini = INT_MAX;
    node *traverse = head;
    while (traverse != nullptr)
    {
        if (mini > traverse->val)
            mini = traverse->val;
 
        traverse = traverse->next;
    }
    if (mini == INT_MAX) {
        cout << "The List is Empty!!\n";
        return 0;
    }
    return mini;
}
 
int List::Size()
{
    int cnt = 0;
    node *traverse = head;
    while (traverse != nullptr)
    {
        cnt++;
        traverse = traverse->next;
    }
    return cnt;
}
 
void List::print()
{
    if (!isEmpty()){
        node *traverse = head;
        while (traverse != nullptr)
        {
            cout << traverse->val <<' ';
            traverse = traverse->next;
        }
        cout << endl;
    }
    else
        cout << "The List is Empty!!\n";
}
 
void List::Sort()
{
    int sz = Size();
    for (int k=0; k < sz; k++)
    {
        node *prev = head, *traverse = head->next;
        while (traverse != nullptr)
        {
            if (prev->val > traverse->val)
                swap(prev->val, traverse->val);
 
            prev = traverse;
            traverse = traverse->next;
        }
    }
}
void List::Reverse()
{
    node *prev = nullptr;
    node *current = head;
    node *next;
    swap(head, tail);
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}
 
List::~List()
{
    node *current = head, *temp;
    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete(temp);
    }
}
