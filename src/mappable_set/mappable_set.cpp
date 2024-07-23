#include "mappable_set/mappable_set.hpp"
#include <algorithm>

namespace nstd {

template<typename T, typename Key>
MappableSet<T, Key>::MappableSet(Key T::* field) : field(field), comparator(field), set(comparator) {};

template<typename T, typename Key>
void MappableSet<T, Key>::insert(const T& value)
{
  set.insert(value); 
}

template<typename T, typename Key>
const T& MappableSet<T, Key>::get(const Key& key) const
{
  const auto& [begin, end] = std::equal_range(set.begin(), set.end(), key, comparator);
  return *begin;
}

template<typename T, typename Key>
void MappableSet<T, Key>::modifyKey(const Key& oldKey, const Key& newKey)
{
  const auto& [begin, end] = std::equal_range(set.begin(), set.end(), oldKey, Comparator(field));
  T newElement = *begin;
  newElement.*field = newKey;
  set.erase(begin);
  set.insert(std::move(newElement));
}
} //namespace nstd
