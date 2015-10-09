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

  auto foldrArray(const any&) -> any;

  auto foldlArray(const any&) -> any;

}

#endif // Data_FoldableFFI_HH
