// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ManagerModule.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "ManagerModule.h"
#include<iostream>

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

class CIE{
   public:
     float x;
     float y;
     float z;
     CIE(){
 x=0;
 y=0;
 z=0;
}

};

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
CIE cie1,cie2;

  if(m_image_inIn.isNew()){//カメライメージが入力されたらアルコRTCにデータを流す
    m_image_inIn.read();
    m_aruco_out.data=m_image_in.data;
    std::cout<<"image data inputed!!"<<std::endl;//デバッグプリント
    m_aruco_outOut.write();
  }

if(m_aruco_inIn.isNew()){
    m_aruco_inIn.read();//アルコマーカーの座標を読み取る
    float cameraPoseX=0;
    std::cout<<"aruco data inputed!!"<<std::endl;//デバッグプリント

    if(m_aruco_in.ids[0]==1){//idをiに格納
    std::cout<<"id:1"<<std::endl;
    cie1.x=cameraPoseX+m_aruco_in.translates[0].x;//idに対応したインスタンスにデータを格納
    cie1.y=cameraPoseX+m_aruco_in.translates[0].y;
    cie1.z=cameraPoseX+m_aruco_in.translates[0].z;

    cie2.x=cameraPoseX+m_aruco_in.translates[1].x;//idに対応したインスタンスにデータを格納
    cie2.y=cameraPoseX+m_aruco_in.translates[1].y;
    cie2.z=cameraPoseX+m_aruco_in.translates[1].z;
    }else if(m_aruco_in.ids[0]==2){
    std::cout<<"id:2"<<std::endl;
    cie1.x=cameraPoseX+m_aruco_in.translates[1].x;//idに対応したインスタンスにデータを格納
    cie1.y=cameraPoseX+m_aruco_in.translates[1].y;
    cie1.z=cameraPoseX+m_aruco_in.translates[1].z;

    cie2.x=cameraPoseX+m_aruco_in.translates[0].x;//idに対応したインスタンスににデータを格納
    cie2.y=cameraPoseX+m_aruco_in.translates[0].y;
    cie2.z=cameraPoseX+m_aruco_in.translates[0].z;
    }
}

if(m_ui_inIn.isNew()){//UIの入力受取
    m_ui_inIn.read();
    std::cout<<"ui data inputed!!"<<std::endl;//デバッグプリント
    std::cout<<m_ui_in.data<<std::endl;//デバッグプリント


 switch(m_ui_in.data){//UIからのデータを判別

  case 1://UIがマーカー1を選択したら配列[1]の座標を変換RTCに伝達
    std::cout<<"ui select 1"<<std::endl;//デバッグプリント
    m_convert_out.translates[0].x=cie1.x;
    m_convert_out.translates[0].y=cie1.y;
    m_convert_out.translates[0].z=cie1.z;
    break;

  case 2://UIがマーカー2を選択したら配列[2]の座標を変換RTCに伝達
    std::cout<<"ui select 2"<<std::endl;//デバッグプリント
    m_convert_out.translates[0].x=cie2.x;
    m_convert_out.translates[0].y=cie2.y;
    m_convert_out.translates[0].z=cie2.z;
    break;

}

    m_convert_outOut.write(m_convert_out);
    std::cout<<"convert now..."<<std::endl;//デバッグプリント

    while(true){
          if(m_convert_inIn.isNew()){//変換データが返ってくるまで待機
    std::cout<<"convert data inputed!!"<<std::endl;//デバッグプリント

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
