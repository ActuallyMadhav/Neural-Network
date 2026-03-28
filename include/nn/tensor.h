#pragma once
#include <vector>

class Tensor{
private:
    std::vector<float> _data;
    std::vector<std::size_t> _shape;
    

public:
    Tensor(float data); // scalar
    Tensor(std::vector<float> data); // 1d tensor
    Tensor(std::vector<std::vector<float>> data); // 2d tensor
};