/*
Требуется реализовать список строк (указателей char *) с возможностью его сортировки по различным критериям. Предполагается, что после добавления строки в список ее длина измениться не может. Поэтому для размещения строки в памяти используется new (или malloc), а полученные указатели сохраняютя в списке.
Реализация класса должна обеспечивать следующие возможности:
- создать пустой список;
- добавить элемент в конце списка;
- добавить в конец все элементы другого списка;
- вставить элемент так, чтобы он имел указанный индекс (порядковый номер);
- вставить в конец / начало списка; +/+ 
- получить указатель на следующий / предудущий элементы списка (перемещение текущей позиции и итератор);
- получить индекс (порядковый номер) текущего элемента;
- получить указатель (или ссылку) текущего элемента для непосредственного доступа к значению; + (?)
- удалить текущий элемент или элемент по указанному индексу; +/-
- получить количество элементов в списке;
- удалить все элементы из списка; +
- сортировать список по указанной функции сравнения строк;
*/

#include "CList_v1.h"


List::List()
{
    b_=e_=curr_=nullptr;
}

~List()
{
    clear();
}

void List::add_b(char*& c)
{
    Cstring cstring(c);
    Node* new_node = new Node(c);
    new_node->c_ = cstring;
    if(this->curr_ == nullptr)
    {
        curr_=b_=e_=new_node;
    }
    else
    {
        new_node->next_ = b_;
        b_->prev_ = new_node;
    }
}

void List::add_e(char*& c)
{
    Cstring cstring(c);
    Node* new_node = new Node(c);
    new_node->c_ = cstring;
    if(this->curr_ == nullptr)
    {
        curr_=b_=e_=new_node;
    }
    else
    {
        new_node->prev_ = e_;
        e_->next_ = new_node;
    }
}

void List::clear()
{
    this->curr_ = this->e_;
    while(!empty())
    {
        del_curr();
    }
}

bool List::empty()
{
    return curr_ == nullptr;
}

void List::del_curr()
{
    Node* buf_node = curr_;
    if(buf_node->prev_)
    {
        buf_node->prev_->next_ = buf_node->next_;
        curr_ = buf_node->prev_;
    }
    else
    {
        b_ = buf_node->next_;
    }
    if(buf_node->next_)
    {
        buf_node->next_->prev_ = buf_node->prev_;
        curr_ = buf_node->next_;
    }
    else
    {
        curr_ = e_ = buf_node->prev_;
    }
    delete buf_node;
}

// Cstring& List::get()
// {
//     return curr->c_;
// }

void Node::add