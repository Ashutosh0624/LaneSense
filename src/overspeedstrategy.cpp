#include "overspeedstrategy.h"

OverSpeedStrategy::OverSpeedStrategy(double speedLimit): m_speedLimit{speedLimit} {}

QString OverSpeedStrategy::checkWarning(SensorDataModel *model) const
{
    if (!model) return "";

    double speed = model->speed();

    if (speed > m_speedLimit) {
        return QString("🚨 Over Speed! Current: %1 km/h | Limit: %2 km/h")
            .arg(speed, 0, 'f', 1)
            .arg(m_speedLimit, 0, 'f', 1);
    }

    return "";
}
