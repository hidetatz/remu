FROM ubuntu:20.04

ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

WORKDIR /home/root

RUN apt-get update 
RUN apt-get install -y \
    autoconf \
    automake \
    autotools-dev \
    curl \
    git \
    python3 \
    libmpc-dev \
    libmpfr-dev \
    libgmp-dev \
    gawk \
    build-essential \
    bison \
    flex \
    texinfo \
    gperf \
    libtool \
    patchutils \
    bc \
    zlib1g-dev \
    libexpat-dev \
    ninja-build

RUN git clone --depth 1 https://github.com/riscv/riscv-gnu-toolchain 

WORKDIR /home/root/riscv-gnu-toolchain
RUN ./configure --prefix=/opt/riscv --with-arch=rv64gc && make linux

WORKDIR /home/root

FROM ubuntu:20.04

ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update 

WORKDIR /root/
COPY --from=0 /opt/riscv/ /opt/riscv/
RUN apt-get install -y build-essential
RUN echo "PATH=$PATH:/opt/riscv/bin" >> /root/.bashrc
