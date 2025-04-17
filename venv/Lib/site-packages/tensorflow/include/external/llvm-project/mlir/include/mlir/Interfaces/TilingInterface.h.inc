/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
class TilingInterface;
namespace detail {
struct TilingInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::mlir::SmallVector<::mlir::utils::IteratorType> (*getLoopIteratorTypes)(const Concept *impl, ::mlir::Operation *);
    ::mlir::SmallVector<::mlir::Range> (*getIterationDomain)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &);
    ::mlir::FailureOr<::mlir::TilingResult> (*getTiledImplementation)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::ArrayRef<::mlir::OpFoldResult> );
    ::llvm::LogicalResult (*getResultTilePosition)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, unsigned, ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::SmallVector<::mlir::OpFoldResult> &, ::mlir::SmallVector<::mlir::OpFoldResult> &);
    ::mlir::FailureOr<::mlir::TilingResult> (*generateResultTileValue)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, unsigned, ::mlir::ArrayRef<::mlir::OpFoldResult>, ::mlir::ArrayRef<::mlir::OpFoldResult>);
    ::mlir::FailureOr<::mlir::TilingResult> (*getTiledImplementationFromOperandTile)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, unsigned, ::mlir::ArrayRef<::mlir::OpFoldResult>, ::mlir::ArrayRef<::mlir::OpFoldResult>);
    ::llvm::LogicalResult (*getIterationDomainTileFromOperandTile)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, unsigned, ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &);
    ::llvm::LogicalResult (*getIterationDomainTileFromResultTile)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, unsigned, ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &);
    ::llvm::LogicalResult (*generateScalarImplementation)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, ::mlir::Location , ::mlir::ValueRange );
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::TilingInterface;
    Model() : Concept{getLoopIteratorTypes, getIterationDomain, getTiledImplementation, getResultTilePosition, generateResultTileValue, getTiledImplementationFromOperandTile, getIterationDomainTileFromOperandTile, getIterationDomainTileFromResultTile, generateScalarImplementation} {}

    static inline ::mlir::SmallVector<::mlir::utils::IteratorType> getLoopIteratorTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::SmallVector<::mlir::Range> getIterationDomain(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b);
    static inline ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes);
    static inline ::llvm::LogicalResult getResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes);
    static inline ::mlir::FailureOr<::mlir::TilingResult> generateResultTileValue(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes);
    static inline ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementationFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes);
    static inline ::llvm::LogicalResult getIterationDomainTileFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes);
    static inline ::llvm::LogicalResult getIterationDomainTileFromResultTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes);
    static inline ::llvm::LogicalResult generateScalarImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::Location  loc, ::mlir::ValueRange  ivs);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::TilingInterface;
    FallbackModel() : Concept{getLoopIteratorTypes, getIterationDomain, getTiledImplementation, getResultTilePosition, generateResultTileValue, getTiledImplementationFromOperandTile, getIterationDomainTileFromOperandTile, getIterationDomainTileFromResultTile, generateScalarImplementation} {}

    static inline ::mlir::SmallVector<::mlir::utils::IteratorType> getLoopIteratorTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::mlir::SmallVector<::mlir::Range> getIterationDomain(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b);
    static inline ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes);
    static inline ::llvm::LogicalResult getResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes);
    static inline ::mlir::FailureOr<::mlir::TilingResult> generateResultTileValue(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes);
    static inline ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementationFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes);
    static inline ::llvm::LogicalResult getIterationDomainTileFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes);
    static inline ::llvm::LogicalResult getIterationDomainTileFromResultTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes);
    static inline ::llvm::LogicalResult generateScalarImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::Location  loc, ::mlir::ValueRange  ivs);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
    ::mlir::SmallVector<::mlir::utils::IteratorType> getLoopIteratorTypes(::mlir::Operation *tablegen_opaque_val) const;
    ::mlir::SmallVector<::mlir::Range> getIterationDomain(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b) const;
    ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementation(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) const;
    ::llvm::LogicalResult getResultTilePosition(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVector<::mlir::OpFoldResult> &resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> &resultSizes) const;
    ::mlir::FailureOr<::mlir::TilingResult> generateResultTileValue(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) const;
    ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementationFromOperandTile(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) const;
    ::llvm::LogicalResult getIterationDomainTileFromOperandTile(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainSizes) const;
    ::llvm::LogicalResult getIterationDomainTileFromResultTile(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainSizes) const;
    ::llvm::LogicalResult generateScalarImplementation(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, ::mlir::Location loc, ::mlir::ValueRange ivs) const;
  };
};
template <typename ConcreteOp>
struct TilingInterfaceTrait;

} // namespace detail
class TilingInterface : public ::mlir::OpInterface<TilingInterface, detail::TilingInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<TilingInterface, detail::TilingInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::TilingInterfaceTrait<ConcreteOp> {};
  /// Returns a list of iterator types that describe the number of loops.
  ::mlir::SmallVector<::mlir::utils::IteratorType> getLoopIteratorTypes();
  /// Returns a list of ranges that describe the loop bounds and
  /// step for the loops of the operation.
  ::mlir::SmallVector<::mlir::Range> getIterationDomain(::mlir::OpBuilder & b);
  /// Method to generate the tiled implementation of an operation.
  /// 
  /// Given a tile of the iteration space (as returned by
  /// `getIterationDomain`), generate in-place the code that represents
  /// the computation corresponding to that tile of the iteration space.
  /// It is the responsibility of the implementation of this method in
  /// the operation to generate the slices of the operands needed for the
  /// tiled implementation.
  /// - `offsets` provides the offset of the tile in the coordinate system
  ///   of the original iteration space, i.e., if an iteration space
  ///   dimension had non-zero offset, it will be included in the offset
  ///   provided here (as opposed to zero-based offset "relative" to the
  ///   iteration space).
  /// - `sizes` provides the size of the tile.
  /// 
  /// The returned `TilingResult` must return for each result of the
  /// untiled operation, a `Value` that is the result of the tiled
  /// operation.
  ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementation(::mlir::OpBuilder & b, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes);
  /// Method to return the position of the result tile computed by the
  /// tiled operation.
  /// 
  /// For operations that return a value (typically a value of type
  /// `RankedTensorType`), the generated tiled computation has to also
  /// recompute a replacement for the results of the original operation.
  /// The tiled implementation of the operation returns a tile of the
  /// result(s). This methods returns information about what part of the
  /// result tensor is computed by the tiled implementation. The manner in
  /// which these tiles get put together to get the final result is upto
  /// the surrounding loop construct. If an operation has no results, (for
  /// example an operation that operates only on memrefs), then this method
  /// need not be implemented by the operation.
  /// - `resultNumber` is the result number of the original operation
  ///   being processed.
  /// - `offsets` provides the offset of the tile in the coordinate system
  ///   of the original iteration space, i.e., if an iteration space
  ///   dimension had non-zero offset, it will be included in the offset
  ///   provided here (as opposed to zero-based offset "relative" to the
  ///   iteration space).
  /// - `sizes` provides the size of the tile.
  /// - `resultOffsets` is the offsets of the tile of the result generated
  ///   by the tiled implementation (returned by value).
  /// - `resultSizes` is the size of the tile of the result generated
  ///   by the tiled implementation (returned by value).
  /// 
  /// Note: It is undefined behaviour if there is overlap between the
  /// tiles of the result generated by the tiled implementation.
  ::llvm::LogicalResult getResultTilePosition(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes);
  /// Method to generate the code that produces a tile of the result.
  /// 
  /// This method is required to allow operations to be "tiled and fused"
  /// with an (already tiled) consumer. Typically, for two operations with
  /// producer -> consumer relation ship, to compute a tile of the
  /// consumer a `slice` of the producer is needed. This method allows
  /// computing that slice of the producer in-place, thereby "fusing"
  /// the operations at tile-granularity. This method is different from
  /// `getTiledImplementation`, which produces a tiled implementation
  /// for a tile of the iteration space. This method produces a tiled
  /// implementation based on the tile of producer required.
  /// - `resultNumber` is the result of the producer used by the consumer.
  /// - `offsets` is the offset of the slice of the producer result used by
  ///   the tiled implementation of the consumer.
  /// - `sizes` is the size of the slice of the producer result used by the
  ///   consumer.
  /// If fusion of the producer with the consumer is not legal for the
  /// operation/result, this method should return failure.
  /// 
  /// Note: This method only deals with the mechanism of implementing the
  /// fusion. In general the fusion might result in recomputation (based on
  /// the way the result is produced by the producer and the access pattern
  /// used in the consumer to access). This is upto the caller to handle
  /// appropriately.
  ::mlir::FailureOr<::mlir::TilingResult> generateResultTileValue(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes);
  /// Method to generate the tiled implementation of an operation that uses
  /// exactly a tile of the given operand.
  /// 
  /// This method is required to allow operations to be "tiled and fused"
  /// with an (already tiled) producer. Given a tile of the producer, this
  /// method generates the tile of the consumer that uses exactly this
  /// produced tile. In some sense it is the "reverse" of
  /// `generateResultTileValue`.
  /// - `operandNumber` is the result of the producer used by the consumer.
  /// - `offsets` is the offset of the slice of the producer result used by
  ///   the tiled implementation of the consumer.
  /// - `sizes` is the size of the slice of the producer result used by the
  ///   consumer.
  /// If it is illegal to fuse with a producer along the given operand for
  /// an operation, the implementation should return a failure.
  ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementationFromOperandTile(::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes);
  /// Method to return the tile of the iteration domain that uses a given
  /// tile of the operand.
  /// 
  /// This method is required to allow operations to be "tiled and fused"
  /// with an (already tiled) producer. Given a tile of an operand,
  /// returns the tile of the iteration space that uses this tile.
  /// - `operandNumber` is the result of the producer used by the consumer.
  /// - `offsets` is the offset of the slice of the producer result used by
  ///   the tiled implementation of the consumer.
  /// - `sizes` is the size of the slice of the producer result used by the
  ///   consumer.
  /// If it is illegal to fuse with a producer along the given operand for
  /// an operation, or if this mapping cannot be computed, the
  /// implementation should return a failure.
  /// 
  /// Note that unlike the "tile consumer and fuse producer" case, the
  /// "tile producer and fuse consumer" requires an additional method to get
  /// the iteration tile space that encompasses all uses of the given operand
  /// tile. The reason for this is, consider
  /// ```mlir
  /// %1 = scf.for...  {
  ///   %2 = <tiled_producer_op>
  ///   %3 = tensor.insert_slice %2 into ...
  ///   scf.yield %3
  /// }
  /// %4 = <consumer_op>)(... %1... )
  /// ... <some_op>(... %4 ...)
  /// ```
  /// 
  /// when fused this becomes
  /// ```
  /// %1 = scf.for...  {
  ///   %2 = <tiled_producer_op>
  ///   %3 = <tiled_consumer_op>(... %2...)
  ///   %4 = tensor.insert_slice %3 into ...
  ///   scf.yield %4
  /// }
  /// ... <some_op>(... %1 ...)
  /// ```
  /// 
  /// i.e, when fusing the consumer, the replacement for the result of the
  /// consumer needs to be returned to replace the uses of the consumer.
  /// For the tile+fuse algorithm to do this it needs information about
  /// which tile of the iteration space encompasses all uses of the tile
  /// produced and use that to compute what are the results produced. Note
  /// that this iteration space might be the entire iteration space of the
  /// operation, or multiple operand tiles might map to intersecting
  /// iteration spaces. It is upto the caller to make sure that it is still
  /// fusable with producer in this scenario, or it must return a failure.
  /// 
  /// Note that this method is only used as a way to implement the
  /// transformation. It does not provide guarantees on whether such a
  /// transformation is profitable.
  /// 
  /// For most cases `getTiledImplementationFromOperandTile` could be a
  /// implemented using `getIterationDomainTileFromOperandTile` +
  /// `getTiledImplementation` methods.
  ::llvm::LogicalResult getIterationDomainTileFromOperandTile(::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes);
  /// Method to return the tile of the iteration domain based
  /// on the given tile of the certain result.
  /// 
  /// This method is required to allow operations to be "tiled and fused"
  /// with an (already tiled) consumer. Given a tile of an result,
  /// returns the tile of the iteration space that uses this tile.
  /// - `resultNumber` is the result of the producer used by the consumer.
  /// - `offsets` is the offset of the slice of the producer result used by
  ///   the tiled implementation of the consumer.
  /// - `sizes` is the size of the slice of the producer result used by the
  ///   consumer.
  /// If fusion of the producer with the consumer is not legal for the
  /// result, or if this mapping cannot be computed, the implementation
  /// should return a failure.
  /// 
  /// For most cases `generateResultTileValue` could be a implemented using
  /// `getIterationDomainTileFromResultTile` + `getTiledImplementation`
  /// methods.
  ::llvm::LogicalResult getIterationDomainTileFromResultTile(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes);
  /// Generates the scalar implementation of the operation.
  /// 
  /// Given the list `ivs` that represent points in the iteration space
  /// (as specified by `getIterationDomain()`) returns the scalar operations
  /// that represent the computation at that point in the iteration space.
  /// This method is typically used as the "exit path", i.e. once all
  /// transformations are done, this method can be used to lower to scalar
  /// code that can then be lowered to LLVM or SPIR-V dialects.
  ::llvm::LogicalResult generateScalarImplementation(::mlir::OpBuilder & b, ::mlir::Location  loc, ::mlir::ValueRange  ivs);
};
namespace detail {
  template <typename ConcreteOp>
  struct TilingInterfaceTrait : public ::mlir::OpInterface<TilingInterface, detail::TilingInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    /// Returns a list of iterator types that describe the number of loops.
    ::mlir::SmallVector<::mlir::utils::IteratorType> getLoopIteratorTypes() {
      return {};
    }
    /// Returns a list of ranges that describe the loop bounds and
    /// step for the loops of the operation.
    ::mlir::SmallVector<::mlir::Range> getIterationDomain(::mlir::OpBuilder & b) {
      return {};
    }
    /// Method to generate the tiled implementation of an operation.
    /// 
    /// Given a tile of the iteration space (as returned by
    /// `getIterationDomain`), generate in-place the code that represents
    /// the computation corresponding to that tile of the iteration space.
    /// It is the responsibility of the implementation of this method in
    /// the operation to generate the slices of the operands needed for the
    /// tiled implementation.
    /// - `offsets` provides the offset of the tile in the coordinate system
    ///   of the original iteration space, i.e., if an iteration space
    ///   dimension had non-zero offset, it will be included in the offset
    ///   provided here (as opposed to zero-based offset "relative" to the
    ///   iteration space).
    /// - `sizes` provides the size of the tile.
    /// 
    /// The returned `TilingResult` must return for each result of the
    /// untiled operation, a `Value` that is the result of the tiled
    /// operation.
    ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementation(::mlir::OpBuilder & b, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes) {
      return {};
    }
    /// Method to return the position of the result tile computed by the
    /// tiled operation.
    /// 
    /// For operations that return a value (typically a value of type
    /// `RankedTensorType`), the generated tiled computation has to also
    /// recompute a replacement for the results of the original operation.
    /// The tiled implementation of the operation returns a tile of the
    /// result(s). This methods returns information about what part of the
    /// result tensor is computed by the tiled implementation. The manner in
    /// which these tiles get put together to get the final result is upto
    /// the surrounding loop construct. If an operation has no results, (for
    /// example an operation that operates only on memrefs), then this method
    /// need not be implemented by the operation.
    /// - `resultNumber` is the result number of the original operation
    ///   being processed.
    /// - `offsets` provides the offset of the tile in the coordinate system
    ///   of the original iteration space, i.e., if an iteration space
    ///   dimension had non-zero offset, it will be included in the offset
    ///   provided here (as opposed to zero-based offset "relative" to the
    ///   iteration space).
    /// - `sizes` provides the size of the tile.
    /// - `resultOffsets` is the offsets of the tile of the result generated
    ///   by the tiled implementation (returned by value).
    /// - `resultSizes` is the size of the tile of the result generated
    ///   by the tiled implementation (returned by value).
    /// 
    /// Note: It is undefined behaviour if there is overlap between the
    /// tiles of the result generated by the tiled implementation.
    ::llvm::LogicalResult getResultTilePosition(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes) {
      return failure();
    }
    /// Method to generate the code that produces a tile of the result.
    /// 
    /// This method is required to allow operations to be "tiled and fused"
    /// with an (already tiled) consumer. Typically, for two operations with
    /// producer -> consumer relation ship, to compute a tile of the
    /// consumer a `slice` of the producer is needed. This method allows
    /// computing that slice of the producer in-place, thereby "fusing"
    /// the operations at tile-granularity. This method is different from
    /// `getTiledImplementation`, which produces a tiled implementation
    /// for a tile of the iteration space. This method produces a tiled
    /// implementation based on the tile of producer required.
    /// - `resultNumber` is the result of the producer used by the consumer.
    /// - `offsets` is the offset of the slice of the producer result used by
    ///   the tiled implementation of the consumer.
    /// - `sizes` is the size of the slice of the producer result used by the
    ///   consumer.
    /// If fusion of the producer with the consumer is not legal for the
    /// operation/result, this method should return failure.
    /// 
    /// Note: This method only deals with the mechanism of implementing the
    /// fusion. In general the fusion might result in recomputation (based on
    /// the way the result is produced by the producer and the access pattern
    /// used in the consumer to access). This is upto the caller to handle
    /// appropriately.
    ::mlir::FailureOr<::mlir::TilingResult> generateResultTileValue(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) {
      return failure();
    }
    /// Method to generate the tiled implementation of an operation that uses
    /// exactly a tile of the given operand.
    /// 
    /// This method is required to allow operations to be "tiled and fused"
    /// with an (already tiled) producer. Given a tile of the producer, this
    /// method generates the tile of the consumer that uses exactly this
    /// produced tile. In some sense it is the "reverse" of
    /// `generateResultTileValue`.
    /// - `operandNumber` is the result of the producer used by the consumer.
    /// - `offsets` is the offset of the slice of the producer result used by
    ///   the tiled implementation of the consumer.
    /// - `sizes` is the size of the slice of the producer result used by the
    ///   consumer.
    /// If it is illegal to fuse with a producer along the given operand for
    /// an operation, the implementation should return a failure.
    ::mlir::FailureOr<::mlir::TilingResult> getTiledImplementationFromOperandTile(::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) {
      return failure();
    }
    /// Method to return the tile of the iteration domain that uses a given
    /// tile of the operand.
    /// 
    /// This method is required to allow operations to be "tiled and fused"
    /// with an (already tiled) producer. Given a tile of an operand,
    /// returns the tile of the iteration space that uses this tile.
    /// - `operandNumber` is the result of the producer used by the consumer.
    /// - `offsets` is the offset of the slice of the producer result used by
    ///   the tiled implementation of the consumer.
    /// - `sizes` is the size of the slice of the producer result used by the
    ///   consumer.
    /// If it is illegal to fuse with a producer along the given operand for
    /// an operation, or if this mapping cannot be computed, the
    /// implementation should return a failure.
    /// 
    /// Note that unlike the "tile consumer and fuse producer" case, the
    /// "tile producer and fuse consumer" requires an additional method to get
    /// the iteration tile space that encompasses all uses of the given operand
    /// tile. The reason for this is, consider
    /// ```mlir
    /// %1 = scf.for...  {
    ///   %2 = <tiled_producer_op>
    ///   %3 = tensor.insert_slice %2 into ...
    ///   scf.yield %3
    /// }
    /// %4 = <consumer_op>)(... %1... )
    /// ... <some_op>(... %4 ...)
    /// ```
    /// 
    /// when fused this becomes
    /// ```
    /// %1 = scf.for...  {
    ///   %2 = <tiled_producer_op>
    ///   %3 = <tiled_consumer_op>(... %2...)
    ///   %4 = tensor.insert_slice %3 into ...
    ///   scf.yield %4
    /// }
    /// ... <some_op>(... %1 ...)
    /// ```
    /// 
    /// i.e, when fusing the consumer, the replacement for the result of the
    /// consumer needs to be returned to replace the uses of the consumer.
    /// For the tile+fuse algorithm to do this it needs information about
    /// which tile of the iteration space encompasses all uses of the tile
    /// produced and use that to compute what are the results produced. Note
    /// that this iteration space might be the entire iteration space of the
    /// operation, or multiple operand tiles might map to intersecting
    /// iteration spaces. It is upto the caller to make sure that it is still
    /// fusable with producer in this scenario, or it must return a failure.
    /// 
    /// Note that this method is only used as a way to implement the
    /// transformation. It does not provide guarantees on whether such a
    /// transformation is profitable.
    /// 
    /// For most cases `getTiledImplementationFromOperandTile` could be a
    /// implemented using `getIterationDomainTileFromOperandTile` +
    /// `getTiledImplementation` methods.
    ::llvm::LogicalResult getIterationDomainTileFromOperandTile(::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes) {
      return failure();
    }
    /// Method to return the tile of the iteration domain based
    /// on the given tile of the certain result.
    /// 
    /// This method is required to allow operations to be "tiled and fused"
    /// with an (already tiled) consumer. Given a tile of an result,
    /// returns the tile of the iteration space that uses this tile.
    /// - `resultNumber` is the result of the producer used by the consumer.
    /// - `offsets` is the offset of the slice of the producer result used by
    ///   the tiled implementation of the consumer.
    /// - `sizes` is the size of the slice of the producer result used by the
    ///   consumer.
    /// If fusion of the producer with the consumer is not legal for the
    /// result, or if this mapping cannot be computed, the implementation
    /// should return a failure.
    /// 
    /// For most cases `generateResultTileValue` could be a implemented using
    /// `getIterationDomainTileFromResultTile` + `getTiledImplementation`
    /// methods.
    ::llvm::LogicalResult getIterationDomainTileFromResultTile(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes) {
      return failure();
    }
    /// Generates the scalar implementation of the operation.
    /// 
    /// Given the list `ivs` that represent points in the iteration space
    /// (as specified by `getIterationDomain()`) returns the scalar operations
    /// that represent the computation at that point in the iteration space.
    /// This method is typically used as the "exit path", i.e. once all
    /// transformations are done, this method can be used to lower to scalar
    /// code that can then be lowered to LLVM or SPIR-V dialects.
    ::llvm::LogicalResult generateScalarImplementation(::mlir::OpBuilder & b, ::mlir::Location  loc, ::mlir::ValueRange  ivs) {
      return failure();
    }
  };
}// namespace detail
} // namespace mlir
namespace mlir {
class PartialReductionOpInterface;
namespace detail {
struct PartialReductionOpInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    ::mlir::FailureOr<SmallVector<Value>> (*generateInitialTensorForPartialReduction)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, Location, ::mlir::ArrayRef<::mlir::OpFoldResult>, ::mlir::ArrayRef<int>);
    ::mlir::FailureOr<TilingResult> (*tileToPartialReduction)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, Location , ValueRange, ::mlir::ArrayRef<::mlir::OpFoldResult>, ::mlir::ArrayRef<::mlir::OpFoldResult>, ::mlir::ArrayRef<int>);
    ::mlir::FailureOr<MergeResult> (*mergeReductions)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, Location , ValueRange, ::mlir::ArrayRef<int>);
    ::llvm::LogicalResult (*getPartialResultTilePosition)(const Concept *impl, ::mlir::Operation *, ::mlir::OpBuilder &, unsigned, ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::ArrayRef<::mlir::OpFoldResult> , ::mlir::SmallVector<::mlir::OpFoldResult> &, ::mlir::SmallVector<::mlir::OpFoldResult> &, ::mlir::ArrayRef<int>);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::PartialReductionOpInterface;
    Model() : Concept{generateInitialTensorForPartialReduction, tileToPartialReduction, mergeReductions, getPartialResultTilePosition} {}

    static inline ::mlir::FailureOr<SmallVector<Value>> generateInitialTensorForPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim);
    static inline ::mlir::FailureOr<TilingResult> tileToPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims);
    static inline ::mlir::FailureOr<MergeResult> mergeReductions(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim);
    static inline ::llvm::LogicalResult getPartialResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes, ::mlir::ArrayRef<int> reductionDims);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::PartialReductionOpInterface;
    FallbackModel() : Concept{generateInitialTensorForPartialReduction, tileToPartialReduction, mergeReductions, getPartialResultTilePosition} {}

    static inline ::mlir::FailureOr<SmallVector<Value>> generateInitialTensorForPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim);
    static inline ::mlir::FailureOr<TilingResult> tileToPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims);
    static inline ::mlir::FailureOr<MergeResult> mergeReductions(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim);
    static inline ::llvm::LogicalResult getPartialResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes, ::mlir::ArrayRef<int> reductionDims);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
    ::mlir::FailureOr<SmallVector<Value>> generateInitialTensorForPartialReduction(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim) const;
    ::mlir::FailureOr<TilingResult> tileToPartialReduction(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, Location loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims) const;
    ::mlir::FailureOr<MergeResult> mergeReductions(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, Location loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim) const;
    ::llvm::LogicalResult getPartialResultTilePosition(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVector<::mlir::OpFoldResult> &resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> &resultSizes, ::mlir::ArrayRef<int> reductionDims) const;
  };
};
template <typename ConcreteOp>
struct PartialReductionOpInterfaceTrait;

} // namespace detail
class PartialReductionOpInterface : public ::mlir::OpInterface<PartialReductionOpInterface, detail::PartialReductionOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<PartialReductionOpInterface, detail::PartialReductionOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::PartialReductionOpInterfaceTrait<ConcreteOp> {};
  /// Method to generate a tensor initalized with the identity value of the
  /// operation reduction. The tensor shape is equal to operation result
  /// shape with new dimension for each non zero tile size.
  ::mlir::FailureOr<SmallVector<Value>> generateInitialTensorForPartialReduction(::mlir::OpBuilder & b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim);
  /// Method to generate a tiled version of the operation where the tiled
  /// reduction dimension are converted to parallel dimensions with a size
  /// less or equal to the tile size. This is meant to be used with
  /// `mergeReductions` method which will combine the partial reductions.
  ::mlir::FailureOr<TilingResult> tileToPartialReduction(::mlir::OpBuilder & b, Location  loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims);
  /// Method to merge partial reductions for an operation that has been
  /// tiled along the reduction dimensions. This will only apply the
  /// reduction the operation.
  ::mlir::FailureOr<MergeResult> mergeReductions(::mlir::OpBuilder & b, Location  loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim);
  /// Method to return the position of the partial result tile computed by
  /// the tiled operation. This is same as
  /// TilingInterface:::getResultTilePosition, but determines the result
  /// tile position for partial reduction.
  ::llvm::LogicalResult getPartialResultTilePosition(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes, ::mlir::ArrayRef<int> reductionDims);
};
namespace detail {
  template <typename ConcreteOp>
  struct PartialReductionOpInterfaceTrait : public ::mlir::OpInterface<PartialReductionOpInterface, detail::PartialReductionOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    /// Method to generate a tensor initalized with the identity value of the
    /// operation reduction. The tensor shape is equal to operation result
    /// shape with new dimension for each non zero tile size.
    ::mlir::FailureOr<SmallVector<Value>> generateInitialTensorForPartialReduction(::mlir::OpBuilder & b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim) {
      return failure();
    }
    /// Method to generate a tiled version of the operation where the tiled
    /// reduction dimension are converted to parallel dimensions with a size
    /// less or equal to the tile size. This is meant to be used with
    /// `mergeReductions` method which will combine the partial reductions.
    ::mlir::FailureOr<TilingResult> tileToPartialReduction(::mlir::OpBuilder & b, Location  loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims) {
      return failure();
    }
    /// Method to merge partial reductions for an operation that has been
    /// tiled along the reduction dimensions. This will only apply the
    /// reduction the operation.
    ::mlir::FailureOr<MergeResult> mergeReductions(::mlir::OpBuilder & b, Location  loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim) {
      return failure();
    }
    /// Method to return the position of the partial result tile computed by
    /// the tiled operation. This is same as
    /// TilingInterface:::getResultTilePosition, but determines the result
    /// tile position for partial reduction.
    ::llvm::LogicalResult getPartialResultTilePosition(::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes, ::mlir::ArrayRef<int> reductionDims) {
      return failure();
    }
  };
}// namespace detail
} // namespace mlir
namespace mlir {
template<typename ConcreteOp>
::mlir::SmallVector<::mlir::utils::IteratorType> detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getLoopIteratorTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getLoopIteratorTypes();
}
template<typename ConcreteOp>
::mlir::SmallVector<::mlir::Range> detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getIterationDomain(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getIterationDomain(b);
}
template<typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getTiledImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getTiledImplementation(b, offsets, sizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getResultTilePosition(b, resultNumber, offsets, sizes, resultOffsets, resultSizes);
}
template<typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::generateResultTileValue(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).generateResultTileValue(b, resultNumber, offsets, sizes);
}
template<typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getTiledImplementationFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getTiledImplementationFromOperandTile(b, operandNumber, offsets, sizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getIterationDomainTileFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getIterationDomainTileFromOperandTile(b, operandNumber, offsets, sizes, iterDomainOffsets, iterDomainSizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::getIterationDomainTileFromResultTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getIterationDomainTileFromResultTile(b, resultNumber, offsets, sizes, iterDomainOffsets, iterDomainSizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::Model<ConcreteOp>::generateScalarImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::Location  loc, ::mlir::ValueRange  ivs) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).generateScalarImplementation(b, loc, ivs);
}
template<typename ConcreteOp>
::mlir::SmallVector<::mlir::utils::IteratorType> detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getLoopIteratorTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getLoopIteratorTypes(tablegen_opaque_val);
}
template<typename ConcreteOp>
::mlir::SmallVector<::mlir::Range> detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getIterationDomain(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b) {
  return static_cast<const ConcreteOp *>(impl)->getIterationDomain(tablegen_opaque_val, b);
}
template<typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getTiledImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes) {
  return static_cast<const ConcreteOp *>(impl)->getTiledImplementation(tablegen_opaque_val, b, offsets, sizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes) {
  return static_cast<const ConcreteOp *>(impl)->getResultTilePosition(tablegen_opaque_val, b, resultNumber, offsets, sizes, resultOffsets, resultSizes);
}
template<typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::generateResultTileValue(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) {
  return static_cast<const ConcreteOp *>(impl)->generateResultTileValue(tablegen_opaque_val, b, resultNumber, offsets, sizes);
}
template<typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getTiledImplementationFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) {
  return static_cast<const ConcreteOp *>(impl)->getTiledImplementationFromOperandTile(tablegen_opaque_val, b, operandNumber, offsets, sizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getIterationDomainTileFromOperandTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes) {
  return static_cast<const ConcreteOp *>(impl)->getIterationDomainTileFromOperandTile(tablegen_opaque_val, b, operandNumber, offsets, sizes, iterDomainOffsets, iterDomainSizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getIterationDomainTileFromResultTile(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> & iterDomainSizes) {
  return static_cast<const ConcreteOp *>(impl)->getIterationDomainTileFromResultTile(tablegen_opaque_val, b, resultNumber, offsets, sizes, iterDomainOffsets, iterDomainSizes);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::generateScalarImplementation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, ::mlir::Location  loc, ::mlir::ValueRange  ivs) {
  return static_cast<const ConcreteOp *>(impl)->generateScalarImplementation(tablegen_opaque_val, b, loc, ivs);
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::SmallVector<::mlir::utils::IteratorType> detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getLoopIteratorTypes(::mlir::Operation *tablegen_opaque_val) const {
return {};
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::SmallVector<::mlir::Range> detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getIterationDomain(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b) const {
return {};
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getTiledImplementation(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) const {
return {};
}
template<typename ConcreteModel, typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getResultTilePosition(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVector<::mlir::OpFoldResult> &resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> &resultSizes) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::generateResultTileValue(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::FailureOr<::mlir::TilingResult> detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getTiledImplementationFromOperandTile(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getIterationDomainTileFromOperandTile(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned operandNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainSizes) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getIterationDomainTileFromResultTile(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainOffsets, ::mlir::SmallVectorImpl<::mlir::OpFoldResult> &iterDomainSizes) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::llvm::LogicalResult detail::TilingInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::generateScalarImplementation(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, ::mlir::Location loc, ::mlir::ValueRange ivs) const {
return failure();
}
} // namespace mlir
namespace mlir {
template<typename ConcreteOp>
::mlir::FailureOr<SmallVector<Value>> detail::PartialReductionOpInterfaceInterfaceTraits::Model<ConcreteOp>::generateInitialTensorForPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).generateInitialTensorForPartialReduction(b, loc, sizes, reductionDim);
}
template<typename ConcreteOp>
::mlir::FailureOr<TilingResult> detail::PartialReductionOpInterfaceInterfaceTraits::Model<ConcreteOp>::tileToPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).tileToPartialReduction(b, loc, init, offsets, sizes, reductionDims);
}
template<typename ConcreteOp>
::mlir::FailureOr<MergeResult> detail::PartialReductionOpInterfaceInterfaceTraits::Model<ConcreteOp>::mergeReductions(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).mergeReductions(b, loc, partialReduce, reductionDim);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::PartialReductionOpInterfaceInterfaceTraits::Model<ConcreteOp>::getPartialResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes, ::mlir::ArrayRef<int> reductionDims) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getPartialResultTilePosition(b, resultNumber, offsets, sizes, resultOffsets, resultSizes, reductionDims);
}
template<typename ConcreteOp>
::mlir::FailureOr<SmallVector<Value>> detail::PartialReductionOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::generateInitialTensorForPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim) {
  return static_cast<const ConcreteOp *>(impl)->generateInitialTensorForPartialReduction(tablegen_opaque_val, b, loc, sizes, reductionDim);
}
template<typename ConcreteOp>
::mlir::FailureOr<TilingResult> detail::PartialReductionOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::tileToPartialReduction(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims) {
  return static_cast<const ConcreteOp *>(impl)->tileToPartialReduction(tablegen_opaque_val, b, loc, init, offsets, sizes, reductionDims);
}
template<typename ConcreteOp>
::mlir::FailureOr<MergeResult> detail::PartialReductionOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::mergeReductions(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, Location  loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim) {
  return static_cast<const ConcreteOp *>(impl)->mergeReductions(tablegen_opaque_val, b, loc, partialReduce, reductionDim);
}
template<typename ConcreteOp>
::llvm::LogicalResult detail::PartialReductionOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getPartialResultTilePosition(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder & b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult>  offsets, ::mlir::ArrayRef<::mlir::OpFoldResult>  sizes, ::mlir::SmallVector<::mlir::OpFoldResult> & resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> & resultSizes, ::mlir::ArrayRef<int> reductionDims) {
  return static_cast<const ConcreteOp *>(impl)->getPartialResultTilePosition(tablegen_opaque_val, b, resultNumber, offsets, sizes, resultOffsets, resultSizes, reductionDims);
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::FailureOr<SmallVector<Value>> detail::PartialReductionOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::generateInitialTensorForPartialReduction(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, Location loc, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDim) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::FailureOr<TilingResult> detail::PartialReductionOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::tileToPartialReduction(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, Location loc, ValueRange init, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::ArrayRef<int> reductionDims) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::mlir::FailureOr<MergeResult> detail::PartialReductionOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::mergeReductions(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, Location loc, ValueRange partialReduce, ::mlir::ArrayRef<int> reductionDim) const {
return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
::llvm::LogicalResult detail::PartialReductionOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getPartialResultTilePosition(::mlir::Operation *tablegen_opaque_val, ::mlir::OpBuilder &b, unsigned resultNumber, ::mlir::ArrayRef<::mlir::OpFoldResult> offsets, ::mlir::ArrayRef<::mlir::OpFoldResult> sizes, ::mlir::SmallVector<::mlir::OpFoldResult> &resultOffsets, ::mlir::SmallVector<::mlir::OpFoldResult> &resultSizes, ::mlir::ArrayRef<int> reductionDims) const {
return failure();
}
} // namespace mlir
