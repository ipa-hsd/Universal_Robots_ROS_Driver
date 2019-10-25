// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// Copyright 2019 FZI Forschungszentrum Informatik
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Felix Mauch mauch@fzi.de
 * \date    2019-10-21
 *
 */
//----------------------------------------------------------------------

#ifndef UR_ROBOT_DRIVER_ROS_DASHBOARD_CLIENT_H_INCLUDED
#define UR_ROBOT_DRIVER_ROS_DASHBOARD_CLIENT_H_INCLUDED

#include <regex>

#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <std_srvs/Empty.h>

#include <ur_robot_driver/ur/dashboard_client.h>

namespace ur_driver
{
  /*!
   * \brief ROS wrapper for UR's dashboard server access. Many (not necessarily all) dashboard
   * functionalities are wrapped into ROS services here.
   */
class DashboardClientROS
{
public:
  DashboardClientROS(const ros::NodeHandle& nh, const std::string& robot_ip);
  virtual ~DashboardClientROS() = default;

private:
  ros::NodeHandle nh_;
  ur_driver::DashboardClient client_;

  // Commanding services
  ros::ServiceServer add_to_log_service_;
  ros::ServiceServer brake_release_service_;
  ros::ServiceServer clear_operational_mode_service_;
  ros::ServiceServer close_popup_service_;
  ros::ServiceServer close_safety_popup_service_;
  ros::ServiceServer load_installation_service_;
  ros::ServiceServer load_program_service_;
  ros::ServiceServer pause_service_;
  ros::ServiceServer play_service_;
  ros::ServiceServer popup_service_;
  ros::ServiceServer power_off_service_;
  ros::ServiceServer power_on_service_;
  ros::ServiceServer quit_service_;
  ros::ServiceServer restart_safety_service_;
  ros::ServiceServer set_operational_mode_service_;
  ros::ServiceServer shutdown_service_;
  ros::ServiceServer stop_service_;
  ros::ServiceServer unlock_protective_stop_service_;

  // Query services
  ros::ServiceServer running_service_;
  ros::ServiceServer robot_mode_service_;
  ros::ServiceServer get_loaded_program_service_;
  ros::ServiceServer is_program_saved_service_;
  ros::ServiceServer program_state_service_;
  ros::ServiceServer polyscope_version_service_;
  ros::ServiceServer safety_mode_service_;
  ros::ServiceServer safety_status_service_;
};
}  // namespace ur_driver
#endif  // ifndef UR_ROBOT_DRIVER_ROS_DASHBOARD_CLIENT_H_INCLUDED
