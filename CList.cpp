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

#include "Char.h"

class Node{
public:
	Cstring c_;
	class Node* next_;
	class Node* prev_;

	Node();
	Node(const Cstring &c);
	friend void print_list(Node*& root, Node*& curr); // prints all linked list with current element
	friend void insert_to_end(Node*& root); // adding new element to the end of the list with value determined by user
	friend void delete_from_end(Node*& root, Node*& curr); // deleting element from the end of the list
	friend void move_next(Node*& current); // moving to the next element of the list
	friend void pop_next(Node*& current); // adding new element after current with value determined by user 
	friend void move_previous(Node*& current); //moving to the previous element of the list 
	friend void free_list(Node*& root, Node*& current); // clearing list memory
	friend void push_next(Node*& current); // deleting element after current
	friend void gen_root(Node*& root); // generating root of the list with reading value
};
Node::Node()
{
}

Node::Node(const Cstring &c)
{
	this->next_ = nullptr;
	this->prev_ = nullptr;
	this->c_ = c;
}

Node::~Node()
{
}

int interface(void); // interface to read strings, which will be used to operate with list 
int processing(void); 

void push_next(Node*& current)
{
	if(current == NULL || current->next == NULL)
	{
		printf("Can't push next elem\n\n");
		return;
	}
	else
	{
		Node* buf_node = current->next_->next_;
		delete current->next_;
		current->next_ = buf_node;
	}
}

void free_list(Node*& root, Node*& current)
{
	while(root!=NULL)
	{
		if(root == NULL)
		{
			return;
		}
		delete_from_end(root, current);
	}
}

void move_previous(Node*& current)
{
	if(current == root)
	{
		printf("No =)\n\n");
	}
	else
	{
		Node* curr = root;
		while(curr->next_ != current)
		{
			curr = curr->next_;
		}
		current = curr;
	}
}

void pop_next(Node*& current)
{
	Node* buf = current;
	Node* new_node;
	// Node* new_node = (Node*)malloc(sizeof(Node));
	printf("Enter value of node: ");
	std::cin >> new_node->c_;
	new_node->next_ = current->next_;
	buf->next_ = new_node; 
}

void move_next(Node*& current)
{
	if(current == NULL || current->next_ == NULL)
	{
		printf("\nNo =)\n");
	}
	else 
	{
		current = current->next_;
	}
}

void gen_root(Node*& root)
{
	// root = (Node*)malloc(sizeof(Node));
	root = new Node*;
	root->next_ = NULL;
	// must dodelat;
	std::cin << root->c_;
}

void print_list(Node*& root, Node*& curr)
{
	if(root!=NULL)
	{
		Node current = root;
		printf("\nList:  ");
		for(int i = 0; current!=NULL; i++)
		{
			if(curr == current)
			{
				std::cout << " >>" << curr->c_ << "<< ";
				//printf(" >>%d<< ", curr->value);
			}
			else
			{
				std::cout << " " << curr->c_ << " ";
				//printf(" %d ", current->value);
			}
			current = current->next;
		}
		std::cout << "\n\n";
		//printf("\n\n");
	}
}

void insert_to_end(Node*& root)
{
	// Node* new_node = (Node*)malloc(sizeof(Node));
	root = new Node*;
	new_node->next_ = NULL;
	printf("Enter value of node: ");
	scanf("%d", &(new_node->value_));
	Node* current = *root;
	for(;current->next != NULL;)
	{
		current = current->next;
	}
	current->next = new_node;
}

void delete_from_end(Node*& root, Node*& curr)
{
	if(*root == NULL)
	{
		printf("No element\n");
	}
	else if(root->next_ != NULL)
	{
		Node* current = root;
		Node* bef_curr = NULL;	
		while(current->next_ != NULL)
		{
			bef_curr = current;
			current = current->next_;
		}
		if(current == curr)
		{
			curr = root;
		}
		free(current);
		delete current;
		bef_curr->next_ = NULL;
	}
	else if(root->next_ == NULL && root != NULL)
	{
		curr = NULL;
		delete root;
		free(root);
		root = NULL;
		printf("No element\n");
	}
}

int interface(void)
{
	int command = 0;
	printf("Enter 1 to move to the next element of the list\n");
	printf("Enter 2 to move to the previous element of the list\n");
	printf("Enter 3 to pop new element after current\n");
	printf("Enter 4 to push element after current\n");
	printf("Enter 5 to print the list\n");
	printf("Enter -1 to end programm\n");
	scanf("%d", &command);
	return command;
}

int processing(void)
{
	int k = 0;
	Node* root = NULL;
	Node* current = NULL;
	while(k!=-1)
	{
		k = interface();
		if(k == 1)
		{
			move_next(current);
			print_list(root, current);
		}
		else if(k == 2)
		{
			move_previous(root, current);
			print_list(root, current);
		}
		else if(k == 3)
		{
			if(root == NULL)
			{
				gen_root(root);
				current = root;
			}
			else
				pop_next(current);
				//insert_to_end(&root);
			print_list(root, current);
		}
		else if(k == 4)
		{
			//delete_from_end(&root, &current);
			push_next(current);
			print_list(root, current);
		}
		else if(k == 5)
		{
			print_list(root, current);
		}
		else if(k==-1)
		{
			break;
		}
		else if(k!=9)
		{
			printf("Wromg command\n");
		}
		k = 9;
	}
	free_list(root, current);
	return 0;
}

int main(void)
{
	processing();
	return 0;
}