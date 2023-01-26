#Download base image.
#The ubuntu:20.04 tag points to the "20.04 LTS"
FROM ubuntu:20.04

#Set location to download ARM toolkit from.
# This will need to be changed over time or replaced with a static link to the latest release.
ENV ARMBINURL="https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/RC2.1/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2?revision=6e63531f-8cb1-40b9-bbfc-8a57cdfc01b4&la=en&hash=F761343D43A0587E8AC0925B723C04DBFB848339"

#Set Timezone to avoid interaction during tzdata package installation
ENV TZ=Europe/Paris
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

#Create volume /havocbin for compiled firmware binaries
VOLUME /havocbin

#Copy build context (repository root) to /havocsrc
#COPY ./ /havocsrc

#Fetch dependencies from APT
RUN apt-get update && \
        apt-get install -y tar wget dfu-util cmake python bzip2 curl python3 python3-yaml git && \
        apt-get -qy autoremove

#Install current pip from PyPa
RUN curl https://bootstrap.pypa.io/pip/3.4/get-pip.py -o get-pip.py && \
        python get-pip.py

#Fetch additional dependencies from Python 2.x pip
RUN pip install pyyaml
RUN rm -rf /usr/bin/python && \
    rm -rf /usr/bin/pip && \
    ln -s /usr/bin/python3 /usr/bin/python && \
    ln -s /usr/bin/pip3 /usr/bin/pip

ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8
ENV repoURL https://github.com/eried/portapack-mayhem.git
ENV activeBranch next

#Grab the GNU ARM toolchain from arm.com
#Then extract contents to /opt/build/armbin/
RUN mkdir /opt/build && cd /opt/build && \
        wget -O gcc-arm-none-eabi $ARMBINURL && \
        mkdir armbin && \
        tar --strip=1 -xjvf gcc-arm-none-eabi -C armbin
    
#Set environment variable so compiler knows where the toolchain lives
ENV PATH=$PATH:/opt/build/armbin/bin

CMD chmod 777 /havoc/README.md ; \
    [ -f /havoc/README.md ] || git clone $repoURL /havoc ; \
    cd /havoc ; \
    [ $activeBranch == next ] || git checkout $activeBranch ; \
    mkdir /havoc/build ; cd /havoc/build ; \
    cmake .. ; git submodule update --recursive --init ; make firmware

