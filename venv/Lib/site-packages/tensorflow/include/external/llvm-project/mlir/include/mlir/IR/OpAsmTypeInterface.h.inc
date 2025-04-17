/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
class OpAsmTypeInterface;
namespace detail {
struct OpAsmTypeInterfaceInterfaceTraits {
  struct Concept {
    /// The methods defined by the interface.
    void (*getAsmName)(const Concept *impl, ::mlir::Type , ::mlir::OpAsmSetNameFn);
  };
  template<typename ConcreteType>
  class Model : public Concept {
  public:
    using Interface = ::mlir::OpAsmTypeInterface;
    Model() : Concept{getAsmName} {}

    static inline void getAsmName(const Concept *impl, ::mlir::Type tablegen_opaque_val, ::mlir::OpAsmSetNameFn setNameFn);
  };
  template<typename ConcreteType>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::OpAsmTypeInterface;
    FallbackModel() : Concept{getAsmName} {}

    static inline void getAsmName(const Concept *impl, ::mlir::Type tablegen_opaque_val, ::mlir::OpAsmSetNameFn setNameFn);
  };
  template<typename ConcreteModel, typename ConcreteType>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteType;
    void getAsmName(::mlir::Type tablegen_opaque_val, ::mlir::OpAsmSetNameFn setNameFn) const;
  };
};
template <typename ConcreteType>
struct OpAsmTypeInterfaceTrait;

} // namespace detail
class OpAsmTypeInterface : public ::mlir::TypeInterface<OpAsmTypeInterface, detail::OpAsmTypeInterfaceInterfaceTraits> {
public:
  using ::mlir::TypeInterface<OpAsmTypeInterface, detail::OpAsmTypeInterfaceInterfaceTraits>::TypeInterface;
  template <typename ConcreteType>
  struct Trait : public detail::OpAsmTypeInterfaceTrait<ConcreteType> {};
  /// Get a name to use when printing a value of this type.
  void getAsmName(::mlir::OpAsmSetNameFn setNameFn) const;
};
namespace detail {
  template <typename ConcreteType>
  struct OpAsmTypeInterfaceTrait : public ::mlir::TypeInterface<OpAsmTypeInterface, detail::OpAsmTypeInterfaceInterfaceTraits>::Trait<ConcreteType> {
    /// Get a name to use when printing a value of this type.
    void getAsmName(::mlir::OpAsmSetNameFn setNameFn) const {
      ;
    }
  };
}// namespace detail
} // namespace mlir
namespace mlir {
template<typename ConcreteType>
void detail::OpAsmTypeInterfaceInterfaceTraits::Model<ConcreteType>::getAsmName(const Concept *impl, ::mlir::Type tablegen_opaque_val, ::mlir::OpAsmSetNameFn setNameFn) {
  return (::llvm::cast<ConcreteType>(tablegen_opaque_val)).getAsmName(setNameFn);
}
template<typename ConcreteType>
void detail::OpAsmTypeInterfaceInterfaceTraits::FallbackModel<ConcreteType>::getAsmName(const Concept *impl, ::mlir::Type tablegen_opaque_val, ::mlir::OpAsmSetNameFn setNameFn) {
  return static_cast<const ConcreteType *>(impl)->getAsmName(tablegen_opaque_val, setNameFn);
}
template<typename ConcreteModel, typename ConcreteType>
void detail::OpAsmTypeInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteType>::getAsmName(::mlir::Type tablegen_opaque_val, ::mlir::OpAsmSetNameFn setNameFn) const {
;
}
} // namespace mlir
