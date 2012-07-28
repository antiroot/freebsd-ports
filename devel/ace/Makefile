# Ports collection makefile for:	ace
# Date created:				5 January 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD: ports/devel/ace/Makefile,v 1.24 2009/08/02 19:33:01 mezz Exp $
#

PORTNAME=	ace
PORTVERSION=   5.8.3
CATEGORIES=	devel
MASTER_SITES=	ftp://download.dre.vanderbilt.edu/previous_versions/ \
		http://download.dre.vanderbilt.edu/previous_versions/
DISTNAME=	ACE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Adaptive Communication Environment for C++

CONFLICTS=	ace+tao-5*

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-ace-tests
USE_OPENSSL=   yes
USE_GNOME=	pkgconfig

WRKSRC=		${WRKDIR}/ACE_wrappers
BUILD_WRKSRC=	${WRKSRC}/objdir
INSTALL_WRKSRC=	${BUILD_WRKSRC}
NOT_FOR_ARCHS=	sparc64
MAKE_JOBS_SAFE=	yes
PLIST_SUB+=    PORTVERSION=${PORTVERSION}

MAN1=    ace_gperf.1

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${BUILD_WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@libdir@/pkgconfig|@prefix@/libdata/pkgconfig|g'
.if (${OSVERSION} >= 700110 && ${OSVERSION} < 800000) || ${OSVERSION} >= 800024
	@${REINPLACE_CMD} -e 's|cpu_set_t|cpuset_t|g' ${WRKSRC}/ace/OS_NS_Thread.cpp \
		${WRKSRC}/ace/OS_NS_Thread.h
.endif

do-configure:
	@(cd ${BUILD_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ../${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			 ${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			 (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
			 ${FALSE}; \
		fi)

post-install:
       @suf=.so; while read f; do \
       case $$f in \
       *%%PORTVERSION%%.so* ) \
              f=$${f%\%%PORTVERSION%%$$suf}${PORTVERSION}$$suf; \
              ${LN} -fs ${PREFIX}/$$f \
                     ${PREFIX}/$${f%-${PORTVERSION}$$suf}$$suf.5; \
       esac \
       done < ${PLIST}

.include <bsd.port.post.mk>
