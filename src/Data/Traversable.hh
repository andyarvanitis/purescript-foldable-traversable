///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Traversable.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Traversable FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_TraversableFFI_HH
#define Data_TraversableFFI_HH

#include "Purescript/Purescript.hh"

namespace Data_Traversable {

  using namespace PureScript;

  // forall m a b. (m (a -> b) -> m a -> m b) -> apply
  //               ((a -> b) -> m a -> m b) -> map
  //               (a -> m a) -> pure
  //               (a -> m b) -> f
  //               Array a -> xs
  //               m (Array b)

  // STUB!!!
  template <typename A, typename B, template <typename _M1> class M>
  auto traverseArrayImpl(const fn<M<fn<A,B>>,fn<M<A>,M<B>>>& apply) {
    return [=](const fn<fn<A,B>,fn<M<A>,M<B>>>& map) {
      return [=](const fn<A,M<A>>& pure) {
        return [=](const fn<A,M<B>>& f) {
          return [=](const array<A>& xs) {
            return array<B>();
          };
        };
      };
    };
  }
}

#endif // Data_TraversableFFI_HH
