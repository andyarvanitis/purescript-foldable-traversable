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

#include "PureScript/PureScript.hh"

namespace Data_Traversable {

  using namespace PureScript;

  auto traverseArrayImpl(const any&) -> any;

}

#endif // Data_TraversableFFI_HH
