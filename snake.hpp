//
// Created by yalavrinenko on 29.03.2021.
//

#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include "common.hpp"
#include <list>

class snake {
public:
  using snake_segment = point<size_t>;
  using snake_body = std::list<snake_segment>;

  snake(point<size_t> const &food_position, size_t len): body_(len){
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
