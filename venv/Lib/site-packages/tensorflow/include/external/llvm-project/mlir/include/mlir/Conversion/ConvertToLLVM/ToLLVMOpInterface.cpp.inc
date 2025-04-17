/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/// Populate the provided vector with a list of convert to LLVM attributes
/// to apply.
void mlir::ConvertToLLVMOpInterface::getConvertToLLVMConversionAttrs(::llvm::SmallVectorImpl<::mlir::ConvertToLLVMAttrInterface>& attrs) {
      return getImpl()->getConvertToLLVMConversionAttrs(getImpl(), getOperation(), attrs);
  }
