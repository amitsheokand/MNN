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
        initLayer();
    }

    ErrorCode CoreMLGatherV2::onResize(const std::vector<Tensor *> &inputs, const std::vector<Tensor *> &outputs) {

        MNN_ASSERT(inputs.size() == 1 && outputs.size() == 1);

        // op parameters
        auto gatherParam = mOp->main_as_GatherV2();

        mLayer_->layer_case = CORE_ML__SPECIFICATION__NEURAL_NETWORK_LAYER__LAYER_GATHER;
        mLayer_->gather = mCoreMLBackend->create<CoreML__Specification__GatherLayerParams>();
        core_ml__specification__gather_layer_params__init(mLayer_->gather);
        mLayer_->gather->axis = gatherParam->Taxis();

        setLayerInputsAndOutputs(mLayer_, {mCoreMLBackend->getTensorName(inputs[0])}, {mCoreMLBackend->getTensorName(outputs[0])});
        mCoreMLBackend->addLayer(mLayer_);

        return NO_ERROR;
    }

    REGISTER_COREML_OP_CREATOR(CoreMLGatherV2, OpType_GatherV2);

} // namespace MNN