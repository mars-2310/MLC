#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "../tensor/tensor.h";

Tensor linear_regression_train(Tensor a, Tensor b, float lr, int iteration);
Tensor linear_regression_predict(Tensor a, Tensor theta);

#endif
