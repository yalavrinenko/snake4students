//
// Created by yalavrinenko on 29.03.2021.
//

#ifndef SNAKE_COMMON_HPP
#define SNAKE_COMMON_HPP

#include <type_traits>
#include <iostream>

template<typename T>
struct point{
  T x, y;

  auto operator+ (point const& rhs) const{
    return point{x + rhs.x, y + rhs.y};
  }

  template<typename TRhs> requires std::is_convertible_v<TRhs, T>
  auto operator+ (point<TRhs> const& rhs) const {
    return point{x + rhs.x, y + rhs.y};
  }

  template<typename TRhs> requires std::is_convertible_v<TRhs, T>
  auto& operator+= (point<TRhs> const& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  template<typename TRhs> requires std::is_convertible_v<TRhs, T>
  auto operator <=>(point<TRhs> const& rhs) const{
    return (x == rhs.x) ? y <=> rhs.y : x <=> rhs.x;
  }
};

template<typename T>
point(T, T) -> point<T>;

template<typename T>
auto& operator<<(std::ostream &out, point<T> const &v){
  return out << "[" << v.x << " " << v.y << "]";
}

#endif //SNAKE_COMMON_HPP
