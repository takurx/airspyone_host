#!/bin/bash

#echo -e "\033[0;31mテキスト\033[0;39m"
#http://d.hatena.ne.jp/R-H/20110119/1295452747
echo -e "\033[1;34m command: $ rm -rf build \033[0;39m"
rm -rf build
echo -e "\033[1;34m command: $ mkdir build \033[0;39m"
mkdir build
echo -e "\033[1;34m command: $ cd build \033[0;39m"
cd build
echo -e "\033[1;34m command: $ cmake ../ -DINSTALL_UDEV_RULES=ON \033[0;39m"
cmake ../ -DINSTALL_UDEV_RULES=ON
echo -e "\033[1;34m command: $ make \033[0;39m"
make
echo -e "\033[1;34m test command: $ ~/Github/takurx_airspyone_host/build/airspy-tools/src/airspy_rx -a 3000000 -r /dev/null -t 2 -n 3000000 \033[0;39m"
~/Github/takurx_airspyone_host/build/airspy-tools/src/airspy_rx -a 3000000 -r /dev/null -t 2 -n 3000000
