#ifndef SENSORDATAMODEL_H
#define SENSORDATAMODEL_H

#include <QObject>
#include <QDebug>
#include <QRandomGenerator>
#include <QTimer>

class SensorDataModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double speed READ speed NOTIFY dataChanged FINAL)
    Q_PROPERTY(double objectDistance   READ objectDistance NOTIFY dataChanged FINAL)
    Q_PROPERTY(int laneoffset READ laneoffset NOTIFY dataChanged FINAL)
    Q_PROPERTY(bool leftBlindSpot READ leftBlindSpot NOTIFY dataChanged FINAL)
    Q_PROPERTY(bool rightBlindSpot READ rightBlindSpot NOTIFY dataChanged FINAL)
    Q_PROPERTY(QString trafficSign READ trafficSign NOTIFY dataChanged FINAL)

public:
    explicit SensorDataModel(QObject *parent = nullptr);


    // getter function
    double speed() const;
    double objectDistance()const;
    int laneoffset() const;
    bool leftBlindSpot()const;
    bool rightBlindSpot() const;
    QString trafficSign() const;

    // Start simulation
    Q_INVOKABLE void startSimulation();

signals:
    void dataChanged();

private slots:
    void generateMockData();


private:
    double  m_speed;
    double  m_objectDistance;
    int     m_laneOffSet;
    bool    m_leftBlindSpot;
    bool    m_rightBlindSpot;
    QString m_trafficSign;

    QTimer m_timer;
};

#endif // SENSORDATAMODEL_H
