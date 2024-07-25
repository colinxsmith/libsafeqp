Name:           libsafeqp
Version:        1
Release:        0
Epoch:          1
Summary:        BITA Optimiser

Group:          BITA
BuildArch:      x86_64
License:        GPL
URL:            www.corfinancialgroup.com
Source0:        libsafeqp.tgz

%global debug_package %{nil}
%description
BITA Optimiser

%prep
%setup -q
%build
%install
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/bin
install -m 0755  bin/ETL $RPM_BUILD_ROOT/usr/local/bin
install -m 0755  bin/logopt $RPM_BUILD_ROOT/usr/local/bin
install -m 0755  bin/pversion $RPM_BUILD_ROOT/usr/local/bin
install -m 0755  bin/safeconic $RPM_BUILD_ROOT/usr/local/bin
install -m 0755  bin/safeqp $RPM_BUILD_ROOT/usr/local/bin
install -m 0755  bin/safeqpU $RPM_BUILD_ROOT/usr/local/bin
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libsafeqp.a $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib
touch $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so.1 
ln -s libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so 
ln -s libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so.1 
install -m 0755  lib/libsafepl.a $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libsafepl.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib
touch $RPM_BUILD_ROOT/usr/local/lib/libsafepl.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libsafepl.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafepl.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafepl.so.1 
ln -s libsafepl.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafepl.so 
ln -s libsafepl.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafepl.so.1 
install -m 0755  lib/libOptimiserController.a $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libOptimiserController.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib
touch $RPM_BUILD_ROOT/usr/local/lib/libOptimiserController.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libOptimiserController.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libOptimiserController.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libOptimiserController.so.1 
ln -s libOptimiserController.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libOptimiserController.so 
ln -s libOptimiserController.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libOptimiserController.so.1 
install -m 0755  lib/libsafe.a $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libsafe.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib
touch $RPM_BUILD_ROOT/usr/local/lib/libsafe.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libsafe.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafe.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafe.so.1 
ln -s libsafe.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafe.so 
ln -s libsafe.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafe.so.1 
install -m 0755  lib/libsafecsharp.a $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libsafecsharp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib
touch $RPM_BUILD_ROOT/usr/local/lib/libsafecsharp.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libsafecsharp.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafecsharp.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafecsharp.so.1 
ln -s libsafecsharp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafecsharp.so 
ln -s libsafecsharp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafecsharp.so.1 
install -m 0755  lib/libsafejava.a $RPM_BUILD_ROOT/usr/local/lib
install -m 0755  lib/libsafejava.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib
touch $RPM_BUILD_ROOT/usr/local/lib/libsafejava.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libsafejava.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafejava.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafejava.so.1 
ln -s libsafejava.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafejava.so 
ln -s libsafejava.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafejava.so.1 
uname > ~/rpm`date +-\%d-\%m-\%Y-\%T`
ldd $RPM_BUILD_ROOT/usr/local/lib/libsafeqp.so >> ~/rpm`date +-\%d-\%m-\%Y-\%T`

%files
/usr/local/lib
/usr/local/lib/libsafeqp.a
/usr/local/lib/libsafeqp.so.1.0.0
/usr/local/lib/libsafepl.a
/usr/local/lib/libsafepl.so.1.0.0
/usr/local/lib/libOptimiserController.a
/usr/local/lib/libOptimiserController.so.1.0.0
/usr/local/lib/libsafe.a
/usr/local/lib/libsafe.so.1.0.0
/usr/local/lib/libsafecsharp.a
/usr/local/lib/libsafecsharp.so.1.0.0
/usr/local/lib/libsafejava.a
/usr/local/lib/libsafejava.so.1.0.0
/usr/local/bin/ETL
/usr/local/bin/logopt
/usr/local/bin/pversion
/usr/local/bin/safeconic
/usr/local/bin/safeqp
/usr/local/bin/safeqpU
%post
echo -e "\e[1;34mInstall step\e[0m"
ldconfig /usr/local/lib
%postun
ldconfig
echo -e "\e[1;33mUninstall step\e[0m"
%changelog
* Tue Sep  4 2018 Colin Smith <colin.smith@corfinancialgroup.com> 1.0.0
- make fedora and centos rpm packages
