//
// Created by yalavrinenko on 29.03.2021.
//

#include "snake.hpp"

void snake::move() {
  std::copy_backward(std::rbegin(body_), std::prev(std::rend(body_)), std::rend(body_));
  body_.back() += direction_;
}

void snake::feed(const point<size_t> &food_position) {
  body_.push_back(food_position);
}
