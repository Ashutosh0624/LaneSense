#include "laneoffsetwarning.h"

LaneOffSetWarning::LaneOffSetWarning() {}

QString LaneOffSetWarning::checkWarning(SensorDataModel *model) const
{
    if (!model) return "";

    int lane = model->laneoffset();  // -1 (left), 0 (center), 1 (right)

    if (lane == -1) {
        return "⚠️ Drifting Left!";
    } else if (lane == 1) {
        return "⚠️ Drifting Right!";
    }

    return "";  // Centered, no warning
}
