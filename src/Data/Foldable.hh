///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Foldable.hh
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
#ifndef Data_FoldableFFI_HH
#define Data_FoldableFFI_HH

#include "Purescript/Purescript.hh"

namespace Data_Foldable {

  using namespace PureScript;

  template <typename A, typename B>
  auto foldrArray(fn<A,fn<B,B>> f) -> fn<B,fn<list<A>,B>> {
    return [=](B z) {
      return [=](list<A> xs) {
        auto acc = z;
        for (typename list<A>::const_iterator xit = xs.begin(); xit != xs.end() ;++xit) {
          acc = f(*xit)(acc);
        }
        return acc;
      };
    };
  }

  template <typename A, typename B>
  auto foldlArray(fn<B,fn<A,B>> f) -> fn<B,fn<list<A>,B>> {
    return [=](B z) {
      return [=](list<A> xs) {
        auto acc = z;
        for (typename list<A>::const_iterator xit = xs.begin(); xit != xs.end() ;++xit) {
          acc = f(acc)(*xit);
        }
        return acc;
      };
    };
  }
}

#endif // Data_FoldableFFI_HH
