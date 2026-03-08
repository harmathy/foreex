#!/bin/bash

build_deps=(
  build-essential
  cmake
  libfontconfig-dev
  libharfbuzz-dev
)

export DEBIAN_FRONTEND="noninteractive"

apt-get -U install -y "${build_deps[@]}"
