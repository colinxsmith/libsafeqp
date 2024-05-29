Name:           libsafeqp
Version:        1
Release:        0
Epoch:          1
Summary:        BITA Optimiser

Group:          BITA
BuildArch:      x86_64
License:        GPL
URL:            www.bita.com
Source0:        libsafeqp.tgz

%description
BITA Optimiser

%prep
%setup -q
%build
%install
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1
install -m 0755  libsafeqp.a $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1
install -m 0755  libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1
touch $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so 
touch $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so.1 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so 
rm $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so.1 
ln -s libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so 
ln -s libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so.1 
uname > ~/rpm`date +-\%d-\%m-\%Y-\%T`
ldd $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so >> ~/rpm`date +-\%d-\%m-\%Y-\%T`

%files
/usr/local/lib/libsafeqp-1
/usr/local/lib/libsafeqp-1/libsafeqp.a
/usr/local/lib/libsafeqp-1/libsafeqp.so.1.0.0
%post
/sbin/ldconfig /usr/local/lib/libsafeqp-1
%postun
/sbin/ldconfig
%changelog
* Tue Sep  4 2018 Colin Smith <csmith@corfinancialgroup.com> 1.0.0
- make debian and centos packages
