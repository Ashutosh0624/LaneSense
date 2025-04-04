#ifndef DISTANCEWARNINGSTRATEGY_H
#define DISTANCEWARNINGSTRATEGY_H

#include "ISafetyStrategy.h"

class DistanceWarningStrategy : public ISafetyStrategy
{
public:
    QString checkWarning(SensorDataModel* model) const override;
};

#endif // DISTANCEWARNINGSTRATEGY_H
