# FROM node:8.4
# ADD . /app
# COPY . /app
# WORKDIR /app
# RUN ["npm", "install"]
# EXPOSE 3000/tcp


FROM ubuntu
# ...
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install wget zsh git gcc mono-mcs g++-multilib && \
    rm -rf /var/lib/apt/lists/*
# RUN apt-get install -y zsh
# RUN ["apt-get", "install", "-y", "zsh"]
RUN wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true

RUN mkdir /app
WORKDIR /app