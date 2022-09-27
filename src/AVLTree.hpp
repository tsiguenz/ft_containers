/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/27 22:23:15 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include "pair.hpp"

namespace ft {
	template<typename T>
		struct Node {
			T		data;
			Node*	left;
			Node*	right;
			Node*	parent;

			Node(T const& val = T())
				: data(val), left(), right(), parent() { }

			~Node() { }
		};

	template<typename T, class Alloc = std::allocator<T>, class Compare = std::less<T> >
		class AVLTree {
			private:
				typedef Node<T>											node;
				typedef typename Alloc::template rebind<node>::other	AllocNode;

				Node<T>*	_root;
				Node<T>*	_begin;
				Node<T>*	_end;
				Alloc		_allocPair;
				AllocNode	_allocNode;
				size_t		_size;
				Compare		_comp;

			public:
				// Empty constructor
				// Initialisation list for _comp bc value_compare don't have default constructor
				AVLTree(Compare const& comp = Compare()): _comp(comp) {
					_root = NULL;
					_end = _createNode();
					_begin = _end;
					_allocPair = Alloc();
					_allocNode = AllocNode();
					_size = 0;
				}

				// Destructor
				~AVLTree() {
					while (_root != NULL)
						remove(_root->data);
					_deallocateNode(_end);
				}

				void	swap(AVLTree& rhs){
					Node<T>*	tmpRoot = this->_root;
					Node<T>*	tmpBegin = this->_begin;
					Node<T>*	tmpEnd = this->_end;
					size_t		tmpSize = this->_size;
					Compare		tmpComp = this->_comp;

					this->_root = rhs._root;
					this->_begin = rhs._begin;
					this->_end = rhs._end;
					this->_size = rhs._size;
					this->_comp = rhs._comp;

					rhs._root = tmpRoot;
					rhs._begin = tmpBegin;
					rhs._end = tmpEnd;
					rhs._size = tmpSize;
					rhs._comp = tmpComp;
				}

				node*	getRoot() const
				{ return _root; }

				void	insert(T const& data) {
					// Duplicates are not allowed (this do not protect duplicate key in pair)
					if (searchByData(data) != NULL)
						return ;
					_unsetEnd();
					node*	newNode = _createNode(data);
					_root = _insertHelper(_root, newNode);
					_size++;
					_begin = minimum();
					_setEnd();
				}

				void	remove(T const& key) {
					if (searchByData(key) == NULL)
						return ;
					_unsetEnd();
					_root = _removeHelper(_root, key);
					_size--;
					_setEnd();
					_begin = (_size != 0) ? minimum() : _end;
				}

				// remove for iterator
				void	removeNode(node* n) {
					_unsetEnd();
					_removeHelper(n->parent, n->data);
					_size--;
					_setEnd();
					_begin = (_size != 0) ? minimum() : _end;
				}

				node*	searchByData(T const& data) {
					node*	curr = this->_root;
					while (curr != NULL && (_comp(curr->data, data) || _comp(data, curr->data)))
						curr = (_comp(curr->data, data)) ? curr->right : curr->left;
					return curr;
				}

				node*	minimum(node* n) {
					if (n == NULL)
						return NULL;
					node*	current = n;
					while (current->left != NULL)
						current = current->left;
					return current;
				}

				node*	minimum()
				{ return minimum(this->_root); }

				node*	maximum(node* n) {
					if (n == NULL)
						return NULL;
					node*	current = n;
					while (current->right != NULL && current->right != _end)
						current = current->right;
					return current;
				}

				node*	maximum()
				{ return maximum(this->_root); }

				void	inorder(node* root) const {
					if (root == NULL || root == _end)
						return ;
					inorder(root->left);
					inorder(root->right);
				}

				size_t	size() const
				{ return _size; }

				size_t	max_size() const
				{ return _allocNode.max_size(); }

				node*	begin()
				{ return _begin; }

				node * const	begin() const
				{ return _begin; }

				node*	end()
				{ return _end; }

				node *const	end() const
				{ return _end; }

			private:

				void	_unsetEnd(){
					if (_root == NULL)
						return ;
					_end->parent->right = NULL;
					_end->parent = NULL;
				}

				void	_setEnd(){
					if (_root == NULL)
						return ;
					node*	tmp = maximum();
					tmp->right = _end;
					_end->parent = tmp;
				}

				node*	_createNode(T const& val = T()) {
					node*	newNode = _allocNode.allocate(1);
					_allocNode.construct(newNode, val);
					return newNode;
				}

				void	_deallocateNode(node* n) {
					_allocNode.destroy(n);
					_allocNode.deallocate(n, 1);
					n = NULL;
				}

				int	_getHeight(node* n) {
					if (n == NULL)
						return -1;
					else {
						int	lheight = _getHeight(n->left);
						int	rheight = _getHeight(n->right);
						return ((lheight > rheight) ? lheight : rheight) + 1;
					}
				}

				int	_getBalanceFactor(node* n) {
					if (n == NULL)
						return -1;
					return _getHeight(n->left) - _getHeight(n->right);
				}

				node*	_rightRotate(node* y) {
					node*	child = y->left;
					node*	baby = child->right;

					child->right = y;
					child->parent = y->parent;
					y->left = baby;
					y->parent = child;
					if (baby != NULL)
						baby->parent = y;
					return child;
				}

				node*	_leftRotate(node* x) {
					node*	child = x->right;
					node*	baby = child->left;

					child->left = x;
					child->parent = x->parent;
					x->right = baby;
					x->parent = child;
					if (baby != NULL)
						baby->parent = x;
					return child;
				}

				node*	_insertHelper(node* root, node* n) {
					if (root == NULL)
						return n;
					// Left subtree case
					if (_comp(n->data,  root->data)) {
						root->left = _insertHelper(root->left, n);
						root->left->parent = root;
					}
					// Right subtree case
					else if (_comp(root->data, n->data)) {
						root->right = _insertHelper(root->right, n);
						root->right->parent = root;
					}
					// Rebalance the tree
					int	bf = _getBalanceFactor(root);
					// Left left case
					if (bf > 1 && _comp(n->data, root->left->data))
						return _rightRotate(root);
					// Right right case
					if (bf < -1 && _comp(root->data, n->data))
						return _leftRotate(root);
					// Left right case
					if (bf > 1 && _comp(root->data, n->data)) {
						root->left = _leftRotate(root->left);
						return _rightRotate(root);
					}
					// Right left case
					if (bf < -1 && _comp(n->data, root->right->data)) {
						root->right = _rightRotate(root->right);
						return _leftRotate(root);
					}
					return root;
				}

				node*	_removeHelper(node* root, T const& key) {
					if (root == NULL)
						return root;
					if (_comp(key, root->data))
						root->left = _removeHelper(root->left, key);
					else if(_comp(root->data, key))
						root->right = _removeHelper(root->right, key);
					else {
						// No child case
						if (root->left == NULL && root->right == NULL) {
							this->_allocNode.destroy(root);
							this->_allocNode.deallocate(root, 1);
							root = NULL;
							return (NULL);
						}
						// One child case
						else if (root->left == NULL || root->right == NULL) {
							node*	temp = root;
							root = root->left ? root->left : root->right;
							root->parent = temp->parent;
							_deallocateNode(temp);
							return (root);
						}
						// Two childs case
						else {
							node* temp = maximum(root->left);
							// Destroy and construct for const value
							_allocPair.destroy(&root->data);
							_allocPair.construct(&root->data, temp->data);
							root->left = _removeHelper(root->left, temp->data);
						}
					}
					// If the tree had only one node
					if (root == NULL)
						return root;
					// Rebalance the tree
					int	bf = _getBalanceFactor(root);
					// Left Left Case
					if (bf > 1 && _getBalanceFactor(root->left) >= 0)
						return _rightRotate(root);
					// Left Right Case
					if (bf > 1 && _getBalanceFactor(root->left) < 0) {
						root->left = _leftRotate(root->left);
						return _rightRotate(root);
					}
					// Right Right Case
					if (bf < -1 && _getBalanceFactor(root->right) <= 0)
						return _leftRotate(root);
					// Right Left Case
					if (bf < -1 && _getBalanceFactor(root->right) > 0) {
						root->right = _rightRotate(root->right);
						return _leftRotate(root);
					}
					return root;
				}
		};
}

#endif // AVLTREE_HPP
