#include "mappable_set/comparator.hpp"

namespace nstd {

template <typename T, typename Key>
Comparator<T, Key>::Comparator(Key T::* field) : field(field) {};

template <typename T, typename Key>
bool Comparator<T, Key>::operator() (const T& lhs, const T& rhs) const
{
  return lhs.*field < rhs.*field;
}

template <typename T, typename Key>
bool Comparator<T, Key>::operator() (const T& lhs, const Key& rhs) const
{
  return lhs.*field < rhs;
}

template <typename T, typename Key>
bool Comparator<T, Key>::operator() (const Key& lhs, const T& rhs) const
{
  return lhs < rhs.*field;
}
} //namespace nstd
