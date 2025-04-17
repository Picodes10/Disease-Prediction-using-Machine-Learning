/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace amx {
class TileType;
namespace detail {
struct TileTypeStorage;
} // namespace detail
class TileType : public ::mlir::Type::TypeBase<TileType, ::mlir::Type, detail::TileTypeStorage, ::mlir::ShapedType::Trait, ::mlir::ValueSemantics> {
public:
  using Base::Base;
  /// Returns if this type is ranked (always true).
  bool hasRank() const { return true; }

  /// Clone this tile type with the given shape and element type. If the
  /// provided shape is `std::nullopt`, the current shape of the type is used.
  TileType cloneWith(std::optional<ArrayRef<int64_t>> shape,
                     Type elementType) const {
    return get(shape.value_or(getShape()), elementType);
  }
  static constexpr ::llvm::StringLiteral name = "amx.tile";
  static constexpr ::llvm::StringLiteral dialectName = "amx";
  using Base::getChecked;
  static TileType get(ArrayRef<int64_t> shape, Type elementType);
  static TileType getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ArrayRef<int64_t> shape, Type elementType);
  static ::llvm::LogicalResult verifyInvariantsImpl(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, ::mlir::Type elementType);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<int64_t> shape, ::mlir::Type elementType);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"tile"};
  }

  static ::mlir::Type parse(::mlir::AsmParser &odsParser);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getShape() const;
  ::mlir::Type getElementType() const;
};
} // namespace amx
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::amx::TileType)

#endif  // GET_TYPEDEF_CLASSES

