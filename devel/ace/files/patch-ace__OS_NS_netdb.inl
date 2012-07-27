--- ace/OS_NS_netdb.inl.orig	2012-07-27 13:11:29.000000000 -0500
+++ ace/OS_NS_netdb.inl	2012-07-27 13:13:36.000000000 -0500
@@ -6,6 +6,8 @@
 #include "ace/OS_NS_string.h"
 #include "ace/OS_NS_errno.h"
 
+#include <sys/param.h>
+
 #if defined (ACE_LACKS_NETDB_REENTRANT_FUNCTIONS)
 # if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
 #   define ACE_NETDBCALL_RETURN(OP,TYPE,FAILVALUE,TARGET,SIZE) \
@@ -125,7 +127,7 @@
       *h_errnop = h_errno;
       return (struct hostent *) 0;
     }
-#   elif defined (__GLIBC__)
+#   elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));
 
@@ -317,7 +319,7 @@
       *h_errnop = h_errno;
       return (struct hostent *) 0;
     }
-#   elif defined (__GLIBC__)
+#   elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   ACE_OS::memset (buffer, 0, sizeof (ACE_HOSTENT_DATA));
 
@@ -531,7 +533,7 @@
   else
     return 0;
   //FUZZ: enable check_for_lack_ACE_OS
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   //FUZZ: disable check_for_lack_ACE_OS
   if (::getprotobyname_r (name,
@@ -612,7 +614,7 @@
   //FUZZ: enable check_for_lack_ACE_OS
   else
     return 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   //FUZZ: disable check_for_lack_ACE_OS
   if (::getprotobynumber_r (proto,
@@ -698,7 +700,7 @@
   //FUZZ: enable check_for_lack_ACE_OS
   else
     return (struct servent *) 0;
-# elif defined (__GLIBC__)
+# elif defined (__GLIBC__) || (defined(__FreeBSD__) && __FreeBSD_version >= 700015)
   // GNU C library has a different signature
   ACE_OS::memset (buf, 0, sizeof (ACE_SERVENT_DATA));
 
