#### １．Overview

本软件包用于从服务器上下载pcd点云文件并在rviz下显示pcd点云文件

#### ２．Build

```shell
cd ~
mkdir -p pcd_rviz_ws/src
cd ./pcd_rviz/src
git clone　https://github.com/yzqttt/pcd_rviz.git
./download [name]
cd ..
catkin_make
source ./devel/setup.bash
roslaunch pcd_rviz pcd_display.launch
```

#### ３．Hints

* download.sh脚本用于从服务器上下载pcd点云文件，[name]参数为你的服务器用户名
* 由于pcd点云文件脚本，运行roslaunch会经过一段时间的加载后rviz才会出现点云



