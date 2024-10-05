//
// Created by Amit Sheokand on 05/10/2024.
//
//
// Created by Amit Sheokand on 05/10/2024.
//

#include "CoreMLGatherV2.hpp"

#include <MNN_generated.h>

namespace MNN {
    CoreMLGatherV2::CoreMLGatherV2(Backend *b, const Op *op, const std::vector<Tensor *> &inputs,
        const std::vector<Tensor *> &outputs): CoreMLCommonExecution(b, op){
        auto opName = mOp->name()->str();


    }

    ErrorCode CoreMLGatherV2::onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {

        return NO_ERROR;
    }

    REGISTER_COREML_OP_CREATOR(CoreMLGatherV2, OpType_GatherV2);

} // namespace MNN