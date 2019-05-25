#include "btree.h"

template <typename T>
Btree<T>::Btree(int degree) {
	root = NULL;
	this.degree = degree;
}


template <typename T>
Btree<T>::~Btree() {
}


template <typename T>
int Btree<T>::insert_node(BtreeNode<T>* node) {
	return 0;
}


template <typename T>
int Btree<T>::delete_node(BtreeNode<T>* node) {
	return 0;
}


template <typename T>
BtreeNode<T>* Btree<T>::search_node(int key)
{
	int idx = 0;

	idx = 1;
	/* if root k`ey is equaled to.. */
	if(root->key == key)
		return root;

	/* stage 1: linear search on the node. */
	while(root->nr_node < idx && key > root->get_child_key(idx)) 
		idx += 1;
	
	/* stage 2: found the node. */
	if(idx <= root->nr_node&& key == root->key)
		return root->get_child_node(idx);

	/* stage 3: if it is leaf node.*/
	else if(root->is_leaf_node()) 
		return NULL;
	/* stage 4: recursive find~ */
	else
		(root->get_child_node(idx))->seach_node(key);	
}


template <typename T>
void Btree<T>::split_child(BtreeNode<T>* node, int idx) {
	BtreeNode<T>* second = new BtreeNode<T>();
	BtreeNode<T>* first = node->get_child_node(idx);
	int i, j, k, t = 0;
	
	/* cacluate splited (new allocated)node number */
	if(degree % 2 == 1)
		t = degree / 2;
	else 
		t = degree / 2 - 1;
	
	/* set the number of node splited node */
	second->set_nr_node(t);

	/* copy key to second splited node */
	for(j = 1; j <= t ; j++)
		second->set_key(j, first->get_key(j + t + 1));
}

int main(void)
{
	return 0;
}
