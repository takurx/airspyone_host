echo "command: $ rm -rf build"
rm -rf build
echo "command: $ mkdir build"
mkdir build
echo "command: $ cd build"
cd build
echo "command: $ cmake ../ -DINSTALL_UDEV_RULES=ON"
cmake ../ -DINSTALL_UDEV_RULES=ON
echo "command: $ make"
make