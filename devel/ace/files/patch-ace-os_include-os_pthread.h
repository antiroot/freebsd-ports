--- ace/os_include/os_pthread.h.orig	2012-07-27 13:59:14.000000000 -0500
+++ ace/os_include/os_pthread.h	2012-07-27 13:59:50.000000000 -0500
@@ -299,7 +299,11 @@
 #    undef THR_DAEMON
 
 #    define THR_BOUND               0x00000001
+# if defined(__FreeBSD__)
+#    define THR_NEW_LWP             0x00000000
+# else
 #    define THR_NEW_LWP             0x00000002
+# endif
 #    define THR_DETACHED            0x00000040
 #    define THR_SUSPENDED           0x00000080
 #    define THR_DAEMON              0x00000100
