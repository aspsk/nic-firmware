Name: agilio-__FW_NAME__-firmware
Summary: Firmware for Netronome Agilio SmartNICs
License: Netronome
Version: __VERSION__
Release: 1
BuildArch: noarch
Vendor: Netronome Systems, Inc.
URL: http://netronome.com
Packager: Edwin Peer <edwin.peer@netronome.com>

%description
Firmware for Netronome Agilio SmartNICs

%files
%define _binaries_in_noarch_packages_terminate_build 0
%defattr(-,root, root)
/lib/firmware/netronome/agilio-__FW_NAME__
/lib/udev/agilio-nic-name-gen
/lib/udev/rules.d/79-agilio-nic.rules