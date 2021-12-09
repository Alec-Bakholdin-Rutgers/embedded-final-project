# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/user/final-project/final-project-vitis/audio_mixer/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/user/final-project/final-project-vitis/audio_mixer/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {audio_mixer}\
-hw {/home/user/final-project/final-project-vivado/final_project/audio_mixer.xsa}\
-out {/home/user/final-project/final-project-vitis}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform active {audio_mixer}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
