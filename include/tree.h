#include <fstream>
#include <iostream>
using namespace std;

template <class T> struct Node
{
	T key;
	Node<T>* Left;
	Node<T>* Right;
};
template <class T> class Tree
{
private:
	Node<T>*root;
	int count;
public:
	Tree();
	~Tree();
	void deleteNode(Node<T>* temp);
	void insert_node(const T&);
	int get_count()const;
	void print()const;
	Node<T>* find_node(const T& val, Node<T>* temp)const;
	Node<T>*root_()const;
	void display(Node<T>* temp, unsigned int level)const;
	void out()const;
	void reading(const std::string filename); // чтение из файла
	void output(std::ostream& ost, Node<T>* temp)const; //вывод в консоль
	void writing(const std::string filename); //запись в файл 
};

template<class T>
Tree<T>::Tree()
{
	root = nullptr;
	count = 0;
}
template<class T>
Tree<T>::~Tree()
{
	deleteNode(root);
}
template<class T>
void Tree<T>::deleteNode(Node<T>* temp)
{
	if (!temp)
		return;
	if (temp->Left)
	{
		deleteNode(temp->Left);
		temp->Left = nullptr;
	}

	if (temp->Right)
	{
		deleteNode(temp->Right);
		temp->Right = nullptr;
	}
	delete temp;
}

template<class T>
Node<T>*Tree<T>::root_()const
{
	return root;
}
template<class T>
int Tree<T>::get_count()const
{
	return count;
}


template<class T>
void Tree<T>::insert_node(const T&x)
{
	Node<T>* dn = new Node<T>;
	dn->key = x;
	dn->Left = dn->Right = 0;
	Node<T>* pn = root;
	Node<T>* temp = root;
	while (temp)
	{
		pn = temp;
		if (x < temp->key)
			temp = temp->Left;
		else
			temp = temp->Right;
	}
	if (!pn)
		root = dn;
	else
	{
		if (x < pn->key)
			pn->Left = dn;
		else
			pn->Right = dn;
	}
	count++;

}
template<class T>
Node<T>* Tree<T>::find_node(const T& val, Node<T>* temp) const
{
	if (temp == 0 || val == temp->key)
		return temp;
	if (val > temp->key)
		return find_node(val, temp->Right);
	else
		return find_node(val, temp->Left);
}

template<typename T>
void Tree<T>::reading(const std::string filename)
{
	ifstream fin(filename);
	if (root != nullptr)
	{
		deleteNode(root->Right);
		deleteNode(root->Left);
		root = 0;
	}

	int k;
	fin >> k;
	T temp;
	for (int i = 0; i < k; ++i)
	{
		fin >> temp;
		insert_node(temp);
	}
	fin.close();
}
template<typename T>
void Tree<T>::print() const
{
	output(cout, this->root);
}
template<typename T>
void Tree<T>::output(ostream& ost, Node<T>* temp)const
{
	if (!temp) return;
	ost << temp->key << " ";
	output(ost, temp->Left);
	output(ost, temp->Right);
}

template<typename T>
void Tree<T>::writing(const std::string filename)
{
	ofstream fout(filename);
	fout << count << " ";
	output(fout, root);
	fout.close();
}

template<typename T>
void Tree<T>::display(Node<T>* temp, unsigned int level)const
{

	if (temp)
	{
		display(temp->Left, level + 1);
		for (unsigned int i = 0; i < level; i++)
			std::cout << "-";
		std::cout << temp->key << std::endl;
		display(temp->Right, level + 1);
	}
}
template<typename T>
void Tree<T>::out()const
{
	display(root, 0);
}
