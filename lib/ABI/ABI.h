//===--- ABI.h - Declare datatypes that come from clang ----------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
/// \file
/// \brief This file is temporarily being used to declare vocabulary value
/// types used throughout the codegen process
///
//===----------------------------------------------------------------------===//
#ifndef ABI_DWA2012105_H
# define ABI_DWA2012105_H

#include "llvm/Support/DataTypes.h"

// Declarations of value types from clang used by ABI-level codegen
namespace llvm_abi {

class Qualifiers
{
 public:
    class ObjCLifetime {};
    bool hasVolatile() const;
    bool hasRestrict() const;
};
class QualType {};
class Type {};
class Expr;
class CharUnits
{
 public:
    typedef int64_t QuantityType;
    QuantityType getQuantity() const;
};
class ASTContext {};
}

#endif // ABI_DWA2012105_H
