#!/usr/bin/env bash

apt-get update
apt-get install -y \
    build-essential \
    clang-format \
    clang-tidy \
    cppcheck \
    iwyu \
    cmake \
    lcov \
    python3-pip
