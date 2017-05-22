#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <stdlib.h>

#define VECTOR(T) typedef struct { int capacity; int size; T *data; } Vector_##T

#define VECTOR_INIT(T, vec) do { Vector_##T v = vec; v.capacity = v.size = 0; v.data = NULL; vec = v; } while(0);

#endif // VECTOR_HPP_INCLUDED
