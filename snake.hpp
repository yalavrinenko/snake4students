//
// Created by yalavrinenko on 29.03.2021.
//

#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <list>

class snake {
public:
  using snake_segment = std::pair<size_t, size_t>;
  using snake_body = std::list<snake_segment>;

  snake(size_t cx, size_t cy, size_t len): body_(len){

  }

private:
  snake_body body_;
};


#endif //SNAKE_SNAKE_HPP
