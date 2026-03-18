#include<stdio.h>
#include "../tensor/tensor.h";
#include "./linear_regression.h";

Tensor linear_regression_predict(Tensor a, Tensor theta){
    return tensor_matmul(a, theta);
};

Tensor linear_regression_train(Tensor a, Tensor b, float lr, int iteration){
    int n = a.shape[1];
    int sshape[2] = {n, 1};
    Tensor theta = tensor_zeroes(2, sshape);

    for(int iter = 0; iter < iteration; iter++){
        Tensor pred = tensor_matmul(&a, &theta);
        Tensor error = tensor_sub(pred, b);
        Tensor XT = tensor_transpose(&a);
        Tensor grad = tensor_matmul(&XT, &error);

        for(int i = 0; i < grad.size(); i++){
            grad.data[i] /= X.shape[0];
        };

        for(int i = 0; i < theta.size(); i++){
            theta.data[i] -= lr*grad.data[i];
        };

        tensor_free(&pred);
        tensor_free(&error);
        tensor_free(&XT);
        tensor_free(&grad);
    };
    return theta;
};
