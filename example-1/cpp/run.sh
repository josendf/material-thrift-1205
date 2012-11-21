#!/bin/bash

USR_DIR=${HOME}/usr
THRIFT_DIR=${HOME}/usr/thrift-0.8.0

export LD_LIBRARY_PATH=${USR_DIR}/lib:${THRIFT_DIR}/lib:$LD_LIBRARY_PATH

exec ./$1
