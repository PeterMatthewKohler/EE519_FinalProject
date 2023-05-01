// Copyright 2020-2021 The MathWorks, Inc.
// Common copy functions for fp_msgs/SigmaID
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4265)
#pragma warning(disable : 4456)
#pragma warning(disable : 4458)
#pragma warning(disable : 4946)
#pragma warning(disable : 4244)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "fp_msgs/msg/sigma_id.hpp"
#include "visibility_control.h"
#include "class_loader/multi_library_class_loader.hpp"
#include "ROS2PubSubTemplates.hpp"
class FP_MSGS_EXPORT fp_msgs_msg_SigmaID_common : public MATLABROS2MsgInterface<fp_msgs::msg::SigmaID> {
  public:
    virtual ~fp_msgs_msg_SigmaID_common(){}
    virtual void copy_from_struct(fp_msgs::msg::SigmaID* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const fp_msgs::msg::SigmaID* msg, MultiLibLoader loader, size_t size = 1);
};
  void fp_msgs_msg_SigmaID_common::copy_from_struct(fp_msgs::msg::SigmaID* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //sigma
        const matlab::data::TypedArray<double> sigma_arr = arr["sigma"];
        msg->sigma = sigma_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'sigma' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'sigma' is wrong type; expected a double.");
    }
    try {
        //id
        const matlab::data::TypedArray<int8_t> id_arr = arr["id"];
        msg->id = id_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'id' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'id' is wrong type; expected a int8.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T fp_msgs_msg_SigmaID_common::get_arr(MDFactory_T& factory, const fp_msgs::msg::SigmaID* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","sigma","id"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("fp_msgs/SigmaID");
    // sigma
    auto currentElement_sigma = (msg + ctr)->sigma;
    outArray[ctr]["sigma"] = factory.createScalar(currentElement_sigma);
    // id
    auto currentElement_id = (msg + ctr)->id;
    outArray[ctr]["id"] = factory.createScalar(currentElement_id);
    }
    return std::move(outArray);
  } 
class FP_MSGS_EXPORT fp_msgs_SigmaID_message : public ROS2MsgElementInterfaceFactory {
  public:
    virtual ~fp_msgs_SigmaID_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType /*type*/);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType /*type*/);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          fp_msgs_SigmaID_message::generatePublisherInterface(ElementType /*type*/){
    return std::make_shared<ROS2PublisherImpl<fp_msgs::msg::SigmaID,fp_msgs_msg_SigmaID_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         fp_msgs_SigmaID_message::generateSubscriberInterface(ElementType /*type*/){
    return std::make_shared<ROS2SubscriberImpl<fp_msgs::msg::SigmaID,fp_msgs_msg_SigmaID_common>>();
  }
#include "class_loader/register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(fp_msgs_msg_SigmaID_common, MATLABROS2MsgInterface<fp_msgs::msg::SigmaID>)
CLASS_LOADER_REGISTER_CLASS(fp_msgs_SigmaID_message, ROS2MsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER