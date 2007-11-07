/*-
 * Copyright (c) 1982, 1986, 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * @(#)socketvar.h	8.3 (Berkeley) 2/19/95
 * $FreeBSD: src/sys/sys/socketvar.h,v 1.46.2.10 2003/08/24 08:24:39 hsu Exp $
 * $DragonFly: src/sys/sys/socketvar2.h,v 1.1 2007/11/07 18:24:04 dillon Exp $
 */

#ifndef _SYS_SOCKETVAR2_H_
#define _SYS_SOCKETVAR2_H_

#ifndef _SYS_SOCKETVAR_H_
#include <sys/socketvar.h>
#endif
#ifndef _SYS_SYSTM_H_
#include <sys/systm.h>
#endif
#ifndef _SYS_MALLOC_H_
#include <sys/malloc.h>
#endif

/*
 * Acquire a lock on a signalsockbuf, sleep if the lock is already held.
 * The sleep is interruptable unless SSB_NOINTR is set in the ssb.
 *
 * Returns 0 on success, non-zero if the lock could not be acquired.
 */
static __inline int
ssb_lock(struct signalsockbuf *ssb, int wf)
{
	if (ssb->ssb_flags & SSB_LOCK) {
		if (wf == M_WAITOK)
			return _ssb_lock(ssb);
		return EWOULDBLOCK;
	} else {
		ssb->ssb_flags |= SSB_LOCK;
		return 0;
	}
}

/*
 * Release a previously acquired lock on a signalsockbuf.
 */
static __inline void
ssb_unlock(struct signalsockbuf *ssb)
{
	ssb->ssb_flags &= ~SSB_LOCK;
	if (ssb->ssb_flags & SSB_WANT) {
		ssb->ssb_flags &= ~SSB_WANT;
		wakeup(&ssb->ssb_flags);
	}
}

#endif
