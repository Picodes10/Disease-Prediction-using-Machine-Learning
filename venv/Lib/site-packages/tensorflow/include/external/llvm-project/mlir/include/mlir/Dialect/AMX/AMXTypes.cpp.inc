/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::amx::TileType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES

static ::mlir::OptionalParseResult generatedTypeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::amx::TileType::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::amx::TileType::parse(parser);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return std::nullopt;
    });
}

static ::llvm::LogicalResult generatedTypePrinter(::mlir::Type def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::llvm::LogicalResult>(def)    .Case<::mlir::amx::TileType>([&](auto t) {
      printer << ::mlir::amx::TileType::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace amx {
namespace detail {
struct TileTypeStorage : public ::mlir::TypeStorage {
  using KeyTy = std::tuple<::llvm::ArrayRef<int64_t>, ::mlir::Type>;
  TileTypeStorage(::llvm::ArrayRef<int64_t> shape, ::mlir::Type elementType) : shape(std::move(shape)), elementType(std::move(elementType)) {}

  KeyTy getAsKey() const {
    return KeyTy(shape, elementType);
  }

  bool operator==(const KeyTy &tblgenKey) const {
    return (shape == std::get<0>(tblgenKey)) && (elementType == std::get<1>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey));
  }

  static TileTypeStorage *construct(::mlir::TypeStorageAllocator &allocator, KeyTy &&tblgenKey) {
    auto shape = std::move(std::get<0>(tblgenKey));
    auto elementType = std::move(std::get<1>(tblgenKey));
    shape = allocator.copyInto(shape);
    return new (allocator.allocate<TileTypeStorage>()) TileTypeStorage(std::move(shape), std::move(elementType));
  }

  ::llvm::ArrayRef<int64_t> shape;
  ::mlir::Type elementType;
};
} // namespace detail
TileType TileType::get(ArrayRef<int64_t> shape, Type elementType) {
  return Base::get(elementType.getContext(), shape, elementType);
}

TileType TileType::getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ArrayRef<int64_t> shape, Type elementType) {
  return Base::getChecked(emitError, elementType.getContext(), shape, elementType);
}

::llvm::LogicalResult TileType::verifyInvariantsImpl(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, ::mlir::Type elementType) {
  if (!(((elementType.isF32())) || ((elementType.isF16())) || ((::llvm::isa<::mlir::BFloat16Type>(elementType))) || ((elementType.isSignlessInteger(32))) || ((elementType.isSignlessInteger(8))))) {
    emitError() << "failed to verify 'elementType': 32-bit float or 16-bit float or bfloat16 type or 32-bit signless integer or 8-bit signless integer";
    return ::mlir::failure();
  }

  return ::mlir::success();
}

::llvm::LogicalResult TileType::verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, ::mlir::Type elementType) {
  if (::mlir::failed(verifyInvariantsImpl(emitError, shape, elementType)))
    return ::mlir::failure();
  return ::mlir::success();
}

::llvm::ArrayRef<int64_t> TileType::getShape() const {
  return getImpl()->shape;
}

::mlir::Type TileType::getElementType() const {
  return getImpl()->elementType;
}

} // namespace amx
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::amx::TileType)
namespace mlir {
namespace amx {

/// Parse a type registered to this dialect.
::mlir::Type AMXDialect::parseType(::mlir::DialectAsmParser &parser) const {
  ::llvm::SMLoc typeLoc = parser.getCurrentLocation();
  ::llvm::StringRef mnemonic;
  ::mlir::Type genType;
  auto parseResult = generatedTypeParser(parser, &mnemonic, genType);
  if (parseResult.has_value())
    return genType;
  
  parser.emitError(typeLoc) << "unknown  type `"
      << mnemonic << "` in dialect `" << getNamespace() << "`";
  return {};
}
/// Print a type registered to this dialect.
void AMXDialect::printType(::mlir::Type type,
                    ::mlir::DialectAsmPrinter &printer) const {
  if (::mlir::succeeded(generatedTypePrinter(type, printer)))
    return;
  
}
} // namespace amx
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

