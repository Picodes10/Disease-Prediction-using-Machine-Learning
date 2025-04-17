/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace sdy {
class ShardableDataFlowOpInterface;
namespace detail {
struct ShardableDataFlowOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    mlir::SmallVector<mlir::sdy::TensorShardingAttr> (*getBlockArgumentEdgeOwnerShardings)(const Concept *impl, ::mlir::Operation *);
    void (*setBlockArgumentEdgeOwnerShardings)(const Concept *impl, ::mlir::Operation *, mlir::ArrayRef<mlir::sdy::TensorShardingAttr>);
    mlir::SmallVector<mlir::sdy::TensorShardingAttr> (*getOpResultEdgeOwnerShardings)(const Concept *impl, ::mlir::Operation *);
    void (*setOpResultEdgeOwnerShardings)(const Concept *impl, ::mlir::Operation *, mlir::ArrayRef<mlir::sdy::TensorShardingAttr>);
    mlir::sdy::TensorShardingAttr (*transformTargetSharding)(const Concept *impl, ::mlir::Operation *, mlir::Value, mlir::sdy::TensorShardingAttr, mlir::sdy::DataFlowShardingTransformType);
    mlir::ArrayRef<mlir::BlockArgument> (*getBlockArgumentEdgeOwners)(const Concept *impl, ::mlir::Operation *);
    mlir::ResultRange (*getOpResultEdgeOwners)(const Concept *impl, ::mlir::Operation *);
    mlir::SmallVector<mlir::Value> (*getEdgeSources)(const Concept *impl, ::mlir::Operation *, mlir::Value);
    mlir::Value (*getEdgeOwnerFromTarget)(const Concept *impl, ::mlir::Operation *, mlir::Value);
    mlir::Value (*getEdgeOwnerFromSource)(const Concept *impl, ::mlir::Operation *, mlir::OpOperand&);
    mlir::SmallVector<mlir::Value> (*getNonEdgeOwnerTargets)(const Concept *impl, ::mlir::Operation *, mlir::Value);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::sdy::ShardableDataFlowOpInterface;
    Model() : Concept{getBlockArgumentEdgeOwnerShardings, setBlockArgumentEdgeOwnerShardings, getOpResultEdgeOwnerShardings, setOpResultEdgeOwnerShardings, transformTargetSharding, getBlockArgumentEdgeOwners, getOpResultEdgeOwners, getEdgeSources, getEdgeOwnerFromTarget, getEdgeOwnerFromSource, getNonEdgeOwnerTargets} {}

    static inline mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline void setBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
    static inline mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline void setOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
    static inline mlir::sdy::TensorShardingAttr transformTargetSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType);
    static inline mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline mlir::ResultRange getOpResultEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline mlir::SmallVector<mlir::Value> getEdgeSources(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner);
    static inline mlir::Value getEdgeOwnerFromTarget(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target);
    static inline mlir::Value getEdgeOwnerFromSource(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::OpOperand& source);
    static inline mlir::SmallVector<mlir::Value> getNonEdgeOwnerTargets(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::sdy::ShardableDataFlowOpInterface;
    FallbackModel() : Concept{getBlockArgumentEdgeOwnerShardings, setBlockArgumentEdgeOwnerShardings, getOpResultEdgeOwnerShardings, setOpResultEdgeOwnerShardings, transformTargetSharding, getBlockArgumentEdgeOwners, getOpResultEdgeOwners, getEdgeSources, getEdgeOwnerFromTarget, getEdgeOwnerFromSource, getNonEdgeOwnerTargets} {}

    static inline mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline void setBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
    static inline mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline void setOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
    static inline mlir::sdy::TensorShardingAttr transformTargetSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType);
    static inline mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline mlir::ResultRange getOpResultEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline mlir::SmallVector<mlir::Value> getEdgeSources(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner);
    static inline mlir::Value getEdgeOwnerFromTarget(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target);
    static inline mlir::Value getEdgeOwnerFromSource(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::OpOperand& source);
    static inline mlir::SmallVector<mlir::Value> getNonEdgeOwnerTargets(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
    mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val) const;
    void setBlockArgumentEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) const;
    mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val) const;
    void setOpResultEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) const;
    mlir::sdy::TensorShardingAttr transformTargetSharding(::mlir::Operation *tablegen_opaque_val, mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType) const;
    mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners(::mlir::Operation *tablegen_opaque_val) const;
    mlir::SmallVector<mlir::Value> getNonEdgeOwnerTargets(::mlir::Operation *tablegen_opaque_val, mlir::Value owner) const;
  };
};
template <typename ConcreteOp>
struct ShardableDataFlowOpInterfaceTrait;

} // namespace detail
class ShardableDataFlowOpInterface : public ::mlir::OpInterface<ShardableDataFlowOpInterface, detail::ShardableDataFlowOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<ShardableDataFlowOpInterface, detail::ShardableDataFlowOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::ShardableDataFlowOpInterfaceTrait<ConcreteOp> {};
  /// Returns the shardings of all block argument data flow edge owners.
  mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings();
  /// Sets `shardings` of all block argument edge owners.
  void setBlockArgumentEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
  /// Returns the shardings of all op result data flow edge owners.
  mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings();
  /// Sets `shardings` of all op result edge owners.
  void setOpResultEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings);
  /// Transforms the `sharding` of the target depending on `transformType`
  /// 
  /// See `DataFlowShardingTransformType` for more information.
  mlir::sdy::TensorShardingAttr transformTargetSharding(mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType);
  /// Gets all block argument edge owners.
  mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners();
  /// Gets all op result edge owners.
  mlir::ResultRange getOpResultEdgeOwners();
  /// Gets the data flow edge sources given the edge `owner`.
  mlir::SmallVector<mlir::Value> getEdgeSources(mlir::Value owner);
  /// Gets the owner `target` of a data flow edge given a `target` that may or
  /// may not be the owner.
  mlir::Value getEdgeOwnerFromTarget(mlir::Value target);
  /// Gets the owner target of a data flow edge given a `source`.
  mlir::Value getEdgeOwnerFromSource(mlir::OpOperand& source);
  /// Gets the non-owner targets of a data flow edge given the edge `owner`.
  mlir::SmallVector<mlir::Value> getNonEdgeOwnerTargets(mlir::Value owner);

    // Gets the sharding of the block argument edge owner with the given
    // `index`.
    TensorShardingAttr getBlockArgumentEdgeOwnerSharding(
        unsigned index);

    // Gets the sharding of the op result edge owner with the given `index`.
    TensorShardingAttr getOpResultEdgeOwnerSharding(unsigned index);

    // Gets the sharding of the edge owner of the given `value`.
    TensorShardingAttr getEdgeOwnerSharding(Value value);

    // Sets the `sharding` of the block argument edge owner with the given
    // `index`.
    void setBlockArgumentEdgeOwnerSharding(
      unsigned index, TensorShardingAttr sharding);

    //  Sets the `sharding` of the op result edge owner with the given `index`.
    void setOpResultEdgeOwnerSharding(
      unsigned index, TensorShardingAttr sharding);

    // Sets the `sharding` of the edge owner of the given `value`.
    void setEdgeOwnerSharding(
        Value value, TensorShardingAttr sharding);
};
namespace detail {
  template <typename ConcreteOp>
  struct ShardableDataFlowOpInterfaceTrait : public ::mlir::OpInterface<ShardableDataFlowOpInterface, detail::ShardableDataFlowOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    /// Returns the shardings of all block argument data flow edge owners.
    mlir::SmallVector<mlir::sdy::TensorShardingAttr> getBlockArgumentEdgeOwnerShardings() {
      return {};
    }
    /// Sets `shardings` of all block argument edge owners.
    void setBlockArgumentEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) {
      return;
    }
    /// Returns the shardings of all op result data flow edge owners.
    mlir::SmallVector<mlir::sdy::TensorShardingAttr> getOpResultEdgeOwnerShardings() {
      return mlir::sdy::details::getOpResultEdgeOwnerShardingsImpl((*static_cast<ConcreteOp *>(this)));
    }
    /// Sets `shardings` of all op result edge owners.
    void setOpResultEdgeOwnerShardings(mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) {
      mlir::sdy::details::setOpResultEdgeOwnerShardingsImpl((*static_cast<ConcreteOp *>(this)), shardings);
    }
    /// Transforms the `sharding` of the target depending on `transformType`
    /// 
    /// See `DataFlowShardingTransformType` for more information.
    mlir::sdy::TensorShardingAttr transformTargetSharding(mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType) {
      return sharding;
    }
    /// Gets all block argument edge owners.
    mlir::ArrayRef<mlir::BlockArgument> getBlockArgumentEdgeOwners() {
      return {};
    }
    /// Gets the non-owner targets of a data flow edge given the edge `owner`.
    mlir::SmallVector<mlir::Value> getNonEdgeOwnerTargets(mlir::Value owner) {
      return {};
    }
  };
}// namespace detail
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class ShardingRuleOpInterface;
namespace detail {
struct ShardingRuleOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    mlir::sdy::OpShardingRuleAttr (*getShardingRule)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::sdy::ShardingRuleOpInterface;
    Model() : Concept{getShardingRule} {}

    static inline mlir::sdy::OpShardingRuleAttr getShardingRule(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::sdy::ShardingRuleOpInterface;
    FallbackModel() : Concept{getShardingRule} {}

    static inline mlir::sdy::OpShardingRuleAttr getShardingRule(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};
template <typename ConcreteOp>
struct ShardingRuleOpInterfaceTrait;

} // namespace detail
class ShardingRuleOpInterface : public ::mlir::OpInterface<ShardingRuleOpInterface, detail::ShardingRuleOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<ShardingRuleOpInterface, detail::ShardingRuleOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::ShardingRuleOpInterfaceTrait<ConcreteOp> {};
  /// Returns the sharding rule of the op.
  mlir::sdy::OpShardingRuleAttr getShardingRule();
};
namespace detail {
  template <typename ConcreteOp>
  struct ShardingRuleOpInterfaceTrait : public ::mlir::OpInterface<ShardingRuleOpInterface, detail::ShardingRuleOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
  };
}// namespace detail
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
class CollectiveOpInterface;
namespace detail {
struct CollectiveOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::mlir::sdy::TensorShardingAttr (*getOutSharding)(const Concept *impl, ::mlir::Operation *);
    void (*setOutShardingAttr)(const Concept *impl, ::mlir::Operation *, ::mlir::sdy::TensorShardingAttr);
    ::mlir::TypedValue<::mlir::TensorType> (*getTensor)(const Concept *impl, ::mlir::Operation *);
    ::mlir::Type (*getType)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::sdy::CollectiveOpInterface;
    Model() : Concept{getOutSharding, setOutShardingAttr, getTensor, getType} {}

    static inline ::mlir::sdy::TensorShardingAttr getOutSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline void setOutShardingAttr(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::sdy::TensorShardingAttr sharding);
    static inline ::mlir::TypedValue<::mlir::TensorType> getTensor(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::Type getType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::sdy::CollectiveOpInterface;
    FallbackModel() : Concept{getOutSharding, setOutShardingAttr, getTensor, getType} {}

    static inline ::mlir::sdy::TensorShardingAttr getOutSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline void setOutShardingAttr(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::sdy::TensorShardingAttr sharding);
    static inline ::mlir::TypedValue<::mlir::TensorType> getTensor(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::Type getType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};
template <typename ConcreteOp>
struct CollectiveOpInterfaceTrait;

} // namespace detail
class CollectiveOpInterface : public ::mlir::OpInterface<CollectiveOpInterface, detail::CollectiveOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<CollectiveOpInterface, detail::CollectiveOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::CollectiveOpInterfaceTrait<ConcreteOp> {};
  /// Returns the output tensor sharding of the collective op.
  ::mlir::sdy::TensorShardingAttr getOutSharding();
  /// Sets the output tensor sharding of the collective op.
  void setOutShardingAttr(::mlir::sdy::TensorShardingAttr sharding);
  /// Get the tensor operand of the collective op.
  ::mlir::TypedValue<::mlir::TensorType> getTensor();
  /// Get the type of the collective op result.
  ::mlir::Type getType();
};
namespace detail {
  template <typename ConcreteOp>
  struct CollectiveOpInterfaceTrait : public ::mlir::OpInterface<CollectiveOpInterface, detail::CollectiveOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    static ::llvm::LogicalResult verifyTrait(::mlir::Operation *op) {
      return ::mlir::sdy::verifyCollectiveOp(op);
    }
  };
}// namespace detail
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
template<typename ConcreteOp>
mlir::SmallVector<mlir::sdy::TensorShardingAttr> detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getBlockArgumentEdgeOwnerShardings();
}
template<typename ConcreteOp>
void detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::setBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).setBlockArgumentEdgeOwnerShardings(shardings);
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::sdy::TensorShardingAttr> detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOpResultEdgeOwnerShardings();
}
template<typename ConcreteOp>
void detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::setOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).setOpResultEdgeOwnerShardings(shardings);
}
template<typename ConcreteOp>
mlir::sdy::TensorShardingAttr detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::transformTargetSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).transformTargetSharding(target, sharding, transformType);
}
template<typename ConcreteOp>
mlir::ArrayRef<mlir::BlockArgument> detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getBlockArgumentEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getBlockArgumentEdgeOwners();
}
template<typename ConcreteOp>
mlir::ResultRange detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getOpResultEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOpResultEdgeOwners();
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::Value> detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getEdgeSources(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getEdgeSources(owner);
}
template<typename ConcreteOp>
mlir::Value detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getEdgeOwnerFromTarget(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getEdgeOwnerFromTarget(target);
}
template<typename ConcreteOp>
mlir::Value detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getEdgeOwnerFromSource(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::OpOperand& source) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getEdgeOwnerFromSource(source);
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::Value> detail::ShardableDataFlowOpInterfaceInterfaceTraits::Model<ConcreteOp>::getNonEdgeOwnerTargets(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getNonEdgeOwnerTargets(owner);
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::sdy::TensorShardingAttr> detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getBlockArgumentEdgeOwnerShardings(tablegen_opaque_val);
}
template<typename ConcreteOp>
void detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::setBlockArgumentEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) {
  return static_cast<const ConcreteOp *>(impl)->setBlockArgumentEdgeOwnerShardings(tablegen_opaque_val, shardings);
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::sdy::TensorShardingAttr> detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getOpResultEdgeOwnerShardings(tablegen_opaque_val);
}
template<typename ConcreteOp>
void detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::setOpResultEdgeOwnerShardings(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) {
  return static_cast<const ConcreteOp *>(impl)->setOpResultEdgeOwnerShardings(tablegen_opaque_val, shardings);
}
template<typename ConcreteOp>
mlir::sdy::TensorShardingAttr detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::transformTargetSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType) {
  return static_cast<const ConcreteOp *>(impl)->transformTargetSharding(tablegen_opaque_val, target, sharding, transformType);
}
template<typename ConcreteOp>
mlir::ArrayRef<mlir::BlockArgument> detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getBlockArgumentEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getBlockArgumentEdgeOwners(tablegen_opaque_val);
}
template<typename ConcreteOp>
mlir::ResultRange detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getOpResultEdgeOwners(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getOpResultEdgeOwners(tablegen_opaque_val);
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::Value> detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getEdgeSources(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner) {
  return static_cast<const ConcreteOp *>(impl)->getEdgeSources(tablegen_opaque_val, owner);
}
template<typename ConcreteOp>
mlir::Value detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getEdgeOwnerFromTarget(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value target) {
  return static_cast<const ConcreteOp *>(impl)->getEdgeOwnerFromTarget(tablegen_opaque_val, target);
}
template<typename ConcreteOp>
mlir::Value detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getEdgeOwnerFromSource(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::OpOperand& source) {
  return static_cast<const ConcreteOp *>(impl)->getEdgeOwnerFromSource(tablegen_opaque_val, source);
}
template<typename ConcreteOp>
mlir::SmallVector<mlir::Value> detail::ShardableDataFlowOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getNonEdgeOwnerTargets(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, mlir::Value owner) {
  return static_cast<const ConcreteOp *>(impl)->getNonEdgeOwnerTargets(tablegen_opaque_val, owner);
}
template<typename ConcreteModel, typename ConcreteOp>
mlir::SmallVector<mlir::sdy::TensorShardingAttr> detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getBlockArgumentEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val) const {
return {};
}
template<typename ConcreteModel, typename ConcreteOp>
void detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::setBlockArgumentEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) const {
return;
}
template<typename ConcreteModel, typename ConcreteOp>
mlir::SmallVector<mlir::sdy::TensorShardingAttr> detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getOpResultEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val) const {
return mlir::sdy::details::getOpResultEdgeOwnerShardingsImpl((llvm::cast<ConcreteOp>(tablegen_opaque_val)));
}
template<typename ConcreteModel, typename ConcreteOp>
void detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::setOpResultEdgeOwnerShardings(::mlir::Operation *tablegen_opaque_val, mlir::ArrayRef<mlir::sdy::TensorShardingAttr> shardings) const {
mlir::sdy::details::setOpResultEdgeOwnerShardingsImpl((llvm::cast<ConcreteOp>(tablegen_opaque_val)), shardings);
}
template<typename ConcreteModel, typename ConcreteOp>
mlir::sdy::TensorShardingAttr detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::transformTargetSharding(::mlir::Operation *tablegen_opaque_val, mlir::Value target, mlir::sdy::TensorShardingAttr sharding, mlir::sdy::DataFlowShardingTransformType transformType) const {
return sharding;
}
template<typename ConcreteModel, typename ConcreteOp>
mlir::ArrayRef<mlir::BlockArgument> detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getBlockArgumentEdgeOwners(::mlir::Operation *tablegen_opaque_val) const {
return {};
}
template<typename ConcreteModel, typename ConcreteOp>
mlir::SmallVector<mlir::Value> detail::ShardableDataFlowOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getNonEdgeOwnerTargets(::mlir::Operation *tablegen_opaque_val, mlir::Value owner) const {
return {};
}
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
template<typename ConcreteOp>
mlir::sdy::OpShardingRuleAttr detail::ShardingRuleOpInterfaceInterfaceTraits::Model<ConcreteOp>::getShardingRule(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getShardingRule();
}
template<typename ConcreteOp>
mlir::sdy::OpShardingRuleAttr detail::ShardingRuleOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getShardingRule(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getShardingRule(tablegen_opaque_val);
}
} // namespace sdy
} // namespace mlir
namespace mlir {
namespace sdy {
template<typename ConcreteOp>
::mlir::sdy::TensorShardingAttr detail::CollectiveOpInterfaceInterfaceTraits::Model<ConcreteOp>::getOutSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOutSharding();
}
template<typename ConcreteOp>
void detail::CollectiveOpInterfaceInterfaceTraits::Model<ConcreteOp>::setOutShardingAttr(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::sdy::TensorShardingAttr sharding) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).setOutShardingAttr(sharding);
}
template<typename ConcreteOp>
::mlir::TypedValue<::mlir::TensorType> detail::CollectiveOpInterfaceInterfaceTraits::Model<ConcreteOp>::getTensor(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getTensor();
}
template<typename ConcreteOp>
::mlir::Type detail::CollectiveOpInterfaceInterfaceTraits::Model<ConcreteOp>::getType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getType();
}
template<typename ConcreteOp>
::mlir::sdy::TensorShardingAttr detail::CollectiveOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getOutSharding(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getOutSharding(tablegen_opaque_val);
}
template<typename ConcreteOp>
void detail::CollectiveOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::setOutShardingAttr(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::sdy::TensorShardingAttr sharding) {
  return static_cast<const ConcreteOp *>(impl)->setOutShardingAttr(tablegen_opaque_val, sharding);
}
template<typename ConcreteOp>
::mlir::TypedValue<::mlir::TensorType> detail::CollectiveOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getTensor(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getTensor(tablegen_opaque_val);
}
template<typename ConcreteOp>
::mlir::Type detail::CollectiveOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getType(tablegen_opaque_val);
}
} // namespace sdy
} // namespace mlir
