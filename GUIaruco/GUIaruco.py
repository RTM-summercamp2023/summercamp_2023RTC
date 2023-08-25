#!/usr/bin/env python
# -*- coding: utf-8 -*-
# -*- Python -*-

# <rtc-template block="description">
"""
 @file GUIaruco.py
 @brief ModuleDescription
 @date $Date$


"""
# </rtc-template>

import sys
import time
from PyQt5.QtCore import Qt, QThread, pyqtSignal, QTimer
from PyQt5.QtWidgets import (
    QMainWindow,
    QApplication,
    QWidget,
    QVBoxLayout,
    QPushButton,
    QVBoxLayout,
    QGroupBox,
    QRadioButton,
    QLabel,
)
from pyqtspinner.spinner import WaitingSpinner
import multiprocessing
from desigharuco import Ui_MainWindow

sys.path.append(".")
# グローバル変数を定義(並列処理のデータ共有に用いる)
global_var = multiprocessing.Value("i", 0)

# Import RTM module
import RTC
import OpenRTM_aist

window = None


# Import Service implementation class
# <rtc-template block="service_impl">

# </rtc-template>

# Import Service stub modules
# <rtc-template block="consumer_import">
# </rtc-template>


# This module's spesification
# <rtc-template block="module_spec">
guiaruco_spec = [
    "implementation_id",
    "GUIaruco",
    "type_name",
    "GUIaruco",
    "description",
    "ModuleDescription",
    "version",
    "1.0.0",
    "vendor",
    "VenderName",
    "category",
    "Category",
    "activity_type",
    "STATIC",
    "max_instance",
    "1",
    "language",
    "Python",
    "lang_type",
    "SCRIPT",
    "",
]
# </rtc-template>


# <rtc-template block="component_description">
##
# @class GUIaruco
# @brief ModuleDescription
#
#
# </rtc-template>
class GUIaruco(OpenRTM_aist.DataFlowComponentBase):
    ##
    # @brief constructor
    # @param manager Maneger Object
    #
    def __init__(self, manager):
        OpenRTM_aist.DataFlowComponentBase.__init__(self, manager)

        self._d_gui_out = OpenRTM_aist.instantiateDataType(RTC.TimedShort)
        """
        """
        self._gui_outOut = OpenRTM_aist.OutPort("gui_out", self._d_gui_out)

        # initialize of configuration-data.
        # <rtc-template block="init_conf_param">

        # </rtc-template>

    ##
    #
    # The initialize action (on CREATED->ALIVE transition)
    #
    # @return RTC::ReturnCode_t
    #
    #
    def onInitialize(self):
        # Bind variables and configuration variable

        # Set InPort buffers

        # Set OutPort buffers
        self.addOutPort("gui_out", self._gui_outOut)

        # Set service provider to Ports

        # Set service consumers to Ports

        # Set CORBA Service Ports

        return RTC.RTC_OK

    ###
    ##
    ## The finalize action (on ALIVE->END transition)
    ##
    ## @return RTC::ReturnCode_t
    #
    ##
    # def onFinalize(self):
    #

    #    return RTC.RTC_OK

    ###
    ##
    ## The startup action when ExecutionContext startup
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##
    ##
    # def onStartup(self, ec_id):
    #
    #    return RTC.RTC_OK

    ###
    ##
    ## The shutdown action when ExecutionContext stop
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##
    ##
    # def onShutdown(self, ec_id):
    #
    #    return RTC.RTC_OK

    ##
    #
    # The activated action (Active state entry action)
    #
    # @param ec_id target ExecutionContext Id
    #
    # @return RTC::ReturnCode_t
    #
    #
    def onActivated(self, ec_id):
        window.signal_message.emit()

        return RTC.RTC_OK

    ##
    #
    # The deactivated action (Active state exit action)
    #
    # @param ec_id target ExecutionContext Id
    #
    # @return RTC::ReturnCode_t
    #
    #
    def onDeactivated(self, ec_id):
        return RTC.RTC_OK

    ##
    #
    # The execution action that is invoked periodically
    #
    # @param ec_id target ExecutionContext Id
    #
    # @return RTC::ReturnCode_t
    #
    #
    def onExecute(self, ec_id):
        global global_var
        with global_var.get_lock():
            # print(global_var.value)
            if global_var.value == 1:
                self._d_gui_out.data = 1
                self._gui_outOut.write()
                global_var.value = 0
                print("write1")
            if global_var.value == 2:
                self._d_gui_out.data = 2
                self._gui_outOut.write()
                global_var.value = 0
                print("write2")

        return RTC.RTC_OK

    ###
    ##
    ## The aborting action when main logic error occurred.
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##
    ##
    # def onAborting(self, ec_id):
    #
    #    return RTC.RTC_OK

    ###
    ##
    ## The error action in ERROR state
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##
    ##
    # def onError(self, ec_id):
    #
    #    return RTC.RTC_OK

    ###
    ##
    ## The reset action that is invoked resetting
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##
    ##
    # def onReset(self, ec_id):
    #
    #    return RTC.RTC_OK

    ###
    ##
    ## The state update action that is invoked after onExecute() action
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##

    ##
    # def onStateUpdate(self, ec_id):
    #
    #    return RTC.RTC_OK

    ###
    ##
    ## The action that is invoked when execution context's rate is changed
    ##
    ## @param ec_id target ExecutionContext Id
    ##
    ## @return RTC::ReturnCode_t
    ##
    ##
    # def onRateChanged(self, ec_id):
    #
    #    return RTC.RTC_OK


class gui(QMainWindow, Ui_MainWindow):
    signal_message = pyqtSignal()

    def __init__(self, parent=None):
        super(gui, self).__init__(parent)
        self.setupUi(self)
        self.signal_message.connect(self.show)

    def start_process1(self):  # aruco1を押したときに呼び出される
        global global_var
        with global_var.get_lock():
            global_var.value = 1
        print("Home")

    def start_process2(self):  # aruco2ボタンを押したときに呼び出される
        global global_var
        with global_var.get_lock():
            global_var.value = 2
        print("Reception desk")


def GUIarucoInit(manager):
    profile = OpenRTM_aist.Properties(defaults_str=guiaruco_spec)
    manager.registerFactory(profile, GUIaruco, OpenRTM_aist.Delete)


def MyModuleInit(manager):
    GUIarucoInit(manager)

    # create instance_name option for createComponent()
    instance_name = [i for i in sys.argv if "--instance_name=" in i]
    if instance_name:
        args = instance_name[0].replace("--", "?")
    else:
        args = ""

    # Create a component
    comp = manager.createComponent("GUIaruco" + args)


def main():
    # remove --instance_name= option
    argv = [i for i in sys.argv if not "--instance_name=" in i]
    # Initialize manager
    mgr = OpenRTM_aist.Manager.init(sys.argv)
    mgr.setModuleInitProc(MyModuleInit)
    mgr.activateManager()
    mgr.runManager(True)
    main2()


def main2():
    global window
    # GUI表示
    app = QApplication(sys.argv)
    window = gui()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
