/***************************************************************************
 *   Copyright (C) 2007 Ryan Schultz, PCSX-df Team, PCSX team              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02111-1307 USA.           *
 ***************************************************************************/

#ifndef __COFF_H__
#define __COFF_H__

/********************** FILE HEADER **********************/

struct external_filehdr {
	unsigned short f_magic;		/* magic number			*/
	unsigned short f_nscns;		/* number of sections		*/
	unsigned int f_timdat;	/* time & date stamp		*/
	unsigned int f_symptr;	/* file pointer to symtab	*/
	unsigned int f_nsyms;		/* number of symtab entries	*/
	unsigned short f_opthdr;	/* sizeof(optional hdr)		*/
	unsigned short f_flags;		/* flags			*/
};

// #define	FILHDR	struct external_filehdr
// #define	FILHSZ	sizeof(FILHDR)

/*
 * Some ECOFF definitions.
 */
typedef struct filehdr {
	u16		f_magic;        /* magic number */
	u16		f_nscns;        /* number of sections */
	u32		f_timdat;       /* time & date stamp */
	u32		f_symptr;       /* file pointer to symbolic header */
	u32		f_nsyms;        /* sizeof(symbolic hdr) */
	u16		f_opthdr;       /* sizeof(optional hdr) */
	u16		f_flags;        /* flags */
} FILHDR;

typedef struct scnhdr {
	char	s_name[8];      /* section name */
	u32		s_paddr;        /* physical address, aliased s_nlib */
	u32		s_vaddr;        /* virtual address */
	u32		s_size;         /* section size */
	u32		s_scnptr;       /* file ptr to raw data for section */
	u32		s_relptr;       /* file ptr to relocation */
	u32		s_lnnoptr;      /* file ptr to gp histogram */
	u16		s_nreloc;       /* number of relocation entries */
	u16		s_nlnno;        /* number of gp histogram entries */
	u32		s_flags;        /* flags */
} SCNHDR;

typedef struct aouthdr {
	u16		magic;          /* magic */
	u16		vstamp;         /* version stamp */
	u32		tsize;          /* text size in bytes, padded to DW bdry */
	u32		dsize;          /* initialized data */
	u32		bsize;          /* uninitialized data */
	u32		entry;          /* entry pt. */
	u32		text_start;     /* base of text used for this file */
	u32		data_start;     /* base of data used for this file */
} AOUTHDR;

#endif
