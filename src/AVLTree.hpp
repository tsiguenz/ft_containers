/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/09/08 23:31:51 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include "AVLIterator.hpp"
# include "pair.hpp"

namespace ft {
	template<typename T>
		struct Node {
			T		data;
			Node*	left;
			Node*	right;
			Node*	parent;

			Node(T const& val = T()): data(val) {
				left = right = parent = NULL;
			}

			~Node() { }
		};

	template<typename T, class Alloc = std::allocator<T>, class Compare = std::less<T> >
		class AVLTree {
			private:

				typedef Node<T>	node;
				typedef typename Alloc::template rebind<node>::other AllocNode;

				Node<T>*	_root;
				Node<T>*	_begin;
				Node<T>*	_end;
				Alloc		_allocPair;
				AllocNode	_allocNode;
				size_t		_size;
				Compare		_comp;

			public:

				// Constructor
				AVLTree() {
					_root = NULL;
					_begin = NULL;
					_end = _createNode();
					_allocPair = Alloc();
					_allocNode = AllocNode();
					_size = 0;
					_comp = Compare();
				}

				// Destructor
				~AVLTree() {
					while (_root != NULL)
						remove(_root->data);
					_deallocateNode(_end);
				}

				// TODO implement copy constructor and operator=

				node*	getRoot()
				{ return _root; }

				void	insert(T const& data) {
					// Duplicates are not allowed (don't protect duplicate key in pair)
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
					_begin = minimum();
					_setEnd();
				}

				node*	searchByData(T const& data) {
					node*	curr = this->_root;
					while (curr != NULL && curr->data != data)
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
					std::cout << root->data.first << "  ";
					inorder(root->right);
				}

				size_t	size() const
				{ return _size; }

				node*	begin()
				{ return _begin; }

				node*	end()
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
//					node*	x = y->left;
//
//					y->left = x->right;
//					x->right = y;
//					return x;
					node*	left_child = y->left;
					node*	right_g_child = left_child->right;

					left_child->right = y;
					left_child->parent = y->parent;
					y->left = right_g_child;
					if (left_child != _end)
						y->parent = left_child;
					if (right_g_child != NULL)
						right_g_child->parent = y;
					return left_child;
				}

				node*	_leftRotate(node* x) {
//					node*	y = x->right;
//
//					x->right = y->left;
//					y->left = x;
//					return y;
					node*	right_child = x->right;
					node*	left_g_child = right_child->left;

					right_child->left = x;
					right_child->parent = x->parent;
					x->right = left_g_child;
					if (right_child != _end)
						x->parent = right_child;
					if (left_g_child != NULL)
						left_g_child->parent = x;
					return right_child;
				}

				node*	_insertHelper(node* root, node* n) {
					if (root == NULL)
						return n;
					// Left subtree case
					// implement value_compare
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
							return (root);
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
							node* temp = minimum(root->right);
							// Destroy and construct for const value
							_allocPair.destroy(&root->data);
							_allocPair.construct(&root->data, temp->data);
							root->right = _removeHelper(root->right, temp->data);
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
