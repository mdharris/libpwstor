/*
 * Copyright (c) 2008
 *      Matt Harris.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY Mr. Harris AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Mr. Harris OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef INCLUDED_PWSTORINTERNAL_H
# define INCLUDED_PWSTORINTERNAL_H	1

# include "localconfig.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <errno.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/param.h>
# include <limits.h>
# include <string.h>
# if defined(HAVE_SYS_ENDIAN_H)
#  include <sys/endian.h>
# elif defined(HAVE_MACHINE_ENDIAN_H)
#  include <machine/endian.h>
# endif /* defined(HAVE_SYS_ENDIAN_H) ; defined(HAVE_MACHINE_ENDIAN_H) */
# include "pwstor.h"

/* OpenSSL includes */
# include <openssl/opensslv.h>
# include <openssl/rand.h>
# include <openssl/bio.h>
# include <openssl/crypto.h>
# include <openssl/evp.h>
# include <openssl/engine.h>
# include <openssl/err.h>

# define stringtoint(x)			(int)strtol((x), (char **)NULL, 10)
# define stringtolong(x)		strtol((x), (char **)NULL, 10)
# define stringtouint(x)		(unsigned int)strtoul((x), (char **)NULL, 10)
# define stringtoulong(x)		strtoul((x), (char **)NULL, 10)
# define stringtofloat(x)		strtof((x), (char **)NULL)

/* Note here: strlen() is used, so the string must be null-terminated to use this macro... */
# define pws_base64_dstrlen(x)			(3 * (strlen((x)) / 4 + 1))
/* This one is safe if it's not a null-terminated string, just pass the length of the data to be decoded. */
# define pws_base64_dlen(x)			(3 * ((x) / 4 + 1))

#endif /* INCLUDED_PWSTORINTERNAL_H */
