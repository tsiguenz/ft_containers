/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:38:11 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/08/23 23:34:25 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

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
		class RedBlackTree {
			private:

				Node<T>*	root;

			public:

				typedef Node<T>	node;
				// constructor
				RedBlackTree() { root = NULL; }

				node*	getRoot() { return root; }

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

				void	insert(T const& data) {
					node*	newNode = new node(data);
					root = insertHelper(root, newNode);
				}

				void	deleteNode(T const& key) {
					node*	curr = searchByKey(key);

					if (curr == NULL)
						return ;
					if (curr->left == NULL && curr->right == NULL) {
						delete curr;
						curr = NULL;
						return ;
					}
					if (curr->left == NULL || curr->right == NULL) {
						node*	toDel;
						if (curr->left == NULL)
							toDel = curr->right;
						else 
							toDel = curr->left;
						curr->data = toDel->data;
						curr->left = toDel->left;
						delete toDel;
					}
				}

				node*	searchByKey(T const& key) {
					node*	curr = root;

					while (curr != NULL && curr->data != key) {
						if (curr->data < key)
							curr = curr->right;
						else
							curr = curr->left;
					}
					return curr;
				}

				node*	minimum() {
					node*	current = this->root;
					while (current->left != NULL)
						current = current->left;
					return current;
				}

				node*	maximum() {
					node*	current = this->root;
					while (current->right != NULL)
						current = current->right;
					return current;
				}

				void inorderHelper(node* root)
				{
					if (root == NULL)
						return;

					inorderHelper(root->left);
					std::cout << root->data << "  ";
					inorderHelper(root->right);
				}
		};
}

#endif // REDBLACKTREE_HPP
