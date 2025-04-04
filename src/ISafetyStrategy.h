#ifndef ISAFETYSTRATEGY_H
#define ISAFETYSTRATEGY_H

#include "sensordatamodel.h"
#include <QString>

class ISafetyStrategy {
public:
    virtual ~ISafetyStrategy() = default;

    // Must be overridden by concrete strategies
    virtual QString checkWarning(SensorDataModel* model) const = 0;

};

#endif // ISAFETYSTRATEGY_H
