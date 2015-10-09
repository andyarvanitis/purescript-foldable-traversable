///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Foldable.cc
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Foldable FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#include "Foldable.hh"

namespace Data_Foldable {

  using namespace PureScript;

  auto foldrArray(const any& f) -> any {
    return [=](const any& init) -> any {
      return [=](const any& xs_) -> any {
        const auto& xs = xs_.cast<any::vector>();
        any acc = init;
        for (typename any::vector::const_reverse_iterator it = xs.rbegin(); it != xs.rend() ; ++it) {
          acc = f(*it)(acc);
        }
        return acc;
      };
    };
  }

  auto foldlArray(const any& f) -> any {
    return [=](const any& init) -> any {
      return [=](const any& xs_) -> any {
        const auto& xs = xs_.cast<any::vector>();
        any acc = init;
        for (typename any::vector::const_iterator it = xs.begin(); it != xs.end() ; ++it) {
          acc = f(acc)(*it);
        }
        return acc;
      };
    };
  }
}
