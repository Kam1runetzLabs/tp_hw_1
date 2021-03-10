FROM ubuntu:20.04
LABEL maintainer="notsoserious2017@gmail.com"
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get -y update && \
    apt-get -y install software-properties-common valgrind doxygen rpm curl cppcheck llvm g++ lcov gcovr cmake python3-pip clang git && \
    add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
    pip3 install cpplint gitpython requests && \
    apt clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
