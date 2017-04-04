#include <fstream>
#include <iostream>

template <class T> struct Node
{
	T key;
	Node<T>* Left;
	Node<T>* Right;
	Node<T>*parent;
};
template <class T> class Tree
{
private:
	Node<T>*root;
	int count;
public:
	Tree();
	~Tree();
	void insert_node(const T&);
	int get_count()const;
	void print()const;
	Node<T>* find_node(const T& val, Node<T>* temp)const;
	Node<T>*root_()const;
	void reading(const std::string filename); // чтение из файла
	void output(std::ostream& ost, Node<T>* temp)const; //вывод в консоль
	void writing(const std::string filename); //запись в файл 
};
