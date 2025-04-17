/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ops.td                                                               *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace sdy {
class AllGatherOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class AllReduceOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class AllSliceOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class AllToAllOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class CollectivePermuteOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ConstantOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class DataFlowEdgeOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ManualComputationOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class MeshOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class NamedComputationOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class PropagationBarrierOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ReshardOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ReturnOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ShardingConstraintOp;
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ShardingGroupOp;
} // namespace sdy
} // namespace mlir
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::AllGatherOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AllGatherOpGenericAdaptorBase {
public:
  struct Properties {
    using gathering_axesTy = ::mlir::sdy::ListOfAxisRefListsAttr;
    gathering_axesTy gathering_axes;

    auto getGatheringAxes() {
      auto &propStorage = this->gathering_axes;
      return ::llvm::cast<::mlir::sdy::ListOfAxisRefListsAttr>(propStorage);
    }
    void setGatheringAxes(const ::mlir::sdy::ListOfAxisRefListsAttr &propValue) {
      this->gathering_axes = propValue;
    }
    using out_shardingTy = ::mlir::sdy::TensorShardingAttr;
    out_shardingTy out_sharding;

    auto getOutSharding() {
      auto &propStorage = this->out_sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setOutSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->out_sharding = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.gathering_axes == this->gathering_axes &&
        rhs.out_sharding == this->out_sharding &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  AllGatherOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.all_gather", odsAttrs.getContext());
  }

  AllGatherOpGenericAdaptorBase(AllGatherOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::ListOfAxisRefListsAttr getGatheringAxesAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::ListOfAxisRefListsAttr>(getProperties().gathering_axes);
    return attr;
  }

  ::llvm::ArrayRef<AxisRefListAttr> getGatheringAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
};
} // namespace detail
template <typename RangeT>
class AllGatherOpGenericAdaptor : public detail::AllGatherOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AllGatherOpGenericAdaptorBase;
public:
  AllGatherOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AllGatherOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : AllGatherOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AllGatherOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AllGatherOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AllGatherOpGenericAdaptor(RangeT values, const AllGatherOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AllGatherOp, typename = std::enable_if_t<std::is_same_v<LateInst, AllGatherOp>>>
  AllGatherOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AllGatherOpAdaptor : public AllGatherOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AllGatherOpGenericAdaptor::AllGatherOpGenericAdaptor;
  AllGatherOpAdaptor(AllGatherOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AllGatherOp : public ::mlir::Op<AllGatherOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait, ::mlir::sdy::CollectiveOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AllGatherOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AllGatherOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("gathering_axes"), ::llvm::StringRef("out_sharding")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getGatheringAxesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getGatheringAxesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getOutShardingAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getOutShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.all_gather");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getTensor() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::ListOfAxisRefListsAttr getGatheringAxesAttr() {
    return ::llvm::cast<::mlir::sdy::ListOfAxisRefListsAttr>(getProperties().gathering_axes);
  }

  ::llvm::ArrayRef<AxisRefListAttr> getGatheringAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
  void setGatheringAxesAttr(::mlir::sdy::ListOfAxisRefListsAttr attr) {
    getProperties().gathering_axes = attr;
  }

  void setGatheringAxes(::llvm::ArrayRef<AxisRefListAttr> attrValue);
  void setOutShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().out_sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::mlir::sdy::ListOfAxisRefListsAttr gathering_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::mlir::sdy::ListOfAxisRefListsAttr gathering_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::sdy::ListOfAxisRefListsAttr gathering_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefListAttr> gathering_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefListAttr> gathering_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefListAttr> gathering_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::AllGatherOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::AllReduceOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AllReduceOpGenericAdaptorBase {
public:
  struct Properties {
    using out_shardingTy = ::mlir::sdy::TensorShardingAttr;
    out_shardingTy out_sharding;

    auto getOutSharding() {
      auto &propStorage = this->out_sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setOutSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->out_sharding = propValue;
    }
    using reduction_axesTy = ::mlir::sdy::AxisRefListAttr;
    reduction_axesTy reduction_axes;

    auto getReductionAxes() {
      auto &propStorage = this->reduction_axes;
      return ::llvm::cast<::mlir::sdy::AxisRefListAttr>(propStorage);
    }
    void setReductionAxes(const ::mlir::sdy::AxisRefListAttr &propValue) {
      this->reduction_axes = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.out_sharding == this->out_sharding &&
        rhs.reduction_axes == this->reduction_axes &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  AllReduceOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.all_reduce", odsAttrs.getContext());
  }

  AllReduceOpGenericAdaptorBase(AllReduceOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::AxisRefListAttr getReductionAxesAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::AxisRefListAttr>(getProperties().reduction_axes);
    return attr;
  }

  ::llvm::ArrayRef<AxisRefAttr> getReductionAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
};
} // namespace detail
template <typename RangeT>
class AllReduceOpGenericAdaptor : public detail::AllReduceOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AllReduceOpGenericAdaptorBase;
public:
  AllReduceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AllReduceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : AllReduceOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AllReduceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AllReduceOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AllReduceOpGenericAdaptor(RangeT values, const AllReduceOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AllReduceOp, typename = std::enable_if_t<std::is_same_v<LateInst, AllReduceOp>>>
  AllReduceOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AllReduceOpAdaptor : public AllReduceOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AllReduceOpGenericAdaptor::AllReduceOpGenericAdaptor;
  AllReduceOpAdaptor(AllReduceOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AllReduceOp : public ::mlir::Op<AllReduceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait, ::mlir::sdy::CollectiveOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AllReduceOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AllReduceOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("out_sharding"), ::llvm::StringRef("reduction_axes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getOutShardingAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOutShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getReductionAxesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getReductionAxesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.all_reduce");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getTensor() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::AxisRefListAttr getReductionAxesAttr() {
    return ::llvm::cast<::mlir::sdy::AxisRefListAttr>(getProperties().reduction_axes);
  }

  ::llvm::ArrayRef<AxisRefAttr> getReductionAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
  void setReductionAxesAttr(::mlir::sdy::AxisRefListAttr attr) {
    getProperties().reduction_axes = attr;
  }

  void setReductionAxes(::llvm::ArrayRef<AxisRefAttr> attrValue);
  void setOutShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().out_sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::mlir::sdy::AxisRefListAttr reduction_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::mlir::sdy::AxisRefListAttr reduction_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::sdy::AxisRefListAttr reduction_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefAttr> reduction_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefAttr> reduction_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefAttr> reduction_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::AllReduceOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::AllSliceOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AllSliceOpGenericAdaptorBase {
public:
  struct Properties {
    using out_shardingTy = ::mlir::sdy::TensorShardingAttr;
    out_shardingTy out_sharding;

    auto getOutSharding() {
      auto &propStorage = this->out_sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setOutSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->out_sharding = propValue;
    }
    using slicing_axesTy = ::mlir::sdy::ListOfAxisRefListsAttr;
    slicing_axesTy slicing_axes;

    auto getSlicingAxes() {
      auto &propStorage = this->slicing_axes;
      return ::llvm::cast<::mlir::sdy::ListOfAxisRefListsAttr>(propStorage);
    }
    void setSlicingAxes(const ::mlir::sdy::ListOfAxisRefListsAttr &propValue) {
      this->slicing_axes = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.out_sharding == this->out_sharding &&
        rhs.slicing_axes == this->slicing_axes &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  AllSliceOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.all_slice", odsAttrs.getContext());
  }

  AllSliceOpGenericAdaptorBase(AllSliceOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::ListOfAxisRefListsAttr getSlicingAxesAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::ListOfAxisRefListsAttr>(getProperties().slicing_axes);
    return attr;
  }

  ::llvm::ArrayRef<AxisRefListAttr> getSlicingAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
};
} // namespace detail
template <typename RangeT>
class AllSliceOpGenericAdaptor : public detail::AllSliceOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AllSliceOpGenericAdaptorBase;
public:
  AllSliceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AllSliceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : AllSliceOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AllSliceOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AllSliceOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AllSliceOpGenericAdaptor(RangeT values, const AllSliceOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AllSliceOp, typename = std::enable_if_t<std::is_same_v<LateInst, AllSliceOp>>>
  AllSliceOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AllSliceOpAdaptor : public AllSliceOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AllSliceOpGenericAdaptor::AllSliceOpGenericAdaptor;
  AllSliceOpAdaptor(AllSliceOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AllSliceOp : public ::mlir::Op<AllSliceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait, ::mlir::sdy::CollectiveOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AllSliceOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AllSliceOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("out_sharding"), ::llvm::StringRef("slicing_axes")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getOutShardingAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOutShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getSlicingAxesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getSlicingAxesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.all_slice");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getTensor() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::ListOfAxisRefListsAttr getSlicingAxesAttr() {
    return ::llvm::cast<::mlir::sdy::ListOfAxisRefListsAttr>(getProperties().slicing_axes);
  }

  ::llvm::ArrayRef<AxisRefListAttr> getSlicingAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
  void setSlicingAxesAttr(::mlir::sdy::ListOfAxisRefListsAttr attr) {
    getProperties().slicing_axes = attr;
  }

  void setSlicingAxes(::llvm::ArrayRef<AxisRefListAttr> attrValue);
  void setOutShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().out_sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::mlir::sdy::ListOfAxisRefListsAttr slicing_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::mlir::sdy::ListOfAxisRefListsAttr slicing_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::sdy::ListOfAxisRefListsAttr slicing_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefListAttr> slicing_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefListAttr> slicing_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::llvm::ArrayRef<AxisRefListAttr> slicing_axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::AllSliceOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::AllToAllOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class AllToAllOpGenericAdaptorBase {
public:
  struct Properties {
    using axesTy = ::mlir::sdy::AxisRefListAttr;
    axesTy axes;

    auto getAxes() {
      auto &propStorage = this->axes;
      return ::llvm::cast<::mlir::sdy::AxisRefListAttr>(propStorage);
    }
    void setAxes(const ::mlir::sdy::AxisRefListAttr &propValue) {
      this->axes = propValue;
    }
    using out_shardingTy = ::mlir::sdy::TensorShardingAttr;
    out_shardingTy out_sharding;

    auto getOutSharding() {
      auto &propStorage = this->out_sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setOutSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->out_sharding = propValue;
    }
    using src_dimTy = ::mlir::IntegerAttr;
    src_dimTy src_dim;

    auto getSrcDim() {
      auto &propStorage = this->src_dim;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setSrcDim(const ::mlir::IntegerAttr &propValue) {
      this->src_dim = propValue;
    }
    using tgt_dimTy = ::mlir::IntegerAttr;
    tgt_dimTy tgt_dim;

    auto getTgtDim() {
      auto &propStorage = this->tgt_dim;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setTgtDim(const ::mlir::IntegerAttr &propValue) {
      this->tgt_dim = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.axes == this->axes &&
        rhs.out_sharding == this->out_sharding &&
        rhs.src_dim == this->src_dim &&
        rhs.tgt_dim == this->tgt_dim &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  AllToAllOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.all_to_all", odsAttrs.getContext());
  }

  AllToAllOpGenericAdaptorBase(AllToAllOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getSrcDimAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().src_dim);
    return attr;
  }

  uint64_t getSrcDim();
  ::mlir::IntegerAttr getTgtDimAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().tgt_dim);
    return attr;
  }

  uint64_t getTgtDim();
  ::mlir::sdy::AxisRefListAttr getAxesAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::AxisRefListAttr>(getProperties().axes);
    return attr;
  }

  ::llvm::ArrayRef<AxisRefAttr> getAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
};
} // namespace detail
template <typename RangeT>
class AllToAllOpGenericAdaptor : public detail::AllToAllOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AllToAllOpGenericAdaptorBase;
public:
  AllToAllOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AllToAllOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : AllToAllOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AllToAllOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AllToAllOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AllToAllOpGenericAdaptor(RangeT values, const AllToAllOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AllToAllOp, typename = std::enable_if_t<std::is_same_v<LateInst, AllToAllOp>>>
  AllToAllOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AllToAllOpAdaptor : public AllToAllOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AllToAllOpGenericAdaptor::AllToAllOpGenericAdaptor;
  AllToAllOpAdaptor(AllToAllOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AllToAllOp : public ::mlir::Op<AllToAllOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait, ::mlir::sdy::CollectiveOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AllToAllOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AllToAllOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("axes"), ::llvm::StringRef("out_sharding"), ::llvm::StringRef("src_dim"), ::llvm::StringRef("tgt_dim")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getAxesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAxesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getOutShardingAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getOutShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getSrcDimAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getSrcDimAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getTgtDimAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getTgtDimAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.all_to_all");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getTensor() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getSrcDimAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().src_dim);
  }

  uint64_t getSrcDim();
  ::mlir::IntegerAttr getTgtDimAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().tgt_dim);
  }

  uint64_t getTgtDim();
  ::mlir::sdy::AxisRefListAttr getAxesAttr() {
    return ::llvm::cast<::mlir::sdy::AxisRefListAttr>(getProperties().axes);
  }

  ::llvm::ArrayRef<AxisRefAttr> getAxes();
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
  void setSrcDimAttr(::mlir::IntegerAttr attr) {
    getProperties().src_dim = attr;
  }

  void setSrcDim(uint64_t attrValue);
  void setTgtDimAttr(::mlir::IntegerAttr attr) {
    getProperties().tgt_dim = attr;
  }

  void setTgtDim(uint64_t attrValue);
  void setAxesAttr(::mlir::sdy::AxisRefListAttr attr) {
    getProperties().axes = attr;
  }

  void setAxes(::llvm::ArrayRef<AxisRefAttr> attrValue);
  void setOutShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().out_sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::mlir::IntegerAttr src_dim, ::mlir::IntegerAttr tgt_dim, ::mlir::sdy::AxisRefListAttr axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::mlir::IntegerAttr src_dim, ::mlir::IntegerAttr tgt_dim, ::mlir::sdy::AxisRefListAttr axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::IntegerAttr src_dim, ::mlir::IntegerAttr tgt_dim, ::mlir::sdy::AxisRefListAttr axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, uint64_t src_dim, uint64_t tgt_dim, ::llvm::ArrayRef<AxisRefAttr> axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, uint64_t src_dim, uint64_t tgt_dim, ::llvm::ArrayRef<AxisRefAttr> axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, uint64_t src_dim, uint64_t tgt_dim, ::llvm::ArrayRef<AxisRefAttr> axes, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::AllToAllOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::CollectivePermuteOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class CollectivePermuteOpGenericAdaptorBase {
public:
  struct Properties {
    using out_shardingTy = ::mlir::sdy::TensorShardingAttr;
    out_shardingTy out_sharding;

    auto getOutSharding() {
      auto &propStorage = this->out_sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setOutSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->out_sharding = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.out_sharding == this->out_sharding &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  CollectivePermuteOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.collective_permute", odsAttrs.getContext());
  }

  CollectivePermuteOpGenericAdaptorBase(CollectivePermuteOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
};
} // namespace detail
template <typename RangeT>
class CollectivePermuteOpGenericAdaptor : public detail::CollectivePermuteOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::CollectivePermuteOpGenericAdaptorBase;
public:
  CollectivePermuteOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  CollectivePermuteOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : CollectivePermuteOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  CollectivePermuteOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : CollectivePermuteOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  CollectivePermuteOpGenericAdaptor(RangeT values, const CollectivePermuteOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = CollectivePermuteOp, typename = std::enable_if_t<std::is_same_v<LateInst, CollectivePermuteOp>>>
  CollectivePermuteOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getTensor() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class CollectivePermuteOpAdaptor : public CollectivePermuteOpGenericAdaptor<::mlir::ValueRange> {
public:
  using CollectivePermuteOpGenericAdaptor::CollectivePermuteOpGenericAdaptor;
  CollectivePermuteOpAdaptor(CollectivePermuteOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class CollectivePermuteOp : public ::mlir::Op<CollectivePermuteOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait, ::mlir::sdy::CollectiveOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CollectivePermuteOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = CollectivePermuteOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("out_sharding")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getOutShardingAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOutShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.collective_permute");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getTensor() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getTensorMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::TensorShardingAttr getOutShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().out_sharding);
  }

  ::mlir::sdy::TensorShardingAttr getOutSharding();
  void setOutShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().out_sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::sdy::TensorShardingAttr out_sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::CollectivePermuteOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::ConstantOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ConstantOpGenericAdaptorBase {
public:
  struct Properties {
    using valueTy = ::mlir::ElementsAttr;
    valueTy value;

    auto getValue() {
      auto &propStorage = this->value;
      return ::llvm::cast<::mlir::ElementsAttr>(propStorage);
    }
    void setValue(const ::mlir::ElementsAttr &propValue) {
      this->value = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.value == this->value &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ConstantOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.constant", odsAttrs.getContext());
  }

  ConstantOpGenericAdaptorBase(ConstantOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::ElementsAttr getValueAttr() {
    auto attr = ::llvm::cast<::mlir::ElementsAttr>(getProperties().value);
    return attr;
  }

  ::mlir::ElementsAttr getValue();
};
} // namespace detail
template <typename RangeT>
class ConstantOpGenericAdaptor : public detail::ConstantOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ConstantOpGenericAdaptorBase;
public:
  ConstantOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ConstantOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ConstantOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ConstantOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ConstantOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ConstantOpGenericAdaptor(RangeT values, const ConstantOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ConstantOp, typename = std::enable_if_t<std::is_same_v<LateInst, ConstantOp>>>
  ConstantOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ConstantOpAdaptor : public ConstantOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ConstantOpGenericAdaptor::ConstantOpGenericAdaptor;
  ConstantOpAdaptor(ConstantOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ConstantOp : public ::mlir::Op<ConstantOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::RankedTensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ConstantOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ConstantOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("value")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getValueAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getValueAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.constant");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::RankedTensorType> getOutput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::RankedTensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::ElementsAttr getValueAttr() {
    return ::llvm::cast<::mlir::ElementsAttr>(getProperties().value);
  }

  ::mlir::ElementsAttr getValue();
  void setValueAttr(::mlir::ElementsAttr attr) {
    getProperties().value = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type output, ::mlir::ElementsAttr value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ElementsAttr value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ElementsAttr value);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  static bool isCompatibleReturnTypes(TypeRange l, TypeRange r);
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ConstantOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::DataFlowEdgeOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class DataFlowEdgeOpGenericAdaptorBase {
public:
  struct Properties {
    using shardingTy = ::mlir::sdy::TensorShardingAttr;
    shardingTy sharding;

    auto getSharding() {
      auto &propStorage = this->sharding;
      return ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->sharding = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.sharding == this->sharding &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  DataFlowEdgeOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.data_flow_edge", odsAttrs.getContext());
  }

  DataFlowEdgeOpGenericAdaptorBase(DataFlowEdgeOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::TensorShardingAttr getShardingAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingAttr>(getProperties().sharding);
    return attr;
  }

  ::std::optional<::mlir::sdy::TensorShardingAttr> getSharding();
};
} // namespace detail
template <typename RangeT>
class DataFlowEdgeOpGenericAdaptor : public detail::DataFlowEdgeOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::DataFlowEdgeOpGenericAdaptorBase;
public:
  DataFlowEdgeOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  DataFlowEdgeOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : DataFlowEdgeOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  DataFlowEdgeOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : DataFlowEdgeOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  DataFlowEdgeOpGenericAdaptor(RangeT values, const DataFlowEdgeOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = DataFlowEdgeOp, typename = std::enable_if_t<std::is_same_v<LateInst, DataFlowEdgeOp>>>
  DataFlowEdgeOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class DataFlowEdgeOpAdaptor : public DataFlowEdgeOpGenericAdaptor<::mlir::ValueRange> {
public:
  using DataFlowEdgeOpGenericAdaptor::DataFlowEdgeOpGenericAdaptor;
  DataFlowEdgeOpAdaptor(DataFlowEdgeOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class DataFlowEdgeOp : public ::mlir::Op<DataFlowEdgeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::ShapedType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DataFlowEdgeOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = DataFlowEdgeOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("sharding")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getShardingAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.data_flow_edge");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::ShapedType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::ShapedType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::ShapedType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::ShapedType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::TensorShardingAttr getShardingAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingAttr>(getProperties().sharding);
  }

  ::std::optional<::mlir::sdy::TensorShardingAttr> getSharding();
  void setShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().sharding = attr;
  }

  ::mlir::Attribute removeShardingAttr() {
      auto &attr = getProperties().sharding;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value input);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, /*optional*/::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, /*optional*/::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, /*optional*/::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  // If `target` is a target of a data-flow edge, returns the corresponding
  // `DataFlowEdgeOp`, otherwise returns `nullptr`.
  static DataFlowEdgeOp lookup(Value target);

  // If `source` is a source of a data-flow edge, returns the corresponding
  // `DataFlowEdgeOp`, otherwise returns `nullptr`.
  static DataFlowEdgeOp lookup(OpOperand& source);

  // Transforms the `sharding` of a target depending on `transformType`.
  //
  // See `DataFlowShardingTransformType` for more information.
  TensorShardingAttr transformTargetSharding(
      TensorShardingAttr sharding,
      DataFlowShardingTransformType transformType);

  // Returns all sources of this `DataFlowEdgeOp`.
  SmallVector<Value> getSources();

  // Returns all non-edge-owner targets of this `DataFlowEdgeOp`.
  SmallVector<Value> getNonOwnerTargets();
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::DataFlowEdgeOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::ManualComputationOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ManualComputationOpGenericAdaptorBase {
public:
  struct Properties {
    using in_shardingsTy = ::mlir::sdy::TensorShardingPerValueAttr;
    in_shardingsTy in_shardings;

    auto getInShardings() {
      auto &propStorage = this->in_shardings;
      return ::llvm::cast<::mlir::sdy::TensorShardingPerValueAttr>(propStorage);
    }
    void setInShardings(const ::mlir::sdy::TensorShardingPerValueAttr &propValue) {
      this->in_shardings = propValue;
    }
    using manual_axesTy = ::mlir::sdy::ManualAxesAttr;
    manual_axesTy manual_axes;

    auto getManualAxes() {
      auto &propStorage = this->manual_axes;
      return ::llvm::cast<::mlir::sdy::ManualAxesAttr>(propStorage);
    }
    void setManualAxes(const ::mlir::sdy::ManualAxesAttr &propValue) {
      this->manual_axes = propValue;
    }
    using out_shardingsTy = ::mlir::sdy::TensorShardingPerValueAttr;
    out_shardingsTy out_shardings;

    auto getOutShardings() {
      auto &propStorage = this->out_shardings;
      return ::llvm::cast<::mlir::sdy::TensorShardingPerValueAttr>(propStorage);
    }
    void setOutShardings(const ::mlir::sdy::TensorShardingPerValueAttr &propValue) {
      this->out_shardings = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.in_shardings == this->in_shardings &&
        rhs.manual_axes == this->manual_axes &&
        rhs.out_shardings == this->out_shardings &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ManualComputationOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.manual_computation", odsAttrs.getContext());
  }

  ManualComputationOpGenericAdaptorBase(ManualComputationOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::TensorShardingPerValueAttr getInShardingsAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().in_shardings);
    return attr;
  }

  ::mlir::sdy::TensorShardingPerValueAttr getInShardings();
  ::mlir::sdy::TensorShardingPerValueAttr getOutShardingsAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().out_shardings);
    return attr;
  }

  ::mlir::sdy::TensorShardingPerValueAttr getOutShardings();
  ::mlir::sdy::ManualAxesAttr getManualAxesAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::ManualAxesAttr>(getProperties().manual_axes);
    return attr;
  }

  ::llvm::ArrayRef<StringAttr> getManualAxes();
  ::mlir::Region &getBody() {
    return *odsRegions[0];
  }

  ::mlir::RegionRange getRegions() {
    return odsRegions;
  }

};
} // namespace detail
template <typename RangeT>
class ManualComputationOpGenericAdaptor : public detail::ManualComputationOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ManualComputationOpGenericAdaptorBase;
public:
  ManualComputationOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ManualComputationOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ManualComputationOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ManualComputationOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ManualComputationOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ManualComputationOpGenericAdaptor(RangeT values, const ManualComputationOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ManualComputationOp, typename = std::enable_if_t<std::is_same_v<LateInst, ManualComputationOp>>>
  ManualComputationOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getTensors() {
    return getODSOperands(0);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ManualComputationOpAdaptor : public ManualComputationOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ManualComputationOpGenericAdaptor::ManualComputationOpGenericAdaptor;
  ManualComputationOpAdaptor(ManualComputationOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ManualComputationOp : public ::mlir::Op<ManualComputationOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::SingleBlock, ::mlir::OpTrait::SingleBlockImplicitTerminator<ReturnOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::HasRecursiveMemoryEffects, ::mlir::OpTrait::IsIsolatedFromAbove, ::mlir::sdy::ShardableDataFlowOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ManualComputationOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ManualComputationOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("in_shardings"), ::llvm::StringRef("manual_axes"), ::llvm::StringRef("out_shardings")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getInShardingsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getInShardingsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getManualAxesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getManualAxesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOutShardingsAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getOutShardingsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.manual_computation");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::Operation::operand_range getTensors() {
    return getODSOperands(0);
  }

  ::mlir::MutableOperandRange getTensorsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::Operation::result_range getResults() {
    return getODSResults(0);
  }

  ::mlir::Region &getBody() {
    return (*this)->getRegion(0);
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::TensorShardingPerValueAttr getInShardingsAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().in_shardings);
  }

  ::mlir::sdy::TensorShardingPerValueAttr getInShardings();
  ::mlir::sdy::TensorShardingPerValueAttr getOutShardingsAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().out_shardings);
  }

  ::mlir::sdy::TensorShardingPerValueAttr getOutShardings();
  ::mlir::sdy::ManualAxesAttr getManualAxesAttr() {
    return ::llvm::cast<::mlir::sdy::ManualAxesAttr>(getProperties().manual_axes);
  }

  ::llvm::ArrayRef<StringAttr> getManualAxes();
  void setInShardingsAttr(::mlir::sdy::TensorShardingPerValueAttr attr) {
    getProperties().in_shardings = attr;
  }

  void setOutShardingsAttr(::mlir::sdy::TensorShardingPerValueAttr attr) {
    getProperties().out_shardings = attr;
  }

  void setManualAxesAttr(::mlir::sdy::ManualAxesAttr attr) {
    getProperties().manual_axes = attr;
  }

  void setManualAxes(::llvm::ArrayRef<StringAttr> attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ValueRange tensors, ::mlir::sdy::TensorShardingPerValueAttr in_shardings, ::mlir::sdy::TensorShardingPerValueAttr out_shardings, ::mlir::sdy::ManualAxesAttr manual_axes);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ValueRange tensors, ::mlir::sdy::TensorShardingPerValueAttr in_shardings, ::mlir::sdy::TensorShardingPerValueAttr out_shardings, ::llvm::ArrayRef<StringAttr> manual_axes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings();
  void setBlockArgumentEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
  mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings();
  void setOpResultEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
  mlir::sdy::TensorShardingAttr transformTargetSharding(mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType);
  mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners();
  mlir::ResultRange getOpResultEdgeOwners();
  mlir::SmallVector<mlir::Value> getEdgeSources(mlir::Value owner);
  mlir::Value getEdgeOwnerFromTarget(mlir::Value target);
  mlir::Value getEdgeOwnerFromSource(mlir::OpOperand&source);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
  TensorShardingAttr getInSharding(int64_t operandIndex) {
    return getInShardings().getSharding(operandIndex);
  }
  TensorShardingAttr getOutSharding(int64_t resultIndex) {
    return getOutShardings().getSharding(resultIndex);
  }

  void setInShardings(ArrayRef<TensorShardingAttr> shardings);
  void setOutShardings(ArrayRef<TensorShardingAttr> shardings);

  void setInSharding(int64_t operandIndex, TensorShardingAttr sharding);
  void setOutSharding(int64_t resultIndex, TensorShardingAttr sharding);

  // Same as `getInSharding`, but removes any prefixed manual axes from each
  // dim sharding.
  TensorShardingAttr getInShardingWithoutManualAxes(int64_t operandIndex);

  // Same as `getOutSharding`, but removes any prefixed manual axes from each
  // dim sharding.
  TensorShardingAttr getOutShardingWithoutManualAxes(int64_t resultIndex);
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ManualComputationOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::MeshOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class MeshOpGenericAdaptorBase {
public:
  struct Properties {
    using meshTy = ::mlir::sdy::MeshAttr;
    meshTy mesh;

    auto getMesh() {
      auto &propStorage = this->mesh;
      return ::llvm::cast<::mlir::sdy::MeshAttr>(propStorage);
    }
    void setMesh(const ::mlir::sdy::MeshAttr &propValue) {
      this->mesh = propValue;
    }
    using sym_nameTy = ::mlir::StringAttr;
    sym_nameTy sym_name;

    auto getSymName() {
      auto &propStorage = this->sym_name;
      return ::llvm::cast<::mlir::StringAttr>(propStorage);
    }
    void setSymName(const ::mlir::StringAttr &propValue) {
      this->sym_name = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.mesh == this->mesh &&
        rhs.sym_name == this->sym_name &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  MeshOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.mesh", odsAttrs.getContext());
  }

  MeshOpGenericAdaptorBase(MeshOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::StringAttr getSymNameAttr() {
    auto attr = ::llvm::cast<::mlir::StringAttr>(getProperties().sym_name);
    return attr;
  }

  ::llvm::StringRef getSymName();
  ::mlir::sdy::MeshAttr getMeshAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::MeshAttr>(getProperties().mesh);
    return attr;
  }

  ::mlir::sdy::MeshAttr getMesh();
};
} // namespace detail
template <typename RangeT>
class MeshOpGenericAdaptor : public detail::MeshOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::MeshOpGenericAdaptorBase;
public:
  MeshOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  MeshOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : MeshOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  MeshOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : MeshOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  MeshOpGenericAdaptor(RangeT values, const MeshOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = MeshOp, typename = std::enable_if_t<std::is_same_v<LateInst, MeshOp>>>
  MeshOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class MeshOpAdaptor : public MeshOpGenericAdaptor<::mlir::ValueRange> {
public:
  using MeshOpGenericAdaptor::MeshOpGenericAdaptor;
  MeshOpAdaptor(MeshOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class MeshOp : public ::mlir::Op<MeshOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::HasParent<ModuleOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::SymbolOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MeshOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = MeshOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("mesh"), ::llvm::StringRef("sym_name")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getMeshAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getMeshAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getSymNameAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getSymNameAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.mesh");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::StringAttr getSymNameAttr() {
    return ::llvm::cast<::mlir::StringAttr>(getProperties().sym_name);
  }

  ::llvm::StringRef getSymName();
  ::mlir::sdy::MeshAttr getMeshAttr() {
    return ::llvm::cast<::mlir::sdy::MeshAttr>(getProperties().mesh);
  }

  ::mlir::sdy::MeshAttr getMesh();
  void setSymNameAttr(::mlir::StringAttr attr) {
    getProperties().sym_name = attr;
  }

  void setSymName(::llvm::StringRef attrValue);
  void setMeshAttr(::mlir::sdy::MeshAttr attr) {
    getProperties().mesh = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::StringAttr sym_name, ::mlir::sdy::MeshAttr mesh);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::StringAttr sym_name, ::mlir::sdy::MeshAttr mesh);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::StringRef sym_name, ::mlir::sdy::MeshAttr mesh);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::llvm::StringRef sym_name, ::mlir::sdy::MeshAttr mesh);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::MeshOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::NamedComputationOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class NamedComputationOpGenericAdaptorBase {
public:
  struct Properties {
    using in_shardingsTy = ::mlir::sdy::TensorShardingPerValueAttr;
    in_shardingsTy in_shardings;

    auto getInShardings() {
      auto &propStorage = this->in_shardings;
      return ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingPerValueAttr>(propStorage);
    }
    void setInShardings(const ::mlir::sdy::TensorShardingPerValueAttr &propValue) {
      this->in_shardings = propValue;
    }
    using nameTy = ::mlir::StringAttr;
    nameTy name;

    auto getName() {
      auto &propStorage = this->name;
      return ::llvm::cast<::mlir::StringAttr>(propStorage);
    }
    void setName(const ::mlir::StringAttr &propValue) {
      this->name = propValue;
    }
    using out_shardingsTy = ::mlir::sdy::TensorShardingPerValueAttr;
    out_shardingsTy out_shardings;

    auto getOutShardings() {
      auto &propStorage = this->out_shardings;
      return ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingPerValueAttr>(propStorage);
    }
    void setOutShardings(const ::mlir::sdy::TensorShardingPerValueAttr &propValue) {
      this->out_shardings = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.in_shardings == this->in_shardings &&
        rhs.name == this->name &&
        rhs.out_shardings == this->out_shardings &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  NamedComputationOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.named_computation", odsAttrs.getContext());
  }

  NamedComputationOpGenericAdaptorBase(NamedComputationOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::StringAttr getNameAttr() {
    auto attr = ::llvm::cast<::mlir::StringAttr>(getProperties().name);
    return attr;
  }

  ::llvm::StringRef getName();
  ::mlir::sdy::TensorShardingPerValueAttr getInShardingsAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().in_shardings);
    return attr;
  }

  ::std::optional<::mlir::sdy::TensorShardingPerValueAttr> getInShardings();
  ::mlir::sdy::TensorShardingPerValueAttr getOutShardingsAttr() {
    auto attr = ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().out_shardings);
    return attr;
  }

  ::std::optional<::mlir::sdy::TensorShardingPerValueAttr> getOutShardings();
  ::mlir::Region &getBody() {
    return *odsRegions[0];
  }

  ::mlir::RegionRange getRegions() {
    return odsRegions;
  }

};
} // namespace detail
template <typename RangeT>
class NamedComputationOpGenericAdaptor : public detail::NamedComputationOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::NamedComputationOpGenericAdaptorBase;
public:
  NamedComputationOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  NamedComputationOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : NamedComputationOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  NamedComputationOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : NamedComputationOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  NamedComputationOpGenericAdaptor(RangeT values, const NamedComputationOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = NamedComputationOp, typename = std::enable_if_t<std::is_same_v<LateInst, NamedComputationOp>>>
  NamedComputationOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getOperands() {
    return getODSOperands(0);
  }

private:
  RangeT odsOperands;
};
class NamedComputationOpAdaptor : public NamedComputationOpGenericAdaptor<::mlir::ValueRange> {
public:
  using NamedComputationOpGenericAdaptor::NamedComputationOpGenericAdaptor;
  NamedComputationOpAdaptor(NamedComputationOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class NamedComputationOp : public ::mlir::Op<NamedComputationOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::SingleBlock, ::mlir::OpTrait::SingleBlockImplicitTerminator<ReturnOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::HasRecursiveMemoryEffects, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::RecursivelySpeculatableImplTrait, ::mlir::OpTrait::IsIsolatedFromAbove, ::mlir::InferTypeOpInterface::Trait, ::mlir::sdy::ShardableDataFlowOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = NamedComputationOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = NamedComputationOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("in_shardings"), ::llvm::StringRef("name"), ::llvm::StringRef("out_shardings")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getInShardingsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getInShardingsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getNameAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getNameAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOutShardingsAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getOutShardingsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.named_computation");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::Operation::operand_range getOperands() {
    return getODSOperands(0);
  }

  ::mlir::MutableOperandRange getOperandsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::Region &getBody() {
    return (*this)->getRegion(0);
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::StringAttr getNameAttr() {
    return ::llvm::cast<::mlir::StringAttr>(getProperties().name);
  }

  ::llvm::StringRef getName();
  ::mlir::sdy::TensorShardingPerValueAttr getInShardingsAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().in_shardings);
  }

  ::std::optional<::mlir::sdy::TensorShardingPerValueAttr> getInShardings();
  ::mlir::sdy::TensorShardingPerValueAttr getOutShardingsAttr() {
    return ::llvm::dyn_cast_or_null<::mlir::sdy::TensorShardingPerValueAttr>(getProperties().out_shardings);
  }

  ::std::optional<::mlir::sdy::TensorShardingPerValueAttr> getOutShardings();
  void setNameAttr(::mlir::StringAttr attr) {
    getProperties().name = attr;
  }

  void setName(::llvm::StringRef attrValue);
  void setInShardingsAttr(::mlir::sdy::TensorShardingPerValueAttr attr) {
    getProperties().in_shardings = attr;
  }

  void setOutShardingsAttr(::mlir::sdy::TensorShardingPerValueAttr attr) {
    getProperties().out_shardings = attr;
  }

  ::mlir::Attribute removeInShardingsAttr() {
      auto &attr = getProperties().in_shardings;
      attr = {};
      return attr;
  }

  ::mlir::Attribute removeOutShardingsAttr() {
      auto &attr = getProperties().out_shardings;
      attr = {};
      return attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultType0, ::mlir::StringAttr name, ::mlir::ValueRange operands, /*optional*/::mlir::sdy::TensorShardingPerValueAttr in_shardings, /*optional*/::mlir::sdy::TensorShardingPerValueAttr out_shardings);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::StringAttr name, ::mlir::ValueRange operands, /*optional*/::mlir::sdy::TensorShardingPerValueAttr in_shardings, /*optional*/::mlir::sdy::TensorShardingPerValueAttr out_shardings);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultType0, ::llvm::StringRef name, ::mlir::ValueRange operands, /*optional*/::mlir::sdy::TensorShardingPerValueAttr in_shardings, /*optional*/::mlir::sdy::TensorShardingPerValueAttr out_shardings);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::StringRef name, ::mlir::ValueRange operands, /*optional*/::mlir::sdy::TensorShardingPerValueAttr in_shardings, /*optional*/::mlir::sdy::TensorShardingPerValueAttr out_shardings);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings();
  void setBlockArgumentEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
  mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings();
  void setOpResultEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
  mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners();
  mlir::ResultRange getOpResultEdgeOwners();
  mlir::SmallVector<mlir::Value> getEdgeSources(mlir::Value owner);
  mlir::Value getEdgeOwnerFromTarget(mlir::Value target);
  mlir::Value getEdgeOwnerFromSource(mlir::OpOperand&source);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::NamedComputationOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::PropagationBarrierOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class PropagationBarrierOpGenericAdaptorBase {
public:
  struct Properties {
    using allowed_directionTy = ::mlir::sdy::PropagationDirectionAttr;
    allowed_directionTy allowed_direction;

    auto getAllowedDirection() {
      auto &propStorage = this->allowed_direction;
      return ::llvm::cast<::mlir::sdy::PropagationDirectionAttr>(propStorage);
    }
    void setAllowedDirection(const ::mlir::sdy::PropagationDirectionAttr &propValue) {
      this->allowed_direction = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.allowed_direction == this->allowed_direction &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  PropagationBarrierOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.propagation_barrier", odsAttrs.getContext());
  }

  PropagationBarrierOpGenericAdaptorBase(PropagationBarrierOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::PropagationDirectionAttr getAllowedDirectionAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::PropagationDirectionAttr>(getProperties().allowed_direction);
    return attr;
  }

  ::mlir::sdy::PropagationDirection getAllowedDirection();
};
} // namespace detail
template <typename RangeT>
class PropagationBarrierOpGenericAdaptor : public detail::PropagationBarrierOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::PropagationBarrierOpGenericAdaptorBase;
public:
  PropagationBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  PropagationBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : PropagationBarrierOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  PropagationBarrierOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : PropagationBarrierOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  PropagationBarrierOpGenericAdaptor(RangeT values, const PropagationBarrierOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = PropagationBarrierOp, typename = std::enable_if_t<std::is_same_v<LateInst, PropagationBarrierOp>>>
  PropagationBarrierOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class PropagationBarrierOpAdaptor : public PropagationBarrierOpGenericAdaptor<::mlir::ValueRange> {
public:
  using PropagationBarrierOpGenericAdaptor::PropagationBarrierOpGenericAdaptor;
  PropagationBarrierOpAdaptor(PropagationBarrierOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class PropagationBarrierOp : public ::mlir::Op<PropagationBarrierOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::RankedTensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::Elementwise, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PropagationBarrierOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = PropagationBarrierOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("allowed_direction")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getAllowedDirectionAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAllowedDirectionAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.propagation_barrier");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::RankedTensorType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::RankedTensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::RankedTensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::RankedTensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::PropagationDirectionAttr getAllowedDirectionAttr() {
    return ::llvm::cast<::mlir::sdy::PropagationDirectionAttr>(getProperties().allowed_direction);
  }

  ::mlir::sdy::PropagationDirection getAllowedDirection();
  void setAllowedDirectionAttr(::mlir::sdy::PropagationDirectionAttr attr) {
    getProperties().allowed_direction = attr;
  }

  void setAllowedDirection(::mlir::sdy::PropagationDirection attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::sdy::PropagationDirectionAttr allowed_direction);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::sdy::PropagationDirectionAttr allowed_direction);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::sdy::PropagationDirectionAttr allowed_direction);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::sdy::PropagationDirection allowed_direction);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::sdy::PropagationDirection allowed_direction);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::sdy::PropagationDirection allowed_direction);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::PropagationBarrierOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::ReshardOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ReshardOpGenericAdaptorBase {
public:
  struct Properties {
    using shardingTy = ::mlir::sdy::TensorShardingAttr;
    shardingTy sharding;

    auto getSharding() {
      auto &propStorage = this->sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->sharding = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.sharding == this->sharding &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ReshardOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.reshard", odsAttrs.getContext());
  }

  ReshardOpGenericAdaptorBase(ReshardOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::TensorShardingAttr getShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getSharding();
};
} // namespace detail
template <typename RangeT>
class ReshardOpGenericAdaptor : public detail::ReshardOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ReshardOpGenericAdaptorBase;
public:
  ReshardOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ReshardOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ReshardOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ReshardOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ReshardOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ReshardOpGenericAdaptor(RangeT values, const ReshardOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ReshardOp, typename = std::enable_if_t<std::is_same_v<LateInst, ReshardOp>>>
  ReshardOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ReshardOpAdaptor : public ReshardOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ReshardOpGenericAdaptor::ReshardOpGenericAdaptor;
  ReshardOpAdaptor(ReshardOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ReshardOp : public ::mlir::Op<ReshardOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::Elementwise, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ReshardOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ReshardOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("sharding")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getShardingAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.reshard");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::TensorShardingAttr getShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().sharding);
  }

  ::mlir::sdy::TensorShardingAttr getSharding();
  void setShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ReshardOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::ReturnOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ReturnOpGenericAdaptorBase {
public:
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  ::mlir::RegionRange odsRegions;
public:
  ReturnOpGenericAdaptorBase(::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.return", odsAttrs.getContext());
  }

  ReturnOpGenericAdaptorBase(::mlir::Operation *op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), odsRegions(op->getRegions()) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize);
  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};
} // namespace detail
template <typename RangeT>
class ReturnOpGenericAdaptor : public detail::ReturnOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ReturnOpGenericAdaptorBase;
public:
  ReturnOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = {}, const ::mlir::EmptyProperties &properties = {}, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ReturnOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ReturnOpGenericAdaptor(values, attrs, (properties ? *properties.as<::mlir::EmptyProperties *>() : ::mlir::EmptyProperties{}), regions) {}

  ReturnOpGenericAdaptor(RangeT values, const ReturnOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ReturnOp, typename = std::enable_if_t<std::is_same_v<LateInst, ReturnOp>>>
  ReturnOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  RangeT getResults() {
    return getODSOperands(0);
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ReturnOpAdaptor : public ReturnOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ReturnOpGenericAdaptor::ReturnOpGenericAdaptor;
  ReturnOpAdaptor(ReturnOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ReturnOp : public ::mlir::Op<ReturnOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::OpInvariants, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::IsTerminator> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ReturnOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ReturnOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.return");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::Operation::operand_range getResults() {
    return getODSOperands(0);
  }

  ::mlir::MutableOperandRange getResultsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange results);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ReturnOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::ShardingConstraintOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ShardingConstraintOpGenericAdaptorBase {
public:
  struct Properties {
    using shardingTy = ::mlir::sdy::TensorShardingAttr;
    shardingTy sharding;

    auto getSharding() {
      auto &propStorage = this->sharding;
      return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(propStorage);
    }
    void setSharding(const ::mlir::sdy::TensorShardingAttr &propValue) {
      this->sharding = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.sharding == this->sharding &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ShardingConstraintOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.sharding_constraint", odsAttrs.getContext());
  }

  ShardingConstraintOpGenericAdaptorBase(ShardingConstraintOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::sdy::TensorShardingAttr getShardingAttr() {
    auto attr = ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().sharding);
    return attr;
  }

  ::mlir::sdy::TensorShardingAttr getSharding();
};
} // namespace detail
template <typename RangeT>
class ShardingConstraintOpGenericAdaptor : public detail::ShardingConstraintOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ShardingConstraintOpGenericAdaptorBase;
public:
  ShardingConstraintOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ShardingConstraintOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ShardingConstraintOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ShardingConstraintOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ShardingConstraintOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ShardingConstraintOpGenericAdaptor(RangeT values, const ShardingConstraintOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ShardingConstraintOp, typename = std::enable_if_t<std::is_same_v<LateInst, ShardingConstraintOp>>>
  ShardingConstraintOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ShardingConstraintOpAdaptor : public ShardingConstraintOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ShardingConstraintOpGenericAdaptor::ShardingConstraintOpGenericAdaptor;
  ShardingConstraintOpAdaptor(ShardingConstraintOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ShardingConstraintOp : public ::mlir::Op<ShardingConstraintOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::OpTrait::Elementwise, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ShardingConstraintOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ShardingConstraintOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("sharding")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getShardingAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getShardingAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.sharding_constraint");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::sdy::TensorShardingAttr getShardingAttr() {
    return ::llvm::cast<::mlir::sdy::TensorShardingAttr>(getProperties().sharding);
  }

  ::mlir::sdy::TensorShardingAttr getSharding();
  void setShardingAttr(::mlir::sdy::TensorShardingAttr attr) {
    getProperties().sharding = attr;
  }

  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::sdy::TensorShardingAttr sharding);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::llvm::LogicalResult verify();
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ShardingConstraintOp)

namespace mlir {
namespace sdy {

//===----------------------------------------------------------------------===//
// ::mlir::sdy::ShardingGroupOp declarations
//===----------------------------------------------------------------------===//

namespace detail {
class ShardingGroupOpGenericAdaptorBase {
public:
  struct Properties {
    using group_idTy = ::mlir::IntegerAttr;
    group_idTy group_id;

    auto getGroupId() {
      auto &propStorage = this->group_id;
      return ::llvm::cast<::mlir::IntegerAttr>(propStorage);
    }
    void setGroupId(const ::mlir::IntegerAttr &propValue) {
      this->group_id = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.group_id == this->group_id &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ShardingGroupOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("sdy.sharding_group", odsAttrs.getContext());
  }

  ShardingGroupOpGenericAdaptorBase(ShardingGroupOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::IntegerAttr getGroupIdAttr() {
    auto attr = ::llvm::cast<::mlir::IntegerAttr>(getProperties().group_id);
    return attr;
  }

  uint64_t getGroupId();
};
} // namespace detail
template <typename RangeT>
class ShardingGroupOpGenericAdaptor : public detail::ShardingGroupOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ShardingGroupOpGenericAdaptorBase;
public:
  ShardingGroupOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ShardingGroupOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions = {}) : ShardingGroupOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ShardingGroupOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ShardingGroupOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ShardingGroupOpGenericAdaptor(RangeT values, const ShardingGroupOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ShardingGroupOp, typename = std::enable_if_t<std::is_same_v<LateInst, ShardingGroupOp>>>
  ShardingGroupOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ShardingGroupOpAdaptor : public ShardingGroupOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ShardingGroupOpGenericAdaptor::ShardingGroupOpGenericAdaptor;
  ShardingGroupOpAdaptor(ShardingGroupOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ShardingGroupOp : public ::mlir::Op<ShardingGroupOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ShardingGroupOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ShardingGroupOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("group_id")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getGroupIdAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getGroupIdAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("sdy.sharding_group");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::RankedTensorType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::RankedTensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void populateInherentAttrs(::mlir::MLIRContext *ctx, const Properties &prop, ::mlir::NamedAttrList &attrs);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::IntegerAttr getGroupIdAttr() {
    return ::llvm::cast<::mlir::IntegerAttr>(getProperties().group_id);
  }

  uint64_t getGroupId();
  void setGroupIdAttr(::mlir::IntegerAttr attr) {
    getProperties().group_id = attr;
  }

  void setGroupId(uint64_t attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::IntegerAttr group_id);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::IntegerAttr group_id);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, uint64_t group_id);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, uint64_t group_id);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::OpaqueProperties properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

public:
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ShardingGroupOp)


#endif  // GET_OP_CLASSES

