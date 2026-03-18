#include "tensor.h"
#include <stdio.h>
#include <stdlib.h>


Tensor tensor_create(int dim, int *shape){
	Tensor t;
	t.dim = dim;
	t.shape = malloc(sizeof(int) * dim);
	t.size = 1;
	for(int i = 0; i < dim; i++){
		t.shape[i] = shape[i];
		t.size = t.size * shape[i];
	};
	t.data = malloc(sizeof(float)*t.size);
	
	return t;
};


Tensor tensor_copy(Tensor *a){
	Tensor t = tensor_create(a.dim, a.shape);
	for(int i = 0; i < t.size; i++){
		t.data[i] = a.data[i];
	};

	return t;
};

Tensor tensor_zeroes(int dim, int *shape){
	Tensor t = tensor_create(dim, shape);
	for(int i = 0; i < t.size; i++){
		t.data[i] = 0;
	};

	return t;
};


Tensor tensor_ones(int dim, int *shape){
	Tensor t = tensor_create(dim, shape);
	for(int i = 0; i < t.size; i++){
		t.data[i] = 0;
	};

	return t;
};

Tensor tensor_rand(int dim, int *shape){
	Tensor t = tensor_create(dim, shape);
	for(int i = 0; i < t.size; i++){
	
	};

	return t;
};


//free memory
void tensor_free(Tensor *t){
	free(t.data);
	free(t.shape);
	*t.data = NULL;
	*t.shape = NULL;
	*t.dim = 0;
	*t.size = 0;
};


float tensor_get(Tensor *t, int *indices){
	int index = 0;
	int stride = 1;
	for(int i = *t.dim - 1; i >= 0; i--){
		index += stride * indices[i];
		stride *= *t.shape[i];
	};

	return *t.data[index];
};


void tensor_set(Tensor *t, int *indices, float *value){
	int index = 0;
	int stride = 1;
	for(int i = *t.dim - 1; i >= 0; i--){
		index += stride * indices[i];
		stride *= *t.shape[i];
	};

	*t.data[index] = value;
};


Tensor tensor_add(Tensor a, Tensor b){
	Tensor t = tensor_create(a.dim, a.size);
	for(int i = 0; i < t.size; i++){
		t.data[i] = a.data[i] + b.data[i];
	};

	return t;
};


Tensor tensor_sub(Tensor a, Tensor b){
	Tensor t = tensor_create(a.dim, a.size);
	for(int i = 0; i < t.size; i++){
		t.data[i] = a.data[i] - b.data[i];
	};

	return t;
};


Tensor tensor_scalar_mul(Tensor a, float scalar){
	Tensor t = tensor_create(a.dim, a.size);
	for(int i = 0; i < t.size; i++){
		t.data[i] = scalar * a.data[i];
	};

	return t;
};



Tensor tensor_matmul(Tensor a, Tensor b){
    if(a -> dim != 2 || b -> dim != 2){
        printf("Only 2D tensors supported!");
        exit(1);
    };

    if(a -> shape[1] != b -> shape[0]){
        printf("Shape doesn't match");
        exit(1);
    };
    
    int sshape = {a -> shape[0], b -> shape[1]};
    Tensor t = tensor_create(2, sshape);
    
    for(int i = 0; i < a -> shape[0]; i++){
        for(int j = 0; j < b -> shape[1]; j++){
            float sum = 0;
            for(int k = 0; k < a -> shape[1]; k++){
                float val1 = a -> data[i*(a->shape[1]) + k];
                float val2 = b -> data[k*(b->shape[1]) + j];
                sum += val1 * val2;
            };
            t.data[i*(b->shape[1]) + j] = sum;
        };
    };
	return t;
};


Tensor tensor_transpose(Tensor *a){
    if(a -> dim != 2){
        printf("Only 2D tensors supported");
        exit(1);
    };

    int row = a -> shape[0];
    int col = a -> shape[1];
    
    Tensor t = tensor_create(2, {col, row});
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            t.data[j*row + i] = t -> data[i*col + j];
        };
    };
    return t;
};



Tensor tensor_print(Tensor t){
    printf("[");
    if(t.dim == 1){
        for(int i = 0; i < t.shape[0]; i++){
            printf("%f ", t.data[i]);
        };
    } 
    else if(t.dim == 2){
        int row = t.shape[0];
        int col = t.shape[1];

        for(int  i = 0; i < row; i++){
            printf("[ ");
            for(int j = 0; j < col; j++){
                printf("%f ", t.data[i * col + j]);
            };
            printf("]\n");
        };
    }
    else {
        printf("Only allowed for upto two dimensions\n");
    };
    printf("]\n");
};
