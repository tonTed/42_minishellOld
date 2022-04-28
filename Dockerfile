FROM ubuntu:focal

# Fix enter timezone issue
ENV TZ=America/Montreal
ENV TERM=xterm-256color
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update -y && apt-get -y  upgrade
RUN apt-get install -y clang make curl
RUN apt-get install -y valgrind

WORKDIR /minishell