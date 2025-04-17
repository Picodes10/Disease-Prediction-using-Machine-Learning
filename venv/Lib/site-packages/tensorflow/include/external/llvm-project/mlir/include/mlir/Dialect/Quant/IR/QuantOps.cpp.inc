/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: QuantOps.td                                                          *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::quant::DequantizeCastOp,
::mlir::quant::QuantizeCastOp,
::mlir::quant::StorageCastOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace quant {

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_QuantOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<mlir::quant::QuantizedType>(type))) || (((::llvm::isa<::mlir::TensorType>(type))) && ([](::mlir::Type elementType) { return (::llvm::isa<mlir::quant::QuantizedType>(elementType)); }(::llvm::cast<::mlir::ShapedType>(type).getElementType()))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be scalar or tensor of quantized type, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_QuantOps2(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::FloatType>(type))) || (((::llvm::isa<::mlir::TensorType>(type))) && ([](::mlir::Type elementType) { return (::llvm::isa<::mlir::FloatType>(elementType)); }(::llvm::cast<::mlir::ShapedType>(type).getElementType()))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be scalar or tensor of floating-point, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_type_constraint_QuantOps3(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!((((type.isSignlessInteger())) || ((::llvm::isa<mlir::quant::QuantizedType>(type)))) || (((::llvm::isa<::mlir::TensorType>(type))) && ([](::mlir::Type elementType) { return ((elementType.isSignlessInteger())) || ((::llvm::isa<mlir::quant::QuantizedType>(elementType))); }(::llvm::cast<::mlir::ShapedType>(type).getElementType()))))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be scalar or tensor of signless integer or quantized type, but got " << type;
  }
  return ::mlir::success();
}
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::DequantizeCastOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
DequantizeCastOpAdaptor::DequantizeCastOpAdaptor(DequantizeCastOp op) : DequantizeCastOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult DequantizeCastOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void DequantizeCastOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input) {
  odsState.addOperands(input);
  odsState.addTypes(result);
}

void DequantizeCastOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void DequantizeCastOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult DequantizeCastOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantOps2(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  if (!((((((*this->getODSOperands(0).begin()).getType().isSignlessInteger())) || ((::llvm::isa<::mlir::FloatType>((*this->getODSOperands(0).begin()).getType()))) || ((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSOperands(0).begin()).getType())))) && ((((*this->getODSResults(0).begin()).getType().isSignlessInteger())) || ((::llvm::isa<::mlir::FloatType>((*this->getODSResults(0).begin()).getType()))) || ((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSResults(0).begin()).getType()))))) || ((((::llvm::isa<::mlir::UnrankedTensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType()))) && (((::llvm::isa<::mlir::UnrankedTensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType())))) || ((((::llvm::isa<::mlir::RankedTensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType()))) && (((::llvm::isa<::mlir::RankedTensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType()))) && (((::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getShape()) == (::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getShape()) && (::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getShape()) == (::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getShape()))))))
    return emitOpError("failed to verify that input and result are both scalars or both tensors with matching shape");
  return ::mlir::success();
}

::llvm::LogicalResult DequantizeCastOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult DequantizeCastOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(&inputRawOperand, 1);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type inputRawType{};
  ::llvm::ArrayRef<::mlir::Type> inputTypes(&inputRawType, 1);
  ::mlir::Type resultRawType{};
  ::llvm::ArrayRef<::mlir::Type> resultTypes(&resultRawType, 1);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    inputRawType = type;
  }
  if (parser.parseKeyword("to"))
    return ::mlir::failure();

  {
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    resultRawType = type;
  }
  result.addTypes(resultTypes);
  if (parser.resolveOperands(inputOperands, inputTypes, inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void DequantizeCastOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getInput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ' ' << "to";
  _odsPrinter << ' ';
  {
    auto type = getResult().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void DequantizeCastOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace quant
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::quant::DequantizeCastOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::QuantizeCastOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
QuantizeCastOpAdaptor::QuantizeCastOpAdaptor(QuantizeCastOp op) : QuantizeCastOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult QuantizeCastOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void QuantizeCastOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input) {
  odsState.addOperands(input);
  odsState.addTypes(result);
}

void QuantizeCastOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void QuantizeCastOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult QuantizeCastOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantOps2(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  if (!((((((*this->getODSOperands(0).begin()).getType().isSignlessInteger())) || ((::llvm::isa<::mlir::FloatType>((*this->getODSOperands(0).begin()).getType()))) || ((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSOperands(0).begin()).getType())))) && ((((*this->getODSResults(0).begin()).getType().isSignlessInteger())) || ((::llvm::isa<::mlir::FloatType>((*this->getODSResults(0).begin()).getType()))) || ((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSResults(0).begin()).getType()))))) || ((((::llvm::isa<::mlir::UnrankedTensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType()))) && (((::llvm::isa<::mlir::UnrankedTensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType())))) || ((((::llvm::isa<::mlir::RankedTensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType()))) && (((::llvm::isa<::mlir::RankedTensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType()))) && (((::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getShape()) == (::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getShape()) && (::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getShape()) == (::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getShape()))))))
    return emitOpError("failed to verify that input and result are both scalars or both tensors with matching shape");
  return ::mlir::success();
}

::llvm::LogicalResult QuantizeCastOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult QuantizeCastOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(&inputRawOperand, 1);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type inputRawType{};
  ::llvm::ArrayRef<::mlir::Type> inputTypes(&inputRawType, 1);
  ::mlir::Type resultRawType{};
  ::llvm::ArrayRef<::mlir::Type> resultTypes(&resultRawType, 1);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    inputRawType = type;
  }
  if (parser.parseKeyword("to"))
    return ::mlir::failure();

  {
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    resultRawType = type;
  }
  result.addTypes(resultTypes);
  if (parser.resolveOperands(inputOperands, inputTypes, inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void QuantizeCastOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getInput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ' ' << "to";
  _odsPrinter << ' ';
  {
    auto type = getResult().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void QuantizeCastOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace quant
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::quant::QuantizeCastOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::StorageCastOp definitions
//===----------------------------------------------------------------------===//

namespace detail {
} // namespace detail
StorageCastOpAdaptor::StorageCastOpAdaptor(StorageCastOp op) : StorageCastOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult StorageCastOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void StorageCastOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input) {
  odsState.addOperands(input);
  odsState.addTypes(result);
}

void StorageCastOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void StorageCastOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::llvm::LogicalResult StorageCastOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantOps3(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantOps3(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  if (!((((((*this->getODSOperands(0).begin()).getType().isSignlessInteger())) || ((::llvm::isa<::mlir::FloatType>((*this->getODSOperands(0).begin()).getType()))) || ((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSOperands(0).begin()).getType())))) && ((((*this->getODSResults(0).begin()).getType().isSignlessInteger())) || ((::llvm::isa<::mlir::FloatType>((*this->getODSResults(0).begin()).getType()))) || ((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSResults(0).begin()).getType()))))) || ((((::llvm::isa<::mlir::UnrankedTensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType()))) && (((::llvm::isa<::mlir::UnrankedTensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType())))) || ((((::llvm::isa<::mlir::RankedTensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType()))) && (((::llvm::isa<::mlir::RankedTensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (true); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType()))) && (((::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getShape()) == (::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getShape()) && (::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getShape()) == (::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getShape()))))))
    return emitOpError("failed to verify that input and result are both scalars or both tensors with matching shape");
  if (!(((((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSOperands(0).begin()).getType()))) || (((::llvm::isa<::mlir::TensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (::llvm::isa<mlir::quant::QuantizedType>(elementType)); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType())))) && ((((*this->getODSResults(0).begin()).getType().isSignlessInteger())) || (((::llvm::isa<::mlir::TensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (elementType.isSignlessInteger()); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType()))))) || (((((*this->getODSOperands(0).begin()).getType().isSignlessInteger())) || (((::llvm::isa<::mlir::TensorType>((*this->getODSOperands(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (elementType.isSignlessInteger()); }(::llvm::cast<::mlir::ShapedType>((*this->getODSOperands(0).begin()).getType()).getElementType())))) && (((::llvm::isa<mlir::quant::QuantizedType>((*this->getODSResults(0).begin()).getType()))) || (((::llvm::isa<::mlir::TensorType>((*this->getODSResults(0).begin()).getType()))) && ([](::mlir::Type elementType) { return (::llvm::isa<mlir::quant::QuantizedType>(elementType)); }(::llvm::cast<::mlir::ShapedType>((*this->getODSResults(0).begin()).getType()).getElementType())))))))
    return emitOpError("failed to verify that input must be integer and result must be quantized, or vice versa");
  return ::mlir::success();
}

::llvm::LogicalResult StorageCastOp::verifyInvariants() {
  if(::mlir::succeeded(verifyInvariantsImpl()) && ::mlir::succeeded(verify()))
    return ::mlir::success();
  return ::mlir::failure();
}

::mlir::ParseResult StorageCastOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(&inputRawOperand, 1);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type inputRawType{};
  ::llvm::ArrayRef<::mlir::Type> inputTypes(&inputRawType, 1);
  ::mlir::Type resultRawType{};
  ::llvm::ArrayRef<::mlir::Type> resultTypes(&resultRawType, 1);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    inputRawType = type;
  }
  if (parser.parseKeyword("to"))
    return ::mlir::failure();

  {
    ::mlir::Type type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    resultRawType = type;
  }
  result.addTypes(resultTypes);
  if (parser.resolveOperands(inputOperands, inputTypes, inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void StorageCastOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  _odsPrinter.printOptionalAttrDict((*this)->getAttrs(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getInput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
  _odsPrinter << ' ' << "to";
  _odsPrinter << ' ';
  {
    auto type = getResult().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::Type>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void StorageCastOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

} // namespace quant
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::quant::StorageCastOp)


#endif  // GET_OP_CLASSES

