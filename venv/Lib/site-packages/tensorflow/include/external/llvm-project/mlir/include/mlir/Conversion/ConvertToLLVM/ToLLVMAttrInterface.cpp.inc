/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/// Populate the dialect conversion target, type converter and pattern set.
void mlir::ConvertToLLVMAttrInterface::populateConvertToLLVMConversionPatterns(::mlir::ConversionTarget& target, ::mlir::LLVMTypeConverter& typeConverter, ::mlir::RewritePatternSet& patternSet) const {
      return getImpl()->populateConvertToLLVMConversionPatterns(getImpl(), *this, target, typeConverter, patternSet);
  }
