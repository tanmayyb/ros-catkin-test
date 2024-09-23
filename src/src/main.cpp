// #include <bimanual_planning_ros/panda_bimanual_control.h>

#include <ros/ros.h>
#include <bimanual_planning_ros/helper.h>

int main(int argc, char **argv) {
  ghostplanner::cfplanner::run_dummy();
  ros::init(argc, argv, "panda_bimanual_planning");
  // bimanual_planning_ros::PandaBimanualPlanning panda_bimanual_;
  // panda_bimanual_.start();
  // auto [panda_bimanual, panda_l, panda_r]{initVrep()};
  return 0;
}