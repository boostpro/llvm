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
#include <string>

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

  template <class Ptr, class ValueType = Ptr>
  struct ptr_archetype
  {
    ValueType& operator*() const;
    ValueType* operator->() const;
    friend bool operator==(ptr_archetype const&, ptr_archetype const&);
    friend bool operator!=(ptr_archetype const&, ptr_archetype const&);
  };

class Type
{
public:
  bool isPointerType() const;
  bool isVariableArrayType() const;
  template <typename T> T* getAs() const;
};
  
class QualType : public ptr_archetype<QualType, Type> {
public:
  enum DestructionKind {
    DK_none,
    DK_cxx_destructor,
    DK_objc_strong_lifetime,
    DK_objc_weak_lifetime
  };
  QualType getNonReferenceType() const;
};

  class PointerType : public Type
  {
 public:
    QualType getPointeeType() const;
  };
  
class Expr
{
public:
  QualType getType() const;
};
  
class VariableArrayType
{
public:
  Expr* getSizeExpr() const;
};
  
  template <typename> class CanQual
  {
 public:
    Type* getTypePtr() const;
  };
  
  typedef CanQual<Type> CanQualType;
class CharUnits
{
 public:
    typedef int64_t QuantityType;
    QuantityType getQuantity() const;
  static CharUnits Zero();
};
  class MangleContext;

/// \brief The types of C++ ABIs for which we can generate code.
enum TargetCXXABI {
  /// The generic ("Itanium") C++ ABI, documented at:
  ///   http://www.codesourcery.com/public/cxx-abi/
  CXXABI_Itanium,

  /// The ARM C++ ABI, based largely on the Itanium ABI but with
  /// significant differences.
  ///    http://infocenter.arm.com
  ///                    /help/topic/com.arm.doc.ihi0041c/IHI0041C_cppabi.pdf
  CXXABI_ARM,

  /// The Visual Studio ABI.  Only scattered official documentation exists.
  CXXABI_Microsoft
};
  
  class TargetInfo {
 public:
    class  ConstraintInfo {};
    TargetCXXABI getCXXABI() const;
    uint64_t getPointerWidth(unsigned AddrSpace) const;
    uint64_t getPointerAlign(unsigned AddrSpace) const;
  };
  
  class LangOptions
  {
 public:
    bool Exceptions;
  };
  
class ASTContext
{
public:
  const VariableArrayType *getAsVariableArrayType(QualType T);
  CanQualType getCanonicalType(QualType T) const;
  const Type *getCanonicalType(const Type *T) const;
  MangleContext *createMangleContext();
  const TargetInfo& getTargetInfo() const;
  const LangOptions &getLangOpts() const;
  CharUnits toCharUnitsFromBits(int64_t BitSize) const;
  };

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

  class SourceLocation {
 public:
    bool isValid() const;
    friend bool operator==(const SourceLocation&, const SourceLocation&);
    friend bool operator!=(const SourceLocation&, const SourceLocation&);
  };
  
class SourceRange {
  SourceLocation B;
  SourceLocation E;
public:
  SourceRange(): B(SourceLocation()), E(SourceLocation()) {}
  SourceRange(SourceLocation loc) : B(loc), E(loc) {}
  SourceRange(SourceLocation begin, SourceLocation end) : B(begin), E(end) {}

  SourceLocation getBegin() const { return B; }
  SourceLocation getEnd() const { return E; }

  void setBegin(SourceLocation b) { B = b; }
  void setEnd(SourceLocation e) { E = e; }

  bool isValid() const { return B.isValid() && E.isValid(); }
  bool isInvalid() const { return !isValid(); }

  bool operator==(const SourceRange &X) const {
    return B == X.B && E == X.E;
  }

  bool operator!=(const SourceRange &X) const {
    return B != X.B || E != X.E;
  }
};

  class BlockDecl;
  class LinkageSpecDecl;
  class OpaqueValueExpr;
  class ImplicitParamDecl;
  class BaseSubobject {};

  template <class It, class ValueType = It>
  struct iterator_archetype : ptr_archetype<It, ValueType>
  {
    It& operator++();
    It operator++(int);
  };
  
  class CastExpr {
 public:
    struct path_const_iterator : iterator_archetype<path_const_iterator>
    {
    };
  };
  
  class CallExpr {
 public:
    struct const_arg_iterator : iterator_archetype<const_arg_iterator,Expr*>
    {
      QualType getType() const;
      Expr* operator->() const; // EVIL
    };
  };
  class ConstantArrayType;
  class CXXNewExpr;
  class CXXDeleteExpr;
  class CXXTypeidExpr;
  class CXXDynamicCastExpr;
  class CXXTryStmt;
  class VAArgExpr;
  class MemberExpr;
  class ObjCIsaExpr;
  class CXXConstructExpr;
  class ObjCMessageExpr;
  class NestedNameSpecifier;
  class CXXMemberCallExpr;
  class CXXOperatorCallExpr;
  class CUDAKernelCallExpr;
  class ExprWithCleanups;
  class CXXThrowExpr;
  class AtomicExpr;
  class APValue;

  class MemberPointerType;
  
  class Decl {};
  class ValueDecl : public Decl {};
  class VarDecl : public ValueDecl {
 public:
    std::string getNameAsString() const;
  };
}

#endif // ABI_DWA2012105_H
