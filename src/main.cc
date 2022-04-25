#include <pcl/io/pcd_io.h>
#include <ros/ros.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <string>

int main(int argc, char** argv) {
  ros::init(argc, argv, "pcd_display");
  ros::NodeHandle nh;
  ros::Publisher pcd_publish =
      nh.advertise<sensor_msgs::PointCloud2>("pcd_display", 1000);
	
	ROS_WARN("read from pcd file...");
  std::string file_path;
	nh.param<std::string>("pcd_file_path", file_path, "");
	if(file_path.empty()){
		ROS_ERROR("ERROR");
		return 0;
	}
	
	ROS_WARN("pcd file path: %s", file_path.c_str());
  pcl::PointCloud<pcl::PointXYZ>::Ptr point_ptr(
      new pcl::PointCloud<pcl::PointXYZ>());
  pcl::io::loadPCDFile(file_path, *point_ptr);
  ROS_WARN("read complete: pcd size: %d", point_ptr->size());

	sensor_msgs::PointCloud2 full_res_map;
	pcl::toROSMsg(*point_ptr, full_res_map);
	full_res_map.header.stamp = ros::Time();
	full_res_map.header.frame_id = "map";
	pcd_publish.publish(full_res_map);
  while(ros::ok()){
		ros::spin();
  }
  return 0;
}