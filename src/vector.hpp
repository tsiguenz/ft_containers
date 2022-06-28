/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/28 19:27:34 by tsiguenz         ###   ########.fr       */
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
			typedef struct	RandomAccessIterator<T> iterator;

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
