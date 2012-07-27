--- ace/OS_NS_signal.h.orig	2012-07-27 13:25:47.000000000 -0500
+++ ace/OS_NS_signal.h	2012-07-27 13:26:36.000000000 -0500
@@ -33,10 +33,10 @@
 #endif
 #define ACE_EXPORT_MACRO ACE_Export
 
-#if defined (__Lynx__)
-// LynxOS defines pthread_sigmask() in pthread.h
+#if defined (__Lynx__) || defined (__OpenBSD__) || defined (__FreeBSD__)
+// LynxOS, OpenBSD and FreeBSD define pthread_sigmask() in pthread.h
 # include "ace/os_include/os_pthread.h"
-#endif /* __Lynx__ */
+#endif /* __Lynx__ || OpenBSD || FreeBSD */
 
 /*
  * We inline and undef some functions that may be implemented
