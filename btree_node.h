#ifndef __BREE_NODE_H__
#define __BREE_NODE_H__
#include "common.h"
template <typename T>
class BtreeNode {
public:
	BtreeNode();
	~BtreeNode();

	T get_key(int idx) const;
	void set_key(int idx, int key);
	
	int get_nr_node(void) const;
	void set_nr_node(int nr);

	BtreeNode *get_child_node(int idx) const;
	int insert_child_node(const BtreeNode<T> *node);
	/* equal to insert_child_node */
	int operator+(const BtreeNode<T> *node);

	void split_child(int idx, int degree); 
	int insert_nonefull(int key, int degree);

	bool is_full(void) const;
private:
	/* key of the node */
	vector<T> key;
	/* number of children */
	int nr_node;
	/* pointer to children, list */
	vector<BtreeNode<T>* > child;		
	/* is leaf node ? */
	bool is_leaf;
};
#endif
