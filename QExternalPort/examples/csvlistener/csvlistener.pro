#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T16:49:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csvlistener
TEMPLATE = app

INCLUDEPATH += mavlink

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    mavlink/microos_messages/mavlink.h \
    mavlink/microos_messages/mavlink_msg_event.h \
    mavlink/microos_messages/mavlink_msg_gpio.h \
    mavlink/microos_messages/mavlink_msg_heartbeat.h \
    mavlink/microos_messages/mavlink_msg_partition.h \
    mavlink/microos_messages/mavlink_msg_print.h \
    mavlink/microos_messages/mavlink_msg_robot_id.h \
    mavlink/microos_messages/mavlink_msg_thread_info.h \
    mavlink/microos_messages/microos_messages.h \
    mavlink/microos_messages/testsuite.h \
    mavlink/microos_messages/version.h \
    mavlink/robot_messages/mavlink.h \
    mavlink/robot_messages/mavlink_msg_attitude.h \
    mavlink/robot_messages/mavlink_msg_attitude_cmd.h \
    mavlink/robot_messages/mavlink_msg_channel_io.h \
    mavlink/robot_messages/mavlink_msg_channel_io_info.h \
    mavlink/robot_messages/mavlink_msg_pose.h \
    mavlink/robot_messages/mavlink_msg_position.h \
    mavlink/robot_messages/mavlink_msg_position_cmd.h \
    mavlink/robot_messages/mavlink_msg_radar_cloud.h \
    mavlink/robot_messages/mavlink_msg_radar_line.h \
    mavlink/robot_messages/mavlink_msg_signal_multisine.h \
    mavlink/robot_messages/mavlink_msg_signal_steppedsine.h \
    mavlink/robot_messages/mavlink_msg_signal_sweptsine.h \
    mavlink/robot_messages/mavlink_msg_velocity.h \
    mavlink/robot_messages/mavlink_msg_velocity_cmd.h \
    mavlink/robot_messages/robot_messages.h \
    mavlink/robot_messages/testsuite.h \
    mavlink/robot_messages/version.h \
    mavlink/checksum.h \
    mavlink/mavlink_conversions.h \
    mavlink/mavlink_helpers.h \
    mavlink/mavlink_protobuf_manager.hpp \
    mavlink/mavlink_types.h \
    mavlink/protocol.h

FORMS    += mainwindow.ui

include(../../src/qexternalport.pri)
