/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/24 19:36:30 by tsiguenz         ###   ########.fr       */
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

				Node<T>*	root;

				node*	insertHelper(node* root, node* n) {
					if (root == NULL) {
						return n;
					}
					if (n->data < root->data) {
						root->left = insertHelper(root->left, n);
						root->left->parent = root;
					}
					else if (n->data > root->data) {
						root->right = insertHelper(root->right, n);
						root->right->parent = root;
					}
					return root;
				}

			public:

				// Constructor
				AVLTree()
				{ root = NULL; }

				// Destructor
				~AVLTree() {
					while (root != NULL) {
						remove(root->data);
					}
				}

				node*	getRoot()
				{ return root; }

				void	insert(T const& data) {
					node*	newNode = new node(data);
					root = insertHelper(root, newNode);
				}

				void	remove(T const& key) {
					node*	curr = searchByKey(key);

					if (curr == NULL)
						return ;
					if (curr == root && curr->left == NULL && curr->left == NULL) {
						delete root;
						root = NULL;
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
					node*	curr = this->root;

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
				{ return minimum(this->root); }

				node*	maximum(node* n) {
					node*	current = n;
					while (current->right != NULL)
						current = current->right;
					return current;
				}

				node*	maximum()
				{ return maximum(this->root); }

				void	inorder(node* root) const {
					if (root == NULL)
						return;
					inorder(root->left);
					std::cout << root->data << "  ";
					inorder(root->right);
				}
		};
}

#endif // AVLTREE_HPP
