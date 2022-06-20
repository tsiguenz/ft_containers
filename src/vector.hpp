/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 10:48:08 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/20 18:27:56 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public:

		// Object managment

			vector(): c(), size() { }
			vector(size_t const& size): size(size) { c = allocator.allocate(size); }
			vector(vector const& rhs) { *this = rhs; }
			~vector() { allocator.deallocate(c, this->size); }

		// Operator overload

			vector&	operator=(vector const& rhs) {
				//TODO implement copy operator
				return rhs;
			}
			T&	operator[](size_t const& pos) { return this->c[pos]; }

		// Member functions

			// Iterators

			//std::iterator<T>.pointer	begin() { return this->c; }

			// Element acces TODO test element acces

			// need the same exception message ?
			T&	at(size_t pos) {
				if (pos < 0 || pos >= size)
					throw std::out_of_range("Vector::Out of range");
				return (*this)[pos];
			}
			T&	front() { return (*this)[0]; }//TODO replace with iterators
			T&	back() { return (*this)[this->size - 1]; }//TODO replace with iterators
			T*	data() { return this->c; }

		protected:
			T*			c;
			size_t		size;
			Allocator	allocator;

		private:

	};
}

#endif
