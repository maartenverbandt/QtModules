#include "qsteppedsineexcitationwidget.h"

QSteppedsineExcitationWidget::QSteppedsineExcitationWidget(QExcitationChannelWidget *channels, QWidget *parent) :
    QWidget(parent), _channels(channels)
{
    QFormLayout *form = new QFormLayout(0);
    form->addRow("fl",_fl_spinbox);
    form->addRow("fh",_fh_spinbox);
    form->addRow("fstep",_fstep_spinbox);
    form->addRow("periods",_periods_spinbox);
    form->addRow("amplitude",_amplitude_spinbox);

    _fl_spinbox->setRange(0,1e3);
    _fl_spinbox->setValue(1);
    _fh_spinbox->setRange(0,1e3);
    _fh_spinbox->setValue(10);
    _fstep_spinbox->setRange(0,1e3);
    _fstep_spinbox->setValue(1e-1);
    _periods_spinbox->setRange(0,1e2);
    _periods_spinbox->setValue(10);
    _amplitude_spinbox->setRange(0,1e6);
    _amplitude_spinbox->setDecimals(4);
    _amplitude_spinbox->setValue(0);

    setLayout(form);
}

double QSteppedsineExcitationWidget::fl()
{
    return _fl_spinbox->value();
}

double QSteppedsineExcitationWidget::fh()
{
    return _fh_spinbox->value();
}

double QSteppedsineExcitationWidget::fstep()
{
    return _fstep_spinbox->value();
}

double QSteppedsineExcitationWidget::periods()
{
    return _periods_spinbox->value();
}

double QSteppedsineExcitationWidget::amplitude()
{
    return _amplitude_spinbox->value();
}

unsigned int QSteppedsineExcitationWidget::channels()
{
    return _channels->getChannels();
}


QSteppedsineDataNodeWidget::QSteppedsineDataNodeWidget(QExcitationChannelWidget *channels, QWidget *parent) :
    QExcitationDataNodeWidgetInterface(parent), _w(new QSteppedsineExcitationWidget(channels, parent))
{
    //do nothing
}

QWidget* QSteppedsineDataNodeWidget::w()
{
    return _w;
}

QSteppedsineExcitationWidget* QSteppedsineDataNodeWidget::steppedsineWidget()
{
    return _w;
}

void QSteppedsineDataNodeWidget::enableExcitation()
{
    signal_steppedsine_t steppedsine;
    steppedsine.channels = _w->channels();
    steppedsine.fmin = _w->fl();
    steppedsine.fmax = _w->fh();
    steppedsine.stepsize = _w->fstep();
    steppedsine.period = _w->periods();
    steppedsine.amplitude = _w->amplitude();
    emit transmit(steppedsine);
}

void QSteppedsineDataNodeWidget::disableExcitation()
{
    event_t event;
    event.type = DISABLE_EXCITATION;
    emit transmit(event);
}
