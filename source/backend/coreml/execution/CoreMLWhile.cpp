//
// Created by Amit Sheokand on 06/10/2024.
//

// CoreMLWhile.cpp
#include "CoreMLWhile.hpp"

namespace MNN {
    CoreMLWhile::CoreMLWhile(Backend *b, const Op *op, const std::vector<Tensor *> &inputs,
        const std::vector<Tensor *> &outputs): CoreMLCommonExecution(b, op){
        auto opName = mOp->name()->str();
    }

    ErrorCode CoreMLWhile::onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {


        return NO_ERROR;

    }

    REGISTER_COREML_OP_CREATOR(CoreMLWhile, OpType_While);

} // namespace MNN