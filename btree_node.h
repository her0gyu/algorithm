#ifndef __BREE_NODE_H__
#define __BREE_NODE_H__
#include "common.h"
template <typename T>
class BtreeNode {
public:
	BtreeNode();
	~BtreeNode();
	T get_key(int idx);
	BtreeNode *get_child_node(int idx);
	bool is_leaf_node(void);

	int get_nr_node(void);
	void set_nr_node(int nr);

	void set_key(int idx, int key);

private:
	/* key of the node */
	vector<T> key;
	/* number of children */
	int nr_node;
	/* pointer to children, list */
	vector<BtreeNode*> child;		
};
#endif
