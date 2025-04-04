#include "adasmanager.h"
#include "strategyfactory.h"
#include <QDebug>

ADASManager::ADASManager(QObject *parent)
    : QObject{parent},
    m_sensorModel(new SensorDataModel(this)),
    m_strategy(StrategyFactory::create("distance")) //default strategy
{
    QObject::connect(m_sensorModel, &SensorDataModel::dataChanged,
            this, &ADASManager::evaluateSafety);
}

ADASManager::~ADASManager() {
    delete m_strategy;
}

SensorDataModel* ADASManager::sensorModel() const {
    return m_sensorModel;
}

void ADASManager::startADAS() {
    qDebug()<<"start ADAS called";
    m_sensorModel->startSimulation();
}

void ADASManager::setStrategy(const QString& name) {
    if (m_strategy) {
        delete m_strategy;
        m_strategy = nullptr;
    }

    m_strategy = StrategyFactory::create(name);
}

void ADASManager::evaluateSafety() {

    qDebug ()<<"Evaluate strategy called ";

    if (!m_strategy) return;

    QString warning = m_strategy->checkWarning(m_sensorModel);
    if (!warning.isEmpty()) {
        emit warningUpdated(warning);
    }
}
