/*
 * Copyright (C) 2018 alx@fastestcode.org
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef tbparse_h
#define tbparse_h

enum tb_entry_type {
	TBE_CASCADE,
	TBE_COMMAND,
	TBE_SEPARATOR
};

struct tb_entry {
	enum tb_entry_type type;
	int level;
	char *title;
	char mnemonic;
	char *command;
	struct tb_entry *next;
};


/*
 * Parses a toolbox menu file. Returns zero on success.
 * If a non-zero value is returned and tb_parse_error_string()
 * returns NULL, the value returned is a system errno value.
 *
 * ent_root receives a pointer to a dynamically allocated list of
 * menu entries. This list is freed on subsequent calls to tb_parse_config.
 */
int tb_parse_config(const char *filename, struct tb_entry **ent_root);

/*
 * Returns detailed information about the syntax error
 * previously encountered while parsing a config file.
 */
char* tb_parser_error_string(void);

#endif /* tbparse_h */
