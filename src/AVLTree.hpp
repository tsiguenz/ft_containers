/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/30 18:44:48 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include "AVLIterator.hpp"

namespace ft {

	template<typename T>
		struct Node {
			T		data;
			Node*	left;
			Node*	right;
			Node*	parent;

			Node(T const& data = T()) {
				this->data = data;
				left = right = parent = NULL;
			}

			~Node() { }
		};

	template<typename T, class Alloc = std::allocator<T> >
		class AVLTree {
			private:

				typedef Node<T>	node;
				typedef typename Alloc::template rebind<node>::other AllocNode;

			public:

				// Constructor
				AVLTree()
				: _root(NULL), _allocPair(), _allocNode() { }

				// Destructor
				~AVLTree() {
					while (_root != NULL) {
						remove(_root->data);
					}
				}

				// TODO implement copy constructor and operator=

				node*	getRoot()
				{ return _root; }

				void	insert(T const& data) {
					// Duplicates are not allowed
					if (searchByKey(data) != NULL)
						return ;
					node*	newNode = _createNode(data);
					_root = _insertHelper(_root, newNode);
				}

				void	remove(T key) {
					_root = _removeHelper(_root, key);
				}

				node*	searchByKey(T const& key) {
					node*	curr = this->_root;

					while (curr != NULL && curr->data != key)
						curr = (curr->data < key) ? curr->right : curr->left;
					return curr;
				}

				node*	minimum(node* n) {
					node*	current = n;
					while (current->left != NULL)
						current = current->left;
					return current;
				}

				node*	minimum()
				{ return minimum(this->_root); }

				node*	maximum(node* n) {
					node*	current = n;
					while (current->right != NULL)
						current = current->right;
					return current;
				}

				node*	maximum()
				{ return maximum(this->_root); }

				void	inorder(node* _root) const {
					if (_root == NULL)
						return;
					inorder(_root->left);
					std::cout << _root->data << "  ";
					inorder(_root->right);
				}

			private:

				Node<T>*	_root;
				Alloc		_allocPair;
				AllocNode	_allocNode;

				node*	_createNode(T const& val) {
					node*	newNode = _allocNode.allocate(1);

					_allocNode.construct(newNode, val);
					return newNode;
				}

				void	_deallocateNode(node* n) {
					_allocNode.destroy(n);
					_allocNode.deallocate(n, 1);
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
					node*	x = y->left;
					node*	T2 = x->right;

					x->right = y;
					y->left = T2;
					return x;
				}

				node*	_leftRotate(node* x) {
					node*	y = x->right;
					node*	T2 = y->left;

					y->left = x;
					x->right = T2;
					return y;
				}

				node*	_insertHelper(node* _root, node* n) {
					if (_root == NULL)
						return n;
					// Left subtree case
					if (n->data < _root->data) {
						_root->left = _insertHelper(_root->left, n);
						_root->left->parent = _root;
					}
					// Right subtree case
					else if (n->data > _root->data) {
						_root->right = _insertHelper(_root->right, n);
						_root->right->parent = _root;
					}
					int	bf = _getBalanceFactor(_root);
					// Left left case
					if (bf > 1 && n->data < _root->left->data)
						return _rightRotate(_root);
					// Right right case
					if (bf < -1 && n->data > _root->right->data)
						return _leftRotate(_root);
					// Left right case
					if (bf > 1 && n->data > _root->left->data) {
						_root->left = _leftRotate(_root->left);
						return _rightRotate(_root);
					}
					// Right left case
					if (bf < -1 && n->data < _root->right->data) {
						_root->right = _rightRotate(_root->right);
						return _leftRotate(_root);
					}
					return _root;
				}

				node*	_removeHelper(node* root, T const& key) {

					if (root == NULL)
						return root;
					if ( key < root->data )
						root->left = _removeHelper(root->left, key);
					else if( key > root->data )
						root->right = _removeHelper(root->right, key);
					else {
						// Node with only one child or no child
						if( (root->left == NULL) || (root->right == NULL) ) {
							node* temp = root->left ?
								root->left :
								root->right;
							// No child case
							if (temp == NULL) {
								temp = root;
								root = NULL;
							}
							else // One child case
								*root = *temp;
							_deallocateNode(temp);
						}
						else {
							// node with two children: Get the inorder
							// successor (smallest in the right subtree)
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
