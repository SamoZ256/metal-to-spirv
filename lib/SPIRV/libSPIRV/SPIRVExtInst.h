//===- SPIRVBuiltin.h - SPIR-V extended instruction -------------*- C++ -*-===//
//
//                     The LLVM/SPIRV Translator
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
// Copyright (c) 2014 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal with the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimers.
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimers in the documentation
// and/or other materials provided with the distribution.
// Neither the names of Advanced Micro Devices, Inc., nor the names of its
// contributors may be used to endorse or promote products derived from this
// Software without specific prior written permission.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH
// THE SOFTWARE.
//
//===----------------------------------------------------------------------===//
/// \file
///
/// This file defines SPIR-V extended instructions.
///
//===----------------------------------------------------------------------===//

#ifndef SPIRV_LIBSPIRV_SPIRVEXTINST_H
#define SPIRV_LIBSPIRV_SPIRVEXTINST_H

#include "GLSL.std.450.h"
#include "NonSemantic.AuxData.h"
#include "SPIRV.debug.h"
#include "SPIRVEnum.h"
#include "SPIRVUtil.h"

#include <string>
#include <vector>

namespace SPIRV {

typedef GLSLstd450::Entrypoints GLSLExtOpKind;

template <> inline void SPIRVMap<GLSLExtOpKind, std::string>::init() {
  add(GLSLstd450::Acos, "acos");
  add(GLSLstd450::Acosh, "acosh");
  add(GLSLstd450::Asin, "asin");
  add(GLSLstd450::Asinh, "asinh");
  add(GLSLstd450::Atan, "atan");
  add(GLSLstd450::Atan2, "atan2");
  add(GLSLstd450::Atanh, "atanh");
  add(GLSLstd450::Cbrt, "cbrt");
  add(GLSLstd450::Ceil, "ceil");
  add(GLSLstd450::Cos, "cos");
  add(GLSLstd450::Cosh, "cosh");
  add(GLSLstd450::Erfc, "erfc");
  add(GLSLstd450::Erf, "erf");
  add(GLSLstd450::Exp, "exp");
  add(GLSLstd450::Exp2, "exp2");
  add(GLSLstd450::Exp10, "exp10");
  add(GLSLstd450::Fabs, "fabs");
  add(GLSLstd450::Fdim, "fdim");
  add(GLSLstd450::Floor, "floor");
  add(GLSLstd450::Fma, "fma");
  add(GLSLstd450::Fmax, "fmax");
  add(GLSLstd450::Fmin, "fmin");
  add(GLSLstd450::Fmod, "fmod");
  add(GLSLstd450::Fract, "fract");
  add(GLSLstd450::Frexp, "frexp");
  add(GLSLstd450::Log, "log");
  add(GLSLstd450::Log2, "log2");
  add(GLSLstd450::Log10, "log10");
  add(GLSLstd450::Modf, "modf");
  add(GLSLstd450::Nan, "nan");
  add(GLSLstd450::Pow, "pow");
  add(GLSLstd450::Remainder, "remainder");
  add(GLSLstd450::Round, "round");
  add(GLSLstd450::Sin, "sin");
  add(GLSLstd450::Sincos, "sincos");
  add(GLSLstd450::Sinh, "sinh");
  add(GLSLstd450::Sqrt, "sqrt");
  add(GLSLstd450::Tan, "tan");
  add(GLSLstd450::Tanh, "tanh");
  add(GLSLstd450::Trunc, "trunc");
  add(GLSLstd450::FClamp, "fclamp");
  add(GLSLstd450::Degrees, "degrees");
  add(GLSLstd450::Mix, "mix");
  add(GLSLstd450::Radians, "radians");
  add(GLSLstd450::Step, "step");
  add(GLSLstd450::Smoothstep, "smoothstep");
  add(GLSLstd450::Sign, "sign");
  add(GLSLstd450::Cross, "cross");
  add(GLSLstd450::Distance, "distance");
  add(GLSLstd450::Length, "length");
  add(GLSLstd450::Normalize, "normalize");
  add(GLSLstd450::Fast_distance, "fast_distance");
  add(GLSLstd450::Fast_length, "fast_length");
  add(GLSLstd450::Fast_normalize, "fast_normalize");
  add(GLSLstd450::SAbs, "s_abs");
  add(GLSLstd450::SClamp, "s_clamp");
  add(GLSLstd450::UClamp, "u_clamp");
  add(GLSLstd450::SMax, "s_max");
  add(GLSLstd450::SMin, "s_min");
  add(GLSLstd450::UMax, "u_max");
  add(GLSLstd450::UMin, "u_min");
  add(GLSLstd450::UAbs, "u_abs");
}
SPIRV_DEF_NAMEMAP(GLSLExtOpKind, OCLExtOpMap)

typedef SPIRVDebug::Instruction SPIRVDebugExtOpKind;
template <> inline void SPIRVMap<SPIRVDebugExtOpKind, std::string>::init() {
  add(SPIRVDebug::DebugInfoNone, "DebugInfoNone");
  add(SPIRVDebug::CompilationUnit, "DebugCompilationUnit");
  add(SPIRVDebug::Source, "DebugSource");
  add(SPIRVDebug::TypeBasic, "DebugTypeBasic");
  add(SPIRVDebug::TypePointer, "DebugTypePointer");
  add(SPIRVDebug::TypeArray, "DebugTypeArray");
  add(SPIRVDebug::TypeArrayDynamic, "DebugTypeArrayDynamic");
  add(SPIRVDebug::TypeVector, "DebugTypeVector");
  add(SPIRVDebug::TypeQualifier, "DebugTypeQualifier");
  add(SPIRVDebug::TypeFunction, "DebugTypeFunction");
  add(SPIRVDebug::TypeComposite, "DebugTypeComposite");
  add(SPIRVDebug::TypeMember, "DebugTypeMember");
  add(SPIRVDebug::TypeEnum, "DebugTypeEnum");
  add(SPIRVDebug::Typedef, "DebugTypedef");
  add(SPIRVDebug::TypeTemplateParameter, "DebugTypeTemplateParameter");
  add(SPIRVDebug::TypeTemplateParameterPack, "DebugTypeTemplateParameterPack");
  add(SPIRVDebug::TypeTemplateTemplateParameter,
      "DebugTypeTemplateTemplateParameter");
  add(SPIRVDebug::TypeTemplate, "DebugTypeTemplate");
  add(SPIRVDebug::TypePtrToMember, "DebugTypePtrToMember,");
  add(SPIRVDebug::TypeSubrange, "DebugTypeSubrange");
  add(SPIRVDebug::TypeString, "DebugTypeString");
  add(SPIRVDebug::TypeInheritance, "DebugTypeInheritance");
  add(SPIRVDebug::Function, "DebugFunction");
  add(SPIRVDebug::FunctionDeclaration, "DebugFunctionDeclaration");
  add(SPIRVDebug::LexicalBlock, "DebugLexicalBlock");
  add(SPIRVDebug::LexicalBlockDiscriminator, "DebugLexicalBlockDiscriminator");
  add(SPIRVDebug::LocalVariable, "DebugLocalVariable");
  add(SPIRVDebug::InlinedVariable, "DebugInlinedVariable");
  add(SPIRVDebug::GlobalVariable, "DebugGlobalVariable");
  add(SPIRVDebug::Declare, "DebugDeclare");
  add(SPIRVDebug::Value, "DebugValue");
  add(SPIRVDebug::Scope, "DebugScope");
  add(SPIRVDebug::NoScope, "DebugNoScope");
  add(SPIRVDebug::InlinedAt, "DebugInlinedAt");
  add(SPIRVDebug::ImportedEntity, "DebugImportedEntity");
  add(SPIRVDebug::ModuleINTEL, "DebugModuleINTEL");
  add(SPIRVDebug::Module, "DebugModule");
  add(SPIRVDebug::Expression, "DebugExpression");
  add(SPIRVDebug::Operation, "DebugOperation");
  add(SPIRVDebug::FunctionDefinition, "DebugFunctionDefinition");
  add(SPIRVDebug::SourceContinued, "DebugSourceContinued");
  add(SPIRVDebug::DebugLine, "DebugLine");
  add(SPIRVDebug::DebugNoLine, "DebugNoLine");
  add(SPIRVDebug::EntryPoint, "DebugEntryPoint");
  add(SPIRVDebug::BuildIdentifier, "DebugBuildIdentifier");
  add(SPIRVDebug::StoragePath, "DebugStoragePath");
}
SPIRV_DEF_NAMEMAP(SPIRVDebugExtOpKind, SPIRVDebugExtOpMap)

typedef NonSemanticAuxData::Instruction NonSemanticAuxDataOpKind;
template <>
inline void SPIRVMap<NonSemanticAuxDataOpKind, std::string>::init() {
  add(NonSemanticAuxData::FunctionMetadata,
      "NonSemanticAuxDataFunctionMetadata");
  add(NonSemanticAuxData::FunctionAttribute,
      "NonSemanticAuxDataFunctionAttribute");
}
SPIRV_DEF_NAMEMAP(NonSemanticAuxDataOpKind, NonSemanticAuxDataOpMap)

} // namespace SPIRV

#endif // SPIRV_LIBSPIRV_SPIRVEXTINST_H
