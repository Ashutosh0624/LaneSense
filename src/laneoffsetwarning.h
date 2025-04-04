#ifndef LANEOFFSETWARNING_H
#define LANEOFFSETWARNING_H

#include "ISafetyStrategy.h"

class LaneOffSetWarning: public ISafetyStrategy
{
public:
    LaneOffSetWarning();
    QString checkWarning(SensorDataModel* model) const override;
};

#endif // LANEOFFSETWARNING_H
