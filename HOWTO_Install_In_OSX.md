# Introduction #
There are known issues with OSX that make it more difficult to make ASH work.  In the OSX world, things seem to change drastically between releases, so some fiddling may be required.

If you find something that works for you that is not documented here, please help by adding comments or contributing to the Wiki.


# Details #

  1. If you want to build the C++ version from source, you will need to install the Xcode command line tools.  See https://developer.apple.com/downloads/index.action?query=command%20line%20tools if you don't already have it installed.
    * Alternatively, if you don't want to install the C++ version and have no interest in the Xcode command line tools, there is a marginally supported bash script that will install only the python version on your system.  Run `./python/osx_install.sh` from the source directory and skip to the configuration step.
  1. In some versions of OSX - `/etc` is actually a symlink to `/private/etc`.  In this case, the normall installation procedure may not work.  To install, you may first need to `sudo mkdir /etc/ash`.
  1. Install the package from source using the [standard instructions](HOWTO_Install.md).  Note: the C++ code may not compile on OSX.  In this case, the python version is the only option.  You can still `make install_python`
  1. After you have installed the program, you may not be able to source the required shell code without first sourcing the program configuration file.  Your .bashrc file may need to include the following:
```
# File: ~/.bashrc
#...

# Source the configuration file.
[ -e /etc/ash/ash.conf] && source /etc/ash/ash.conf

# If you are using the Python version:
export ASH_LOG_BIN=/usr/local/bin/_ash_log.py

# Source the shell code to enable the automatic command logging hooks.
[ -e /usr/lib/advanced_shell_history/bash ] && source /usr/lib/advanced_shell_history/bash
```
  1. OSX does not include procfs, so there is no `/proc` in your filesystem.  Currently (Aug-2012) this causes one or two data points to not be collected.  Testers and bug fixes are welcome!