import launch
import launch_ros
def generate_launch_description():
    action_declare_port=launch.actions.DeclareLaunchArgument(
        'serial',default_value="/dev/pts/2",
    )
    action_node_read_node=launch_ros.actions.Node(
        package='vision_detector',
        executable='read',
        output='screen',
    )
    action_node_find_node=launch_ros.actions.Node(
        package='gimbal_controller',
        executable='find',
        output='screen',
    )
    action_node_fire_node=launch_ros.actions.Node(
        package='serial_interface',
        executable='fire',
        parameters=[{'serial_port':launch.substitutions.LaunchConfiguration('serial', default="/dev/pts/2")}],
        output='screen',
    )
    return launch.LaunchDescription([
        action_node_read_node,
        action_node_find_node,
        action_node_fire_node
    ])
