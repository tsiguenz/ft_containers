/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/24 21:58:01 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

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

		};

	template<typename T, class Alloc = std::allocator<T> >
		class AVLTree {
			public:

				typedef Node<T>	node;

			private:

				Node<T>*	_root;

				node*	insertHelper(node* _root, node* n) {
					if (_root == NULL) {
						return n;
					}
					if (n->data < _root->data) {
						_root->left = insertHelper(_root->left, n);
						_root->left->parent = _root;
					}
					else if (n->data > _root->data) {
						_root->right = insertHelper(_root->right, n);
						_root->right->parent = _root;
					}
					return _root;
				}

			public:

				// Constructor
				AVLTree()
				{ _root = NULL; }

				// Destructor
				~AVLTree() {
					while (_root != NULL) {
						remove(_root->data);
					}
				}

				node*	getRoot()
				{ return _root; }

				void	insert(T const& data) {
					node*	newNode = new node(data);
					_root = insertHelper(_root, newNode);
				}

				void	remove(T const& key) {
					node*	curr = searchByKey(key);

					if (curr == NULL)
						return ;
					if (curr == _root && curr->left == NULL && curr->left == NULL) {
						delete _root;
						_root = NULL;
						return ;
					}
					// Node without child
					if (curr->left == NULL && curr->right == NULL) {
						node*	p = curr->parent;

						(p->left == curr) ? p->left = NULL : p->right = NULL;
						delete curr;
						return ;
					}
					// Node with one child
					if (curr->left == NULL || curr->right == NULL) {
						node*	toDel;
						if (curr->left == NULL)
							toDel = curr->right;
						else 
							toDel = curr->left;
						curr->data = toDel->data;
						curr->left = toDel->left;
						curr->right = toDel->right;
						delete toDel;
						return ;
					}
					// Node with two child
					node*	successor = minimum(curr->right);
					node*	p = successor->parent;

					(p->left == successor) ? p->left = NULL : p->right = NULL;
					curr->data = successor->data;
					delete successor;
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
		};
}

#endif // AVLTREE_HPP
