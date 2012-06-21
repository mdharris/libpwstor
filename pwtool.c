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

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include "localconfig.h"
#include <pwstor.h>


#define OPT_NOBASE64		0x001
#define OPT_MULTI		0x002


extern char *optarg;
extern int optind;
uint16_t Options;

static char *pwtool_prompt(uint32_t l);


int main(int argc, char **argv)
{
	char goc;
	char *pass;
	size_t pass_len;
	uint32_t max_len;
	PasswordData *data;

	Options = 0;
	pass = (char *)NULL;
	pass_len = 0;
	max_len = 0;
	data = (PasswordData *)NULL;

	while ((goc = getopt(argc, argv, "hvbp:")) != -1)
	{
		switch (goc)
		{
			case 'h':
			{
				break;
			}
			case 'v':
			{
				fprintf(stdout, "[%s] pwtool built with libpwstor version %s\n\n", argv[0], pws_version());
				fprintf(stdout, "Copyright 2011 Matt Harris.  All rights reserved.  \nSee the LICENSE file in the source distribution for terms of use.\n");
				fprintf(stdout, "\tURL: http://ftp.redtriangletc.net/pub/code/libs/\n\n");
				return(0);
				break;
			}
			case 'p':
			{
				pass = (char *)malloc(strlen(optarg) + 1);
				if (!pass)
				{
					fprintf(stdout, "Error: malloc(pass): %s\n", strerror(errno));
					return(1);
				}
				memset(pass, 0, (strlen(optarg) + 1));
				pass_len = strlen(optarg);
				snprintf(pass, (strlen(optarg) + 1), "%s", optarg);
				break;
			}
			case 'b':
			{
				Options |= OPT_NOBASE64;
				break;
			}
			default:
			{
				fprintf(stdout, "Error: Invalid argument \"-%c\".\n", goc);
				return(3);
				break;
			}
		}
	}

	if (!pass)
	{
		pass = pwtool_prompt(max_len);
		if (!pass)
		{
			fprintf(stdout, "Error: pwtool_prompt(): %s\n", strerror(errno));
			return(2);
		}
	}

	data = (PasswordData *)calloc(1, sizeof(PasswordData));
	if (!data)
	{
		fprintf(stdout, "Error: malloc(data): %s\n", strerror(errno));
		return(1);
	}

	if (pws_passwords_encodemulti(pass, data) < 0)
	{
		if (pass)
		{
			pws_memnuke((volatile void *)pass, pass_len);
			free(pass);
		}

		fprintf(stdout, "Error: pws_passwords_encodemulti(): %s\n", strerror(errno));
		return(2);
	}

	if (Options & OPT_NOBASE64)
	{
	}
	else
	{
		fprintf(stdout, "%c|%s|%s", data->version, data->salt_b64, data->hash_b64);
	}

	if (pass)
	{
		pws_memnuke((volatile void *)pass, pass_len);
		free(pass);
	}

	fputc('\n', stdout);

	return(0);
}

char *pwtool_prompt(uint32_t l)
{
	return((char *)NULL);
}
