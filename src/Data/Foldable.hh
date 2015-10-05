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

#include "PureScript/PureScript.hh"

namespace Data_Foldable {

  using namespace PureScript;

  inline auto foldrArray(const any& f) -> any {
    return [=](const any& z) -> any {
      return [=](const any& xs_) -> any {
        auto xs = xs_.cast<any::vector>();
        auto acc = z.cast<any::vector>();
        for (typename any::vector::const_iterator xit = xs.begin(); xit != xs.end() ;++xit) {
          acc = f(*xit)(acc);
        }
        return acc;
      };
    };
  }

  inline auto foldlArray(const any& f) -> any {
    return [=](const any& z) -> any {
      return [=](const any& xs_) -> any {
        auto xs = xs_.cast<any::vector>();
        auto acc = z.cast<any::vector>();
        for (typename any::vector::const_iterator xit = xs.begin(); xit != xs.end() ;++xit) {
          acc = f(acc)(*xit);
        }
        return acc;
      };
    };
  }
}

#endif // Data_FoldableFFI_HH
