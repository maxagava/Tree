#include "tree.hpp"
#include <fstream>
#include <iostream>
using namespace std;


template<class T>
Tree<T>::Tree()
{
	root = 0;   
	count = 0;
}
template <class T>
Tree<T>::~Tree()
{
	delete root;
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
	T temp;
	fin >> temp;
	while (fin)
	{
		insert_node(temp);
		fin >> temp;
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
	output(fout, root);
	fout.close();
}
