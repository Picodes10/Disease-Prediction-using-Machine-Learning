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
namespace sdy {
class ManualAxesAttr;
class MeshAxisAttr;
class MeshAttr;
class SubAxisInfoAttr;
class AxisRefAttr;
class DimensionShardingAttr;
class TensorShardingAttr;
class TensorShardingPerValueAttr;
class DimMappingAttr;
class TensorMappingAttr;
class OpShardingRuleAttr;
class AxisRefListAttr;
class ListOfAxisRefListsAttr;
namespace detail {
struct ManualAxesAttrStorage;
} // namespace detail
class ManualAxesAttr : public ::mlir::Attribute::AttrBase<ManualAxesAttr, ::mlir::Attribute, detail::ManualAxesAttrStorage> {
public:
  using Base::Base;
  auto begin() const { return getValue().begin(); }
  auto end() const { return getValue().end(); }
  bool empty() const { return getValue().empty(); }
  size_t size() const { return getValue().size(); }
  auto &front() const { return getValue().front(); }
  auto &back() const { return getValue().back(); }
  auto &operator[](size_t index) { return getValue()[index]; }
  operator ::llvm::ArrayRef<StringAttr>() const { return getValue(); }
  static constexpr ::llvm::StringLiteral name = "sdy.manual_axes";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static ManualAxesAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<StringAttr> value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"manual_axes"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<StringAttr> getValue() const;
};
namespace detail {
struct MeshAxisAttrStorage;
} // namespace detail
class MeshAxisAttr : public ::mlir::Attribute::AttrBase<MeshAxisAttr, ::mlir::Attribute, detail::MeshAxisAttrStorage> {
public:
  using Base::Base;
  static constexpr ::llvm::StringLiteral name = "sdy.mesh_axis";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  using Base::getChecked;
  static MeshAxisAttr get(::mlir::MLIRContext *context, ::llvm::StringRef name, int64_t size);
  static MeshAxisAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::StringRef name, int64_t size);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::StringRef name, int64_t size);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::StringRef name, int64_t size);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"mesh_axis"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::StringRef getName() const;
  int64_t getSize() const;
};
namespace detail {
struct MeshAttrStorage;
} // namespace detail
class MeshAttr : public ::mlir::Attribute::AttrBase<MeshAttr, ::mlir::Attribute, detail::MeshAttrStorage> {
public:
  using Base::Base;
  // Returns true if this mesh has no axes or device ids.
  bool empty() const;

  // Returns true if this mesh has an axis with the given `axisName`.
  bool hasAxis(StringRef axisName) const;

  // Returns the size of the axis with the given `axisName`.
  //
  // Assumes the axis is present in the mesh.
  int64_t getAxisSize(StringRef axisName) const;

  // Returns the total size of the mesh across all axes, as in the total
  // number of devices.
  int64_t getTotalSize() const;

  // Returns whether this mesh is a maximal-sharding mesh
  //
  // A maximal-sharding mesh is a mesh with an empty axis list and a single
  // device ID.
  bool isMaximal() const;

  // Returns whether this mesh is a maximal-sharding mesh with `deviceId`.
  //
  // A maximal-sharding mesh is a mesh with an empty axis list and a single
  // device ID.
  bool isMaximal(int64_t deviceId) const;

  // If this mesh is a maximal-sharding mesh, returns the maximal device ID,
  // otherwise, returns std::nullopt.
  //
  // A maximal-sharding mesh is a mesh with an empty axis list and a single
  // device ID.
  std::optional<int64_t> getMaximalDeviceId() const;

  // Returns a comparator that orders axis names w.r.t. their order in this
  // mesh.
  std::function<bool(StringRef lhs, StringRef rhs)> getAxisNameComparator()
  const;

  // Returns a map from axis name to axis size.
  llvm::SmallDenseMap<StringRef, int64_t> getAxisNameToSize() const;
  static constexpr ::llvm::StringLiteral name = "sdy.mesh";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  using Base::getChecked;
  static MeshAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<MeshAxisAttr> axes, ::llvm::ArrayRef<int64_t> device_ids);
  static MeshAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::llvm::ArrayRef<MeshAxisAttr> axes, ::llvm::ArrayRef<int64_t> device_ids);
  static MeshAttr get(::mlir::MLIRContext *context, mlir::ArrayRef<MeshAxisAttr> axes);
  static MeshAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, mlir::ArrayRef<MeshAxisAttr> axes);
  static MeshAttr get(::mlir::MLIRContext *context, int64_t device_id);
  static MeshAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, int64_t device_id);
  static ::llvm::LogicalResult verify(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<MeshAxisAttr> axes, ::llvm::ArrayRef<int64_t> device_ids);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::llvm::ArrayRef<MeshAxisAttr> axes, ::llvm::ArrayRef<int64_t> device_ids);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"mesh"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<MeshAxisAttr> getAxes() const;
  ::llvm::ArrayRef<int64_t> getDeviceIds() const;
};
namespace detail {
struct SubAxisInfoAttrStorage;
} // namespace detail
class SubAxisInfoAttr : public ::mlir::Attribute::AttrBase<SubAxisInfoAttr, ::mlir::Attribute, detail::SubAxisInfoAttrStorage> {
public:
  using Base::Base;
  // Sub-axes of the same full axis are ordered by their pre-size, and then by
  // their size (overlap is only possible for two sub-axes that shard
  // different tensors), e.g. [1(2), 4(2), 4(4)].
  bool operator<(const SubAxisInfoAttr &rhs) const;

  // Returns the pre-size of the next sub-axis (that is minor to this
  // sub-axis), or the size of the full axis if this is the minor-most
  // sub-axis.
  //
  // The next pre-size is equal to `pre-size * size` of this sub-axis.
  int64_t getNextPreSize() const {
    return getPreSize() * getSize();
  }
  static constexpr ::llvm::StringLiteral name = "sdy.sub_axis_info";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static SubAxisInfoAttr get(::mlir::MLIRContext *context, int64_t pre_size, int64_t size);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"sub_axis_info"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  int64_t getPreSize() const;
  int64_t getSize() const;
};
namespace detail {
struct AxisRefAttrStorage;
} // namespace detail
class AxisRefAttr : public ::mlir::Attribute::AttrBase<AxisRefAttr, ::mlir::Attribute, detail::AxisRefAttrStorage> {
public:
  using Base::Base;
  // Returns a comparator that orders axis names w.r.t. their order in the
  // given `mesh`.
  static std::function<bool(AxisRefAttr lhs, AxisRefAttr rhs)>
  getMeshComparator(MeshAttr mesh);

  // Returns a comparator that order axis names lexicographically.
  // 1. Compare the axis names lexicographically.
  // 2. For a full-axis and sub-axis with the same name "a" -
  //    "a":(1)x < "a" < "a":(y)z, where y > 1.
  // 3. Sort two sub-axes based on comparator of SubAxisInfoAttr.
  bool operator<(const AxisRefAttr &rhs) const;

  std::string toString() const;

  // Returns the size of this axis or sub-axis.
  int64_t getSize(MeshAttr mesh) const;

  // If this is a sub-axis, returns its pre-size, otherwise returns 1.
  int64_t getSubAxisPreSize() const;

  // If this is a sub-axis, returns its next pre-size (see
  // SubAxisInfoAttr::getNextPreSize), otherwise returns its full size.
  int64_t getNextPreSizeOrFullSize(MeshAttr) const;

  // TODO(b/391138813): consider checking `canCoexist` in `contains`,
  // `prefixOf`, and `suffixOf`, instead of in using methods.

  // Returns whether this axis or sub-axis contains `other`, i.e., this axis
  // or sub-axis is equal to `other` or can be split into multiple sub-axes
  // such that one of them is `other`.
  //
  // For example:
  //  "a", "a":(2)2       -> true
  //  "a":(1)8, "a":(1)4  -> true
  //  "a":(2)16, "a":(4)2 -> true
  //  "a", "a"            -> true
  //  "a":(2)2, "a":(2)2  -> true
  //  "a":(1)4, "a":(2)4  -> false
  //  "a":(2)4, "a":(1)2  -> false
  //  "a", "b":(1)2       -> false
  bool contains(AxisRefAttr other) const;

  // Returns whether this axis or sub-axis strictly contains `other`.
  // "a.strictlyContains(b)" is equivalent to "a.contains(b) && a != b".
  //
  // For example:
  //  "a", "a":(2)2       -> true
  //  "a":(1)8, "a":(1)4  -> true
  //  "a":(2)16, "a":(4)2 -> true
  //  "a", "a"            -> false
  //  "a":(2)2, "a":(2)2  -> false
  //  "a":(1)4, "a":(2)4  -> false
  //  "a":(2)4, "a":(1)2  -> false
  //  "a", "b":(1)2       -> false
  bool strictlyContains(AxisRefAttr other) const;

  // Returns whether this axis or sub-axis is a prefix of `other`, i.e.,
  // `other` is equal to this axis ref or can be split into two sub-axes such
  // that the major one is this sub-axis.
  //
  // For example:
  //  "a":(1)2, "a"      -> true
  //  "a":(2)2, "a":(2)4 -> true
  //  "a", "a"           -> true
  //  "a":(2)4, "a":(2)4 -> true
  //  "a":(1)4, "a":(1)2 -> false
  //  "a":(1)4, "a":(2)8 -> false
  //  "a":(1)2, "b"      -> false
  bool prefixOf(AxisRefAttr other) const;

  // Returns whether this axis or sub-axis is a strict prefix of `other`.
  // "a.strictPrefixOf(b)" is equivalent to "a.prefixOf(b) && a != b".
  //
  // For example:
  //  "a":(1)2, "a"      -> true
  //  "a":(2)2, "a":(2)4 -> true
  //  "a", "a"           -> false
  //  "a":(2)4, "a":(2)4 -> false
  //  "a":(1)4, "a":(1)2 -> false
  //  "a":(1)4, "a":(2)8 -> false
  //  "a":(1)2, "b"      -> false
  bool strictPrefixOf(AxisRefAttr other) const;

  // Returns whether this axis or sub-axis is a suffix of `other`, i.e.,
  // `other` is equal to this axis ref or can be split into two sub-axes such
  // that the minor one is this sub-axis.
  //
  // For example:
  //  "a", "a"           -> true
  //  "a":(2)4, "a"      -> true (size("a") == 8)
  //  "a":(2)4, "a":(1)8 -> true
  //  "a", "b"           -> false
  //  "a", "a":(2)4      -> false
  //  "a":(1)8, "a":(2)4 -> false
  //  "a":(1)2, "a":(2)4 -> false
  //  "a":(1)4, "a"      -> false
  bool suffixOf(AxisRefAttr other, MeshAttr mesh) const;

  // Returns whether this axis or sub-axis is a strict suffix of `other`.
  // "a.strictSuffixOf(b)" is equivalent to "a.suffixOf(b) && a != b".
  //
  // For example:
  //  "a":(2)4, "a"      -> true (size("a") == 8)
  //  "a":(2)4, "a":(1)8 -> true
  //  "a", "a"           -> false
  //  "a", "b"           -> false
  //  "a", "a":(2)4      -> false
  //  "a":(1)8, "a":(2)4 -> false
  //  "a":(1)2, "a":(2)4 -> false
  //  "a":(1)4, "a"      -> false
  bool strictSuffixOf(AxisRefAttr other, MeshAttr mesh) const;

  // Returns whether this axis or sub-axis overlaps with `other`, i.e., they
  // are equal or there is a sub-axis that is contained in both axis refs.
  //
  // For example:
  //  "a", "a":(2)2      -> true
  //  "a":(2)2, "a":(2)2 -> true
  //  "a":(1)4, "a":(2)4 -> true
  //  "a":(2)4, "a":(1)4 -> true
  //  "a":(1)4, "a":(1)2 -> true
  //  "a":(2)8, "a":(4)2 -> true
  //  "a":(1)4, "a":(4)2 -> false
  //  "a":(1)2, "a":(4)2 -> false
  //  "a":(1)4, "b":(2)4 -> false
  bool overlaps(AxisRefAttr other) const;

  // Returns whether `a` and `b` can coexist in the same mesh:
  // * If they overlap, then both overlapping and non-overlapping parts must
  //   be valid axes or sub-axes.
  // * Otherwise, both axes can be used to shard the same tensor.
  //
  // For example:
  //  "a", "b"           -> true
  //  "a", "b":(2)2      -> true
  //  "a", "a"           -> true
  //  "a", "a":(2)2      -> true
  //  "a":(1)2, "a":(4)2 -> true
  //  "a":(1)4, "a":(2)4 -> true
  //  "a":(1)2, "a":(1)3 -> false
  //  "a":(1)2, "a":(3)2 -> false
  //  "a":(1)3, "a":(2)3 -> false
  bool canCoexist(AxisRefAttr other) const;

  // Returns the largest prefix of this axis that overlaps with `other`, or
  // `std::nullopt` if the prefix does not exist.
  //
  // If this axis and `other` can't coexist, returns `std::nullopt` (see
  // AxisRefAttr::canCoexist).
  //
  // For example:
  //  "a", "a"           -> "a"
  //  "a":(2)2, "a"      -> "a":(2)2
  //  "a":(2)2, "a":(2)2 -> "a":(2)2
  //  "a":(1)4, "a":(1)2 -> "a":(1)2
  //  "a":(2)8, "a":(1)4 -> "a":(2)2
  //  "a", "b"           -> std::nullopt
  //  "a":(2)2, "b"      -> std::nullopt
  //  "a":(1)4, "a":(2)4 -> std::nullopt
  //  "a":(1)2, "a":(1)3 -> std::nullopt
  //  "a":(3)2, "a":(2)3 -> std::nullopt
  std::optional<AxisRefAttr> getPrefixWithOverlap(
      AxisRefAttr other, MeshAttr mesh) const;

  // If there is no overlap between this axis and `other`, return this axis.
  // Otherwise, return the largest prefix of this axis by removing the
  // overlapping suffix with `other`. Return `std::nullopt` if the prefix does
  // not exist.
  //
  // If this axis and `other` can't coexist, returns `std::nullopt` (see
  // AxisRefAttr::canCoexist).
  //
  // For example:
  //  "a", "a":(2)2      -> "a":(1)2
  //  "a":(1)4, "a":(2)4 -> "a":(1)2
  //  "a":(2)8, "a":(4)2 -> "a":(2)2
  //  "a":(1)4, "a":(4)2 -> "a":(1)4
  //  "a":(1)2, "a":(4)2 -> "a":(1)2
  //  "a":(1)4, "b":(2)4 -> "a":(1)4
  //  "a":(2)2, "a":(2)2 -> std::nullopt
  //  "a":(2)4, "a":(1)4 -> std::nullopt
  //  "a":(1)4, "a":(1)2 -> std::nullopt
  //  "a":(1)2, "a":(3)2 -> std::nullopt
  //  "a":(1)3, "a":(2)3 -> std::nullopt
  std::optional<AxisRefAttr> getPrefixWithoutOverlap(AxisRefAttr other) const;

  // If there is no overlap between this axis and `other`, return this axis.
  // Otherwise, return the largest suffix of this axis by removing the
  // overlapping prefix with `other`. Return `std::nullopt` if the suffix does
  // not exist.
  //
  // If this axis and `other` can't coexist, returns `std::nullopt` (see
  // AxisRefAttr::canCoexist).
  //
  // For example:
  //  "a", "a":(2)2      -> "a":(4)2 (size("a") == 8)
  //  "a":(1)4, "a":(1)2 -> "a":(2)2
  //  "a":(2)8, "a":(4)2 -> "a":(8)2
  //  "a":(1)4, "a":(4)2 -> "a":(1)4
  //  "a":(1)2, "a":(4)2 -> "a":(1)2
  //  "a":(1)4, "b":(2)4 -> "a":(1)4
  //  "a":(2)2, "a":(2)2 -> std::nullopt
  //  "a":(1)4, "a":(2)4 -> std::nullopt
  //  "a":(2)2, "a":(1)4 -> std::nullopt
  //  "a":(2)3, "a":(1)3 -> std::nullopt
  //  "a":(3)2, "a":(1)2 -> std::nullopt
  std::optional<AxisRefAttr> getSuffixWithoutOverlap(
      AxisRefAttr other, MeshAttr mesh) const;

  // Returns the greatest common prefix of this axis and `other`. If the two
  // axes do not have common prefix, return `std::nullopt`.
  //
  // If this axis and `other` can't coexist, returns `std::nullopt` (see
  // AxisRefAttr::canCoexist).
  //
  // For example:
  //  "a", "a"           -> "a"
  //  "a":(1)4, "a"      -> "a":(1)4
  //  "a", "a":(1)4      -> "a":(1)4
  //  "a":(1)2, "a":(1)4 -> "a":(1)2
  //  "a":(2)8, "a":(2)4 -> "a":(2)4
  //  "a", "b"           -> std::nullopt
  //  "a":(1)2, "a":(2)4 -> std::nullopt
  std::optional<AxisRefAttr> getGreatestCommonPrefix(AxisRefAttr other) const;

  // Removes the common prefix of this axis and `other` from this axis. If the
  // two axes do not have common prefix or `other` is greater or equal to this
  // axis, return `std::nullopt`.
  //
  // If this axis and `other` can't coexist, returns `std::nullopt` (see
  // AxisRefAttr::canCoexist).
  //
  // For example:
  //  "a", "a":(1)4      -> "a":(4)2 (size("a") == 8)
  //  "a":(1)4, "a":(1)2 -> "a":(2)2
  //  "a":(2)8, "a":(2)4 -> "a":(8)2
  //  "a", "b"           -> std::nullopt
  //  "a", "a"           -> std::nullopt
  //  "a":(1)4, "a"      -> std::nullopt
  //  "a":(2)4, "a":(2)8 -> std::nullopt
  //  "a":(1)2, "a":(2)4 -> std::nullopt
  //  "a":(1)2, "a":(1)3 -> std::nullopt
  std::optional<AxisRefAttr> removeCommonPrefix(
      AxisRefAttr prefix, MeshAttr mesh) const;

  // Returns whether this axis-ref can be merged with `other`, i.e., they are
  // consecutive sub-axes of the same full axis and this sub-axis is major to
  // `other`.
  //
  // For example:
  //  "a":(2)4, "a":(8)2 -> true
  //  "b":(1)2, "b":(2)4 -> true
  //  "c":(1)2, "c":(4)2 -> false
  //  "d":(2)4, "d":(1)2 -> false
  bool canMerge(AxisRefAttr other) const;

  // Merges this axis-ref with the `other`, assuming `canMerge(other)` is
  // true, i.e., they are consecutive sub-axes of the same full axis and this
  // sub-axis is major to `other`.
  //
  // The mesh is needed for the size of the full axis (see 2nd example below).
  //
  // For example:
  //  "a":(2)4, "a":(8)2 ~> "a":(2)8
  //  "b":(1)2, "b":(2)4 ~> "b"
  AxisRefAttr merge(AxisRefAttr other, MeshAttr mesh) const;
  static constexpr ::llvm::StringLiteral name = "sdy.axis_ref";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static AxisRefAttr get(::mlir::MLIRContext *context, ::llvm::StringRef name, SubAxisInfoAttr sub_axis_info);
  static AxisRefAttr get(::mlir::MLIRContext *context, StringRef name);
  static AxisRefAttr get(::mlir::MLIRContext *context, StringRef name, int64_t pre_size, int64_t size);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"axis_ref"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::StringRef getName() const;
  SubAxisInfoAttr getSubAxisInfo() const;
};
namespace detail {
struct DimensionShardingAttrStorage;
} // namespace detail
class DimensionShardingAttr : public ::mlir::Attribute::AttrBase<DimensionShardingAttr, ::mlir::Attribute, detail::DimensionShardingAttrStorage> {
public:
  using Base::Base;
  ArrayRef<AxisRefAttr>::iterator axis_begin() const {
    return getAxes().begin();
  }
  ArrayRef<AxisRefAttr>::iterator axis_end() const {
    return getAxes().end();
  }

  // Returns true if this dimension sharding has no axes.
  bool emptyAxes() const { return getAxes().empty(); }

  // Shards this dimension further along `axisName`.
  //
  // Assumes it is it not closed or already sharded on `axisName`.
  //
  // Attributes are immutable, so we can't update the sharding in place and
  // must return a new instance.
  DimensionShardingAttr getSharded(StringRef axisName) const;

  // Returns the sharded size of this dimension,
  // i.e., the product of sharding axis sizes.
  int64_t getShardedSize(MeshAttr mesh) const;

  // Drops the first `N` sharding axes, and keeps `M` sharding axes.
  DimensionShardingAttr sliceShardingAxes(size_t N, size_t M) const;

  // Drops the first `N` sharding axes.
  DimensionShardingAttr dropFrontShardingAxes(size_t N) const;

  // Takes the first `N` sharding axes.
  DimensionShardingAttr takeFrontShardingAxes(size_t N) const;

  // Drops the priority of this dimension sharding, if present.
  DimensionShardingAttr dropPriority() const;

  // Returns the priority of this dimension sharding, if present, or the
  // default priority otherwise.
  int64_t getPriorityOrDefault() const;

  // Builds a closed `DimensionShardingAttr` matching `dimSharding` in axes and priority.
  static DimensionShardingAttr getClosedLike(DimensionShardingAttr sharding);
  static constexpr ::llvm::StringLiteral name = "sdy.dimension_sharding";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static DimensionShardingAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<AxisRefAttr> axes, bool is_closed, std::optional<int64_t> priority);
  static DimensionShardingAttr get(::mlir::MLIRContext *context, ArrayRef<AxisRefAttr> axes, bool is_closed);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"dimension_sharding"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<AxisRefAttr> getAxes() const;
  bool getIsClosed() const;
  std::optional<int64_t> getPriority() const;
};
namespace detail {
struct TensorShardingAttrStorage;
} // namespace detail
class TensorShardingAttr : public ::mlir::Attribute::AttrBase<TensorShardingAttr, ::mlir::Attribute, detail::TensorShardingAttrStorage> {
public:
  using Base::Base;
  int64_t getRank() const {
    return getDimShardings().size();
  }

  DimensionShardingAttr getDimSharding(int64_t dim) const {
    return getDimShardings()[dim];
  }

  bool isClosed(int64_t dim) const {
    return getDimSharding(dim).getIsClosed();
  }

  bool isFullyClosed() const {
    return llvm::all_of(getDimShardings(),
                    [](const DimensionShardingAttr dimSharding) {
                       return dimSharding.getIsClosed();
                    });
  }

  bool isFullyReplicated() const {
    return llvm::all_of(getDimShardings(),
                    [](const DimensionShardingAttr dimSharding) {
                       return dimSharding.emptyAxes();
                    });
  }

  // Returns the mesh `FlatSymbolRefAttr` this sharding references, assuming
  // it doesn't have an inlined `MeshAttr`.
  FlatSymbolRefAttr getMeshSymName() const {
    return mlir::cast<FlatSymbolRefAttr>(getMeshOrRef());
  }

  // Returns the mesh name this sharding references, assuming it doesn't have
  // an inlined `MeshAttr`.
  StringRef getMeshName() const {
    return getMeshSymName().getValue();
  }

  // If this sharding has an inlined `MeshAttr`, returns it, otherwise looks
  // up the mesh symbol with the referenced name in `symbolTable`, and returns
  // its `MeshAttr` if it exists in the table, or nullptr otherwise.
  MeshAttr getMesh(const SymbolTable& symbolTable) const;

  // If this sharding has an inlined `MeshAttr`, returns it, otherwise looks
  // up the mesh symbol with the referenced name in the symbol table of the
  // enclosing module of `op`, and returns its `MeshAttr` if it exists in the
  // table, or nullptr otherwise.
  MeshAttr getMesh(Operation* op) const;

  // Returns true if all dimension shardings are empty and there are no
  // replicated axes.
  bool emptyAxes() const;

  // Like `llvm::any_of` but checks the predicate against all dimension
  // sharding and replicated `AxisRefAttr`s.
  bool anyOfAxisRef(std::function<bool(AxisRefAttr)> predicate) const;

  // Like `llvm::for_each` but applies the `callback` against all dimension
  // sharding and replicated `AxisRefAttr`s.
  void forEachAxisRef(std::function<void(AxisRefAttr)> callback) const;

  // Returns true if `axisName` or a sub-axis of it is used to shard any
  // dimension or is replicated.
  bool isBound(StringRef axisName) const;

  // Returns true if dimension `dim` can be further sharded on the full
  // `axisName`.
  bool canShard(int64_t dim, StringRef axisName) const;

  // Returns true if the tensor can be replicated on the full `axisName`.
  bool canReplicate(StringRef axisName) const;

  // Closes sharding dimensions at the specified dimension indices.
  TensorShardingAttr closeShardingDims(ArrayRef<int64_t> dimIndices) const;

  // Opens sharding dimensions at the specified dimension indices.
  TensorShardingAttr openShardingDims(ArrayRef<int64_t> dimIndices) const;

  // Sets the sharding of dimension `dim`.
  //
  // Assumes `dim < getRank()`.
  //
  // Attributes are immutable, so we can't update the sharding in place and
  // must return a new instance.
  TensorShardingAttr replaceDimSharding(
      int64_t dim, DimensionShardingAttr sharding) const;

  // Sets the replicated axes to `replicatedAxes`.
  //
  // Attributes are immutable, so we can't update the sharding in place and
  // must return a new instance.
  TensorShardingAttr replaceReplicatedAxes(
      ArrayRef<AxisRefAttr> replicatedAxes) const;

  // Shards dimension `dim` further along `axisName`.
  //
  // Assumes `canShard(dim, axisName)` is true.
  //
  // Attributes are immutable, so we can't update the sharding in place and
  // must return a new instance.
  TensorShardingAttr getSharded(int64_t dim, StringRef axisName) const;

  // Replicates the tensor along `axisName`.
  //
  // Assumes `canReplicate(axisName)` is true. The `mesh` is needed to keep
  // the replicated axes sorted.
  //
  // Attributes are immutable, so we can't update the sharding in place and
  // must return a new instance.
  TensorShardingAttr getReplicated(StringRef axisName, MeshAttr mesh) const;


  // Verifies that this `TensorShardingAttr` is valid w.r.t the given
  // tensor type and mesh.
  //
  // If `type` isn't a `ShapedType`, the sharding must have rank 0
  // and no replicated axes. Otherwise, the `ShapedType` must have a static
  // shape.

  //
  // If `checkDivisibility` is true, verifies that each dimension size
  // is divisible by its sharded size.
  mlir::LogicalResult verifyForType(
      Type type, MeshAttr mesh,
      std::function<InFlightDiagnostic(StringRef)> emitError,
      bool checkDivisibility = true);

  // Builds a `TensorShardingAttr` with all dim shardings and replicated axes
  // being marked closed (cannot be further replicated/sharded).
  static TensorShardingAttr getFullyClosed(
      MLIRContext* context, int64_t rank, StringRef meshName);

  // Builds a fully closed `TensorShardingAttr` matching `sharding` in
  // `mesh_or_ref` and rank.
  static TensorShardingAttr getFullyClosedLike(TensorShardingAttr sharding);

  // Builds a `TensorShardingAttr` with all dim shardings being marked closed
  // and matching `sharding` in dim sharding axes, `mesh_or_ref` and rank.
  static TensorShardingAttr getClosedLike(TensorShardingAttr sharding);

  // Builds a `TensorShardingAttr` with a closed dim sharding for each axis
  // list in `axesPerDim`.
  static TensorShardingAttr getClosed(
      MLIRContext* context, Attribute meshOrRef,
      ArrayRef<SmallVector<AxisRefAttr>> axesPerDim);

  // Builds a `TensorShardingAttr` with all dim shardings and replicated axes
  // being marked open (can be further replicated/sharded).
  static TensorShardingAttr getFullyOpen(
      MLIRContext* context, int64_t rank, StringRef meshName);

  // Builds a fully open `TensorShardingAttr` matching `sharding` in
  // `mesh_or_ref` and rank.
  static TensorShardingAttr getFullyOpenLike(TensorShardingAttr sharding);

  // Gets the local tensor type from a global RankedTensorType w.r.t. the
  // given mesh and sharding. Assumes that the sharding is valid w.r.t. the
  // mesh and tensor type.
  RankedTensorType getLocalTensorType(RankedTensorType globalTensorType,
                                      MeshAttr mesh) const;

  // Gets the global tensor type from a local RankedTensorType w.r.t. the
  // given mesh and sharding. Assumes that the sharding is valid w.r.t. the
  // mesh and tensor type.
  //
  // NOTE: this doesn't take into account padding. Each dimension of
  // `localTensorType` will be a multiple of the global tensor type returned.
  RankedTensorType getGlobalTensorType(RankedTensorType localTensorType,
                                       MeshAttr mesh) const;

  // Returns true if all dimensions are sharded in the same way.
  bool areDimAxesEqual(TensorShardingAttr otherSharding) const;
  static constexpr ::llvm::StringLiteral name = "sdy.sharding";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  using Base::getChecked;
  static TensorShardingAttr get(::mlir::MLIRContext *context, ::mlir::Attribute mesh_or_ref, ::llvm::ArrayRef<DimensionShardingAttr> dim_shardings, ::llvm::ArrayRef<AxisRefAttr> replicated_axes);
  static TensorShardingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, ::mlir::Attribute mesh_or_ref, ::llvm::ArrayRef<DimensionShardingAttr> dim_shardings, ::llvm::ArrayRef<AxisRefAttr> replicated_axes);
  static TensorShardingAttr get(::mlir::MLIRContext *context, StringAttr mesh_name, ArrayRef<DimensionShardingAttr> dim_shardings, ArrayRef<AxisRefAttr> replicated_axes);
  static TensorShardingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, StringAttr mesh_name, ArrayRef<DimensionShardingAttr> dim_shardings, ArrayRef<AxisRefAttr> replicated_axes);
  static TensorShardingAttr get(::mlir::MLIRContext *context, StringRef mesh_name, ArrayRef<DimensionShardingAttr> dim_shardings, ArrayRef<AxisRefAttr> replicated_axes);
  static TensorShardingAttr getChecked(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::MLIRContext *context, StringRef mesh_name, ArrayRef<DimensionShardingAttr> dim_shardings, ArrayRef<AxisRefAttr> replicated_axes);
  static ::llvm::LogicalResult verifyInvariantsImpl(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::Attribute mesh_or_ref, ::llvm::ArrayRef<DimensionShardingAttr> dim_shardings, ::llvm::ArrayRef<AxisRefAttr> replicated_axes);
  static ::llvm::LogicalResult verifyInvariants(::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError, ::mlir::Attribute mesh_or_ref, ::llvm::ArrayRef<DimensionShardingAttr> dim_shardings, ::llvm::ArrayRef<AxisRefAttr> replicated_axes);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"sharding"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::Attribute getMeshOrRef() const;
  ::llvm::ArrayRef<DimensionShardingAttr> getDimShardings() const;
  ::llvm::ArrayRef<AxisRefAttr> getReplicatedAxes() const;
};
namespace detail {
struct TensorShardingPerValueAttrStorage;
} // namespace detail
class TensorShardingPerValueAttr : public ::mlir::Attribute::AttrBase<TensorShardingPerValueAttr, ::mlir::Attribute, detail::TensorShardingPerValueAttrStorage> {
public:
  using Base::Base;
  // Builds a `TensorSharding` for each type in `types`, with all dimension
  // shardings marked open (can be further replicated/sharded).
  static TensorShardingPerValueAttr getFullyOpen(
      MLIRContext* context, TypeRange types, StringRef meshName);

  // Builds an open `TensorSharding` for each type in `types`, but
  // with the sharding at `index` replaced with `sharding`.
  static TensorShardingPerValueAttr getOpenWithShardingAtIndex(
      MLIRContext* context, TypeRange types, int64_t index,
      TensorShardingAttr sharding);

  // Returns whether there are no values.
  bool empty() const { return getShardings().empty(); }

  // Returns the number of values.
  int64_t size() const { return getShardings().size(); }

  // Returns the sharding of a value at `operandIndex`.
  //
  // Assumes `operandIndex < size()`.
  TensorShardingAttr getSharding(int64_t operandIndex) const {
    assert(operandIndex < size());
    return getShardings()[operandIndex];
  }

  // Sets the sharding of a value at `index`.
  //
  // Assumes `index < size()`.
  //
  // Attributes are immutable, so we can't update the sharding in place and
  // must return a new instance.
  TensorShardingPerValueAttr replaceValueSharding(
      int64_t index, TensorShardingAttr sharding) const;
  static constexpr ::llvm::StringLiteral name = "sdy.sharding_per_value";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static TensorShardingPerValueAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<TensorShardingAttr> shardings);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"sharding_per_value"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<TensorShardingAttr> getShardings() const;
};
namespace detail {
struct DimMappingAttrStorage;
} // namespace detail
class DimMappingAttr : public ::mlir::Attribute::AttrBase<DimMappingAttr, ::mlir::Attribute, detail::DimMappingAttrStorage> {
public:
  using Base::Base;
  // Returns whether the given `factorIndex` is the minor-most factor.
  bool isMinorMost(int64_t factorIndex) const {
    return !getFactorIndices().empty() &&
            getFactorIndices().back() == factorIndex;
  }
  static constexpr ::llvm::StringLiteral name = "sdy.dim_mapping";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static DimMappingAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> factor_indices);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"dim_mapping"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getFactorIndices() const;
};
namespace detail {
struct TensorMappingAttrStorage;
} // namespace detail
class TensorMappingAttr : public ::mlir::Attribute::AttrBase<TensorMappingAttr, ::mlir::Attribute, detail::TensorMappingAttrStorage> {
public:
  using Base::Base;
  int64_t getRank() const { return getDimMappings().size(); }
  bool empty() const { return getDimMappings().empty(); }

  // Returns true if any of the dimension mappings contains the `factorIndex`.
  bool containsFactor(int64_t factorIndex) const;
  static constexpr ::llvm::StringLiteral name = "sdy.tensor_mapping";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static TensorMappingAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<DimMappingAttr> dim_mappings);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"tensor_mapping"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<DimMappingAttr> getDimMappings() const;
};
namespace detail {
struct OpShardingRuleAttrStorage;
} // namespace detail
class OpShardingRuleAttr : public ::mlir::Attribute::AttrBase<OpShardingRuleAttr, ::mlir::Attribute, detail::OpShardingRuleAttrStorage> {
public:
  using Base::Base;
  int64_t getNumFactors() const { return getFactorSizes().size(); }
  int64_t getNumOperands() const { return getOperandMappings().size(); }
  int64_t getNumResults() const { return getResultMappings().size(); }

  int64_t getFactorSize(int64_t factorIndex) const {
    return getFactorSizes()[factorIndex];
  }
  TensorMappingAttr getOperandMapping(int64_t operandNum) const {
    return getOperandMappings()[operandNum];
  }
  TensorMappingAttr getResultMapping(int64_t resultNum) const {
    return getResultMappings()[resultNum];
  }

  bool isCustom() const { return getIsCustomRule(); }

  // Returns a vector of the sizes of all operand and result tensors, the
  // operands come before the results.
  SmallVector<int64_t> getTensorSizes() const;

  // Returns true if the `factorIndex` is a reduction factor.
  bool isReductionFactor(int64_t factorIndex) const;

  // Returns true if the `factorIndex` is a factor requiring full replication.
  bool isNeedReplicationFactor(int64_t factorIndex) const;

  // Returns true if the `factorIndex` is a factor in all non-scalar tensors.
  bool isFactorInAllNonScalarTensors(int64_t factorIndex) const;

  // Returns true if the `factorIndex` is a batching factor, which satisfies:
  // 1. It is not a reduction factor.
  // 2. It is not a need replication factor.
  // 3. It is used in all non-scalar tensors.
  bool isBatchingFactor(int64_t factorIndex) const;

  // Returns a vector of tensor indices that are non-scalar, of all operand
  // and result tensors, the operands come before the results.
  SmallVector<int64_t> getNonScalarTensorIndices() const;

  // Returns a vector of batching factor indices.
  SmallVector<int64_t> getBatchingFactors() const;
  static constexpr ::llvm::StringLiteral name = "sdy.op_sharding_rule";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static OpShardingRuleAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<int64_t> factor_sizes, ::llvm::ArrayRef<TensorMappingAttr> operand_mappings, ::llvm::ArrayRef<TensorMappingAttr> result_mappings, ::llvm::ArrayRef<int64_t> reduction_factors, ::llvm::ArrayRef<int64_t> need_replication_factors, bool is_custom_rule);
  static OpShardingRuleAttr get(::mlir::MLIRContext *context, ArrayRef<int64_t> factor_sizes, ArrayRef<TensorMappingAttr> operand_mappings, ArrayRef<TensorMappingAttr> result_mappings, ArrayRef<int64_t> reduction_factors, ArrayRef<int64_t> need_replication_factors);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"op_sharding_rule"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<int64_t> getFactorSizes() const;
  ::llvm::ArrayRef<TensorMappingAttr> getOperandMappings() const;
  ::llvm::ArrayRef<TensorMappingAttr> getResultMappings() const;
  ::llvm::ArrayRef<int64_t> getReductionFactors() const;
  ::llvm::ArrayRef<int64_t> getNeedReplicationFactors() const;
  bool getIsCustomRule() const;
};
namespace detail {
struct AxisRefListAttrStorage;
} // namespace detail
class AxisRefListAttr : public ::mlir::Attribute::AttrBase<AxisRefListAttr, ::mlir::Attribute, detail::AxisRefListAttrStorage> {
public:
  using Base::Base;
  auto begin() const { return getValue().begin(); }
  auto end() const { return getValue().end(); }
  bool empty() const { return getValue().empty(); }
  size_t size() const { return getValue().size(); }
  auto &front() const { return getValue().front(); }
  auto &back() const { return getValue().back(); }
  auto &operator[](size_t index) { return getValue()[index]; }
  operator ::llvm::ArrayRef<AxisRefAttr>() const { return getValue(); }
  static constexpr ::llvm::StringLiteral name = "sdy.axis_ref_list";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static AxisRefListAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<AxisRefAttr> value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"axis_ref_list"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<AxisRefAttr> getValue() const;
};
namespace detail {
struct ListOfAxisRefListsAttrStorage;
} // namespace detail
class ListOfAxisRefListsAttr : public ::mlir::Attribute::AttrBase<ListOfAxisRefListsAttr, ::mlir::Attribute, detail::ListOfAxisRefListsAttrStorage> {
public:
  using Base::Base;
  auto begin() const { return getValue().begin(); }
  auto end() const { return getValue().end(); }
  bool empty() const { return getValue().empty(); }
  size_t size() const { return getValue().size(); }
  auto &front() const { return getValue().front(); }
  auto &back() const { return getValue().back(); }
  auto &operator[](size_t index) { return getValue()[index]; }
  operator ::llvm::ArrayRef<AxisRefListAttr>() const { return getValue(); }
  static constexpr ::llvm::StringLiteral name = "sdy.list_of_axis_ref_lists";
  static constexpr ::llvm::StringLiteral dialectName = "sdy";
  static ListOfAxisRefListsAttr get(::mlir::MLIRContext *context, ::llvm::ArrayRef<AxisRefListAttr> value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"list_of_axis_ref_lists"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::llvm::ArrayRef<AxisRefListAttr> getValue() const;
};
} // namespace sdy
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ManualAxesAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::MeshAxisAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::MeshAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::SubAxisInfoAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::AxisRefAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::DimensionShardingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::TensorShardingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::TensorShardingPerValueAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::DimMappingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::TensorMappingAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::OpShardingRuleAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::AxisRefListAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::sdy::ListOfAxisRefListsAttr)

#endif  // GET_ATTRDEF_CLASSES

