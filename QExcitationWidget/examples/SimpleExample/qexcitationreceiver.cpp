#include "qexcitationreceiver.h"

QExcitationReceiver::QExcitationReceiver(QObject *parent) : QDataNode(parent)
{

}

void QExcitationReceiver::receive(signal_multisine_t multisine)
{
    qDebug() << "Multisine";
    qDebug() << "amplitude: " << multisine.amplitude;
    qDebug() << "realization: " << multisine.id;
    qDebug() << "channels: " << multisine.channels;
}

void QExcitationReceiver::receive(signal_sweptsine_t sweptsine)
{
    qDebug() << "Sweptsine";
    qDebug() << "amplitude: " << sweptsine.amplitude;
    qDebug() << "period: " << sweptsine.period;
    qDebug() << "fmin: " << sweptsine.fmin;
    qDebug() << "fmax: " << sweptsine.fmax;
    qDebug() << "channels: " << sweptsine.channels;
}

void QExcitationReceiver::receive(event_t event)
{
    qDebug() << "Event " << event.type;
}
