//
// Created by yalavrinenko on 29.03.2021.
//

#include "snake.hpp"

void snake::move() {
  std::copy_backward(std::rbegin(body_), std::prev(std::rend(body_)), std::next(std::rbegin(body_)));
  body_.back() += direction_;
}
