/*
 * Copyright (c) 2015, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_APPLICATION_MANAGER_TEST_MOCK_MESSAGE_HELPER_H_
#define SRC_COMPONENTS_APPLICATION_MANAGER_TEST_MOCK_MESSAGE_HELPER_H_
#include "gmock/gmock.h"
#include "application_manager/application.h"
#include "interfaces/HMI_API.h"
#include "policy/policy_types.h"
#include "application_manager/policies/policy_handler_interface.h"
#include "application_manager/application_manager.h"

namespace application_manager {

namespace smart_objects = NsSmartDeviceLink::NsSmartObjects;
class MockMessageHelper {
 public:
  MOCK_METHOD1(GetHashUpdateNotification,
               smart_objects::SmartObjectSPtr(const uint32_t app_id));
  MOCK_METHOD2(SendHashUpdateNotification,
               void(const uint32_t app_id, ApplicationManager& app_mngr));
  MOCK_METHOD1(HMIResultToString,
               std::string(hmi_apis::Common_Result::eType hmi_result));
  MOCK_METHOD1(HMIResultFromString,
               hmi_apis::Common_Result::eType(const std::string& hmi_result));
  MOCK_METHOD1(MobileResultToString,
               std::string(mobile_apis::Result::eType mobile_result));
  MOCK_METHOD1(MobileResultFromString,
               mobile_api::Result::eType(const std::string& mobile_result));
  MOCK_METHOD1(HMIToMobileResult,
               mobile_api::Result::eType(
                   const hmi_apis::Common_Result::eType hmi_result));
  MOCK_METHOD1(MobileToHMIResult,
               hmi_apis::Common_Result::eType(
                   const mobile_api::Result::eType mobile_result));
  MOCK_METHOD1(StringToHMILevel,
               mobile_api::HMILevel::eType(const std::string& hmi_level));
  MOCK_METHOD1(CreateDeviceListSO,
               smart_objects::SmartObjectSPtr(
                   const connection_handler::DeviceMap& devices));
  MOCK_METHOD2(SendNaviStartStream,
               void(int32_t connection_key, ApplicationManager& app_mngr));
  MOCK_METHOD2(SendNaviStopStream,
               void(int32_t connection_key, ApplicationManager& app_mngr));
  MOCK_METHOD3(SendOnAppPermissionsChangedNotification,
               void(uint32_t connection_key,
                    const policy::AppPermissions& permissions,
                    ApplicationManager& app_mngr));
  MOCK_METHOD2(SendAudioStartStream,
               void(int32_t connection_key, ApplicationManager& app_mngr));
  MOCK_METHOD2(SendAudioStopStream,
               void(int32_t connection_key, ApplicationManager& app_mngr));
  MOCK_METHOD3(SendOnDataStreaming,
               void(protocol_handler::ServiceType service,
                    bool available,
                    ApplicationManager& app_mngr));
  MOCK_METHOD3(CreateGetVehicleDataRequest,
               void(uint32_t correlation_id,
                    const std::vector<std::string>& params,
                    ApplicationManager& app_mngr));
  MOCK_METHOD3(SendUpdateSDLResponse,
               void(const std::string& result,
                    uint32_t correlation_id,
                    ApplicationManager& app_mngr));
  MOCK_METHOD3(SendGetUserFriendlyMessageResponse,
               void(const std::vector<policy::UserFriendlyMessage>& msg,
                    uint32_t correlation_id,
                    ApplicationManager& app_mngr));
  MOCK_METHOD3(SendGetStatusUpdateResponse,
               void(const std::string& status,
                    uint32_t correlation_id,
                    ApplicationManager& app_mngr));
  MOCK_METHOD2(SendOnStatusUpdate,
               void(const std::string& status, ApplicationManager& app_mngr));
  MOCK_METHOD3(SendSDLActivateAppResponse,
               void(policy::AppPermissions& permissions,
                    uint32_t correlation_id,
                    ApplicationManager& app_mngr));
  MOCK_METHOD1(SendGetSystemInfoRequest, void(ApplicationManager& app_mngr));

  MOCK_METHOD4(SendPolicyUpdate,
               void(const std::string& file_path,
                    int timeout,
                    const std::vector<int>& retries,
                    ApplicationManager& app_mngr));
  MOCK_METHOD3(
      SendGetListOfPermissionsResponse,
      void(const std::vector<policy::FunctionalGroupPermission>& permissions,
           uint32_t correlation_id,
           ApplicationManager& app_mngr));
  MOCK_METHOD3(SendOnPermissionsChangeNotification,
               void(uint32_t connection_key,
                    const policy::Permissions& permissions,
                    ApplicationManager& app_mngr));
  MOCK_METHOD4(SendPolicySnapshotNotification,
               void(uint32_t connection_key,
                    const std::vector<uint8_t>& policy_data,
                    const std::string& url,
                    ApplicationManager& app_mngr));
  MOCK_METHOD1(CommonLanguageFromString,
               hmi_apis::Common_Language::eType(const std::string& language));
  MOCK_METHOD1(CommonLanguageToString,
               std::string(hmi_apis::Common_Language::eType));
  MOCK_METHOD2(CreateModuleInfoSO,
               smart_objects::SmartObjectSPtr(uint32_t function_id,
                                              ApplicationManager& app_mngr));
  MOCK_METHOD2(SendAllOnButtonSubscriptionNotificationsForApp,
               void(ApplicationConstSharedPtr app,
                    ApplicationManager& app_mngr));
  MOCK_METHOD2(SendOnResumeAudioSourceToHMI,
               void(uint32_t app_id, ApplicationManager& app_mngr));
  MOCK_METHOD2(CreateAddSubMenuRequestToHMI,
               smart_objects::SmartObjectList(ApplicationConstSharedPtr app,
                                              const uint32_t correlation_id));
  MOCK_METHOD2(CreateAddCommandRequestToHMI,
               smart_objects::SmartObjectList(ApplicationConstSharedPtr app,
                                              ApplicationManager& app_mngr));
  MOCK_METHOD1(CreateAddVRCommandRequestFromChoiceToHMI,
               smart_objects::SmartObjectList(ApplicationConstSharedPtr app));
  MOCK_METHOD1(SendGlobalPropertiesToHMI, void(ApplicationConstSharedPtr app));
  MOCK_METHOD1(GetIVISubscriptionRequests,
               smart_objects::SmartObjectList(ApplicationSharedPtr app));
  MOCK_METHOD3(VerifyImageFiles,
               mobile_apis::Result::eType(smart_objects::SmartObject& message,

                                          ApplicationConstSharedPtr app,
                                          ApplicationManager& app_mngr));
  MOCK_METHOD6(GetBCActivateAppRequestToHMI,
               smart_objects::SmartObjectSPtr(
                   ApplicationConstSharedPtr app,
                   const protocol_handler::SessionObserver& session_observer,
                   const policy::PolicyHandlerInterface& policy_handler,
                   hmi_apis::Common_HMILevel::eType level,
                   bool send_policy_priority,
                   ApplicationManager& app_mngr));
  MOCK_METHOD2(GetOnAppInterfaceUnregisteredNotificationToMobile,
               NsSmartDeviceLink::NsSmartObjects::SmartObjectSPtr(
                   int32_t connection_key,
                   mobile_apis::AppInterfaceUnregisteredReason::eType reason));

  static MockMessageHelper* message_helper_mock();
};

}  // namespace application_manager
#endif  // SRC_COMPONENTS_APPLICATION_MANAGER_TEST_MOCK_MESSAGE_HELPER_H_
