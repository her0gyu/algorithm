#include "btree_node.h"

using namespace std;

/* Constructor */
template <typename T>
BtreeNode<T>::BtreeNode(void) {
	nr_node = 0;
}

template <typename T>
int BtreeNode<T>::insert_child_node(const BtreeNode<T> *node)
{
	child.push_back(node);
	nr_node++;
	return 0;
}

template <typename T>
int BtreeNode<T>::operator+(const BtreeNode<T> *node)
{
	child.push_back(node);
	nr_node++;
	return 0;
}


/* get key by idx */
template <typename T>
T BtreeNode<T>::get_key(int idx) const {
	return key[idx];
}

/* get node by idx */
template <typename T>
BtreeNode<T>* BtreeNode<T>::get_child_node(int idx) const {
	return child[idx]; 
}

/* check the node is leaf ?*/
template <typename T>
bool BtreeNode<T>::is_leaf_node(void) const {
	return is_leaf; 
}

template <typename T>
bool BtreeNode<T>::is_full(int degree) const {
	return((nr_node == 2 * degree - 1) ? true:false); 
}

template <typename T>
void BtreeNode<T>::split_child(int idx, int degree) {
	BtreeNode<T>* second = new BtreeNode<T>();
	BtreeNode<T>* first = this.get_child_node(idx);
	int i, j, k = 0;
	
	second->set_leaf(first->get_leaf());
	/* set the number of node splited node */
	second->set_nr_node(degree - 1);

	/* copy key to second splited node */
	for(j = 0; j < degree - 1; j++)
		second->set_key(j, first->get_key(j + degree + 1));
	
	if(first->is_leaf() == false)
		for(j = 0; j < degree; j++)
			second->set_child_node(first->get_child_node(j + degree));
	first->set_nr_node = degree - 1;
	
	for (j = this.get_nr_node() + 1; j >= idx + 1; j--)
		this.set_child_node(this.get_child_node(j + 1));
	this.set_child_node(second);
		
	for (j = this.get_nr_node; j >= idx; j--)
		this.set_key(j + 1, this.get_key(j));

	this.set_key(idx, first->get_key(degree));

	this.set_nr_node(this.get_nr_node() + 1);

}

template <typename T>
int BtreeNode<T>::insert_nonefull(int key, int degree)
{
	int i;
	i = nr_node;

	if(this.is_leaf_node() == true) {
		while(i >= 0 && key < get_key(i)) {
			this.key[i + 1] = get_key(i);
			i = i - 1;	
		}

		this.key[i + 1] = key;
		this.nr_node = this.nr_node + 1;
	} else {
		while(i >= 0 && key < get_key(i))
			i = i - 1;	

		i += 1;
		/* if full, must be splitted */
		if(get_chlid_node(i)->is_full(degree))
			this.split_child(i, degree);
			/* if splitted, i'th key changed */
			if(key > get_key(i))
				i += 1;
		/* Until get to the leaf node */
		get_child_node(i)->insert_none_full(key);
	}
	
	return 0;
}
