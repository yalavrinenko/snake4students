//
// Created by yalavrinenko on 29.03.2021.
//

#include "game_field.hpp"
#include <random>
struct RandomEngine{
protected:
  static auto& engine() {
    static std::mt19937_64 eng{std::random_device{}()};
    return eng;
  }
public:
  template<class random_t>
  static auto rangom_in_range(random_t from, random_t to){
    return std::uniform_int_distribution<random_t>{from, to}(RandomEngine::engine());
  }
};

auto game_field::generate_food() const {
  auto cell_id = RandomEngine::rangom_in_range(0ul, free_cells_);

  auto field_it = game_field_.begin();
  for (auto i = 0ul; i < cell_id; ++field_it){
    if (!field_it->second) ++i;
  }
  while (field_it->second)
    ++field_it;

  return field_it->first;
}
game_field::game_field(size_t N, size_t M) : snake_({N / 2, M / 2}, 5), N_{N}, M_{M}, free_cells_{N_ * M_} {
  for (std::weakly_incrementable auto i: vs::iota(0ul, N))
    for (std::weakly_incrementable auto j: vs::iota(0ul, M))
      game_field_[{i, j}] = false;

  std::for_each(snake_.body().begin(), snake_.body().end(), [this](auto const& kv){
    game_field_[kv] = true;
  });

  free_cells_ -= snake_.length();

  food_ = generate_food();
}
