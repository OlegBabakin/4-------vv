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

#include "Cstring.h"

Cstring::Cstring()
{
	std::cout << "default constructor for " << __func__ << std::endl; 
	this->word_ = new char[100];
}

Cstring::Cstring(char*& word2)
{
	std::cout << strlen(word2) << std::endl;
	this->word_ = new char[strlen(word2)];
	std::memcpy(this->word_, word2, sizeof this->word_);
}


Cstring::Cstring(const Cstring& c)
{ 
	this->word_ = new char[strlen(c.word_)];
	std::memcpy(this->word_, c.word_, sizeof this->word_);
}

Cstring::Cstring(Cstring&& c)
{
	this->word_ = std::move(c.word_);
}

Cstring::~Cstring()
{
	std::cout << "destructor for " << __func__ << std::endl; 
	//std::cout << "Destructor for " << this << std::endl;
	delete [] this->word_;
	std::cout << __func__ << " ended" << std::endl;
}

Cstring& Cstring::operator=(const Cstring &c)
{
	std::cout << __func__ << " for Cstring" << std::endl;
	delete [] this->word_;
	this->word_ = new char[strlen(c.word_)];
	std::memcpy(this->word_, c.word_, sizeof this->word_);
	return *this;
}