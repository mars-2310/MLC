#ifndef TENSOR_H
#define TENSOR_H

#include<stdlib.h>

typedef struct {
	float *data;
	int *shape;
	int dim;
	int size;
} Tensor;

Tensor tensor_create(int dim, int *shape);
Tensor tensor_copy(Tensor *a);
Tensor tensor_zeroes(int dim, int *shape);
Tensor tensor_ones(int dim, int *shape);
Tensor tensor_rand(int dim, int *shape);

void tensor_free(Tensor *t);

float tensor_get(Tensor *t, int *indices);
void tensor_set(Tensor *t, int *indices, float value);

Tensor tensor_add(Tensor a, Tensor b);
Tensor tensor_sub(Tensor a, Tensor b);
Tensor tensor_scalar_mul(Tensor a, float scalar);

Tensor tensor_matmul(Tensor *a, Tensor *b);
Tensor tensor_transpose(Tensor *a);

void tensor_print(Tensor t);


#endif
