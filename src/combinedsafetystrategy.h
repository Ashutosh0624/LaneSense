#ifndef COMBINEDSAFETYSTRATEGY_H
#define COMBINEDSAFETYSTRATEGY_H

#include "ISafetyStrategy.h"
#include <QList>

class CombinedSafetyStrategy: public ISafetyStrategy
{
public:
    CombinedSafetyStrategy(const QList<ISafetyStrategy*>& strategies);
    ~CombinedSafetyStrategy();

    QString checkWarning(SensorDataModel* model) const override;

private:
    QList<ISafetyStrategy*> m_strategies;

};

#endif // COMBINEDSAFETYSTRATEGY_H
