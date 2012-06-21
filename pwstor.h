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

#ifndef INCLUDED_PWSTOR_H
# define INCLUDED_PWSTOR_H		1

/*
** DEFINES
*/

# define PWS_VERSION_STR		"0.1"
# define PWS_VERSION_INT		0x000010

/*
** STRUCTURES
*/

/*
 * Password data storage structure used by pws_passwords_*multi()
 */
struct _pws_passwords_data
{
	unsigned char version;
	unsigned char salt[8];
	char salt_b64[17];
	unsigned char hash[32];
	char hash_b64[65];
};
typedef struct _pws_passwords_data PasswordData;

/*
** DECLARATIONS
*/

/* base64.c */
extern unsigned char *pws_base64_encode(unsigned char *src, unsigned char *dst, size_t len);
extern unsigned char *pws_base64_decode(unsigned char *src, unsigned char *dst);

/* passwords.c */
extern int pws_passwords_encode(char *indata, char *outdata, uint8_t use_b64);
extern int pws_passwords_check(char *chk, const char *real, uint8_t is_b64);
extern size_t pws_passwords_len(uint8_t use_b64);
extern int pws_passwords_encodemulti(char *indata, struct _pws_passwords_data *outdata);
extern int pws_passwords_checkmulti(char *chk, struct _pws_passwords_data *real);
extern int pws_passwords_converttomulti(unsigned char *indata, struct _pws_passwords_data *outdata, uint8_t is_b64);

/* utils.c */
extern int pws_rand_get(size_t bytes, unsigned char *dst);
extern void pws_memnuke(volatile void *b, size_t sz);
extern char *pws_version(void);
extern uint32_t pws_version_int(void);

#endif /* INCLUDED_PWSTOR_H */
