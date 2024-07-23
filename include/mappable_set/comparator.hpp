#pragma once

namespace nstd {

template <typename T, typename Key>
class Comparator {
public:
  Comparator(Key T::* field);

  bool operator() (const T& lhs, const T& rhs) const;
  bool operator() (const T& lhs, const Key& rhs) const;
  bool operator() (const Key& lhs, const T& rhs) const;

private:
  Key T::* field;
};
} //namespace nstd
