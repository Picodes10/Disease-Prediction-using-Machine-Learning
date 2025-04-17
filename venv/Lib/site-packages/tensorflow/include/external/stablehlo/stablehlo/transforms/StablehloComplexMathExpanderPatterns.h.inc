/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Rewriters                                                                  *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: StablehloComplexMathExpanderPatterns.td                              *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


static ::llvm::LogicalResult __mlir_ods_local_type_constraint_StablehloComplexMathExpanderPatterns1(
    ::mlir::PatternRewriter &rewriter, ::mlir::Operation *op, ::mlir::Type type,
    ::llvm::StringRef failureStr) {
  if (!((isa<ComplexType>(cast<ShapedType>(type).getElementType())))) {
    return rewriter.notifyMatchFailure(op, [&](::mlir::Diagnostic &diag) {
      diag << failureStr << ": Complex element type";
    });
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_StablehloComplexMathExpanderPatterns1(
    ::mlir::PatternRewriter &rewriter, ::mlir::Operation *op, ::mlir::Attribute attr,
    ::llvm::StringRef failureStr) {
  if (!((attr == ResultAccuracyAttr::get(rewriter.getContext(), APFloat(0.0), APFloat(0.0), 0, ResultAccuracyModeAttr::get(rewriter.getContext(), ::mlir::stablehlo::ResultAccuracyMode::DEFAULT))))) {
    return rewriter.notifyMatchFailure(op, [&](::mlir::Diagnostic &diag) {
      diag << failureStr << ": constant attribute ::mlir::stablehlo::ResultAccuracyMode::DEFAULT";
    });
  }
  return ::mlir::success();
}
/* Generated from:
    external/stablehlo/stablehlo/transforms/StablehloComplexMathExpanderPatterns.td:689
*/
struct ExpOp_ComplexElementType_ComplexMathExpander : public ::mlir::RewritePattern {
  ExpOp_ComplexElementType_ComplexMathExpander(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("stablehlo.exponential", 1, context, {"stablehlo.compare", "stablehlo.complex", "stablehlo.cosine", "stablehlo.exponential", "stablehlo.imag", "stablehlo.multiply", "stablehlo.real", "stablehlo.select", "stablehlo.sine"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::Operation::operand_range z(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::stablehlo::ExpOp>(op0); (void)castedOp0;
    if(::mlir::failed(__mlir_ods_local_type_constraint_StablehloComplexMathExpanderPatterns1(rewriter, castedOp0, (*castedOp0.getODSOperands(0).begin()).getType(), "operand 0 of op 'stablehlo.exponential' failed to satisfy constraint: 'Complex element type'"))) {
      return ::mlir::failure();
    }
    z = castedOp0.getODSOperands(0);
    {
      auto tblgen_attr = op0->getAttrOfType<::mlir::stablehlo::ResultAccuracyAttr>("result_accuracy");(void)tblgen_attr;
      if (!tblgen_attr) tblgen_attr = ResultAccuracyAttr::get(rewriter.getContext(), APFloat(0.0), APFloat(0.0), 0, ResultAccuracyModeAttr::get(rewriter.getContext(), ::mlir::stablehlo::ResultAccuracyMode::DEFAULT));
      if (!tblgen_attr) return ::mlir::failure();
      if(::mlir::failed(__mlir_ods_local_attr_constraint_StablehloComplexMathExpanderPatterns1(rewriter, op0, tblgen_attr, "op 'stablehlo.exponential' attribute 'result_accuracy' failed to satisfy constraint: 'constant attribute ::mlir::stablehlo::ResultAccuracyMode::DEFAULT'"))) {
        return ::mlir::failure();
      }
    }

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::stablehlo::RealOp x;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      x = rewriter.create<::mlir::stablehlo::RealOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::ExpOp e;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      e = rewriter.create<::mlir::stablehlo::ExpOp>(odsLoc,
        /*operand=*/tblgen_value_0,
        ResultAccuracyAttr::get(rewriter.getContext(), APFloat(0.0), APFloat(0.0), 0, ResultAccuracyModeAttr::get(rewriter.getContext(), ::mlir::stablehlo::ResultAccuracyMode::DEFAULT))
      );
    }
    auto nativeVar_0 = ::mlir::stablehlo::getConstantLikeInfValue(rewriter, odsLoc, (*x.getODSResults(0).begin()), /*negative=*/false); (void)nativeVar_0;
    auto nativeVar_1 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_1;
    ::mlir::stablehlo::CompareOp eq_e_constant_posinf;
    {
      ::mlir::Value tblgen_value_0 = (*e.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_0;
      eq_e_constant_posinf = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_1
      );
    }
    auto nativeVar_2 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0.5, (*x.getODSResults(0).begin())); (void)nativeVar_2;
    ::mlir::stablehlo::MulOp tblgen_MulOp_3;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_2;
      tblgen_MulOp_3 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::ExpOp e2;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_3.getODSResults(0).begin());
      e2 = rewriter.create<::mlir::stablehlo::ExpOp>(odsLoc,
        /*operand=*/tblgen_value_0,
        ResultAccuracyAttr::get(rewriter.getContext(), APFloat(0.0), APFloat(0.0), 0, ResultAccuracyModeAttr::get(rewriter.getContext(), ::mlir::stablehlo::ResultAccuracyMode::DEFAULT))
      );
    }
    ::mlir::stablehlo::ImagOp y;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      y = rewriter.create<::mlir::stablehlo::ImagOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::CosineOp cs;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      cs = rewriter.create<::mlir::stablehlo::CosineOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_4;
    {
      ::mlir::Value tblgen_value_0 = (*e2.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*cs.getODSResults(0).begin());
      tblgen_MulOp_4 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_5;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_4.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*e2.getODSResults(0).begin());
      tblgen_MulOp_5 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_6;
    {
      ::mlir::Value tblgen_value_0 = (*e.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*cs.getODSResults(0).begin());
      tblgen_MulOp_6 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_7;
    {
      ::mlir::Value tblgen_value_0 = (*eq_e_constant_posinf.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_5.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_6.getODSResults(0).begin());
      tblgen_SelectOp_7 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    auto zero = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0, (*x.getODSResults(0).begin())); (void)zero;
    auto nativeVar_8 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_8;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_9;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = zero;
      tblgen_CompareOp_9 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_8
      );
    }
    ::mlir::stablehlo::SineOp sn;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      sn = rewriter.create<::mlir::stablehlo::SineOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_10;
    {
      ::mlir::Value tblgen_value_0 = (*e2.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*sn.getODSResults(0).begin());
      tblgen_MulOp_10 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_11;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_10.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*e2.getODSResults(0).begin());
      tblgen_MulOp_11 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_12;
    {
      ::mlir::Value tblgen_value_0 = (*e.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*sn.getODSResults(0).begin());
      tblgen_MulOp_12 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_13;
    {
      ::mlir::Value tblgen_value_0 = (*eq_e_constant_posinf.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_11.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_12.getODSResults(0).begin());
      tblgen_SelectOp_13 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_14;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_9.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = zero;
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_13.getODSResults(0).begin());
      tblgen_SelectOp_14 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::ComplexOp tblgen_ComplexOp_15;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*tblgen_SelectOp_7.getODSResults(0).begin()));
      tblgen_values.push_back((*tblgen_SelectOp_14.getODSResults(0).begin()));
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_ComplexOp_15 = rewriter.create<::mlir::stablehlo::ComplexOp>(odsLoc, tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_ComplexOp_15.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/stablehlo/stablehlo/transforms/StablehloComplexMathExpanderPatterns.td:144
*/
struct Log1pOp_ComplexElementType_ComplexMathExpander : public ::mlir::RewritePattern {
  Log1pOp_ComplexElementType_ComplexMathExpander(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("stablehlo.log_plus_one", 1, context, {"stablehlo.abs", "stablehlo.add", "stablehlo.atan2", "stablehlo.compare", "stablehlo.complex", "stablehlo.divide", "stablehlo.imag", "stablehlo.log", "stablehlo.log_plus_one", "stablehlo.maximum", "stablehlo.minimum", "stablehlo.multiply", "stablehlo.negate", "stablehlo.real", "stablehlo.select", "stablehlo.sqrt", "stablehlo.subtract"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::Operation::operand_range z(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::stablehlo::Log1pOp>(op0); (void)castedOp0;
    if(::mlir::failed(__mlir_ods_local_type_constraint_StablehloComplexMathExpanderPatterns1(rewriter, castedOp0, (*castedOp0.getODSOperands(0).begin()).getType(), "operand 0 of op 'stablehlo.log_plus_one' failed to satisfy constraint: 'Complex element type'"))) {
      return ::mlir::failure();
    }
    z = castedOp0.getODSOperands(0);

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::stablehlo::RealOp x;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      x = rewriter.create<::mlir::stablehlo::RealOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::AbsOp ax;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ax = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::ImagOp y;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      y = rewriter.create<::mlir::stablehlo::ImagOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::AbsOp ay;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ay = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MaxOp mx;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      mx = rewriter.create<::mlir::stablehlo::MaxOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto largest = ::mlir::stablehlo::getConstantLikeMaxFiniteValue(rewriter, odsLoc, (*x.getODSResults(0).begin())); (void)largest;
    ::mlir::stablehlo::SqrtOp tblgen_SqrtOp_0;
    {
      ::mlir::Value tblgen_value_0 = largest;
      tblgen_SqrtOp_0 = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_1 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0.01, (*x.getODSResults(0).begin())); (void)nativeVar_1;
    ::mlir::stablehlo::MulOp tblgen_MulOp_2;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SqrtOp_0.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_1;
      tblgen_MulOp_2 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_3 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_3;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_4;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_2.getODSResults(0).begin());
      tblgen_CompareOp_4 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_3
      );
    }
    ::mlir::stablehlo::LogOp tblgen_LogOp_5;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      tblgen_LogOp_5 = rewriter.create<::mlir::stablehlo::LogOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto half = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0.5, (*x.getODSResults(0).begin())); (void)half;
    ::mlir::stablehlo::MinOp mn;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      mn = rewriter.create<::mlir::stablehlo::MinOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_6 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_6;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_7;
    {
      ::mlir::Value tblgen_value_0 = (*mn.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mx.getODSResults(0).begin());
      tblgen_CompareOp_7 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_6
      );
    }
    auto one = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1, (*x.getODSResults(0).begin())); (void)one;
    ::mlir::stablehlo::DivOp r;
    {
      ::mlir::Value tblgen_value_0 = (*mn.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mx.getODSResults(0).begin());
      r = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_8;
    {
      ::mlir::Value tblgen_value_0 = (*r.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*r.getODSResults(0).begin());
      tblgen_MulOp_8 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_9;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_7.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = one;
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_8.getODSResults(0).begin());
      tblgen_SelectOp_9 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::Log1pOp tblgen_Log1pOp_10;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SelectOp_9.getODSResults(0).begin());
      tblgen_Log1pOp_10 = rewriter.create<::mlir::stablehlo::Log1pOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_11;
    {
      ::mlir::Value tblgen_value_0 = half;
      ::mlir::Value tblgen_value_1 = (*tblgen_Log1pOp_10.getODSResults(0).begin());
      tblgen_MulOp_11 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_12;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_LogOp_5.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_11.getODSResults(0).begin());
      tblgen_AddOp_12 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp xp1;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = one;
      xp1 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AbsOp tblgen_AbsOp_13;
    {
      ::mlir::Value tblgen_value_0 = (*xp1.getODSResults(0).begin());
      tblgen_AbsOp_13 = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_14;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AbsOp_13.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      tblgen_AddOp_14 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_15 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0.2, (*x.getODSResults(0).begin())); (void)nativeVar_15;
    auto nativeVar_16 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_16;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_17;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_14.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_15;
      tblgen_CompareOp_17 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::LT),
        /*compare_type=*/nativeVar_16
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_18;
    {
      ::mlir::Value tblgen_value_0 = (*xp1.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xp1.getODSResults(0).begin());
      tblgen_MulOp_18 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp square_dekker_high;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*y.getODSResults(0).begin());
      square_dekker_high = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_19;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_18.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*square_dekker_high.getODSResults(0).begin());
      tblgen_AddOp_19 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::LogOp tblgen_LogOp_20;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_19.getODSResults(0).begin());
      tblgen_LogOp_20 = rewriter.create<::mlir::stablehlo::LogOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_21;
    {
      ::mlir::Value tblgen_value_0 = half;
      ::mlir::Value tblgen_value_1 = (*tblgen_LogOp_20.getODSResults(0).begin());
      tblgen_MulOp_21 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp x2h;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x.getODSResults(0).begin());
      x2h = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_2sum_high_2_;
    {
      ::mlir::Value tblgen_value_0 = (*x2h.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*square_dekker_high.getODSResults(0).begin());
      _add_2sum_high_2_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp _square_dekker_high_0_;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x.getODSResults(0).begin());
      _square_dekker_high_0_ = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_2sum_high_1_;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_2_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_square_dekker_high_0_.getODSResults(0).begin());
      _add_2sum_high_1_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::NegOp tblgen_NegOp_22;
    {
      ::mlir::Value tblgen_value_0 = (*square_dekker_high.getODSResults(0).begin());
      tblgen_NegOp_22 = rewriter.create<::mlir::stablehlo::NegOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_23 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1e+308, (*x.getODSResults(0).begin())); (void)nativeVar_23;
    auto nativeVar_24 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_24;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_25;
    {
      ::mlir::Value tblgen_value_0 = largest;
      ::mlir::Value tblgen_value_1 = nativeVar_23;
      tblgen_CompareOp_25 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_24
      );
    }
    auto nativeVar_26 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 134217729, (*x.getODSResults(0).begin())); (void)nativeVar_26;
    auto nativeVar_27 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1e+38, (*x.getODSResults(0).begin())); (void)nativeVar_27;
    auto nativeVar_28 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_28;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_29;
    {
      ::mlir::Value tblgen_value_0 = largest;
      ::mlir::Value tblgen_value_1 = nativeVar_27;
      tblgen_CompareOp_29 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_28
      );
    }
    auto nativeVar_30 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 4097, (*x.getODSResults(0).begin())); (void)nativeVar_30;
    auto nativeVar_31 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 65, (*x.getODSResults(0).begin())); (void)nativeVar_31;
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_32;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_29.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_30;
      ::mlir::Value tblgen_value_2 = nativeVar_31;
      tblgen_SelectOp_32 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp veltkamp_splitter_constant;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_25.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_26;
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_32.getODSResults(0).begin());
      veltkamp_splitter_constant = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::MulOp multiply_veltkamp_splitter_constant_y;
    {
      ::mlir::Value tblgen_value_0 = (*veltkamp_splitter_constant.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*y.getODSResults(0).begin());
      multiply_veltkamp_splitter_constant_y = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_33;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_veltkamp_splitter_constant_y.getODSResults(0).begin());
      tblgen_SubtractOp_33 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp yh;
    {
      ::mlir::Value tblgen_value_0 = (*multiply_veltkamp_splitter_constant_y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_33.getODSResults(0).begin());
      yh = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_34;
    {
      ::mlir::Value tblgen_value_0 = (*yh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yh.getODSResults(0).begin());
      tblgen_MulOp_34 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_35;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_NegOp_22.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_34.getODSResults(0).begin());
      tblgen_AddOp_35 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp yl;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yh.getODSResults(0).begin());
      yl = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp multiply_yh_yl;
    {
      ::mlir::Value tblgen_value_0 = (*yh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yl.getODSResults(0).begin());
      multiply_yh_yl = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_36;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_35.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_yh_yl.getODSResults(0).begin());
      tblgen_AddOp_36 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_37;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_36.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_yh_yl.getODSResults(0).begin());
      tblgen_AddOp_37 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_38;
    {
      ::mlir::Value tblgen_value_0 = (*yl.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yl.getODSResults(0).begin());
      tblgen_MulOp_38 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp square_dekker_low;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_37.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_38.getODSResults(0).begin());
      square_dekker_low = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_2sum_high_0_;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*square_dekker_low.getODSResults(0).begin());
      _add_2sum_high_0_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::NegOp tblgen_NegOp_39;
    {
      ::mlir::Value tblgen_value_0 = (*_square_dekker_high_0_.getODSResults(0).begin());
      tblgen_NegOp_39 = rewriter.create<::mlir::stablehlo::NegOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp multiply_veltkamp_splitter_constant_x;
    {
      ::mlir::Value tblgen_value_0 = (*veltkamp_splitter_constant.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x.getODSResults(0).begin());
      multiply_veltkamp_splitter_constant_x = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_40;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_veltkamp_splitter_constant_x.getODSResults(0).begin());
      tblgen_SubtractOp_40 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp xh;
    {
      ::mlir::Value tblgen_value_0 = (*multiply_veltkamp_splitter_constant_x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_40.getODSResults(0).begin());
      xh = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_41;
    {
      ::mlir::Value tblgen_value_0 = (*xh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xh.getODSResults(0).begin());
      tblgen_MulOp_41 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_42;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_NegOp_39.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_41.getODSResults(0).begin());
      tblgen_AddOp_42 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp xl;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xh.getODSResults(0).begin());
      xl = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp multiply_xh_xl;
    {
      ::mlir::Value tblgen_value_0 = (*xh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xl.getODSResults(0).begin());
      multiply_xh_xl = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_43;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_42.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_xh_xl.getODSResults(0).begin());
      tblgen_AddOp_43 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_44;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_43.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_xh_xl.getODSResults(0).begin());
      tblgen_AddOp_44 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_45;
    {
      ::mlir::Value tblgen_value_0 = (*xl.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xl.getODSResults(0).begin());
      tblgen_MulOp_45 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _square_dekker_low_0_;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_44.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_45.getODSResults(0).begin());
      _square_dekker_low_0_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp add_2sum_high;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_square_dekker_low_0_.getODSResults(0).begin());
      add_2sum_high = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp subtract__add_2sum_high_2__x2h;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_2_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x2h.getODSResults(0).begin());
      subtract__add_2sum_high_2__x2h = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_46;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_2_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract__add_2sum_high_2__x2h.getODSResults(0).begin());
      tblgen_SubtractOp_46 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_47;
    {
      ::mlir::Value tblgen_value_0 = (*x2h.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_46.getODSResults(0).begin());
      tblgen_SubtractOp_47 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_48;
    {
      ::mlir::Value tblgen_value_0 = (*square_dekker_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract__add_2sum_high_2__x2h.getODSResults(0).begin());
      tblgen_SubtractOp_48 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp add_2sum_low;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SubtractOp_47.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_48.getODSResults(0).begin());
      add_2sum_low = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp subtract__add_2sum_high_1___add_2sum_high_2_;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_2sum_high_2_.getODSResults(0).begin());
      subtract__add_2sum_high_1___add_2sum_high_2_ = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_49;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract__add_2sum_high_1___add_2sum_high_2_.getODSResults(0).begin());
      tblgen_SubtractOp_49 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_50;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_2_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_49.getODSResults(0).begin());
      tblgen_SubtractOp_50 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_51;
    {
      ::mlir::Value tblgen_value_0 = (*_square_dekker_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract__add_2sum_high_1___add_2sum_high_2_.getODSResults(0).begin());
      tblgen_SubtractOp_51 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_2sum_low_0_;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SubtractOp_50.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_51.getODSResults(0).begin());
      _add_2sum_low_0_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_52;
    {
      ::mlir::Value tblgen_value_0 = (*add_2sum_low.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_2sum_low_0_.getODSResults(0).begin());
      tblgen_AddOp_52 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp subtract__add_2sum_high_0___add_2sum_high_1_;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_2sum_high_1_.getODSResults(0).begin());
      subtract__add_2sum_high_0___add_2sum_high_1_ = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_53;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract__add_2sum_high_0___add_2sum_high_1_.getODSResults(0).begin());
      tblgen_SubtractOp_53 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_54;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_53.getODSResults(0).begin());
      tblgen_SubtractOp_54 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_55;
    {
      ::mlir::Value tblgen_value_0 = (*square_dekker_low.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract__add_2sum_high_0___add_2sum_high_1_.getODSResults(0).begin());
      tblgen_SubtractOp_55 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_2sum_low_1_;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SubtractOp_54.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_55.getODSResults(0).begin());
      _add_2sum_low_1_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_56;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_52.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_2sum_low_1_.getODSResults(0).begin());
      tblgen_AddOp_56 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp subtract_add_2sum_high__add_2sum_high_0_;
    {
      ::mlir::Value tblgen_value_0 = (*add_2sum_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_2sum_high_0_.getODSResults(0).begin());
      subtract_add_2sum_high__add_2sum_high_0_ = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_57;
    {
      ::mlir::Value tblgen_value_0 = (*add_2sum_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract_add_2sum_high__add_2sum_high_0_.getODSResults(0).begin());
      tblgen_SubtractOp_57 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_58;
    {
      ::mlir::Value tblgen_value_0 = (*_add_2sum_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_57.getODSResults(0).begin());
      tblgen_SubtractOp_58 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_59;
    {
      ::mlir::Value tblgen_value_0 = (*_square_dekker_low_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*subtract_add_2sum_high__add_2sum_high_0_.getODSResults(0).begin());
      tblgen_SubtractOp_59 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_2sum_low_2_;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SubtractOp_58.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_59.getODSResults(0).begin());
      _add_2sum_low_2_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_60;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_56.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_2sum_low_2_.getODSResults(0).begin());
      tblgen_AddOp_60 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp sum_2sum_high;
    {
      ::mlir::Value tblgen_value_0 = (*add_2sum_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_AddOp_60.getODSResults(0).begin());
      sum_2sum_high = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::Log1pOp tblgen_Log1pOp_61;
    {
      ::mlir::Value tblgen_value_0 = (*sum_2sum_high.getODSResults(0).begin());
      tblgen_Log1pOp_61 = rewriter.create<::mlir::stablehlo::Log1pOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_62;
    {
      ::mlir::Value tblgen_value_0 = half;
      ::mlir::Value tblgen_value_1 = (*tblgen_Log1pOp_61.getODSResults(0).begin());
      tblgen_MulOp_62 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_63;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_17.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_21.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_62.getODSResults(0).begin());
      tblgen_SelectOp_63 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_64;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_4.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_AddOp_12.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_63.getODSResults(0).begin());
      tblgen_SelectOp_64 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::Atan2Op tblgen_Atan2Op_65;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xp1.getODSResults(0).begin());
      tblgen_Atan2Op_65 = rewriter.create<::mlir::stablehlo::Atan2Op>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::ComplexOp tblgen_ComplexOp_66;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*tblgen_SelectOp_64.getODSResults(0).begin()));
      tblgen_values.push_back((*tblgen_Atan2Op_65.getODSResults(0).begin()));
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_ComplexOp_66 = rewriter.create<::mlir::stablehlo::ComplexOp>(odsLoc, tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_ComplexOp_66.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/stablehlo/stablehlo/transforms/StablehloComplexMathExpanderPatterns.td:549
*/
struct LogOp_ComplexElementType_ComplexMathExpander : public ::mlir::RewritePattern {
  LogOp_ComplexElementType_ComplexMathExpander(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("stablehlo.log", 1, context, {"stablehlo.abs", "stablehlo.add", "stablehlo.atan2", "stablehlo.compare", "stablehlo.complex", "stablehlo.divide", "stablehlo.imag", "stablehlo.log", "stablehlo.log_plus_one", "stablehlo.maximum", "stablehlo.minimum", "stablehlo.multiply", "stablehlo.negate", "stablehlo.real", "stablehlo.select", "stablehlo.subtract"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::Operation::operand_range z(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::stablehlo::LogOp>(op0); (void)castedOp0;
    if(::mlir::failed(__mlir_ods_local_type_constraint_StablehloComplexMathExpanderPatterns1(rewriter, castedOp0, (*castedOp0.getODSOperands(0).begin()).getType(), "operand 0 of op 'stablehlo.log' failed to satisfy constraint: 'Complex element type'"))) {
      return ::mlir::failure();
    }
    z = castedOp0.getODSOperands(0);

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::stablehlo::RealOp x;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      x = rewriter.create<::mlir::stablehlo::RealOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto constant_fneg1 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, -1.0, x); (void)constant_fneg1;
    ::mlir::stablehlo::ImagOp y;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      y = rewriter.create<::mlir::stablehlo::ImagOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp square_dekker_high;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*y.getODSResults(0).begin());
      square_dekker_high = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp _square_dekker_high_0_;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x.getODSResults(0).begin());
      _square_dekker_high_0_ = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_0 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_0;
    ::mlir::stablehlo::CompareOp gt_square_dekker_high__square_dekker_high_0_;
    {
      ::mlir::Value tblgen_value_0 = (*square_dekker_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_square_dekker_high_0_.getODSResults(0).begin());
      gt_square_dekker_high__square_dekker_high_0_ = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_0
      );
    }
    ::mlir::stablehlo::SelectOp mxh;
    {
      ::mlir::Value tblgen_value_0 = (*gt_square_dekker_high__square_dekker_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*square_dekker_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*_square_dekker_high_0_.getODSResults(0).begin());
      mxh = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::AddOp _add_fast2sum_high_2_;
    {
      ::mlir::Value tblgen_value_0 = constant_fneg1;
      ::mlir::Value tblgen_value_1 = (*mxh.getODSResults(0).begin());
      _add_fast2sum_high_2_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp mnh;
    {
      ::mlir::Value tblgen_value_0 = (*gt_square_dekker_high__square_dekker_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_square_dekker_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*square_dekker_high.getODSResults(0).begin());
      mnh = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::AddOp _add_fast2sum_high_1_;
    {
      ::mlir::Value tblgen_value_0 = (*_add_fast2sum_high_2_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mnh.getODSResults(0).begin());
      _add_fast2sum_high_1_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::NegOp tblgen_NegOp_1;
    {
      ::mlir::Value tblgen_value_0 = (*square_dekker_high.getODSResults(0).begin());
      tblgen_NegOp_1 = rewriter.create<::mlir::stablehlo::NegOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto largest = ::mlir::stablehlo::getConstantLikeMaxFiniteValue(rewriter, odsLoc, (*x.getODSResults(0).begin())); (void)largest;
    auto nativeVar_2 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1e+308, (*x.getODSResults(0).begin())); (void)nativeVar_2;
    auto nativeVar_3 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_3;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_4;
    {
      ::mlir::Value tblgen_value_0 = largest;
      ::mlir::Value tblgen_value_1 = nativeVar_2;
      tblgen_CompareOp_4 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_3
      );
    }
    auto nativeVar_5 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 134217729, (*x.getODSResults(0).begin())); (void)nativeVar_5;
    auto nativeVar_6 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1e+38, (*x.getODSResults(0).begin())); (void)nativeVar_6;
    auto nativeVar_7 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_7;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_8;
    {
      ::mlir::Value tblgen_value_0 = largest;
      ::mlir::Value tblgen_value_1 = nativeVar_6;
      tblgen_CompareOp_8 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_7
      );
    }
    auto nativeVar_9 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 4097, (*x.getODSResults(0).begin())); (void)nativeVar_9;
    auto nativeVar_10 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 65, (*x.getODSResults(0).begin())); (void)nativeVar_10;
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_11;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_8.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_9;
      ::mlir::Value tblgen_value_2 = nativeVar_10;
      tblgen_SelectOp_11 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp veltkamp_splitter_constant;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_4.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_5;
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_11.getODSResults(0).begin());
      veltkamp_splitter_constant = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::MulOp multiply_veltkamp_splitter_constant_y;
    {
      ::mlir::Value tblgen_value_0 = (*veltkamp_splitter_constant.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*y.getODSResults(0).begin());
      multiply_veltkamp_splitter_constant_y = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_12;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_veltkamp_splitter_constant_y.getODSResults(0).begin());
      tblgen_SubtractOp_12 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp yh;
    {
      ::mlir::Value tblgen_value_0 = (*multiply_veltkamp_splitter_constant_y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_12.getODSResults(0).begin());
      yh = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_13;
    {
      ::mlir::Value tblgen_value_0 = (*yh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yh.getODSResults(0).begin());
      tblgen_MulOp_13 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_14;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_NegOp_1.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_13.getODSResults(0).begin());
      tblgen_AddOp_14 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp yl;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yh.getODSResults(0).begin());
      yl = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp multiply_yh_yl;
    {
      ::mlir::Value tblgen_value_0 = (*yh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yl.getODSResults(0).begin());
      multiply_yh_yl = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_15;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_14.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_yh_yl.getODSResults(0).begin());
      tblgen_AddOp_15 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_16;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_15.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_yh_yl.getODSResults(0).begin());
      tblgen_AddOp_16 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_17;
    {
      ::mlir::Value tblgen_value_0 = (*yl.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*yl.getODSResults(0).begin());
      tblgen_MulOp_17 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp square_dekker_low;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_16.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_17.getODSResults(0).begin());
      square_dekker_low = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _add_fast2sum_high_0_;
    {
      ::mlir::Value tblgen_value_0 = (*_add_fast2sum_high_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*square_dekker_low.getODSResults(0).begin());
      _add_fast2sum_high_0_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::NegOp tblgen_NegOp_18;
    {
      ::mlir::Value tblgen_value_0 = (*_square_dekker_high_0_.getODSResults(0).begin());
      tblgen_NegOp_18 = rewriter.create<::mlir::stablehlo::NegOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp multiply_veltkamp_splitter_constant_x;
    {
      ::mlir::Value tblgen_value_0 = (*veltkamp_splitter_constant.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x.getODSResults(0).begin());
      multiply_veltkamp_splitter_constant_x = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_19;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_veltkamp_splitter_constant_x.getODSResults(0).begin());
      tblgen_SubtractOp_19 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp xh;
    {
      ::mlir::Value tblgen_value_0 = (*multiply_veltkamp_splitter_constant_x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_19.getODSResults(0).begin());
      xh = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_20;
    {
      ::mlir::Value tblgen_value_0 = (*xh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xh.getODSResults(0).begin());
      tblgen_MulOp_20 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_21;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_NegOp_18.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_20.getODSResults(0).begin());
      tblgen_AddOp_21 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp xl;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xh.getODSResults(0).begin());
      xl = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp multiply_xh_xl;
    {
      ::mlir::Value tblgen_value_0 = (*xh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xl.getODSResults(0).begin());
      multiply_xh_xl = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_22;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_21.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_xh_xl.getODSResults(0).begin());
      tblgen_AddOp_22 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_23;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_22.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*multiply_xh_xl.getODSResults(0).begin());
      tblgen_AddOp_23 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_24;
    {
      ::mlir::Value tblgen_value_0 = (*xl.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*xl.getODSResults(0).begin());
      tblgen_MulOp_24 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp _square_dekker_low_0_;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_23.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_24.getODSResults(0).begin());
      _square_dekker_low_0_ = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp add_fast2sum_high;
    {
      ::mlir::Value tblgen_value_0 = (*_add_fast2sum_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_square_dekker_low_0_.getODSResults(0).begin());
      add_fast2sum_high = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_25;
    {
      ::mlir::Value tblgen_value_0 = (*_add_fast2sum_high_2_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_fneg1;
      tblgen_SubtractOp_25 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp add_fast2sum_low;
    {
      ::mlir::Value tblgen_value_0 = (*mxh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_25.getODSResults(0).begin());
      add_fast2sum_low = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_26;
    {
      ::mlir::Value tblgen_value_0 = (*_add_fast2sum_high_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_fast2sum_high_2_.getODSResults(0).begin());
      tblgen_SubtractOp_26 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp _add_fast2sum_low_0_;
    {
      ::mlir::Value tblgen_value_0 = (*mnh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_26.getODSResults(0).begin());
      _add_fast2sum_low_0_ = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_27;
    {
      ::mlir::Value tblgen_value_0 = (*add_fast2sum_low.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_fast2sum_low_0_.getODSResults(0).begin());
      tblgen_AddOp_27 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_28;
    {
      ::mlir::Value tblgen_value_0 = (*_add_fast2sum_high_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_fast2sum_high_1_.getODSResults(0).begin());
      tblgen_SubtractOp_28 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp _add_fast2sum_low_1_;
    {
      ::mlir::Value tblgen_value_0 = (*square_dekker_low.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_28.getODSResults(0).begin());
      _add_fast2sum_low_1_ = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_29;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_27.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_fast2sum_low_1_.getODSResults(0).begin());
      tblgen_AddOp_29 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp tblgen_SubtractOp_30;
    {
      ::mlir::Value tblgen_value_0 = (*add_fast2sum_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_fast2sum_high_0_.getODSResults(0).begin());
      tblgen_SubtractOp_30 = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SubtractOp _add_fast2sum_low_2_;
    {
      ::mlir::Value tblgen_value_0 = (*_square_dekker_low_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SubtractOp_30.getODSResults(0).begin());
      _add_fast2sum_low_2_ = rewriter.create<::mlir::stablehlo::SubtractOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_31;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_29.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_add_fast2sum_low_2_.getODSResults(0).begin());
      tblgen_AddOp_31 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp sum_fast2sum_high;
    {
      ::mlir::Value tblgen_value_0 = (*add_fast2sum_high.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_AddOp_31.getODSResults(0).begin());
      sum_fast2sum_high = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AbsOp tblgen_AbsOp_32;
    {
      ::mlir::Value tblgen_value_0 = (*sum_fast2sum_high.getODSResults(0).begin());
      tblgen_AbsOp_32 = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto half = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0.5, (*x.getODSResults(0).begin())); (void)half;
    auto nativeVar_33 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_33;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_34;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AbsOp_32.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = half;
      tblgen_CompareOp_34 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::LT),
        /*compare_type=*/nativeVar_33
      );
    }
    ::mlir::stablehlo::Log1pOp tblgen_Log1pOp_35;
    {
      ::mlir::Value tblgen_value_0 = (*sum_fast2sum_high.getODSResults(0).begin());
      tblgen_Log1pOp_35 = rewriter.create<::mlir::stablehlo::Log1pOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_36;
    {
      ::mlir::Value tblgen_value_0 = half;
      ::mlir::Value tblgen_value_1 = (*tblgen_Log1pOp_35.getODSResults(0).begin());
      tblgen_MulOp_36 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AbsOp abs_x;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      abs_x = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::AbsOp abs_y;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      abs_y = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MaxOp mx;
    {
      ::mlir::Value tblgen_value_0 = (*abs_x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*abs_y.getODSResults(0).begin());
      mx = rewriter.create<::mlir::stablehlo::MaxOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::LogOp tblgen_LogOp_37;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      tblgen_LogOp_37 = rewriter.create<::mlir::stablehlo::LogOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MinOp mn;
    {
      ::mlir::Value tblgen_value_0 = (*abs_x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*abs_y.getODSResults(0).begin());
      mn = rewriter.create<::mlir::stablehlo::MinOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_38 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_38;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_39;
    {
      ::mlir::Value tblgen_value_0 = (*mn.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mx.getODSResults(0).begin());
      tblgen_CompareOp_39 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_38
      );
    }
    auto nativeVar_40 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1.0, (*x.getODSResults(0).begin())); (void)nativeVar_40;
    ::mlir::stablehlo::DivOp tblgen_DivOp_41;
    {
      ::mlir::Value tblgen_value_0 = (*mn.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mx.getODSResults(0).begin());
      tblgen_DivOp_41 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp mn_over_mx;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_39.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_40;
      ::mlir::Value tblgen_value_2 = (*tblgen_DivOp_41.getODSResults(0).begin());
      mn_over_mx = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_42;
    {
      ::mlir::Value tblgen_value_0 = (*mn_over_mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mn_over_mx.getODSResults(0).begin());
      tblgen_MulOp_42 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::Log1pOp tblgen_Log1pOp_43;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_42.getODSResults(0).begin());
      tblgen_Log1pOp_43 = rewriter.create<::mlir::stablehlo::Log1pOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_44;
    {
      ::mlir::Value tblgen_value_0 = half;
      ::mlir::Value tblgen_value_1 = (*tblgen_Log1pOp_43.getODSResults(0).begin());
      tblgen_MulOp_44 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_45;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_LogOp_37.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_44.getODSResults(0).begin());
      tblgen_AddOp_45 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_46;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_34.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_36.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_AddOp_45.getODSResults(0).begin());
      tblgen_SelectOp_46 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::Atan2Op tblgen_Atan2Op_47;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*x.getODSResults(0).begin());
      tblgen_Atan2Op_47 = rewriter.create<::mlir::stablehlo::Atan2Op>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::ComplexOp tblgen_ComplexOp_48;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*tblgen_SelectOp_46.getODSResults(0).begin()));
      tblgen_values.push_back((*tblgen_Atan2Op_47.getODSResults(0).begin()));
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_ComplexOp_48 = rewriter.create<::mlir::stablehlo::ComplexOp>(odsLoc, tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_ComplexOp_48.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

/* Generated from:
    external/stablehlo/stablehlo/transforms/StablehloComplexMathExpanderPatterns.td:331
*/
struct SqrtOp_ComplexElementType_ComplexMathExpander : public ::mlir::RewritePattern {
  SqrtOp_ComplexElementType_ComplexMathExpander(::mlir::MLIRContext *context)
      : ::mlir::RewritePattern("stablehlo.sqrt", 1, context, {"stablehlo.abs", "stablehlo.add", "stablehlo.and", "stablehlo.compare", "stablehlo.complex", "stablehlo.divide", "stablehlo.imag", "stablehlo.maximum", "stablehlo.minimum", "stablehlo.multiply", "stablehlo.negate", "stablehlo.or", "stablehlo.real", "stablehlo.select", "stablehlo.sqrt"}) {}
  ::llvm::LogicalResult matchAndRewrite(::mlir::Operation *op0,
      ::mlir::PatternRewriter &rewriter) const override {
    // Variables for capturing values and attributes used while creating ops
    ::mlir::Operation::operand_range z(op0->getOperands());
    ::llvm::SmallVector<::mlir::Operation *, 4> tblgen_ops;

    // Match
    tblgen_ops.push_back(op0);
    auto castedOp0 = ::llvm::dyn_cast<::mlir::stablehlo::SqrtOp>(op0); (void)castedOp0;
    if(::mlir::failed(__mlir_ods_local_type_constraint_StablehloComplexMathExpanderPatterns1(rewriter, castedOp0, (*castedOp0.getODSOperands(0).begin()).getType(), "operand 0 of op 'stablehlo.sqrt' failed to satisfy constraint: 'Complex element type'"))) {
      return ::mlir::failure();
    }
    z = castedOp0.getODSOperands(0);

    // Rewrite
    auto odsLoc = rewriter.getFusedLoc({tblgen_ops[0]->getLoc()}); (void)odsLoc;
    ::llvm::SmallVector<::mlir::Value, 4> tblgen_repl_values;
    ::mlir::stablehlo::RealOp x;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      x = rewriter.create<::mlir::stablehlo::RealOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto constant_0 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 0, (*x.getODSResults(0).begin())); (void)constant_0;
    auto nativeVar_0 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_0;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_1;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_0;
      tblgen_CompareOp_1 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GE),
        /*compare_type=*/nativeVar_0
      );
    }
    ::mlir::stablehlo::AbsOp ax;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ax = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::ImagOp y;
    {
      ::mlir::Value tblgen_value_0 = (*z.begin());
      y = rewriter.create<::mlir::stablehlo::ImagOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::AbsOp ay;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ay = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_2 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_2;
    ::mlir::stablehlo::CompareOp eq_ax_ay;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      eq_ax_ay = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_2
      );
    }
    ::mlir::stablehlo::SqrtOp sq_ax;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      sq_ax = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_3 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1.5537739740300374, (*x.getODSResults(0).begin())); (void)nativeVar_3;
    ::mlir::stablehlo::MulOp tblgen_MulOp_4;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_3;
      tblgen_MulOp_4 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto sq_2 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1.4142135623730951, (*x.getODSResults(0).begin())); (void)sq_2;
    ::mlir::stablehlo::DivOp tblgen_DivOp_5;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_4.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = sq_2;
      tblgen_DivOp_5 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MaxOp mx;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      mx = rewriter.create<::mlir::stablehlo::MaxOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MinOp mn;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      mn = rewriter.create<::mlir::stablehlo::MinOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_6 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_6;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_7;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mn.getODSResults(0).begin());
      tblgen_CompareOp_7 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_6
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_8;
    {
      ::mlir::Value tblgen_value_0 = sq_2;
      ::mlir::Value tblgen_value_1 = (*mx.getODSResults(0).begin());
      tblgen_MulOp_8 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto one = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 1, (*x.getODSResults(0).begin())); (void)one;
    ::mlir::stablehlo::DivOp mn_over_mx;
    {
      ::mlir::Value tblgen_value_0 = (*mn.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mx.getODSResults(0).begin());
      mn_over_mx = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp r;
    {
      ::mlir::Value tblgen_value_0 = (*mn_over_mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*mn_over_mx.getODSResults(0).begin());
      r = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_9;
    {
      ::mlir::Value tblgen_value_0 = one;
      ::mlir::Value tblgen_value_1 = (*r.getODSResults(0).begin());
      tblgen_AddOp_9 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SqrtOp sqa;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_9.getODSResults(0).begin());
      sqa = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_10 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_10;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_11;
    {
      ::mlir::Value tblgen_value_0 = (*sqa.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = one;
      tblgen_CompareOp_11 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_10
      );
    }
    auto nativeVar_12 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_12;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_13;
    {
      ::mlir::Value tblgen_value_0 = (*r.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_0;
      tblgen_CompareOp_13 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_12
      );
    }
    ::mlir::stablehlo::AndOp tblgen_AndOp_14;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_11.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_CompareOp_13.getODSResults(0).begin());
      tblgen_AndOp_14 = rewriter.create<::mlir::stablehlo::AndOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_15;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*r.getODSResults(0).begin());
      tblgen_MulOp_15 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto two = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 2, (*x.getODSResults(0).begin())); (void)two;
    ::mlir::stablehlo::DivOp tblgen_DivOp_16;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_15.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = two;
      tblgen_DivOp_16 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_17;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_16.getODSResults(0).begin());
      tblgen_AddOp_17 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_18;
    {
      ::mlir::Value tblgen_value_0 = (*mx.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*sqa.getODSResults(0).begin());
      tblgen_MulOp_18 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_19;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AndOp_14.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_AddOp_17.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_18.getODSResults(0).begin());
      tblgen_SelectOp_19 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_20;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_7.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_8.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_19.getODSResults(0).begin());
      tblgen_SelectOp_20 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_21;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_SelectOp_20.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = two;
      tblgen_DivOp_21 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_22;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = two;
      tblgen_DivOp_22 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_23;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_DivOp_21.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_22.getODSResults(0).begin());
      tblgen_AddOp_23 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SqrtOp u_general;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_23.getODSResults(0).begin());
      u_general = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_24 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_24;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_25;
    {
      ::mlir::Value tblgen_value_0 = (*u_general.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_0;
      tblgen_CompareOp_25 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_24
      );
    }
    auto nativeVar_26 = ::mlir::stablehlo::getConstantLikeInfValue(rewriter, odsLoc, (*x.getODSResults(0).begin()), /*negative=*/false); (void)nativeVar_26;
    auto nativeVar_27 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_27;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_28;
    {
      ::mlir::Value tblgen_value_0 = (*u_general.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_26;
      tblgen_CompareOp_28 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_27
      );
    }
    ::mlir::stablehlo::OrOp logical_or_eq_u_general_constant_0_eq_u_general_constant_posinf;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_25.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_CompareOp_28.getODSResults(0).begin());
      logical_or_eq_u_general_constant_0_eq_u_general_constant_posinf = rewriter.create<::mlir::stablehlo::OrOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_29 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_29;
    ::mlir::stablehlo::CompareOp gt_ax_ay;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      gt_ax_ay = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_29
      );
    }
    auto nativeVar_30 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_30;
    ::mlir::stablehlo::CompareOp lt_ax_ay;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      lt_ax_ay = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::LT),
        /*compare_type=*/nativeVar_30
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_31;
    {
      ::mlir::Value tblgen_value_0 = (*ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ay.getODSResults(0).begin());
      tblgen_DivOp_31 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_32;
    {
      ::mlir::Value tblgen_value_0 = (*ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*ax.getODSResults(0).begin());
      tblgen_DivOp_32 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_33;
    {
      ::mlir::Value tblgen_value_0 = (*lt_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_31.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_DivOp_32.getODSResults(0).begin());
      tblgen_SelectOp_33 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp _r_0_;
    {
      ::mlir::Value tblgen_value_0 = (*eq_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = one;
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_33.getODSResults(0).begin());
      _r_0_ = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::AbsOp abs__r_0_;
    {
      ::mlir::Value tblgen_value_0 = (*_r_0_.getODSResults(0).begin());
      abs__r_0_ = rewriter.create<::mlir::stablehlo::AbsOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::MaxOp _mx_0_;
    {
      ::mlir::Value tblgen_value_0 = one;
      ::mlir::Value tblgen_value_1 = (*abs__r_0_.getODSResults(0).begin());
      _mx_0_ = rewriter.create<::mlir::stablehlo::MaxOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MinOp _mn_0_;
    {
      ::mlir::Value tblgen_value_0 = one;
      ::mlir::Value tblgen_value_1 = (*abs__r_0_.getODSResults(0).begin());
      _mn_0_ = rewriter.create<::mlir::stablehlo::MinOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    auto nativeVar_34 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_34;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_35;
    {
      ::mlir::Value tblgen_value_0 = (*_mx_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_mn_0_.getODSResults(0).begin());
      tblgen_CompareOp_35 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_34
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_36;
    {
      ::mlir::Value tblgen_value_0 = sq_2;
      ::mlir::Value tblgen_value_1 = (*_mx_0_.getODSResults(0).begin());
      tblgen_MulOp_36 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp _mn_over_mx_0_;
    {
      ::mlir::Value tblgen_value_0 = (*_mn_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_mx_0_.getODSResults(0).begin());
      _mn_over_mx_0_ = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp _r_1_;
    {
      ::mlir::Value tblgen_value_0 = (*_mn_over_mx_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_mn_over_mx_0_.getODSResults(0).begin());
      _r_1_ = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_37;
    {
      ::mlir::Value tblgen_value_0 = one;
      ::mlir::Value tblgen_value_1 = (*_r_1_.getODSResults(0).begin());
      tblgen_AddOp_37 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SqrtOp _sqa_0_;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_37.getODSResults(0).begin());
      _sqa_0_ = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    auto nativeVar_38 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_38;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_39;
    {
      ::mlir::Value tblgen_value_0 = (*_sqa_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = one;
      tblgen_CompareOp_39 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::EQ),
        /*compare_type=*/nativeVar_38
      );
    }
    auto nativeVar_40 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_40;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_41;
    {
      ::mlir::Value tblgen_value_0 = (*_r_1_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_0;
      tblgen_CompareOp_41 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::GT),
        /*compare_type=*/nativeVar_40
      );
    }
    ::mlir::stablehlo::AndOp tblgen_AndOp_42;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_39.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_CompareOp_41.getODSResults(0).begin());
      tblgen_AndOp_42 = rewriter.create<::mlir::stablehlo::AndOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_43;
    {
      ::mlir::Value tblgen_value_0 = (*_mx_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_r_1_.getODSResults(0).begin());
      tblgen_MulOp_43 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_44;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_43.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = two;
      tblgen_DivOp_44 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_45;
    {
      ::mlir::Value tblgen_value_0 = (*_mx_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_44.getODSResults(0).begin());
      tblgen_AddOp_45 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_46;
    {
      ::mlir::Value tblgen_value_0 = (*_mx_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*_sqa_0_.getODSResults(0).begin());
      tblgen_MulOp_46 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_47;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AndOp_42.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_AddOp_45.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_46.getODSResults(0).begin());
      tblgen_SelectOp_47 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp h;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_35.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_36.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_47.getODSResults(0).begin());
      h = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_48;
    {
      ::mlir::Value tblgen_value_0 = one;
      ::mlir::Value tblgen_value_1 = (*h.getODSResults(0).begin());
      tblgen_AddOp_48 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SqrtOp sq_1h;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_48.getODSResults(0).begin());
      sq_1h = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_49;
    {
      ::mlir::Value tblgen_value_0 = (*sq_1h.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = sq_2;
      tblgen_DivOp_49 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_50;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_49.getODSResults(0).begin());
      tblgen_MulOp_50 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SqrtOp sq_ay;
    {
      ::mlir::Value tblgen_value_0 = (*ay.getODSResults(0).begin());
      sq_ay = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::AddOp tblgen_AddOp_51;
    {
      ::mlir::Value tblgen_value_0 = (*_r_0_.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*h.getODSResults(0).begin());
      tblgen_AddOp_51 = rewriter.create<::mlir::stablehlo::AddOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SqrtOp sq_rh;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_AddOp_51.getODSResults(0).begin());
      sq_rh = rewriter.create<::mlir::stablehlo::SqrtOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_52;
    {
      ::mlir::Value tblgen_value_0 = (*sq_rh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = sq_2;
      tblgen_DivOp_52 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_53;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_52.getODSResults(0).begin());
      tblgen_MulOp_53 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_54;
    {
      ::mlir::Value tblgen_value_0 = (*gt_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_50.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_MulOp_53.getODSResults(0).begin());
      tblgen_SelectOp_54 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_55;
    {
      ::mlir::Value tblgen_value_0 = (*logical_or_eq_u_general_constant_0_eq_u_general_constant_posinf.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SelectOp_54.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*u_general.getODSResults(0).begin());
      tblgen_SelectOp_55 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp u;
    {
      ::mlir::Value tblgen_value_0 = (*eq_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_5.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_55.getODSResults(0).begin());
      u = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    auto nativeVar_56 = ::mlir::stablehlo::getConstantLike(rewriter, odsLoc, 2.19736822693562, (*x.getODSResults(0).begin())); (void)nativeVar_56;
    ::mlir::stablehlo::DivOp tblgen_DivOp_57;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = nativeVar_56;
      tblgen_DivOp_57 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_58;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ax.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*sq_ay.getODSResults(0).begin());
      tblgen_DivOp_58 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_59;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*sq_ax.getODSResults(0).begin());
      tblgen_DivOp_59 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_60;
    {
      ::mlir::Value tblgen_value_0 = (*lt_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_58.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_DivOp_59.getODSResults(0).begin());
      tblgen_SelectOp_60 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_61;
    {
      ::mlir::Value tblgen_value_0 = (*eq_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = one;
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_60.getODSResults(0).begin());
      tblgen_SelectOp_61 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_62;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SelectOp_61.getODSResults(0).begin());
      tblgen_MulOp_62 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_63;
    {
      ::mlir::Value tblgen_value_0 = (*sq_1h.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = sq_2;
      tblgen_MulOp_63 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_64;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_MulOp_62.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_63.getODSResults(0).begin());
      tblgen_DivOp_64 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_65;
    {
      ::mlir::Value tblgen_value_0 = (*sq_rh.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = sq_2;
      tblgen_MulOp_65 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_66;
    {
      ::mlir::Value tblgen_value_0 = (*sq_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_65.getODSResults(0).begin());
      tblgen_DivOp_66 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_67;
    {
      ::mlir::Value tblgen_value_0 = (*gt_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_64.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_DivOp_66.getODSResults(0).begin());
      tblgen_SelectOp_67 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::MulOp tblgen_MulOp_68;
    {
      ::mlir::Value tblgen_value_0 = (*u_general.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = two;
      tblgen_MulOp_68 = rewriter.create<::mlir::stablehlo::MulOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::DivOp tblgen_DivOp_69;
    {
      ::mlir::Value tblgen_value_0 = (*ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_MulOp_68.getODSResults(0).begin());
      tblgen_DivOp_69 = rewriter.create<::mlir::stablehlo::DivOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_70;
    {
      ::mlir::Value tblgen_value_0 = (*logical_or_eq_u_general_constant_0_eq_u_general_constant_posinf.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SelectOp_67.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_DivOp_69.getODSResults(0).begin());
      tblgen_SelectOp_70 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp ay_div_u;
    {
      ::mlir::Value tblgen_value_0 = (*eq_ax_ay.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_DivOp_57.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_70.getODSResults(0).begin());
      ay_div_u = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_71;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_1.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*u.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*ay_div_u.getODSResults(0).begin());
      tblgen_SelectOp_71 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    auto nativeVar_72 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_72;
    ::mlir::stablehlo::CompareOp tblgen_CompareOp_73;
    {
      ::mlir::Value tblgen_value_0 = (*x.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_0;
      tblgen_CompareOp_73 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::LT),
        /*compare_type=*/nativeVar_72
      );
    }
    auto nativeVar_74 = ::mlir::stablehlo::ComparisonTypeAttr(); (void)nativeVar_74;
    ::mlir::stablehlo::CompareOp lt_y_constant_0;
    {
      ::mlir::Value tblgen_value_0 = (*y.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = constant_0;
      lt_y_constant_0 = rewriter.create<::mlir::stablehlo::CompareOp>(odsLoc,
        /*lhs=*/tblgen_value_0,
        /*rhs=*/tblgen_value_1,
        ::mlir::stablehlo::ComparisonDirectionAttr::get(rewriter.getContext(), ::mlir::stablehlo::ComparisonDirection::LT),
        /*compare_type=*/nativeVar_74
      );
    }
    ::mlir::stablehlo::NegOp tblgen_NegOp_75;
    {
      ::mlir::Value tblgen_value_0 = (*u.getODSResults(0).begin());
      tblgen_NegOp_75 = rewriter.create<::mlir::stablehlo::NegOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_76;
    {
      ::mlir::Value tblgen_value_0 = (*lt_y_constant_0.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_NegOp_75.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*u.getODSResults(0).begin());
      tblgen_SelectOp_76 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::NegOp tblgen_NegOp_77;
    {
      ::mlir::Value tblgen_value_0 = (*ay_div_u.getODSResults(0).begin());
      tblgen_NegOp_77 = rewriter.create<::mlir::stablehlo::NegOp>(odsLoc,
        /*operand=*/tblgen_value_0
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_78;
    {
      ::mlir::Value tblgen_value_0 = (*lt_y_constant_0.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_NegOp_77.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*ay_div_u.getODSResults(0).begin());
      tblgen_SelectOp_78 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::SelectOp tblgen_SelectOp_79;
    {
      ::mlir::Value tblgen_value_0 = (*tblgen_CompareOp_73.getODSResults(0).begin());
      ::mlir::Value tblgen_value_1 = (*tblgen_SelectOp_76.getODSResults(0).begin());
      ::mlir::Value tblgen_value_2 = (*tblgen_SelectOp_78.getODSResults(0).begin());
      tblgen_SelectOp_79 = rewriter.create<::mlir::stablehlo::SelectOp>(odsLoc,
        /*pred=*/tblgen_value_0,
        /*on_true=*/tblgen_value_1,
        /*on_false=*/tblgen_value_2
      );
    }
    ::mlir::stablehlo::ComplexOp tblgen_ComplexOp_80;
    {
      ::llvm::SmallVector<::mlir::Value, 4> tblgen_values; (void)tblgen_values;
      ::llvm::SmallVector<::mlir::NamedAttribute, 4> tblgen_attrs; (void)tblgen_attrs;
      tblgen_values.push_back((*tblgen_SelectOp_71.getODSResults(0).begin()));
      tblgen_values.push_back((*tblgen_SelectOp_79.getODSResults(0).begin()));
      ::llvm::SmallVector<::mlir::Type, 4> tblgen_types; (void)tblgen_types;
      for (auto v: castedOp0.getODSResults(0)) {
        tblgen_types.push_back(v.getType());
      }
      tblgen_ComplexOp_80 = rewriter.create<::mlir::stablehlo::ComplexOp>(odsLoc, tblgen_types, tblgen_values, tblgen_attrs);
    }

    for (auto v: ::llvm::SmallVector<::mlir::Value, 4>{ tblgen_ComplexOp_80.getODSResults(0) }) {
      tblgen_repl_values.push_back(v);
    }

    rewriter.replaceOp(op0, tblgen_repl_values);
    return ::mlir::success();
  }
};

void LLVM_ATTRIBUTE_UNUSED populateWithGenerated(::mlir::RewritePatternSet &patterns) {
  patterns.add<ExpOp_ComplexElementType_ComplexMathExpander>(patterns.getContext());
  patterns.add<Log1pOp_ComplexElementType_ComplexMathExpander>(patterns.getContext());
  patterns.add<LogOp_ComplexElementType_ComplexMathExpander>(patterns.getContext());
  patterns.add<SqrtOp_ComplexElementType_ComplexMathExpander>(patterns.getContext());
}
