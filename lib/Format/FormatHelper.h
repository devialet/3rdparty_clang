//===--- FormatHelper.h - Format C++ code -----------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// \brief This file implements some methods to check some specific token
/// requirements for Devialet.
///
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_FORMAT_HELPER_H
#define LLVM_CLANG_LIB_FORMAT_HELPER_H

#include "FormatToken.h"

namespace clang {
namespace format {

bool IsStdFunctionReturnType( const FormatToken* token );
bool IsQtSignalEmit( const FormatToken* token );

}
}

#endif
