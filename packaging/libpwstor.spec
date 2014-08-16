%define ver  0.1
%define rel  2
%define jobs 12

Name:          libpwstor
Version:       %{ver}
Release:       %{rel}
Summary:       libpwstor provides a C interface to a secure password storage format
Group:         Applications/Internet
License:       Copyright Matt Harris
URL:           http://kirin-enterprises.us/libpwstor/
Source0:       http://kirin-enterprises.us/libpwstor-%{version}.tar.bz2
BuildRoot:     %{_tmppath}/%{name}-%{version}-%{release}-root

%description
libpwstor provides a C interface to a secure password storage format.                                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                                                                             
%package devel                                                                                                                                                                                                                                                                                                               
Summary: Header and other files needed for compiling programs with libpwstor                                                                                                                                                                                                                                                 
Autoreq: 0                                                                                                                                                                                                                                                                                                                   
Requires: libpwstor >= 0.1                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                             
%description devel                                                                                                                                                                                                                                                                                                           
libpwstor provides a C interface to a secure password storage format.                                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                                                                             
%prep                                                                                                                                                                                                                                                                                                                        
%setup -q -n libpwstor-%{version}                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                             
%build                                                                                                                                                                                                                                                                                                                       
export JOBS=%{jobs}                                                                                                                                                                                                                                                                                                          
./configure --prefix=/usr                                                                                                                                                                                                                                                                                                    
make                                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                             
%install                                                                                                                                                                                                                                                                                                                     
rm -rf %{buildroot}                                                                                                                                                                                                                                                                                                          
make install DESTDIR=%{buildroot}                                                                                                                                                                                                                                                                                            
rm %{buildroot}/usr/lib/libpwstor.so                                                                                                                                                                                                                                                                                         
cp %{buildroot}/usr/lib/libpwstor.so.0.1 %{buildroot}/usr/lib/libpwstor.so                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                             
%clean                                                                                                                                                                                                                                                                                                                       
rm -rf %{buildroot}                                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                                             
%post                                                                                                                                                                                                                                                                                                                        
ldconfig                                                                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                                                                             
%files                                                                                                                                                                                                                                                                                                                       
%defattr(-,root,root,-)                                                                                                                                                                                                                                                                                                      
%doc README LICENSE                                                                                                                                                                                                                                                                                                          
     /usr/bin/pwtool                                                                                                                                                                                                                                                                                                         
     /usr/lib/libpwstor.a
     /usr/lib/libpwstor.so
     /usr/lib/libpwstor.so.0.1
     /usr/man/man1/pwtool.1.gz
     /usr/man/man3/pws_base64_decode.3.gz
     /usr/man/man3/pws_base64_encode.3.gz
     /usr/man/man3/pws_memnuke.3.gz
     /usr/man/man3/pws_passwords_check.3.gz
     /usr/man/man3/pws_passwords_checkmulti.3.gz
     /usr/man/man3/pws_passwords_converttomulti.3.gz
     /usr/man/man3/pws_passwords_encode.3.gz
     /usr/man/man3/pws_passwords_encodemulti.3.gz
     /usr/man/man3/pws_passwords_len.3.gz
     /usr/man/man3/pws_rand_get.3.gz
     /usr/man/man3/pws_version.3.gz
     /usr/man/man3/pws_version_int.3.gz
     /usr/man/man3/pwstor.3.gz

%files devel
     /usr/include/pwstor.h

%changelog
* Sun Aug 04 2014 Matt Harris <matt@kirin> 0.1-2
- Split out devel package and CentOS 7 build test
* Mon Sep 04 2012 Matt Harris <mdh@kirin> 0.1-1
- Initial spec file for RPM build of libpwstor
