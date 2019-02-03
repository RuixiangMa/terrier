#pragma once

#include "optimizer/operator_node.h"

#include <memory>
#include <vector>

namespace terrier::optimizer {

//===--------------------------------------------------------------------===//
// Operator Expr
//===--------------------------------------------------------------------===//
class OperatorExpression {
 public:
  OperatorExpression(Operator op);

  void PushChild(std::shared_ptr<OperatorExpression> op);

  void PopChild();

  const std::vector<std::shared_ptr<OperatorExpression>> &Children() const;

  const Operator &Op() const;

  const std::string GetInfo() const;

 private:
  Operator op;
  std::vector<std::shared_ptr<OperatorExpression>> children;
};

}  // namespace terrier::optimizer
