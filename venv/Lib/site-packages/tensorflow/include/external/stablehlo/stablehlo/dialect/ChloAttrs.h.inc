/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace chlo {
class ComparisonDirectionAttr;
class ComparisonTypeAttr;
class PrecisionAttr;
class RaggedDotDimensionNumbersAttr;
namespace detail {
struct ComparisonDirectionAttrStorage;
} // namespace detail
class ComparisonDirectionAttr : public ::mlir::Attribute::AttrBase<ComparisonDirectionAttr, ::mlir::Attribute, detail::ComparisonDirectionAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "chlo.comparison_direction";
  static constexpr ::llvm::StringLiteral dialectName = "chlo";
  static ComparisonDirectionAttr get(::mlir::MLIRContext *context, ::mlir::chlo::ComparisonDirection value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"comparison_direction"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::chlo::ComparisonDirection getValue() const;
};
namespace detail {
struct ComparisonTypeAttrStorage;
} // namespace detail
class ComparisonTypeAttr : public ::mlir::Attribute::AttrBase<ComparisonTypeAttr, ::mlir::Attribute, detail::ComparisonTypeAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "chlo.comparison_type";
  static constexpr ::llvm::StringLiteral dialectName = "chlo";
  static ComparisonTypeAttr get(::mlir::MLIRContext *context, ::mlir::chlo::ComparisonType value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"comparison_type"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::chlo::ComparisonType getValue() const;
};
namespace detail {
struct PrecisionAttrStorage;
} // namespace detail
class PrecisionAttr : public ::mlir::Attribute::AttrBase<PrecisionAttr, ::mlir::Attribute, detail::PrecisionAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "chlo.precision";
  static constexpr ::llvm::StringLiteral dialectName = "chlo";
  static PrecisionAttr get(::mlir::MLIRContext *context, ::mlir::chlo::Precision value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"precision"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::chlo::Precision getValue() const;
};
namespace detail {
struct RaggedDotDimensionNumbersAttrStorage;
} // namespace detail
class RaggedDotDimensionNumbersAttr : public ::mlir::Attribute::AttrBase<RaggedDotDimensionNumbersAttr, ::mlir::Attribute, detail::RaggedDotDimensionNumbersAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "chlo.ragged_dot";
  static constexpr ::llvm::StringLiteral dialectName = "chlo";
  static RaggedDotDimensionNumbersAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> lhsBatchingDimensions, ::llvm::ArrayRef<int64_t> rhsBatchingDimensions, ::llvm::ArrayRef<int64_t> lhsContractingDimensions, ::llvm::ArrayRef<int64_t> rhsContractingDimensions, ::llvm::ArrayRef<int64_t> lhsRaggedDimensions, ::llvm::ArrayRef<int64_t> rhsGroupDimensions);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"ragged_dot"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getLhsBatchingDimensions() const;
  ::llvm::ArrayRef<int64_t> getRhsBatchingDimensions() const;
  ::llvm::ArrayRef<int64_t> getLhsContractingDimensions() const;
  ::llvm::ArrayRef<int64_t> getRhsContractingDimensions() const;
  ::llvm::ArrayRef<int64_t> getLhsRaggedDimensions() const;
  ::llvm::ArrayRef<int64_t> getRhsGroupDimensions() const;
};
} // namespace chlo
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::chlo::ComparisonDirectionAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::chlo::ComparisonTypeAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::chlo::PrecisionAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::chlo::RaggedDotDimensionNumbersAttr)

#endif  // GET_ATTRDEF_CLASSES

