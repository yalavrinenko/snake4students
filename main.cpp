//
// Created by yalavrinenko on 29.03.2021.
//

#include "snake.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

int main(int argc, char** argv){

  snake s{{5, 5}, 4};

  auto show = [&s]() {
    std::copy(s.body().begin(), s.body().end(), std::ostream_iterator<point<size_t>>{std::cout, "\t"});
    std::cout << "\n";
  };
  show();
  for (auto func: {&snake::turn_down, &snake::turn_left, &snake::turn_up, &snake::turn_right}) {
    std::invoke(func, s);
    for ([[maybe_unused]]std::weakly_incrementable auto const&i: vs::iota(0, 4)){
      s.move();
      show();
    }
  }



  return 0;
}