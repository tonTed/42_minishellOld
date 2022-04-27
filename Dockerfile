FROM ubuntu:latest

RUN apt-get update && apt-get upgrade -y && apt-get install -y clang make valgrind curl

RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.1/zsh-in-docker.sh)" -- \
    -t robbyrussell

WORKDIR /minishell