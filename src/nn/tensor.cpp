#include "nn/tensor.h"
#include <iostream>
#include <vector>

Tensor::Tensor(float data) : _data{data}, _shape{} {};

Tensor::Tensor(std::vector<float> data) : _data(data), _shape{data.size()} {};

