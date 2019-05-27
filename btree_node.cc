#include "btree_node.h"

using namespace std;

/* Constructor */
template <typename T>
BtreeNode<T>::BtreeNode(void) {
	nr_node = 0;
}

template <typename T>
int insert_child_node(const BtreeNode<T> *node)
{
	child.push_back(node);
	nr_node++;
	return 0;
}

template <typename T>
int operator+(const BtreeNode<T> *node)
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
	return this.is_leaf; 
}

template <typename T>
bool BtreeNode<T>::is_full(int degree) const {
	return((nr_node == 2 * degree - 1) ? true:false); 
}

template <typename T>
int BtreeNode<T>::insert_nonefull(int key, int degree)
{
	int i;

	i = nr_node;

	if(this.is_leaf_node() == true) {
		while(i >= 1 && key < get_key(i)) {
			this.key[i + 1] = get_key(i);
			i = i - 1;	
		}

		this.key[i + 1] = key;
		this.nr_node = this.nr_node + 1;
	} else {
		while(i >= 1 && key < get_key(i))
			i = i - 1;
			
		i += 1;
		if(get_chlid_node(i)->is_full(degree))
			//split(i);
			if(key > get_child_node_key(i))
				i += 1;
		//get_child_node(i)->insert_none_full(k);
	}

}


