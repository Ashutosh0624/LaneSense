#include "combinedsafetystrategy.h"

CombinedSafetyStrategy::CombinedSafetyStrategy(const QList<ISafetyStrategy*>& strategies)
    : m_strategies(strategies) {}

CombinedSafetyStrategy::~CombinedSafetyStrategy() {
    qDeleteAll(m_strategies);
    m_strategies.clear();
}

QString CombinedSafetyStrategy::checkWarning(SensorDataModel *model) const
{
    QStringList warnings;

    for (ISafetyStrategy* strategy : m_strategies) {
        if (!strategy) continue;
        QString w = strategy->checkWarning(model);
        if (!w.isEmpty()) warnings << w;
    }

    return warnings.join(" | ");
}
