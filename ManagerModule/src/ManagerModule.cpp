// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ManagerModule.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "ManagerModule.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const managermodule_spec[] =
#else
static const char* managermodule_spec[] =
#endif
  {
    "implementation_id", "ManagerModule",
    "type_name",         "ManagerModule",
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
ManagerModule::ManagerModule(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_image_inIn("image_in", m_image_in),
    m_aruco_inIn("aruco_in", m_aruco_in),
    m_ui_inIn("ui_in", m_ui_in),
    m_convert_inIn("convert_in", m_convert_in),
    m_aruco_outOut("aruco_out", m_aruco_out),
    m_arm_outOut("arm_out", m_arm_out),
    m_convert_outOut("convert_out", m_convert_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ManagerModule::~ManagerModule()
{
}



RTC::ReturnCode_t ManagerModule::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("image_in", m_image_inIn);
  addInPort("aruco_in", m_aruco_inIn);
  addInPort("ui_in", m_ui_inIn);
  addInPort("convert_in", m_convert_inIn);
  
  // Set OutPort buffer
  addOutPort("aruco_out", m_aruco_outOut);
  addOutPort("arm_out", m_arm_outOut);
  addOutPort("convert_out", m_convert_outOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ManagerModule::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t ManagerModule::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModule::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t ManagerModule::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ManagerModule::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ManagerModule::onExecute(RTC::UniqueId /*ec_id*/)
{
  float Outpose[2];//座標を格納する配列
  int i;

  if(m_image_inIn.isNew()){//カメライメージが入力されたらアルコRTCにデータを流す
    m_image_inIn.read();
    m_aruco_out.data=m_image_in.data;
    m_aruco_outOut.write();
  }

if(m_aruco_inIn.isNew()){
    m_aruco_inIn.read();//アルコマーカーの座標を読み取る
    i=m_ArUco3DPose.ids[0];//idをiに格納
    Outpose[i]=m_cameraPoseX+m_ArucoMakerPose.translates[0].x;　//idに対応した配列にデータを格納
    Outpose[i]=m_cameraPoseX+m_ArucoMakerPose.translates[0].y;
    Outpose[i]=m_cameraPoseX+m_ArucoMakerPose.translates[0].z;
}

if(m_ui_inIn.isNew()){//UIの入力受取
    m_ui_inIn.read();


 switch(m_ui_in.data){//UIからのデータを判別
  case 1://UIがマーカー1を選択したら配列[1]の座標を変換RTCに伝達
  m_convert_out.data=Outpose[1];
    break;

  case 2://UIがマーカー2を選択したら配列[2]の座標を変換RTCに伝達
  m_convert_out.data=Outpose[2];
    break;

}

    m_convert_outOut.write();

    while(true){
      if(m_convert_inIn.isNew()){//変換データが返ってくるまで待機
        m_convert_inIn.read();
        break;
        }
    }

    m_arm_out.data=m_convert_in.data;//変換された座標をアームに送信
    m_arm_outOut.write();
}
  
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t ManagerModule::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModule::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModule::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModule::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ManagerModule::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void ManagerModuleInit(RTC::Manager* manager)
  {
    coil::Properties profile(managermodule_spec);
    manager->registerFactory(profile,
                             RTC::Create<ManagerModule>,
                             RTC::Delete<ManagerModule>);
  }
  
}
