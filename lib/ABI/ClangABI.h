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

namespace llvm {}

// Declarations of value types from clang used by ABI-level codegen
namespace llvm_abi {

using namespace llvm;

class Qualifiers
{
 public:
    class ObjCLifetime {};
    bool hasVolatile() const;
    bool hasRestrict() const;
};
class QualType {
public:
  enum DestructionKind {};
};
class Type {};
  template <typename> class CanQual {};
  typedef CanQual<Type> CanQualType;
class Expr;
class CharUnits
{
 public:
    typedef int64_t QuantityType;
    QuantityType getQuantity() const;
};
class ASTContext {};

class FunctionType
{
 public:
  class ExtInfo {};
};

  /// \brief CallingConv - Specifies the calling convention that a function uses.
  enum CallingConv {
    CC_Default,
    CC_C,           // __attribute__((cdecl))
    CC_X86StdCall,  // __attribute__((stdcall))
    CC_X86FastCall, // __attribute__((fastcall))
    CC_X86ThisCall, // __attribute__((thiscall))
    CC_X86Pascal,   // __attribute__((pascal))
    CC_AAPCS,       // __attribute__((pcs("aapcs")))
    CC_AAPCS_VFP    // __attribute__((pcs("aapcs-vfp")))
  };

  class ObjCInterfaceType;

  class GlobalDecl {};

  class SourceLocation {};
  class SourceRange {};
  
}

#endif // ABI_DWA2012105_H
