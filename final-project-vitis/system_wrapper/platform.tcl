# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/user/workspace/system_wrapper/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/user/workspace/system_wrapper/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform active {system_wrapper}
platform config -updatehw {/home/user/Downloads/hw/system_wrapper.xsa}
platform active {system_wrapper}
platform active {system_wrapper}
platform config -updatehw {/home/user/final-project/final-project-vivado/audio-mixer/system_wrapper.xsa}
