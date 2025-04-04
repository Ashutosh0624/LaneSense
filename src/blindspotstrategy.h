#ifndef BLINDSPOTSTRATEGY_H
#define BLINDSPOTSTRATEGY_H

#include "ISafetyStrategy.h"
class BlindSpotStrategy: public ISafetyStrategy
{
public:
    BlindSpotStrategy();

    QString checkWarning(SensorDataModel* model) const override;
};


#endif // BLINDSPOTSTRATEGY_H
