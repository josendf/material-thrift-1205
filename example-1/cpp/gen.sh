#!/bin/bash

THRIFT_DIR=${HOME}/usr/thrift-0.8.0

${THRIFT_DIR}/bin/thrift -r -gen cpp example.thrift
