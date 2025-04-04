#ifndef OVERSPEEDSTRATEGY_H
#define OVERSPEEDSTRATEGY_H

#include "ISafetyStrategy.h"

class OverSpeedStrategy: public ISafetyStrategy
{
public:
    OverSpeedStrategy(double speedLimit = 100.0);
    QString checkWarning(SensorDataModel* model) const override;

private:
    double m_speedLimit;
};

#endif // OVERSPEEDSTRATEGY_H
