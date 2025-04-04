#include "blindspotstrategy.h"

BlindSpotStrategy::BlindSpotStrategy() {}

QString BlindSpotStrategy::checkWarning(SensorDataModel *model) const
{
    if (!model) return "";

    bool left = model->leftBlindSpot();
    bool right = model->rightBlindSpot();

    if (left && right) {
        return "⚠️ Vehicles in both blind spots!";
    } else if (left) {
        return "⚠️ Vehicle in left blind spot!";
    } else if (right) {
        return "⚠️ Vehicle in right blind spot!";
    }

    return "";
}
