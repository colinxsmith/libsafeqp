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
install -m 0755 -d $RPM_BUILD_ROOT/usr/local/lib/libsafeqp
install -m 0755  libsafeqp.a $RPM_BUILD_ROOT/usr/local/lib/libsafeqp
install -m 0755  libsafeqp.so $RPM_BUILD_ROOT/usr/local/lib/libsafeqp
install -m 0755  libsafeqp.so.1 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp
install -m 0755  libsafeqp.so.1.0.0 $RPM_BUILD_ROOT/usr/local/lib/libsafeqp

%files
/usr/local/lib/libsafeqp
/usr/local/lib/libsafeqp/libsafeqp.a
/usr/local/lib/libsafeqp/libsafeqp.so
/usr/local/lib/libsafeqp/libsafeqp.so.1
/usr/local/lib/libsafeqp/libsafeqp.so.1.0.0

%changelog
