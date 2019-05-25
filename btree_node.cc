#include "btree_node.h"

using namespace std;

/* Constructor */
template <typename T>
BtreeNode<T>::BtreeNode(void) {
	nr_node = 0;
}

/* get key by idx */
template <typename T>
T BtreeNode<T>::get_key(int idx) {
	return key[idx];
}

/* get node by idx */
template <typename T>
BtreeNode<T>* BtreeNode<T>::get_child_node(int idx) {
	return child[idx]; 
}

/* check the node is leaf ?*/
template <typename T>
bool BtreeNode<T>::is_leaf_node(void) {
	return ((nr_node == 0) ? true : false);
}
