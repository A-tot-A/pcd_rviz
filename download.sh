#! /bin/bash

if [ $# -lt 1 ]
then
    echo "usage: ./download.sh [username]"
    exit -1
fi

mkdir -p ./pcd
scpCMD="scp $1@10.193.0.130:/home/yezq/PCD/tingchechang/aloam_park.pcd ./pcd/points.pcd"
eval $scpCMD