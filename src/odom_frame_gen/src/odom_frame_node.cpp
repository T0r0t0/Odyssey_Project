#include <string>
#include "rclcpp/rclcpp.hpp"
#include "tf2_msgs/msg/tf_message.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class TFOdomAdder : public rclcpp::Node
{
public:
  TFOdomAdder(): Node("tf_odom_adder")
  {
    this->declare_parameter<bool>("verbose", false);
    this->get_parameter("verbose", verbose_);

    // Subscribe to /tf_ign
    subscription_ = this->create_subscription<tf2_msgs::msg::TFMessage>(
      "/tf_ign", 10,
      [this](tf2_msgs::msg::TFMessage::SharedPtr msg) {
        this->tf_callback(msg);
      });

    // Create a TF broadcaster for /tf
    tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(*this);
    static_tf_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(*this);
  }

private:
  void tf_callback(tf2_msgs::msg::TFMessage::SharedPtr msg)
  {
    for (const auto &transform : msg->transforms) {
      // Check if this is the transform for your specific model (e.g., gr_robot)
      if (transform.child_frame_id == "gr_robot") {
        last_transform.header.stamp = this->now();
        last_transform.header.frame_id = "odom";  // New parent frame
        last_transform.child_frame_id = "base_link";  // Keep child frame
        // Copy the transform data
        last_transform.transform.translation = transform.transform.translation;
        last_transform.transform.rotation = transform.transform.rotation;

        if (verbose_) {
          this->tf_log(last_transform);
        }
        // Publish the transform directly (no need for TFMessage)
        tf_broadcaster_->sendTransform(last_transform);
      }



      // // Check if this is the transform for your specific model (e.g., gr_robot)
      // if (endsWith(transform.child_frame_id,"wheel_link")) {
      //   geometry_msgs::msg::TransformStamped last_transform;
      //   last_transform.header.stamp = this->now();
      //   last_transform.header.frame_id = "base_link";  // New parent frame
      //   last_transform.child_frame_id = transform.child_frame_id;  // Keep child frame

      //   // Copy the transform data
      //   last_transform.transform.translation = transform.transform.translation;
      //   last_transform.transform.rotation = transform.transform.rotation;

      //   this->tf_log(last_transform);

      //   // Publish the transform directly (no need for TFMessage)
      //   static_tf_broadcaster_->sendTransform(last_transform);
      // }
    }
  }



  bool endsWith(const std::string &str, const std::string &suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
  }

  

  void tf_log(geometry_msgs::msg::TransformStamped transform){
    // Print the new transform
    RCLCPP_INFO(
    this->get_logger(),
    "New Transform:\n"
    "  Header:\n"
    "    Stamp: %d.%09d\n"
    "    Frame ID: %s\n"
    "    Child Frame ID: %s\n"
    "  Transform:\n"
    "    Translation: [%.2f, %.2f, %.2f]\n"
    "    Rotation: [%.2f, %.2f, %.2f, %.2f]",
    transform.header.stamp.sec,
    transform.header.stamp.nanosec,
    transform.header.frame_id.c_str(),
    transform.child_frame_id.c_str(),
    transform.transform.translation.x,
    transform.transform.translation.y,
    transform.transform.translation.z,
    transform.transform.rotation.x,
    transform.transform.rotation.y,
    transform.transform.rotation.z,
    transform.transform.rotation.w
    );
  }

  rclcpp::Subscription<tf2_msgs::msg::TFMessage>::SharedPtr subscription_;
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  std::shared_ptr<tf2_ros::StaticTransformBroadcaster> static_tf_broadcaster_;

  geometry_msgs::msg::TransformStamped last_transform;

  bool verbose_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TFOdomAdder>());
  rclcpp::shutdown();
  return 0;
}
