/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
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
 *	@(#)stdio.h	8.5 (Berkeley) 4/29/95
 * $FreeBSD: src/include/stdio.h,v 1.78 2009/03/25 08:07:52 das Exp $
 */

#ifndef	_STDIO_H_
#define	_STDIO_H_

#include <sys/cdefs.h>
#include <sys/_null.h>
#include <sys/types.h>
#include <machine/stdarg.h> /* for __va_list */

typedef	__off_t		fpos_t;

#ifndef _SIZE_T_DECLARED
typedef	__size_t	size_t;
#define	_SIZE_T_DECLARED
#endif

#if __POSIX_VISIBLE >= 200809
#ifndef _OFF_T_DECLARED
#define	_OFF_T_DECLARED
typedef	__off_t		off_t;
#endif
#ifndef _SSIZE_T_DECLARED
#define	_SSIZE_T_DECLARED
typedef	__ssize_t	ssize_t;
#endif
#endif

#if __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE
#ifdef __GNUC__
#ifndef _VA_LIST_DECLARED
#define	_VA_LIST_DECLARED
typedef	__va_list	va_list;
/* __gnuc_va_list is not needed, provided by <machine/stdarg.h> */
#endif
#else
#include <stdarg.h>
#endif
#endif

#define	_FSTDIO			/* Define for new stdio with functions. */

/*
 * stdio state variables.
 *
 * The following always hold:
 *
 *	if (_flags&(__SLBF|__SWR)) == (__SLBF|__SWR),
 *		_lbfsize is -_bf._size, else _lbfsize is 0
 *	if _flags&__SRD, _w is 0
 *	if _flags&__SWR, _r is 0
 *
 * This ensures that the getc and putc macros (or inline functions) never
 * try to write or read from a file that is in `read' or `write' mode.
 * (Moreover, they can, and do, automatically switch from read mode to
 * write mode, and back, on "r+" and "w+" files.)
 *
 * _lbfsize is used only to make the inline line-buffered output stream
 * code as compact as possible.
 *
 * WARNING: Do not change the order of the fields in __FILE_public!
 */
#ifndef _STDFILE_DECLARED
#define	_STDFILE_DECLARED
typedef struct __FILE FILE;
#endif

struct __FILE_public {
	unsigned char	*_p;		/* current position in (some) buffer */
	int		_flags;		/* flags, below; this FILE is free if 0 */
	int		_fileno;	/* fileno, if Unix descriptor, else -1 */
	__ssize_t	_r;		/* read space left for getc() */
	__ssize_t	_w;		/* write space left for putc() */
	__ssize_t	_lbfsize;	/* 0 or -_bf._size, for inline putc */
};

#ifndef _STDSTREAM_DECLARED
__BEGIN_DECLS
extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
__END_DECLS
#define	_STDSTREAM_DECLARED
#endif

#define	__SLBF	0x0001		/* line buffered */
#define	__SNBF	0x0002		/* unbuffered */
#define	__SRD	0x0004		/* OK to read */
#define	__SWR	0x0008		/* OK to write */
	/* RD and WR are never simultaneously asserted */
#define	__SRW	0x0010		/* open for reading & writing */
#define	__SEOF	0x0020		/* found EOF */
#define	__SERR	0x0040		/* found error */
#define	__SMBF	0x0080		/* _buf is from malloc */
#define	__SAPP	0x0100		/* fdopen()ed in append mode */
#define	__SSTR	0x0200		/* this is an sprintf/snprintf string */
#define	__SOPT	0x0400		/* do fseek() optimization */
#define	__SNPT	0x0800		/* do not do fseek() optimization */
#define	__SOFF	0x1000		/* set iff _offset is in fact correct */
#define	__SMOD	0x2000		/* true => fgetln modified _p text */
#define	__SALC	0x4000		/* allocate string space dynamically */
#define	__SIGN	0x8000		/* ignore this file in _fwalk */

/*
 * The following three definitions are for ANSI C, which took them
 * from System V, which brilliantly took internal interface macros and
 * made them official arguments to setvbuf(), without renaming them.
 * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
 *
 * Although numbered as their counterparts above, the implementation
 * does not rely on this.
 */
#define	_IOFBF	0		/* setvbuf should set fully buffered */
#define	_IOLBF	1		/* setvbuf should set line buffered */
#define	_IONBF	2		/* setvbuf should set unbuffered */

#define	BUFSIZ	1024		/* size of buffer used by setbuf */
#define	EOF	(-1)

/*
 * FOPEN_MAX is a minimum maximum, and is the number of streams that
 * stdio can provide without attempting to allocate further resources
 * (which could fail).  Do not use this for anything.
 */
				/* must be == _POSIX_STREAM_MAX <limits.h> */
#ifndef FOPEN_MAX
#define	FOPEN_MAX	20	/* must be <= OPEN_MAX <sys/syslimits.h> */
#endif
#define	FILENAME_MAX	1024	/* must be <= PATH_MAX <sys/syslimits.h> */

/* System V/ANSI C; this is the wrong way to do this, do *not* use these. */
#if __XSI_VISIBLE
#define	P_tmpdir	"/tmp/"
#endif
#define	L_tmpnam	1024	/* XXX must be == PATH_MAX */
#define	TMP_MAX		308915776

/* Always ensure that these are consistent with <fcntl.h> and <unistd.h>! */
#ifndef SEEK_SET
#define	SEEK_SET	0	/* set file offset to offset */
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	/* set file offset to current plus offset */
#endif
#ifndef SEEK_END
#define	SEEK_END	2	/* set file offset to EOF plus offset */
#endif

#define	stdin	__stdinp
#define	stdout	__stdoutp
#define	stderr	__stderrp

__BEGIN_DECLS
/*
 * Functions defined in ANSI C standard.
 */
void	 clearerr(FILE *);
int	 fclose(FILE *);
int	 feof(FILE *);
int	 ferror(FILE *);
int	 fflush(FILE *);
int	 fgetc(FILE *);
int	 fgetpos(FILE * __restrict, fpos_t * __restrict);
char	*fgets(char * __restrict, int, FILE * __restrict);
FILE	*fopen(const char * __restrict, const char * __restrict);
int	 fprintf(FILE * __restrict, const char * __restrict, ...)
	     __printflike(2, 3);
int	 fputc(int, FILE *);
int	 fputs(const char * __restrict, FILE * __restrict);
size_t	 fread(void * __restrict, size_t, size_t, FILE * __restrict);
FILE	*freopen(const char * __restrict, const char * __restrict,
		 FILE * __restrict);
int	 fscanf(FILE * __restrict, const char * __restrict, ...)
	     __scanflike(2, 3);
int	 fseek(FILE *, long, int);
int	 fsetpos(FILE *, const fpos_t *);
long	 ftell(FILE *);
size_t	 fwrite(const void * __restrict, size_t, size_t, FILE * __restrict);
int	 getc(FILE *);
int	 getchar(void);
char	*gets(char *);
void	 perror(const char *);
int	 printf(const char * __restrict, ...) __printflike(1, 2);
int	 putc(int, FILE *);
int	 putchar(int);
int	 puts(const char *);
int	 remove(const char *);
int	 rename(const char *, const char *);
void	 rewind(FILE *);
int	 scanf(const char * __restrict, ...) __scanflike(1, 2);
void	 setbuf(FILE * __restrict, char * __restrict);
int	 setvbuf(FILE * __restrict, char * __restrict, int, size_t);
int	 sprintf(char * __restrict, const char * __restrict, ...)
	     __printflike(2, 3);
int	 sscanf(const char * __restrict, const char * __restrict, ...)
	     __scanflike(2, 3);
FILE	*tmpfile(void);
char	*tmpnam(char *);
int	 ungetc(int, FILE *);
int	 vfprintf(FILE * __restrict, const char * __restrict, __va_list)
	     __printflike(2, 0);
int	 vprintf(const char * __restrict, __va_list) __printflike(1, 0);
int	 vsprintf(char * __restrict, const char * __restrict, __va_list)
	     __printflike(2, 0);

#if __ISO_C_VISIBLE >= 1999 || __XSI_VISIBLE >= 500
int	 snprintf(char * __restrict, size_t, const char * __restrict, ...)
	    __printflike(3, 4);
int	 vsnprintf(char * __restrict, size_t, const char * __restrict,
		   __va_list) __printflike(3, 0);
#endif
#if __ISO_C_VISIBLE >= 1999
int	 vfscanf(FILE * __restrict, const char * __restrict, __va_list)
	    __scanflike(2, 0);
int	 vscanf(const char * __restrict, __va_list) __scanflike(1, 0);
int	 vsscanf(const char * __restrict, const char * __restrict, __va_list)
	    __scanflike(2, 0);
#endif

/*
 * Functions defined in all versions of POSIX 1003.1.
 */
#if __BSD_VISIBLE || __POSIX_VISIBLE <= 199506
#define	L_cuserid	17	/* size for cuserid(3); MAXLOGNAME, legacy */
#endif

#if __POSIX_VISIBLE
#define	L_ctermid	1024	/* size for ctermid(3); PATH_MAX */

char	*ctermid(char *);
FILE	*fdopen(int, const char *);
int	 fileno(FILE *);
#endif /* __POSIX_VISIBLE */

#if __POSIX_VISIBLE >= 199209
int	 pclose(FILE *);
FILE	*popen(const char *, const char *);
#endif

#if __POSIX_VISIBLE >= 199506
int	 ftrylockfile(FILE *);
void	 flockfile(FILE *);
void	 funlockfile(FILE *);

/*
 * These are normally used through macros as defined below, but POSIX
 * requires functions as well.
 */
int	 getc_unlocked(FILE *);
int	 getchar_unlocked(void);
int	 putc_unlocked(int, FILE *);
int	 putchar_unlocked(int);
#endif
#if __BSD_VISIBLE
void	 clearerr_unlocked(FILE *);
int	 feof_unlocked(FILE *);
int	 ferror_unlocked(FILE *);
int	 fileno_unlocked(FILE *);
#endif

#if __XSI_VISIBLE >= 500 || __POSIX_VISIBLE >= 200112
int	 fseeko(FILE *, __off_t, int);
__off_t	 ftello(FILE *);
#endif

#if __BSD_VISIBLE || __XSI_VISIBLE > 0 && __XSI_VISIBLE < 600
int	 getw(FILE *);
int	 putw(int, FILE *);
#endif /* BSD or X/Open before issue 6 */

#if __XSI_VISIBLE
char	*tempnam(const char *, const char *);
#endif

#if __POSIX_VISIBLE >= 200809
FILE 	*fmemopen(void *__restrict, size_t, const char *__restrict);
ssize_t	 getdelim(char ** __restrict, size_t * __restrict, int,
		  FILE * __restrict);
FILE	*open_memstream(char **, size_t *);
int	 renameat(int, const char *, int, const char *);
int	 vdprintf(int, const char * __restrict, __va_list) __printflike(2, 0);
int	 dprintf(int, const char * __restrict, ...) __printflike(2, 3);
ssize_t	 getline(char ** __restrict, size_t * __restrict, FILE * __restrict);
#endif /* __POSIX_VISIBLE >= 200809 */

/*
 * Routines that are purely local.
 */
#if __BSD_VISIBLE
int	 asprintf(char **, const char *, ...) __printflike(2, 3);
char	*ctermid_r(char *);
void	 fcloseall(void);
void	*fcookie(FILE *);
char	*fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *) __format_arg(2);
__ssize_t __fpending(const FILE *);
int	 fpurge(FILE *);
void	 setbuffer(FILE *, char *, int);
int	 setlinebuf(FILE *);
int	 vasprintf(char **, const char *, __va_list) __printflike(2, 0);

/*
 * The system error table contains messages for the first sys_nerr
 * positive errno values.  Use strerror() or strerror_r() from <string.h>
 * instead.
 */
extern const int sys_nerr;
extern const char *const sys_errlist[];

/*
 * Stdio function-access interface.
 */
FILE	*funopen(const void *, int (*)(void *, char *, int),
		 int (*)(void *, const char *, int),
		 fpos_t (*)(void *, fpos_t, int), int (*)(void *));
#define	fropen(cookie, fn) funopen(cookie, fn, 0, 0, 0)
#define	fwopen(cookie, fn) funopen(cookie, 0, fn, 0, 0)
#endif /* __BSD_VISIBLE */

/*
 * Functions internal to the implementation.
 */
int	__srget(FILE *);
int	__swbuf(int, FILE *);

/*
 * The __sfoo functions are here so that we can
 * define real function versions in the C library.
 */
static __inline __always_inline int
__sgetc(FILE *_fp)
{
	struct __FILE_public *_p = (struct __FILE_public *)_fp;

	if (--_p->_r < 0)
		return (__srget(_fp));
	else
		return (*_p->_p++);
}

static __inline __always_inline int
__sputc(int _c, FILE *_fp)
{
	struct __FILE_public *_p = (struct __FILE_public *)_fp;

	if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && _c != '\n'))
		return (*_p->_p++ = _c);
	else
		return (__swbuf(_c, _fp));
}

static __inline __always_inline int
__sfeof(FILE *_fp)
{
	struct __FILE_public *_p = (struct __FILE_public *)_fp;

	return ((_p->_flags & __SEOF) != 0);
}

static __inline __always_inline int
__sferror(FILE *_fp)
{
	struct __FILE_public *_p = (struct __FILE_public *)_fp;

	return ((_p->_flags & __SERR) != 0);
}

static __inline __always_inline void
__sclearerr(FILE *_fp)
{
	struct __FILE_public *_p = (struct __FILE_public *)_fp;

	_p->_flags &= ~(__SERR|__SEOF);
}

static __inline __always_inline int
__sfileno(FILE *_fp)
{
	struct __FILE_public *_p = (struct __FILE_public *)_fp;

	return (_p->_fileno);
}

extern int __isthreaded;

#ifndef __cplusplus
#define	feof(p)		(!__isthreaded ? __sfeof(p) : (feof)(p))
#define	ferror(p)	(!__isthreaded ? __sferror(p) : (ferror)(p))
#define	clearerr(p)	(!__isthreaded ? __sclearerr(p) : (clearerr)(p))

#if __POSIX_VISIBLE
#define	fileno(p)	(!__isthreaded ? __sfileno(p) : (fileno)(p))
#endif

#define	getc(fp)	(!__isthreaded ? __sgetc(fp) : (getc)(fp))
#define	putc(x, fp)	(!__isthreaded ? __sputc(x, fp) : (putc)(x, fp))

#define	getchar()	getc(stdin)
#define	putchar(x)	putc(x, stdout)

#if __BSD_VISIBLE
/*
 * See ISO/IEC 9945-1 ANSI/IEEE Std 1003.1 Second Edition 1996-07-12
 * B.8.2.7 for the rationale behind the *_unlocked() macros.
 */
#define	feof_unlocked(p)	__sfeof(p)
#define	ferror_unlocked(p)	__sferror(p)
#define	clearerr_unlocked(p)	__sclearerr(p)
#define	fileno_unlocked(p)	__sfileno(p)
#endif
#if __POSIX_VISIBLE >= 199506
#define	getc_unlocked(fp)	__sgetc(fp)
#define	putc_unlocked(x, fp)	__sputc(x, fp)

#define	getchar_unlocked()	getc_unlocked(stdin)
#define	putchar_unlocked(x)	putc_unlocked(x, stdout)
#endif
#endif /* __cplusplus */

__END_DECLS
#endif /* !_STDIO_H_ */
