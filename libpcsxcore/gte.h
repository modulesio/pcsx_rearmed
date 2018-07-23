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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.           *
 ***************************************************************************/

#ifndef __GTE_H__
#define __GTE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "psxcommon.h"
#include "r3000a.h"

void gteMFC2();
void gteCFC2();
void gteMTC2();
void gteCTC2();
void gteLWC2();
void gteSWC2();

void gteRTPS(struct psxCP2Regs *regs);
void gteNCLIP(struct psxCP2Regs *regs);
void gteOP(struct psxCP2Regs *regs);
void gteDPCS(struct psxCP2Regs *regs);
void gteINTPL(struct psxCP2Regs *regs);
void gteMVMVA(struct psxCP2Regs *regs);
void gteNCDS(struct psxCP2Regs *regs);
void gteCDP(struct psxCP2Regs *regs);
void gteNCDT(struct psxCP2Regs *regs);
void gteNCCS(struct psxCP2Regs *regs);
void gteCC(struct psxCP2Regs *regs);
void gteNCS(struct psxCP2Regs *regs);
void gteNCT(struct psxCP2Regs *regs);
void gteSQR(struct psxCP2Regs *regs);
void gteDCPL(struct psxCP2Regs *regs);
void gteDPCT(struct psxCP2Regs *regs);
void gteAVSZ3(struct psxCP2Regs *regs);
void gteAVSZ4(struct psxCP2Regs *regs);
void gteRTPT(struct psxCP2Regs *regs);
void gteGPF(struct psxCP2Regs *regs);
void gteGPL(struct psxCP2Regs *regs);
void gteNCCT(struct psxCP2Regs *regs);

#ifdef __cplusplus
}
#endif
#endif
