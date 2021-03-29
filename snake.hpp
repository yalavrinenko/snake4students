//
// Created by yalavrinenko on 29.03.2021.
//

#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include "common.hpp"
#include <vector>
#include <ranges>

namespace rs = std::ranges;
namespace vs = std::views;

class snake {
public:
  using snake_segment = point<size_t>;
  using snake_body = std::vector<snake_segment>;

  snake(point<size_t> const &head_position, size_t len){
    for (std::weakly_incrementable auto const& i : vs::iota(0, static_cast<int>(len)))
      body_.push_back(head_position + point<int>{i, 0});
  }

  void turn_up() { direction_ = {0, 1}; }
  void turn_down() { direction_ = {0, -1};}
  void turn_left() { direction_ = {-1, 0}; }
  void turn_right() { direction_ = {0, 1}; }

  void feed(point<size_t> const& food_position);

  void move();

  [[nodiscard]] auto const& body() const { return body_; }
private:
  snake_body body_;
  point<int> direction_{1, 0};
};


#endif //SNAKE_SNAKE_HPP
