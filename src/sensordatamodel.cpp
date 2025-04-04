#include "sensordatamodel.h"

SensorDataModel::SensorDataModel(QObject *parent)
    : QObject{parent},
      m_speed(0.0),
      m_objectDistance{0.0},
      m_laneOffSet{0},
      m_leftBlindSpot{false},
      m_rightBlindSpot{false},
      m_trafficSign{"None"}
{
    // connect QTimer to data generator  slot
    QObject::connect(&m_timer, &QTimer::timeout, this, &SensorDataModel::generateMockData);
    m_timer.setInterval(1000);
}

double SensorDataModel::speed() const
{
    return this->m_speed;
}

double SensorDataModel::objectDistance() const
{
    return this->m_objectDistance;
}

int SensorDataModel::laneoffset() const
{
    return this->m_laneOffSet;
}

bool SensorDataModel::leftBlindSpot() const
{
    return this->m_leftBlindSpot;
}

bool SensorDataModel::rightBlindSpot() const
{
    return this->m_rightBlindSpot;
}

QString SensorDataModel::trafficSign() const
{
    return this->m_trafficSign;
}

void SensorDataModel::startSimulation()
{
    this->m_timer.start(); // start the timer, when the timer start's the generate mock data slot will fire up
}

void SensorDataModel::generateMockData()
{
    // Formula to for "double"
    // value = rand_between(min, max) = generateDouble() * (max - min) + min
    m_speed = QRandomGenerator::global()->generateDouble() * (120.0 - 20.0) + 20.0;
    m_objectDistance = QRandomGenerator::global()->generateDouble() * (80.0 - 5.0) + 5.0;
    m_laneOffSet = QRandomGenerator::global()->bounded(-1, 2); // -1, 0, 1
    m_leftBlindSpot = QRandomGenerator::global()->bounded(0, 2); // true or false
    m_rightBlindSpot = QRandomGenerator::global()->bounded(0, 2);

    QStringList signs = {"STOP", "SPEED_60", "YIELD", "NONE"};
    m_trafficSign = signs.at(QRandomGenerator::global()->bounded(signs.size()));

    emit dataChanged(); // Notify QML about update

}
