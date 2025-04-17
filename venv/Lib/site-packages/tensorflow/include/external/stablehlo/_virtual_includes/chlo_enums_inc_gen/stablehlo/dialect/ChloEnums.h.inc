/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Enum Utility Declarations                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ChloOps.td                                                           *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace chlo {
// Which comparison operation to perform.
enum class ComparisonDirection : uint32_t {
  EQ = 0,
  NE = 1,
  GE = 2,
  GT = 3,
  LE = 4,
  LT = 5,
};

::std::optional<ComparisonDirection> symbolizeComparisonDirection(uint32_t);
::llvm::StringRef stringifyComparisonDirection(ComparisonDirection);
::std::optional<ComparisonDirection> symbolizeComparisonDirection(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForComparisonDirection() {
  return 5;
}


inline ::llvm::StringRef stringifyEnum(ComparisonDirection enumValue) {
  return stringifyComparisonDirection(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<ComparisonDirection> symbolizeEnum<ComparisonDirection>(::llvm::StringRef str) {
  return symbolizeComparisonDirection(str);
}
} // namespace chlo
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::chlo::ComparisonDirection, ::mlir::chlo::ComparisonDirection> {
  template <typename ParserT>
  static FailureOr<::mlir::chlo::ComparisonDirection> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for Which comparison operation to perform.");

    // Symbolize the keyword.
    if (::std::optional<::mlir::chlo::ComparisonDirection> attr = ::mlir::chlo::symbolizeEnum<::mlir::chlo::ComparisonDirection>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid Which comparison operation to perform. specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::chlo::ComparisonDirection>, std::optional<::mlir::chlo::ComparisonDirection>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::chlo::ComparisonDirection>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::chlo::ComparisonDirection>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::chlo::ComparisonDirection> attr = ::mlir::chlo::symbolizeEnum<::mlir::chlo::ComparisonDirection>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid Which comparison operation to perform. specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::chlo::ComparisonDirection value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::chlo::ComparisonDirection> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::chlo::ComparisonDirection getEmptyKey() {
    return static_cast<::mlir::chlo::ComparisonDirection>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::chlo::ComparisonDirection getTombstoneKey() {
    return static_cast<::mlir::chlo::ComparisonDirection>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::chlo::ComparisonDirection &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::chlo::ComparisonDirection &lhs, const ::mlir::chlo::ComparisonDirection &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace chlo {
// Which comparison type to use.
enum class ComparisonType : uint32_t {
  NOTYPE = 0,
  FLOAT = 1,
  TOTALORDER = 2,
  SIGNED = 3,
  UNSIGNED = 4,
};

::std::optional<ComparisonType> symbolizeComparisonType(uint32_t);
::llvm::StringRef stringifyComparisonType(ComparisonType);
::std::optional<ComparisonType> symbolizeComparisonType(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForComparisonType() {
  return 4;
}


inline ::llvm::StringRef stringifyEnum(ComparisonType enumValue) {
  return stringifyComparisonType(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<ComparisonType> symbolizeEnum<ComparisonType>(::llvm::StringRef str) {
  return symbolizeComparisonType(str);
}
} // namespace chlo
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::chlo::ComparisonType, ::mlir::chlo::ComparisonType> {
  template <typename ParserT>
  static FailureOr<::mlir::chlo::ComparisonType> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for Which comparison type to use.");

    // Symbolize the keyword.
    if (::std::optional<::mlir::chlo::ComparisonType> attr = ::mlir::chlo::symbolizeEnum<::mlir::chlo::ComparisonType>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid Which comparison type to use. specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::chlo::ComparisonType>, std::optional<::mlir::chlo::ComparisonType>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::chlo::ComparisonType>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::chlo::ComparisonType>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::chlo::ComparisonType> attr = ::mlir::chlo::symbolizeEnum<::mlir::chlo::ComparisonType>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid Which comparison type to use. specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::chlo::ComparisonType value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::chlo::ComparisonType> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::chlo::ComparisonType getEmptyKey() {
    return static_cast<::mlir::chlo::ComparisonType>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::chlo::ComparisonType getTombstoneKey() {
    return static_cast<::mlir::chlo::ComparisonType>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::chlo::ComparisonType &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::chlo::ComparisonType &lhs, const ::mlir::chlo::ComparisonType &rhs) {
    return lhs == rhs;
  }
};
}

namespace mlir {
namespace chlo {
// XLA precision for an operand. Has backend specific meaning.
enum class Precision : uint32_t {
  DEFAULT = 0,
  HIGH = 1,
  HIGHEST = 2,
};

::std::optional<Precision> symbolizePrecision(uint32_t);
::llvm::StringRef stringifyPrecision(Precision);
::std::optional<Precision> symbolizePrecision(::llvm::StringRef);
inline constexpr unsigned getMaxEnumValForPrecision() {
  return 2;
}


inline ::llvm::StringRef stringifyEnum(Precision enumValue) {
  return stringifyPrecision(enumValue);
}

template <typename EnumType>
::std::optional<EnumType> symbolizeEnum(::llvm::StringRef);

template <>
inline ::std::optional<Precision> symbolizeEnum<Precision>(::llvm::StringRef str) {
  return symbolizePrecision(str);
}
} // namespace chlo
} // namespace mlir

namespace mlir {
template <typename T, typename>
struct FieldParser;

template<>
struct FieldParser<::mlir::chlo::Precision, ::mlir::chlo::Precision> {
  template <typename ParserT>
  static FailureOr<::mlir::chlo::Precision> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return parser.emitError(loc, "expected keyword for XLA precision for an operand. Has backend specific meaning.");

    // Symbolize the keyword.
    if (::std::optional<::mlir::chlo::Precision> attr = ::mlir::chlo::symbolizeEnum<::mlir::chlo::Precision>(enumKeyword))
      return *attr;
    return parser.emitError(loc, "invalid XLA precision for an operand. Has backend specific meaning. specification: ") << enumKeyword;
  }
};

/// Support for std::optional, useful in attribute/type definition where the enum is
/// used as:
///
///    let parameters = (ins OptionalParameter<"std::optional<TheEnumName>">:$value);
template<>
struct FieldParser<std::optional<::mlir::chlo::Precision>, std::optional<::mlir::chlo::Precision>> {
  template <typename ParserT>
  static FailureOr<std::optional<::mlir::chlo::Precision>> parse(ParserT &parser) {
    // Parse the keyword/string containing the enum.
    std::string enumKeyword;
    auto loc = parser.getCurrentLocation();
    if (failed(parser.parseOptionalKeywordOrString(&enumKeyword)))
      return std::optional<::mlir::chlo::Precision>{};

    // Symbolize the keyword.
    if (::std::optional<::mlir::chlo::Precision> attr = ::mlir::chlo::symbolizeEnum<::mlir::chlo::Precision>(enumKeyword))
      return attr;
    return parser.emitError(loc, "invalid XLA precision for an operand. Has backend specific meaning. specification: ") << enumKeyword;
  }
};
} // namespace mlir

namespace llvm {
inline ::llvm::raw_ostream &operator<<(::llvm::raw_ostream &p, ::mlir::chlo::Precision value) {
  auto valueStr = stringifyEnum(value);
  return p << valueStr;
}
} // namespace llvm

namespace llvm {
template<> struct DenseMapInfo<::mlir::chlo::Precision> {
  using StorageInfo = ::llvm::DenseMapInfo<uint32_t>;

  static inline ::mlir::chlo::Precision getEmptyKey() {
    return static_cast<::mlir::chlo::Precision>(StorageInfo::getEmptyKey());
  }

  static inline ::mlir::chlo::Precision getTombstoneKey() {
    return static_cast<::mlir::chlo::Precision>(StorageInfo::getTombstoneKey());
  }

  static unsigned getHashValue(const ::mlir::chlo::Precision &val) {
    return StorageInfo::getHashValue(static_cast<uint32_t>(val));
  }

  static bool isEqual(const ::mlir::chlo::Precision &lhs, const ::mlir::chlo::Precision &rhs) {
    return lhs == rhs;
  }
};
}

