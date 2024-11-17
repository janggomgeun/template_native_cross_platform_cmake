FROM --platform=linux/amd64 ubuntu:20.04
LABEL Description="Build environment"

ENV DEBIAN_FRONTEND=noninteractive 

RUN apt-get update && apt-get -y --no-install-recommends install \
  build-essential \
  git \
  gdb \
  python3.9 \
  python3-pip \
  libgtk2.0-dev \
  swig \
  unzip \
  wget \
  # cmake \
  curl \
  file \
  libssl-dev \
  ninja-build ant

RUN wget https://github.com/Kitware/CMake/releases/download/v3.22.3/cmake-3.22.3.tar.gz
RUN tar -xvzf cmake-3.22.3.tar.gz && cd cmake-3.22.3/ && ./bootstrap && make && make install

RUN pip3 install "conan==1.62.0"