#pragma once

#include <Eigen/Dense>

Eigen::MatrixXf load_images(const std::string &filepath);
Eigen::MatrixXf load_labels(const std::string &filepath);
