#ifndef CM_RBTREE_HPP
#define CM_RBTREE_HPP  
#include "BinarySearchTree.hpp"
namespace cm
{
	template<typename T> class RBTreeNode;
	template<typename T> class RBTreeIterator;
	template<typename T> class RBTree;

	template<typename T>
	class RBTreeNode
	{
	public:
	  typedef T VALUE_TYPE;
	  enum Color_t { 
		COLOR_BLACK,
		COLOR_RED
	  };

	public:
	  explicit RBTreeNode(const T& v=T(), Color_t c=COLOR_BLACK)
		: value_(v)
		  , left_(NIL)
		  , right_(NIL)
		  , parent_(NIL)
		  , color_(c)
	{
	}

	  RBTreeNode<T>* left()  {	return left_;	}
	  RBTreeNode<T>* right() {	return right_;	}
	  RBTreeNode<T>* parent(){	return parent_; }
	  RBTreeNode<T>* left()   const {  return left_;   }
	  RBTreeNode<T>* right()  const {  return right_;  }
	  RBTreeNode<T>* parent() const {  return parent_; }
	  const T&	   value()		  const {  return value_;  }
	  Color_t color()			  const {  return color_;  }

	  void left(RBTreeNode<T>* node)  {  left_ = node;	 }
	  void right(RBTreeNode<T>* node) {  right_ = node;  }
	  void parent(RBTreeNode<T>* node){  parent_ = node; }
	  void value(const T& value)		  {  value_ = value; }
	  void color(Color_t c) 			  { color_ = c; 	 }

	  operator bool() const
	  {
		return this != NIL;
	  }

	  bool operator !() const
	  {
		return this == NIL;
	  }

	public:
	  static RBTreeNode<T>* NIL;

	private:
	  T 		   value_;
	  RBTreeNode<T>* left_;
	  RBTreeNode<T>* right_;
	  RBTreeNode<T>* parent_;
	  Color_t color_;
	}; 

	template<typename T>
	RBTreeNode<T>* RBTreeNode<T>::NIL(new RBTreeNode<T>());

	template<typename T>
	class RBTree: public BinarySearchTree_T< RBTreeNode<T> >
	{
	public:
	typedef RBTreeNode<T> Node;

	public:
	size_t bh() const
	{
	  return this->bh(this->getRoot());
	}
	size_t bh(const Node* node) const
	{
	  Node* n = node;
	  size_t h =  ;
	  while (n) {
		if (n->color() == Node::COLOR_BLACK) {
		  ++h;
		}
		n = n->left();
	  }
	  return h;
	}
	size_t insert(const T& key)
	{
	  Node* z = new Node(key, Node::COLOR_RED);    // 要插入的节点
	  Node* y = Node::NIL;	  // y 是 x 的父节点
	  Node* x = this->root();
	  while (x != Node::NIL) {
		y = x;
		if (key == x->value()) {
		  return  0;
		}

		if (key < x->value()) {
		  x = x->left();
		}
		else {
		  x = x->right();
		}
	  }

	  z->parent(y);

	  if (y == Node::NIL) {
		this->root_ = z;
		this->root_->parent(Node::NIL);
	  }
	  else {
		if(key < y->value()) {
		  y->left(z);
		}
		else {
		  y->right(z);
		}
	  }

	  z->left(Node::NIL);
	  z->right(Node::NIL);
		insert_fixup(z);

	  ++this->size_;
	  return  ;
	}

	void remove(Node* z)
	{
	  Node* y = Node::NIL;
	  Node* x = Node::NIL;
	  if (z->left() == Node::NIL || z->right() == Node::NIL) {
		y = z;
	  }
	  else {
		//y = this->successor(z);
		y = z->right();
		while (y->left() != Node::NIL) {
		  y = y->left();
		}
	  }

	  // x 是 y的唯一孩子
	  if (y->left() != Node::NIL) {
		x = y->left();
	  }
	  else {
		x = y->right();
	  }

	  x->parent(y->parent());

	  if(y->parent() == Node::NIL) {
		this->root_ = x;
	  }
	  else {
		if (y == y->parent()->left()) {
		  y->parent()->left(x);
		}
		else {
		  y->parent()->right(x);
		}
	  }

	  if (y != z) {
		z->value(y->value());
	  }

	  if (y->color() == Node::COLOR_BLACK) {
		this->delete_fixup(x);
	  }

	  delete y;
	  --this->size_;
	}

	/// 如果key存在，删除并返回 ，否则返回 
	size_t remove(const T& key)
	{
	  Node* node = this->find(key);
	  if (node != Node::NIL) {
		this->remove(node);
		return	;
	  }

	  return  ;
	}

	private:
	void left_rotate(Node* x)
	{
	  Node* y = x->right();

	  // 把y的左子数变成x的右子树
	  x->right(y->left());

	  if (y->left() != Node::NIL) {
		y->left()->parent(x);
	  }

	  if (y != Node::NIL) {
		y->parent(x->parent());
	  }

	  if (x->parent() == Node::NIL) {
		this->root_ = y;
	  }
	  else {
		if (x == x->parent()->left()) {
		  x->parent()->left(y);
		}
		else {
		  x->parent()->right(y);
		}
	  }

	  // 把x变成y的左子节点
	  y->left(x);
	  if (x != Node::NIL) {
		x->parent(y);
	  }
	}
	void right_rotate(Node* x)
	{
	  Node* y = x->left();
	   x->left(y->right());

	  if (y->right() != Node::NIL) {
		y->right()->parent(x);
	  }

	  if (y != Node::NIL) {
		y->parent(x->parent());
	  }

	  if (x->parent() == Node::NIL) {
		this->root_ = y;
	  }
	  else {
		if (x == x->parent()->left()) {
		  x->parent()->left(y);
		}
		else {
		  x->parent()->right(y);
		}
	  }

	  y->right(x);
	  if (x != Node::NIL) {
		x->parent(y);
	  }
	}

	void insert_fixup(Node* z)
	{
	  Node* y = Node::NIL;
	  while (z != this->root() && z->parent()->color() == Node::COLOR_RED) {
		if (z->parent() == z->parent()->parent()->left()) {
		  y = z->parent()->parent()->right();
		  if (y->color() == Node::COLOR_RED) {
			z->parent()->color(Node::COLOR_BLACK);
			y->color(Node::COLOR_BLACK);
			z->parent()->parent()->color(Node::COLOR_RED);
			z = z->parent()->parent();
		  }
		  else {
			if (z == z->parent()->right()) {
			  z = z->parent();
			  this->left_rotate(z);
			}

			z->parent()->color(Node::COLOR_BLACK);
			z->parent()->parent()->color(Node::COLOR_RED);
			this->right_rotate(z->parent()->parent());
		  }
		}
		else {
		  y = z->parent()->parent()->left();
		  if (y->color() == Node::COLOR_RED) {
			z->parent()->color(Node::COLOR_BLACK);
			y->color(Node::COLOR_BLACK);
			z->parent()->parent()->color(Node::COLOR_RED);
			z = z->parent()->parent();
		  }
		  else {
			if (z == z->parent()->left()) {
			  z = z->parent();
			  this->right_rotate(z);
			}

			z->parent()->color(Node::COLOR_BLACK);
			z->parent()->parent()->color(Node::COLOR_RED);
			this->left_rotate(z->parent()->parent());
		  }
		}
	  }

	  this->root()->color(Node::COLOR_BLACK);
	}

	void delete_fixup(Node* x)
	{
	  Node* w = Node::NIL;
	  while (x != this->root() && x->color() == Node::COLOR_BLACK) {
		if (x == x->parent()->left()) {
		  w = x->parent()->right();
		  if (w->color() == Node::COLOR_RED) {
			w->color(Node::COLOR_BLACK);
			x->parent()->color(Node::COLOR_RED);
			this->left_rotate(x->parent());
			w = x->parent()->right();
		  }
		  if (w->left()->color() == Node::COLOR_BLACK && w->right()->color() == Node::COLOR_BLACK) {
			w->color(Node::COLOR_RED);
			x = x->parent();
		  } else {
			if (w->right()->color() == Node::COLOR_BLACK) {
			  w->left()->color(Node::COLOR_BLACK);
			  w->color(Node::COLOR_RED);
			  right_rotate(w);
			  w = x->parent()->right();
			}
			w->color(x->parent()->color());
			x->parent()->color(Node::COLOR_BLACK);
			w->right()->color(Node::COLOR_BLACK);
			left_rotate(x->parent());
			x = this->root();
		  }
		} else {
		  w = x->parent()->left();
		  if (w->color() == Node::COLOR_RED) {
			w->color(Node::COLOR_BLACK);
			x->parent()->color(Node::COLOR_RED);
			right_rotate(x->parent());
			w = x->parent()->left();
		  }
		  if (w->right()->color() == Node::COLOR_BLACK && w->left()->color() == Node::COLOR_BLACK) {
			w->color(Node::COLOR_RED);
			x = x->parent();
		  } else {
			if (w->left()->color() == Node::COLOR_BLACK) {
			  w->right()->color(Node::COLOR_BLACK);
			  w->color(Node::COLOR_RED);
			  left_rotate(w);
			  w = x->parent()->left();
			}
			w->color(x->parent()->color());
			x->parent()->color(Node::COLOR_BLACK);
			w->left()->color(Node::COLOR_BLACK);
			right_rotate(x->parent());
			x = this->root();
		  }
		}
	  }

	  x->color(Node::COLOR_BLACK);
	}
	};

	template<typename T>
	class RBTreeIterator
	{
	public:
	  RBTreeIterator()
		: tree_(RBTreeNode<T>::NIL), current_(RBTreeNode<T>::NIL)
	  {
	  }

	  RBTreeIterator(RBTree<T>& tree, typename RBTree<T>::Node* current)
		: tree_(tree), current_(current)
	  {
	  }

	  const T& operator*() const
	  {
		return current_->value();
	  }

	  T* operator->()
	  {
		return current_;
	  }

	  bool operator==(const RBTreeIterator& rhs) const
	  {
		return current_ == rhs.current_;
	  }

	  bool operator!=(const RBTreeIterator& rhs) const
	  {
		return current_ != rhs.current_;
	  }
	  RBTreeIterator& operator++()
	  {
		current_ = tree_.successor(current_);
		return *this;
	  }

	private:
	  RBTree<T>& tree_;
	  typename RBTree<T>::Node* current_;
	};
} // end namespace cm

#endif // CM


int main()
{
	RBTree<int> *rbTree = new RBTree<int>();
	for(int i=0;i<10;i++)
	{
		rbTree->insert(i);
		rbTree->printBRTree();
		cout<<endl<<endl;
	}
	cout<<"Min: "<<rbTree->minimum()->value<<endl;
	cout<<"Max: "<<rbTree->maxminum()->value<<endl;
	rbTree->printLayer();
	rbTree->remove(4);
	rbTree->printLayer();
	return 0;
}
