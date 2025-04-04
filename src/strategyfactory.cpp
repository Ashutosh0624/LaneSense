#include "strategyfactory.h"
#include "distancewarningstrategy.h"
#include "laneoffsetwarning.h"
#include "combinedsafetystrategy.h"
#include "blindspotstrategy.h"
#include "overspeedstrategy.h"
#include "trafficsignstrategy.h"

ISafetyStrategy* StrategyFactory::create(const QString& strategyName) {
    if (strategyName == "distance")
        return new DistanceWarningStrategy();
    if (strategyName == "lane")
        return new LaneOffSetWarning();
    if (strategyName == "blindspot")
        return new BlindSpotStrategy();
    if (strategyName == "speed")
        return new OverSpeedStrategy(100.0);
    if (strategyName == "sign")
        return new TrafficSignStrategy();
    if (strategyName == "combined") {
        return new CombinedSafetyStrategy({
            new DistanceWarningStrategy(),
            new LaneOffSetWarning(),
            new BlindSpotStrategy(),
            new OverSpeedStrategy(100.0),
            new TrafficSignStrategy()
        });
    }

    return nullptr;
}
