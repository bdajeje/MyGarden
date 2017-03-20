#-------------------------------------------------
#
# Project created by QtCreator 2017-03-20T14:33:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGarden
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
				main_window.cpp \
		utils/properties.cpp \
		utils/files.cpp \
		widgets/plantation_dialog.cpp \
		models/plantation.cpp \
		widgets/jlabel.cpp

HEADERS  += main_window.hpp \
		utils/files.hpp \
		utils/properties.hpp \
		utils/icons_manager.hpp \
		utils/resources_manager.hpp \
		widgets/plantation_dialog.hpp \
		models/plantation.hpp \
		utils/json.hpp \
		widgets/jlabel.hpp
