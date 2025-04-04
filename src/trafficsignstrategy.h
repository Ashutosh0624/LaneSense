#ifndef TRAFFICSIGNSTRATEGY_H
#define TRAFFICSIGNSTRATEGY_H
#include "ISafetyStrategy.h"

class TrafficSignStrategy: public ISafetyStrategy
{
public:
    TrafficSignStrategy();

    QString checkWarning(SensorDataModel* model) const override;
};

#endif // TRAFFICSIGNSTRATEGY_H
