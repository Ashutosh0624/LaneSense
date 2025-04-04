#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H

#include "ISafetyStrategy.h"
#include <QString>

class StrategyFactory
{
public:
    static ISafetyStrategy* create(const QString& strategyName);
};

#endif // STRATEGYFACTORY_H
