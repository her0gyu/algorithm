#ifndef __BTREE_H__
#define __BTREE_H__
#include "common.h"
#include "btree_node.h"

template <typename T>
class Btree {
public:	
	Btree(int degree);
	~Btree();
	int insert_node(BtreeNode<T>* node);
	int delete_node(BtreeNode<T>* node);
	/* search method */
	BtreeNode<T>* search_node(int key);

private:
	BtreeNode<T>* root;	
	int degree;
	void split_child(BtreeNode<T>* node, int idx);
};
#endif
