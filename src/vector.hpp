/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/29 12:02:33 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <Iterators.hpp>
namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public:
		// Types :
			typedef T	value_type;
			typedef Allocator	allocator_type;
			typedef typename std::allocator_traits<Allocator>::pointer	pointer;
			typedef typename std::allocator_traits<Allocator>::const_pointer	const_pointer;
			typedef value_type&	reference;
			typedef const value_type&	const_reference;
			typedef size_t	size_type;
			typedef ptrdiff_t	difference_type;
			typedef struct	RandomAccessIterator<T>	iterator;
			typedef struct	RandomAccessIterator<const T>	const_iterator;
			typedef std::reverse_iterator<iterator>	reverse_iterator;
			typedef std::reverse_iterator<const iterator>	const_reverse_iterator;
		// Object managment

			vector(): c(0), size(0) { }

			vector(size_t const& size): size(size) {
				this->c = allocator.allocate(this->size);
				for (size_t i = 0; i < this->size; i++)
					allocator.construct(this->c + i, 0);
			}

			vector(vector const& rhs) { *this = rhs; }

			~vector() {
				allocator.deallocate(c, this->size);
				for (size_t i = 0; i < this->size; i++)
					allocator.destroy(this->c + i);
			}

		// Operator overload

			vector&	operator=(vector const& rhs) {
				//TODO implement copy operator
				return rhs;
			}
			T&	operator[](size_t const& pos) { return this->c[pos]; }

		// Member functions

			// Iterators

			iterator	begin() { return this->c; }
			iterator	end() { return this->c + size; }

			// Element acces TODO test element acces

			// need the same exception message ?
			T&	at(size_t pos) {
				if (pos < 0 || pos >= size)
					throw std::out_of_range("Vector::Out of range");
				return (*this)[pos];
			}
			T&	front() { return *(this->begin()); }
			T&	back() { return *(this->end() - 1); }//TODO test operators
			T*	data() { return this->c; }

		protected:
			T*			c;
			size_t		size;
			Allocator	allocator;

		private:

	};
}

#endif
