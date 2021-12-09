# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/user/final-project/final-project-vitis/oled_demo_wrapper/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/user/final-project/final-project-vitis/oled_demo_wrapper/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {oled_demo_wrapper}\
-hw {/home/user/final-project/final-project-vivado/oled_demo/oled_demo_wrapper.xsa}\
-out {/home/user/final-project/final-project-vitis}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform active {oled_demo_wrapper}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
platform generate
