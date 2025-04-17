/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
class ConvertToLLVMAttrInterface;
namespace detail {
struct ConvertToLLVMAttrInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    void (*populateConvertToLLVMConversionPatterns)(const Concept *impl, ::mlir::Attribute , ::mlir::ConversionTarget&, ::mlir::LLVMTypeConverter&, ::mlir::RewritePatternSet&);
  };
  template<typename ConcreteAttr>
  class Model : public Concept {
  public:
    using Interface = ::mlir::ConvertToLLVMAttrInterface;
    Model() : Concept{populateConvertToLLVMConversionPatterns} {}

    static inline void populateConvertToLLVMConversionPatterns(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ConversionTarget& target, ::mlir::LLVMTypeConverter& typeConverter, ::mlir::RewritePatternSet& patternSet);
  };
  template<typename ConcreteAttr>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::ConvertToLLVMAttrInterface;
    FallbackModel() : Concept{populateConvertToLLVMConversionPatterns} {}

    static inline void populateConvertToLLVMConversionPatterns(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ConversionTarget& target, ::mlir::LLVMTypeConverter& typeConverter, ::mlir::RewritePatternSet& patternSet);
  };
  template<typename ConcreteModel, typename ConcreteAttr>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteAttr;
  };
};
template <typename ConcreteAttr>
struct ConvertToLLVMAttrInterfaceTrait;

} // namespace detail
class ConvertToLLVMAttrInterface : public ::mlir::AttributeInterface<ConvertToLLVMAttrInterface, detail::ConvertToLLVMAttrInterfaceInterfaceTraits> {
public:
  using ::mlir::AttributeInterface<ConvertToLLVMAttrInterface, detail::ConvertToLLVMAttrInterfaceInterfaceTraits>::AttributeInterface;
  template <typename ConcreteAttr>
  struct Trait : public detail::ConvertToLLVMAttrInterfaceTrait<ConcreteAttr> {};
  /// Populate the dialect conversion target, type converter and pattern set.
  void populateConvertToLLVMConversionPatterns(::mlir::ConversionTarget& target, ::mlir::LLVMTypeConverter& typeConverter, ::mlir::RewritePatternSet& patternSet) const;
};
namespace detail {
  template <typename ConcreteAttr>
  struct ConvertToLLVMAttrInterfaceTrait : public ::mlir::AttributeInterface<ConvertToLLVMAttrInterface, detail::ConvertToLLVMAttrInterfaceInterfaceTraits>::Trait<ConcreteAttr> {
  };
}// namespace detail
} // namespace mlir
namespace mlir {
template<typename ConcreteAttr>
void detail::ConvertToLLVMAttrInterfaceInterfaceTraits::Model<ConcreteAttr>::populateConvertToLLVMConversionPatterns(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ConversionTarget& target, ::mlir::LLVMTypeConverter& typeConverter, ::mlir::RewritePatternSet& patternSet) {
  return (::llvm::cast<ConcreteAttr>(tablegen_opaque_val)).populateConvertToLLVMConversionPatterns(target, typeConverter, patternSet);
}
template<typename ConcreteAttr>
void detail::ConvertToLLVMAttrInterfaceInterfaceTraits::FallbackModel<ConcreteAttr>::populateConvertToLLVMConversionPatterns(const Concept *impl, ::mlir::Attribute tablegen_opaque_val, ::mlir::ConversionTarget& target, ::mlir::LLVMTypeConverter& typeConverter, ::mlir::RewritePatternSet& patternSet) {
  return static_cast<const ConcreteAttr *>(impl)->populateConvertToLLVMConversionPatterns(tablegen_opaque_val, target, typeConverter, patternSet);
}
} // namespace mlir
