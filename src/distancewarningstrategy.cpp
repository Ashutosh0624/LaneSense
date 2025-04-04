#include "distancewarningstrategy.h"

QString DistanceWarningStrategy::checkWarning(SensorDataModel* model) const {

    qDebug() << "Checking Distance: " << model->objectDistance();


    if (!model) return "";

    double distance = model->objectDistance();

    if (distance < 10.0) {
        return "⚠️ Object too close!";
    }

    return "";
}
