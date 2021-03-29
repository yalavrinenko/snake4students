//
// Created by yalavrinenko on 29.03.2021.
//

#ifndef SNAKE_GAME_FIELD_HPP
#define SNAKE_GAME_FIELD_HPP

#include <map>
#include "snake.hpp"
#include <chrono>

class game_field;

template<typename T>
concept IsPlayer = requires (T &p, user_snake &s, point<size_t> const& food, game_field const* field){
  {p.make_move(s, food, field)};
};

struct game_statistics{
  bool win;
  size_t steps;
  std::chrono::milliseconds time;
};

class game_field {
public:
  game_field(size_t N, size_t M);

  auto play_game(IsPlayer auto &player);

  virtual ~game_field() = default;
protected:
  [[nodiscard]] auto generate_food() const;

private:
  snake snake_;
  std::map<point<size_t>, bool>  game_field_;
  point<size_t> food_{};
  size_t N_, M_;
  size_t free_cells_;
};

auto game_field::play_game(IsPlayer auto &player) {
  auto step = 0ul;
  auto stime = std::chrono::high_resolution_clock::now();


  auto ftime = std::chrono::high_resolution_clock::now();
}

#endif //SNAKE_GAME_FIELD_HPP
