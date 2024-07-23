#pragma once
#include "mappable_set/comparator.hpp"
#include <set>

namespace nstd {

template <typename T, typename Key>
class MappableSet {
public: 
  MappableSet(Key T::* field);

  void insert(const T& value);

  const T& get(const Key& key) const;

  void modifyKey(const Key& oldKey, const Key& newKey);

private:
  Key T::* field;
  Comparator<T, Key> comparator;
  std::set<T, decltype(comparator)> set;
}; 
} //namespace nstd
