#!/bin/sh

# https://github.com/mesibo/libmesibo
# 
# Usage:
# curl -s https://raw.githubusercontent.com/mesibo/libmesibo/master/install.sh | sudo bash -
#

# Installs libmesibo on Mac or Linux.
# Supported Platforms:
# * Mac OS
# * Debian Linux
#   * Debian 7, 8
#   * Ubuntu 12.04, 14.04, 14.10, 15.04
#   * Mint 13, 17
# * Red Hat Linux
#   * RHEL/Centos/Scientific 6, 7
#   * Fedora 21, 22
#   * Amazon Linux 2014.09

install_mesibo_linux() {
  echo "installing libmesibo on linux"
  curl -ks https://raw.githubusercontent.com/mesibo/libmesibo/master/linux/libmesibo.so -o /usr/lib/libmesibo.so
  curl -ks https://raw.githubusercontent.com/mesibo/libmesibo/master/include/mesibo.h -o /usr/include/mesibo.h
  ldconfig
  echo "Installed libmesibo"
}

sorry() {
  echo "Sorry, I don't yet know how to install mesibo on $1"
  exit 1
}

# OS-specific installations of mesibo follows
case $(uname -s) in
  *[Dd]arwin*)
    # Mac OS
    echo "Detected Mac OS"
    if type "brew" > /dev/null; then
      echo "Installing libmesibo via homebrew"
      brew install homebrew/science/mesibo
    elif type "port" > /dev/null; then
      echo "Installing libmesibo via MacPorts"
      port install mesibo
    else
      sorry "Mac OS without homebrew or MacPorts"
    fi
    ;;
  *[Rr]aspberry*)
    echo "Detected Raspberry Pi"
    ;;
  *)
    if [ -f /etc/debian_version ]; then
      # Debian Linux
      DISTRO=$(lsb_release -c -s)
      echo "Detected Debian Linux '$DISTRO'"
      install_mesibo_linux
    elif [ -f /etc/redhat-release ]; then
      # Red Hat Linux
      RELEASE=$(cat /etc/redhat-release)
      echo "Detected Red Hat Linux '$RELEASE'"
      install_mesibo_linux
    elif [ -f /etc/system-release ]; then
      # Probably Amazon Linux
      RELEASE=$(cat /etc/system-release)
      install_mesibo_linux
    else
      # Unsupported OS
      sorry "$(uname -a)"
    fi
    ;;
esac
