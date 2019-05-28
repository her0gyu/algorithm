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
int Btree<T>::insert_node(int key) {
	BtreeNode *r;
	BtreeNode *s;

	r = root;

	if(r->is_full(degree)) {
		s = new BtreeNode<T>();
		root = s;
		root->set_nr_node(0);
		root->set_child_node();
		root->split_child(1, degree);
		root->insert_nonefull(key, degree);
	} else 
		r->insert_nonefull(key);
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

int main(void)
{
	return 0;
}
