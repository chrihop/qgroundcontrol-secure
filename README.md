# QGroundControl Ground Control Station

## Build from the source

Step 1. Clone the project

```sh
git clone https://github.com/chrihop/qgroundcontrol-secure

cd qgroundcontrol-secure
git submodule init && git submodule update --recursive
```

Step 2. Build docker image for the building environment.

```sh
docker build --file ./deploy/docker/Dockerfile-build-linux -t qgc-linux .
```

Step 3. Build the project with docker

```sh
mkdir -p build
docker run --rm -v (pwd):/project/source -v (pwd)/build:/project/build qgc-linux:latest
```

Step 4. Launch QGroundControl with Encryption enabled.

```sh
./build/staging/QGroundControl --encrypt --no-auto-conn
```

Note:
- `--encrypt` enables the encryption and decryption of the payload of all mavlink messages.
- `--no-auto-conn` disables the auto connection to the default target upon QGroundControl launches.

## QGround Control

[![Releases](https://img.shields.io/github/release/mavlink/QGroundControl.svg)](https://github.com/mavlink/QGroundControl/releases)

*QGroundControl* (QGC) is an intuitive and powerful ground control station (GCS) for UAVs.

The primary goal of QGC is ease of use for both first time and professional users.
It provides full flight control and mission planning for any MAVLink enabled drone, and vehicle setup for both PX4 and ArduPilot powered UAVs. Instructions for *using QGroundControl* are provided in the [User Manual](https://docs.qgroundcontrol.com/en/) (you may not need them because the UI is very intuitive!)

All the code is open-source, so you can contribute and evolve it as you want.
The [Developer Guide](https://dev.qgroundcontrol.com/en/) explains how to [build](https://dev.qgroundcontrol.com/en/getting_started/) and extend QGC.


Key Links:
* [Website](http://qgroundcontrol.com) (qgroundcontrol.com)
* [User Manual](https://docs.qgroundcontrol.com/en/)
* [Developer Guide](https://dev.qgroundcontrol.com/en/)
* [Discussion/Support](https://docs.qgroundcontrol.com/en/Support/Support.html)
* [Contributing](https://dev.qgroundcontrol.com/en/contribute/)
* [License](https://github.com/mavlink/qgroundcontrol/blob/master/COPYING.md)
