//===--- CGDebugInfo.h - Emit LLVM Code from ASTs for a Module --------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Dummy; hoping to untangle the one in clang from CodeGenModule
//
//===----------------------------------------------------------------------===//
#ifndef CGDEBUGINFO_DWA2012104_H
# define CGDEBUGINFO_DWA2012104_H

# include "CGBuilder.h"

namespace clang {
namespace CodeGen {
  class CGDebugInfo
  {
   public:
    /// EmitLexicalBlockStart - Emit metadata to indicate the beginning of a
    /// new lexical block and push the block onto the stack.
    void EmitLexicalBlockStart(CGBuilderTy &Builder, SourceLocation Loc);

    /// EmitLexicalBlockEnd - Emit metadata to indicate the end of a new lexical
    /// block and pop the current block.
    void EmitLexicalBlockEnd(CGBuilderTy &Builder, SourceLocation Loc);

    void finalize();
  };
}}
#endif // CGDEBUGINFO_DWA2012104_H
