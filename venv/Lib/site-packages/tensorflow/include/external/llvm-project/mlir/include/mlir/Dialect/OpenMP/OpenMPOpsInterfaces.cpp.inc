/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/// Get number of block arguments defined by `host_eval`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numHostEvalBlockArgs() {
      return getImpl()->numHostEvalBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `in_reduction`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numInReductionBlockArgs() {
      return getImpl()->numInReductionBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `map`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numMapBlockArgs() {
      return getImpl()->numMapBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `private`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numPrivateBlockArgs() {
      return getImpl()->numPrivateBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `reduction`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numReductionBlockArgs() {
      return getImpl()->numReductionBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `task_reduction`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numTaskReductionBlockArgs() {
      return getImpl()->numTaskReductionBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `use_device_addr`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numUseDeviceAddrBlockArgs() {
      return getImpl()->numUseDeviceAddrBlockArgs(getImpl(), getOperation());
  }
/// Get number of block arguments defined by `use_device_ptr`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::numUseDevicePtrBlockArgs() {
      return getImpl()->numUseDevicePtrBlockArgs(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `host_eval`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getHostEvalBlockArgsStart() {
      return getImpl()->getHostEvalBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `in_reduction`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getInReductionBlockArgsStart() {
      return getImpl()->getInReductionBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `map`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getMapBlockArgsStart() {
      return getImpl()->getMapBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `private`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getPrivateBlockArgsStart() {
      return getImpl()->getPrivateBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `reduction`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getReductionBlockArgsStart() {
      return getImpl()->getReductionBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `task_reduction`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getTaskReductionBlockArgsStart() {
      return getImpl()->getTaskReductionBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `use_device_addr`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getUseDeviceAddrBlockArgsStart() {
      return getImpl()->getUseDeviceAddrBlockArgsStart(getImpl(), getOperation());
  }
/// Get start index of block arguments defined by `use_device_ptr`.
unsigned mlir::omp::BlockArgOpenMPOpInterface::getUseDevicePtrBlockArgsStart() {
      return getImpl()->getUseDevicePtrBlockArgsStart(getImpl(), getOperation());
  }
/// Get block arguments defined by `host_eval`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getHostEvalBlockArgs() {
      return getImpl()->getHostEvalBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `in_reduction`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getInReductionBlockArgs() {
      return getImpl()->getInReductionBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `map`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getMapBlockArgs() {
      return getImpl()->getMapBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `private`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getPrivateBlockArgs() {
      return getImpl()->getPrivateBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `reduction`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getReductionBlockArgs() {
      return getImpl()->getReductionBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `task_reduction`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getTaskReductionBlockArgs() {
      return getImpl()->getTaskReductionBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `use_device_addr`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getUseDeviceAddrBlockArgs() {
      return getImpl()->getUseDeviceAddrBlockArgs(getImpl(), getOperation());
  }
/// Get block arguments defined by `use_device_ptr`.
::llvm::MutableArrayRef<::mlir::BlockArgument> mlir::omp::BlockArgOpenMPOpInterface::getUseDevicePtrBlockArgs() {
      return getImpl()->getUseDevicePtrBlockArgs(getImpl(), getOperation());
  }
/// Check whether the operation is representing a leaf of a composite OpenMP
/// construct.
bool mlir::omp::ComposableOpInterface::isComposite() {
      return getImpl()->isComposite(getImpl(), getOperation());
  }
/// Mark the operation as part of an OpenMP composite construct.
void mlir::omp::ComposableOpInterface::setComposite(bool val) {
      return getImpl()->setComposite(getImpl(), getOperation(), val);
  }
/// Set the declare target attribute on the current operation with the
/// specified attribute arguments.
void mlir::omp::DeclareTargetInterface::setDeclareTarget(mlir::omp::DeclareTargetDeviceType deviceType, mlir::omp::DeclareTargetCaptureClause captureClause) {
      return getImpl()->setDeclareTarget(getImpl(), getOperation(), deviceType, captureClause);
  }
/// Checks if the declare target attribute has been applied and exists on the
/// current operation. Returns true if it exists on it, otherwise returns
/// false.
bool mlir::omp::DeclareTargetInterface::isDeclareTarget() {
      return getImpl()->isDeclareTarget(getImpl(), getOperation());
  }
/// Returns the DeclareTargetDeviceType segment of the DeclareTarget attribute if it
/// exists on the current operation. Otherwise it returns null.
mlir::omp::DeclareTargetDeviceType mlir::omp::DeclareTargetInterface::getDeclareTargetDeviceType() {
      return getImpl()->getDeclareTargetDeviceType(getImpl(), getOperation());
  }
/// Returns the DeclareTargetCaptureClause segment of the DeclareTarget attribute if it
/// exists on the current operation. Otherwise it returns null.
mlir::omp::DeclareTargetCaptureClause mlir::omp::DeclareTargetInterface::getDeclareTargetCaptureClause() {
      return getImpl()->getDeclareTargetCaptureClause(getImpl(), getOperation());
  }
/// If there is another loop wrapper immediately nested inside, return that
/// operation. Assumes this operation is a valid loop wrapper.
::mlir::omp::LoopWrapperInterface mlir::omp::LoopWrapperInterface::getNestedWrapper() {
      return getImpl()->getNestedWrapper(getImpl(), getOperation());
  }
/// Return the loop nest nested directly or indirectly inside of this loop
/// wrapper. Assumes this operation is a valid loop wrapper.
::mlir::Operation *mlir::omp::LoopWrapperInterface::getWrappedLoop() {
      return getImpl()->getWrappedLoop(getImpl(), getOperation());
  }
/// Get map operands
::mlir::OperandRange mlir::omp::MapClauseOwningOpInterface::getMapVars() {
      return getImpl()->getMapVars(getImpl(), getOperation());
  }
/// Get mutable map operands
::mlir::MutableOperandRange mlir::omp::MapClauseOwningOpInterface::getMapVarsMutable() {
      return getImpl()->getMapVarsMutable(getImpl(), getOperation());
  }
/// Get operand index for a map clause
int64_t mlir::omp::MapClauseOwningOpInterface::getOperandIndexForMap(::mlir::Value map) {
      return getImpl()->getOperandIndexForMap(getImpl(), getOperation(), map);
  }
/// Set the attribute on the current module with the specified boolean
/// argument.
void mlir::omp::OffloadModuleInterface::setIsTargetDevice(bool isTargetDevice) {
      return getImpl()->setIsTargetDevice(getImpl(), getOperation(), isTargetDevice);
  }
/// Get the attribute on the current module if it exists and
/// return its value, if it doesn't exist it returns false by default.
bool mlir::omp::OffloadModuleInterface::getIsTargetDevice() {
      return getImpl()->getIsTargetDevice(getImpl(), getOperation());
  }
/// Set the attribute on the current module with the specified boolean
/// argument.
void mlir::omp::OffloadModuleInterface::setIsGPU(bool isGPU) {
      return getImpl()->setIsGPU(getImpl(), getOperation(), isGPU);
  }
/// Get the attribute on the current module if it exists and
/// return its value, if it doesn't exist it returns false by default.
bool mlir::omp::OffloadModuleInterface::getIsGPU() {
      return getImpl()->getIsGPU(getImpl(), getOperation());
  }
/// Get the FlagsAttr attribute on the current module if it exists
/// and return the attribute, if it doesn't exit it returns a nullptr
mlir::omp::FlagsAttr mlir::omp::OffloadModuleInterface::getFlags() {
      return getImpl()->getFlags(getImpl(), getOperation());
  }
/// Apply an omp.FlagsAttr to a module with the specified values
/// for the flags
void mlir::omp::OffloadModuleInterface::setFlags(uint32_t debugKind, bool assumeTeamsOversubscription, bool assumeThreadsOversubscription, bool assumeNoThreadState, bool assumeNoNestedParallelism, uint32_t openmpDeviceVersion, bool noGPULib) {
      return getImpl()->setFlags(getImpl(), getOperation(), debugKind, assumeTeamsOversubscription, assumeThreadsOversubscription, assumeNoThreadState, assumeNoNestedParallelism, openmpDeviceVersion, noGPULib);
  }
/// Set a StringAttr on the current module containing the host IR file path. This
/// file path is used in two-phase compilation during the device phase to generate
/// device side LLVM IR when lowering MLIR.
void mlir::omp::OffloadModuleInterface::setHostIRFilePath(std::string hostIRFilePath) {
      return getImpl()->setHostIRFilePath(getImpl(), getOperation(), hostIRFilePath);
  }
/// Find the host-ir file path StringAttr from the current module if it exists and
/// return its contained value, if it doesn't exist it returns an empty string. This
/// file path is used in two-phase compilation during the device phase to generate
/// device side LLVM IR when lowering MLIR.
llvm::StringRef mlir::omp::OffloadModuleInterface::getHostIRFilePath() {
      return getImpl()->getHostIRFilePath(getImpl(), getOperation());
  }
/// Get the omp.requires attribute on the operator if it's present and
/// return its value. If it doesn't exist, return `ClauseRequires::none` by
/// default.
::mlir::omp::ClauseRequires mlir::omp::OffloadModuleInterface::getRequires() {
      return getImpl()->getRequires(getImpl(), getOperation());
  }
/// Set the omp.requires attribute on the operator to the specified clauses.
void mlir::omp::OffloadModuleInterface::setRequires(::mlir::omp::ClauseRequires clauses) {
      return getImpl()->setRequires(getImpl(), getOperation(), clauses);
  }
/// Get the omp.target_triples attribute on the operator if it's present and
/// return its value. If it doesn't exist, return an empty array by default.
::llvm::ArrayRef<::mlir::Attribute> mlir::omp::OffloadModuleInterface::getTargetTriples() {
      return getImpl()->getTargetTriples(getImpl(), getOperation());
  }
/// Set the omp.target_triples attribute on the operation.
void mlir::omp::OffloadModuleInterface::setTargetTriples(::llvm::ArrayRef<::std::string> targetTriples) {
      return getImpl()->setTargetTriples(getImpl(), getOperation(), targetTriples);
  }
/// Get alloca block
::mlir::Block*mlir::omp::OutlineableOpenMPOpInterface::getAllocaBlock() {
      return getImpl()->getAllocaBlock(getImpl(), getOperation());
  }
/// Get reduction vars
::mlir::SmallVector<::mlir::Value> mlir::omp::ReductionClauseInterface::getAllReductionVars() {
      return getImpl()->getAllReductionVars(getImpl(), getOperation());
  }
