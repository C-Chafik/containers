# containers

## Vector

  Vectors are sequence containers representing arrays that can change in size.

  Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on       regular pointers to its elements, and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, with their storage being     handled automatically by the container.

  Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new      elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing      time, and thus, vectors do not reallocate each time an element is added to the container.

   Instead, vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity          greater than the storage strictly needed to contain its elements (i.e., its size). Libraries can implement different strategies for growth to balance      between memory usage and reallocations, but in any case, reallocations should only happen at logarithmically growing intervals of size so that the          insertion of individual elements at the end of the vector can be provided with amortized constant time complexity (see push_back).

  Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.

  #### Contiguous memory
  
  Vector is use a contiguous storage to store his elements, but what does it mean ?

  A contiguous memory is a memory that follow each other, for example, an array have a contiguous memory, because every value is stick to each other, an     example of that is like a tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};, every value's memory follow the next one.

  And then what is a not contiguous memory ?, lets take the example of a chained list, it use pointers to link each other, but the pointers are not most of the time near each other, this mean that we have a storage that store values, but the value's addresses are not in the same place.

  https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/

  https://cplusplus.com/reference/vector/vector/?kw=vector
