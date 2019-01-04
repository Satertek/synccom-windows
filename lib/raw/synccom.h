/*
Copyright (C) 2019  Commtech, Inc.

This file is part of synccom-windows.

synccom-windows is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published bythe Free
Software Foundation, either version 3 of the License, or (at your option)
any later version.

synccom-windows is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along
with synccom-windows.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SYNCCOM_PUBLIC_H
#define SYNCCOM_PUBLIC_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <string.h>

#define SYNCCOM_REGISTERS_INIT(registers) memset(&registers, -1, sizeof(registers))
#define SYNCCOM_UPDATE_VALUE -2
#define STATUS_LENGTH 2
#define NUM_CLOCK_BYTES 20

typedef INT64 synccom_register;

struct synccom_registers {
	synccom_register __reserved1[2];
	synccom_register FIFOT;
	synccom_register __reserved2[2];
	synccom_register CMDR;
	synccom_register STAR; /* Read-only */
	synccom_register CCR0;
	synccom_register CCR1;
	synccom_register CCR2;
	synccom_register BGR;
	synccom_register SSR;
	synccom_register SMR;
	synccom_register TSR;
	synccom_register TMR;
	synccom_register RAR;
	synccom_register RAMR;
	synccom_register PPR;
	synccom_register TCR;
	synccom_register VSTR; /* Read-only */
	synccom_register __reserved4[1];
	synccom_register IMR;
	synccom_register DPLLR;
	synccom_register FCR;
};

struct synccom_memory_cap {
	int input;
	int output;
};

enum transmit_modifiers { XF = 0, XREP = 1, TXT = 2, TXEXT = 4 };


enum CCR0_MODE { HDLC = 0 << 0, XSYNC = 1 << 0, TRANS = 2 << 0 };
enum CCR0_CLOCK { CM0 = 0 << 2, CM1 = 1 << 2, CM2 = 2 << 2, CM3 = 3 << 2, CM4 = 4 << 2, CM5 = 5 << 2, CM6 = 6 << 2, CM7 = 7 << 2 };
enum CCR0_LE { NRZ = 0 << 5, NRZI = 1 << 5, FM0 = 2 << 5, FM1 = 3 << 5, MANCHESTER = 4 << 5, DIFF_MANCHESTER = 5 << 5 };
enum CCR0_FSM { FSM0 = 0 << 8, FSM1 = 1 << 8, FSM2 = 2 << 8, FSM3 = 3 << 8, FSM4 = 4 << 8, FSM5 = 5 << 8 };
enum CCR0_SFLAG { SFLAG_DISABLE = 0 << 11, SFLAG_ENABLE = 1 << 11 };
enum CCR0_ITF { ITF_ONES = 0 << 12, ITF_SYNC = 1 << 12 };
enum CCR0_NSB { NSB0 = 0 << 13, NSB1 = 1 << 13, NSB2 = 2 << 13, NSB3 = 3 << 13, NSB4 = 4 << 13 };
enum CCR0_NTB { NTB0 = 0 << 16, NTB1 = 1 << 16, NTB2 = 2 << 16, NTB3 = 3 << 16, NTB4 = 4 << 16 };
enum CCR0_VIS { VIS_DISABLE = 0 << 19, VIS_ENABLE = 1 << 19 };
enum CCR0_CRC { CRC_8 = 0 << 20, CRC_CCITT = 1 << 20, CRC_16 = 2 << 20, CRC_32 = 3 << 20 };
enum CCR0_OBT { OBT_LSB = 0 << 22, OBT_MSB = 1 << 22 };
enum CCR0_ADM { ADM_DISABLE = 0 << 23, ADM1 = 2 << 23, ADM2 = 3 << 23 };
enum CCR0_RECD { RECD_DISABLE = 0 << 25, RECD_ENABLE = 1 << 25 };
enum CCR0_EXTS { EXTS_CTS = 0 << 28, EXTS_DSR = 1 << 28, EXTS_RI = 2 << 28, EXTS_CD = 3 << 28 };

enum CCR1_RTS { RTS_INACTIVE = 0 << 0, RTS_ACTIVE = 1 << 0 };
enum CCR1_DTR { DTR_INACTIVE = 0 << 1, DTR_ACTIVE = 1 << 1 };
enum CCR1_RTSC { RTSC_AUTO = 0 << 2, RTSC_MANUAL = 1 << 2 };
enum CCR1_CTSC { CTSC_AUTO = 0 << 3, CTS_MANUAL = 1 << 3 };
enum CCR1_ZINS { ZINS_DISABLE = 0 << 4, ZINS_ENABLE = 1 << 4 };
enum CCR1_OINS { OINS_DISABLE = 0 << 5, OINS_ENABLE = 1 << 5 };
enum CCR1_DPS { DPS_NORMAL = 0 << 6, DPS_DISABLE = 1 << 6 };
enum CCR1_SYNC2F { SYNC2F_DISABLE = 0 << 7, SYNC2F_ENABLE = 1 << 7 };
enum CCR1_TERM2F { TERM2F_DISABLE = 0 << 8, TERM2F_ENABLE = 1 << 8 };
enum CCR1_ADD2F { ADD2F_DISABLE = 0 << 9, ADD2F_ENABLE = 1 << 9 };
enum CCR1_CRC2F { CRC2F_DISABLE = 0 << 10, CRC2F_ENABLE = 1 << 10 };
enum CCR1_CRCR { CRCR_ONES = 0 << 11, CRC_ZEROS = 1 << 11 };
enum CCR1_DRCRC { DRCRC_DISABLE = 0 << 12, DRCRC_ENABLE = 1 << 12 };
enum CCR1_DTCRC { DTCRC_DISABLE = 0 << 13, DTCRC_ENABLE = 1 << 13 };
enum CCR1_DTERM { DTERM_DISABLE = 0 << 14, DTERM_ENABLE = 1 << 14 };
enum CCR1_DSYNC { DSYNC_DISABLE = 0 << 15, DSYNC_ENABLE = 1 << 15 };
enum CCR1_RIP { RI_LOW = 0 << 16, RI_HIGH = 1 << 16 };
enum CCR1_CDP { CD_HIGH = 0 << 17, CD_LOW = 1 << 17 };
enum CCR1_RTSP { RTS_LOW = 0 << 18, RTS_HIGH = 1 << 18 };
enum CCR1_CTSP { CTS_LOW = 0 << 19, CTSP_HIGH = 1 << 19 };
enum CCR1_DTRP { DTR_LOW = 0 << 20, DTR_HIGH = 1 << 20 };
enum CCR1_DSRP { DSR_LOW = 0 << 21, DSR_HIGH = 1 << 21 };
enum CCR1_FSRP { FSR_HIGH = 0 << 22, FSR_LOW = 1 << 22 };
enum CCR1_FSTP { FST_HIGH = 0 << 23, FST_LOW = 1 << 23 };
enum CCR1_TCOP { TCO_HIGH = 0 << 24, TCO_LOW = 1 << 24 };
enum CCR1_TCIP { TCI_HIGH = 0 << 25, TCI_LOW = 1 << 25 };
enum CCR1_RCP { RC_HIGH = 0 << 26, RC_LOW = 1 << 26 };
enum CCR1_TDP { TD_HIGH = 0 << 27, TD_LOW = 1 << 27 };
enum CCR1_RDP { RD_HIGH = 0 << 28, RD_LOW = 1 << 28 };

enum TCR_TSRC { TSRC_OSC = 0 << 0, TSRC_TRANSMIT = 1 << 0, TSRC_RECEIVE = 2 << 0, TSRC_PCI = 3 << 0 };
enum TCR_TTRIG { TTRIG_REPEAT = 0 << 2, TTRIG_ONCE = 1 << 2 };

enum FCR_RECHO { RECHO_DISABLE = 0 << 16, RECHO_ENABLE = 1 << 16 };
enum FCR_TC485 { CLOCK_422 = 0 << 17, CLOCK_485 = 1 << 17 };
enum FCR_TD485 { DATA_422 = 0 << 18, DATA_485 = 1 << 18 };
enum FCR_FSTDTR { FST_PIN = 0 << 19, DTR_PIN = 1 << 19 };

#define SYNCCOM_IOCTL_MAGIC 0x8018
#define SYNCCOM_IOCTL_INDEX 0x800

#define SYNCCOM_GET_REGISTERS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_SET_REGISTERS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+1, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_PURGE_TX CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_PURGE_RX CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+3, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_ENABLE_APPEND_STATUS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_DISABLE_APPEND_STATUS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+5, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_APPEND_STATUS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+13, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_SET_MEMORY_CAP CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+6, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_MEMORY_CAP CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+7, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_SET_CLOCK_BITS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+8, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_ENABLE_IGNORE_TIMEOUT CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+10, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_DISABLE_IGNORE_TIMEOUT CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+11, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_IGNORE_TIMEOUT CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+15, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_SET_TX_MODIFIERS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+12, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_TX_MODIFIERS CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+14, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_ENABLE_RX_MULTIPLE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+16, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_DISABLE_RX_MULTIPLE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+17, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_RX_MULTIPLE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+18, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_ENABLE_APPEND_TIMESTAMP CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+19, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_DISABLE_APPEND_TIMESTAMP CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+20, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_APPEND_TIMESTAMP CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+21, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_ENABLE_WAIT_ON_WRITE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+22, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_DISABLE_WAIT_ON_WRITE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+23, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define SYNCCOM_GET_WAIT_ON_WRITE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+24, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_GET_MEM_USAGE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+26, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_REPROGRAM CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+27, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SYNCCOM_GET_FIRMWARE CTL_CODE(SYNCCOM_IOCTL_MAGIC, SYNCCOM_IOCTL_INDEX+28, METHOD_BUFFERED, FILE_ANY_ACCESS)

#ifdef __cplusplus
}
#endif
#endif
