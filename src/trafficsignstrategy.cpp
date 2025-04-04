#include "trafficsignstrategy.h"

TrafficSignStrategy::TrafficSignStrategy() {}

QString TrafficSignStrategy::checkWarning(SensorDataModel *model) const
{
    if (!model) return "";

    QString sign = model->trafficSign();

    if (sign == "STOP") {
        return "🛑 Stop Sign Ahead!";
    } else if (sign == "YIELD") {
        return "⚠️ Yield Sign Detected!";
    } else if (sign == "SPEED_60") {
        return "📛 Speed Limit: 60 km/h";
    }

    return "";  // "
}
