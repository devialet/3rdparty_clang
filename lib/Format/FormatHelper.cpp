//===--- FormatHelper.cpp - Format C++ code ---------------------*- C++ -*-===//
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

#include "FormatHelper.h"

namespace clang {
namespace format {

bool IsStdFunctionReturnType( const FormatToken* token )
{
  //Return type must starts with an identifier
  if (token->is(tok::identifier) || token->isSimpleTypeSpecifier()) {
    //Skip identifier::...::identifier sequence
    while ((token->isOneOf(tok::identifier, tok::coloncolon) ||
            token->isSimpleTypeSpecifier()) && token->Previous)
      token = token->Previous;

    //We must have hit '<'
    if (token->isNot(tok::less))
      return false;

    if (!token->Previous)
      return false;

    token = token->Previous;

    if (token->is(tok::identifier) && token->TokenText == "function")
      return true;
  }

  return false;
}

bool IsQtSignalEmit( const FormatToken* token )
{
  return (token->is(tok::identifier) && token->TokenText == "emit");
}

}
}
