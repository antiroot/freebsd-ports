--- ace/OS_NS_Thread.h.orig	2012-07-27 11:50:35.000000000 -0500
+++ ace/OS_NS_Thread.h	2012-07-27 11:51:09.000000000 -0500
@@ -38,6 +38,12 @@
 # include "ace/ACE_export.h"
 # include "ace/Object_Manager_Base.h"
 
+# include <sys/param.h>
+#if (defined(__FreeBSD__) && ((__FreeBSD_version >= 700110 && __FreeBSD_version < 800000) || __FreeBSD_version >= 800024))
+# include <sys/cpuset.h>
+# define cpu_set_t cpuset_t
+#endif
+
 # if defined (ACE_EXPORT_MACRO)
 #   undef ACE_EXPORT_MACRO
 # endif
