/*
Требуется реализовать список строк (указателей char *) с возможностью его сортировки по различным критериям. Предполагается, что после добавления строки в список ее длина измениться не может. Поэтому для размещения строки в памяти используется new (или malloc), а полученные указатели сохраняютя в списке.
Реализация класса должна обеспечивать следующие возможности:
- создать пустой список;
- добавить элемент в конце списка;
- добавить в конец все элементы другого списка;
- вставить элемент так, чтобы он имел указанный индекс (порядковый номер);
- вставить в конец / начало списка;
- получить указатель на следующий / предудущий элементы списка (перемещение текущей позиции и итератор);
- получить индекс (порядковый номер) текущего элемента;
- получить указатель (или ссылку) текущего элемента для непосредственного доступа к значению;
- удалить текущий элемент или элемент по указанному индексу;
- получить количество элементов в списке;
- удалить все элементы из списка;
- сортировать список по указанной функции сравнения строк;
*/

#include "CNode.h"

int main(void)
{
    char* c1 = new char[100];
    std::cin >> c1;
	Node* n1 = new Node[1];
    n1->c_.word_ = c1;
    std::cout <<"12 " << n1->c_.word_ << std::endl;
    delete [] n1;
    std::cout << __func__ << " ended" << std::endl;
	return 1;
}