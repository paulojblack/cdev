FROM ubuntu:latest

RUN apt-get update; \
    apt-get install build-essential vim -y

RUN mkdir /home/sandbox