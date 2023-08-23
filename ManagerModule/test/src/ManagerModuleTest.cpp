// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ManagerModuleTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "ManagerModuleTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const managermodule_spec[] =
#else
static const char* managermodule_spec[] =
#endif
  {
    "implementation_id", "ManagerModuleTest",
    "type_name",         "ManagerModuleTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ManagerModuleTest::ManagerModuleTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_image_inOut("image_in", m_image_in),
    m_aruco_inOut("aruco_in", m_aruco_in),
    m_ui_inOut("ui_in", m_ui_in),
    m_convert_inOut("convert_in", m_convert_in),
    m_aruco_outIn("aruco_out", m_aruco_out),
    m_arm_outIn("arm_out", m_arm_out),
    m_convert_outIn("convert_out", m_convert_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ManagerModuleTest::~ManagerModuleTest()
{
}



RTC::ReturnCode_t ManagerModuleTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("aruco_out", m_aruco_outIn);
  addInPort("arm_out", m_arm_outIn);
  addInPort("convert_out", m_convert_outIn);
  
  // Set OutPort buffer
  addOutPort("image_in", m_image_inOut);
  addOutPort("aruco_in", m_aruco_inOut);
  addOutPort("ui_in", m_ui_inOut);
  addOutPort("convert_in", m_convert_inOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ManagerModuleTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t ManagerModuleTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onActivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onDeactivated(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onExecute(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModuleTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool ManagerModuleTest::runTest()
{
    return true;
}


extern "C"
{
 
  void ManagerModuleTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(managermodule_spec);
    manager->registerFactory(profile,
                             RTC::Create<ManagerModuleTest>,
                             RTC::Delete<ManagerModuleTest>);
  }
  
}
