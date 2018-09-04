Name:           libsafeqp
Version:        1
Release:        0
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
%{__install} -m 0755 -d $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1
%{__install} -m 0755  libsafeqp.a $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1
%{__install} -m 0755  libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1
%{__touch} $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so 
%{__touch} $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so.1 
%{__rm} $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so 
%{__rm} $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so.1 
%{__ln_s} libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so 
%{__ln_s} libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so.1 
uname -a > ~/rpm`date +-\%d-\%m-\%Y-\%T`
ldd $RPM_BUILD_ROOT/usr/local/lib/libsafeqp-1/libsafeqp.so >> ~/rpm`date +-\%d-\%m-\%Y-\%T`

%files
/usr/local/lib/libsafeqp-1
/usr/local/lib/libsafeqp-1/libsafeqp.a
/usr/local/lib/libsafeqp-1/libsafeqp.so.1.0.0

%changelog
