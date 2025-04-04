#ifndef ADASMANAGER_H
#define ADASMANAGER_H

#include "sensordatamodel.h"
#include <QObject>
#include "ISafetyStrategy.h"

class ADASManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SensorDataModel* sensorModel READ sensorModel CONSTANT)

public:
    explicit ADASManager(QObject *parent = nullptr);
    ~ADASManager();

    SensorDataModel *sensorModel() const;

    Q_INVOKABLE void startADAS(); // Called from UI to start the SIMULATION
    Q_INVOKABLE void setStrategy(const QString& name);  // Switch strategies at runtime


signals:
    void warningUpdated(const QString& message);  // Emitted to QML

private slots:
    void evaluateSafety();  // Connected to model's signal

private:
    SensorDataModel* m_sensorModel;
    ISafetyStrategy* m_strategy;

    Q_DISABLE_COPY(ADASManager)
};

#endif // ADASMANAGER_H
