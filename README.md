# ft_containers
In this project, we have to re-implement a few container types of the C++ standard template library.

### How to compile:

Compile tests with my containers:
```
make
```
Compile test with real containers:
```
make real
```
Print the difference between the output of ./containers and ./containers_real:
```
make diff
```
Compile the subject main with my containers:
```
make subject
```
Compile the subject main with real containers:
```
make subject_real
```
Print the difference between the output of ./subject and ./subject_real:
```
make subdiff
``` 
Print the time of execution of ./subject and ./subject_real:
```
make time
``` 

---
### What is a container:
A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows great flexibility in the types supported as elements. The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).

---
### Containers needed for this project:
The containers we need to re-implement are:
- [vector](https://en.cppreference.com/w/cpp/container/vector): Dynamic contiguous array
- [stack](https://en.cppreference.com/w/cpp/container/stack): Adapts a container to provide stack (LIFO data structure)
- [map](https://en.cppreference.com/w/cpp/container/map): Collection of key-value pairs, sorted by keys, keys are unique

We also have to implement:
- [std::iterator_traits](https://en.cppreference.com/w/cpp/iterator/iterator_traits)
- [std::reverse_iterator](https://en.cppreference.com/w/cpp/iterator/reverse_iterator)
- [std::enable_if](https://en.cppreference.com/w/cpp/types/enable_if) (c++11 feature)
- [std::is_integral](https://en.cppreference.com/w/cpp/types/is_integral)
- [std::equal](https://en.cppreference.com/w/cpp/algorithm/equal) and/or [std::lexicographical_compare](https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare) (I do both)
- [std::pair](https://en.cppreference.com/w/cpp/utility/pair)
- [std::make_pair](https://en.cppreference.com/w/cpp/utility/pair/make_pair)

---
### Requirements:
- Only c++98 is allowed.
- The namespace must be ft.
- Each inner data structure used in your containers must be logical and justified (this
means using a simple array for map is not ok).
- You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function or
variable must be justified.
- All the member functions, non-member functions and overloads of the standard
containers are expected.
- You must follow the original naming. Take care of details.
- If the container has an iterator system, you must implement it.
- You must use std::allocator.
- For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.

---
### Others:
I used tests of others student in complement of mine:
- [MLI](https://github.com/mli42/containers_test)
- [mazoise](https://github.com/Mazoise/42TESTERS-CONTAINERS) one fail because it test the capacity of a vector and it depend of the implementation so I don't fix it ([proof](https://tylerayoung.com/2020/08/20/default-capacity-growth-rate-of-c-stdvector/))
