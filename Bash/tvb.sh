#!/bin/bash

echo "Installing TVB Packages on virtual machine..."

echo "Installing python"
# try intalling ubuntu if not install 
# on default from source
sudo apt-get update && apt-get install build-essential checkinstall \ 
&& apt-get install libreadline-gplv2-dev \
libncursesw5-dev \
libssl-dev \
libsqlite3-dev \
tk-dev \ 
libgdbm-dev \
libc6-dev \
libbz2-dev

cd /usr/src && sudo wget https://www.python.org/ftp/python/2.7.14/Python-2.7.14.tgz \
&& sudo tar xzf Python-2.7.14.tgz \
&& cd Python-2.7.14
&& sudo ./configure
&& sudo make altinstall
&& echo python2.7 -V "If you see this messaage python is install"


# Install using pip
pip install tvb-framework

# Start the framwork
# RUN python -m tvb.interfaces.web.run WEB_PROFILE tvb.config
python -m tvb.interfaces.web.run WEB_PROFILE tvb.config
# Your port 8080 should be free, as a CherryPy service will try to run there.
# Your default browser should automatically open http://localhost:8080/
# which is the way to interact with TVB Web Interface.

# curl
# echo "Installing Curl"
# apt-get install curl -y

# miniconda
# echo "Downloading Miniconda"
# cd /tmp
# curl -O https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh
# bash Miniconda3-latest-Linux-x86_64.sh

# tvb
# echo "Installing TVB packages using conda"
# conda install -c conda-forge tvb-framework

# end
echo "Finished Installing TVB Packages."
