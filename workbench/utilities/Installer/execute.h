#ifndef _EXECUTE_H
#define _EXECUTE_H

/* Command symbols */
struct CommandList
{
  char * cmdsymbol;
  int  cmdnumber;
};

#define _USERDEF	-1
#define _UNKNOWN	0

/* Commands */
#define _ABORT		1
#define _AND		2
#define _ASKBOOL	3
#define _ASKCHOICE	4
#define _ASKDIR		5
#define _ASKDISK	6
#define _ASKFILE	7
#define _ASKNUMBER	8
#define _ASKOPTIONS	9
#define _ASKSTRING	10
#define _BITAND		11
#define _BITNOT		12
#define _BITOR		13
#define _BITXOR		14
#define _CAT		15
#define _COMPLETE	16
#define _COPYFILES	17
#define _COPYLIB	18
#define _DATABASE	19
#define _DEBUG		20
#define _DELETE		21
#define _DIFF		22
#define _DIV		23
#define _EARLIER	24
#define _EQUAL		25
#define _EXECUTE	26
#define _EXISTS		27
#define _EXIT		28
#define _EXPANDPATH	29
#define _FILEONLY	30
#define _FOREACH	31
#define _GETASSIGN	32
#define _GETDEVICE	33
#define _GETDISKSPACE	34
#define _GETENV		35
#define _GETSIZE	36
#define _GETSUM		37
#define _GETVERSION	38
#define _IF		39
#define _IN		40
#define _LESS		41
#define _LESSEQ		42
#define _MAKEASSIGN	43
#define _MAKEDIR	44
#define _MESSAGE	45
#define _MINUS		46
#define _MORE		47
#define _MOREEQ		48
#define _NOT		49
#define _ONERROR	50
#define _OR		51
#define _PATHONLY	52
#define _PATMATCH	53
#define _PLUS		54
#define _PROCEDURE	55
#define _PROTECT	56
#define _RENAME		57
#define _REXX		58
#define _RUN		59
#define _SELECT		60
#define _SET		61
#define _SHIFTLEFT	62
#define _SHIFTRGHT	63
#define _STARTUP	64
#define _STRING		65
#define _STRLEN		66
#define _SUBSTR		67
#define _TACKON		68
#define _TEXTFILE	69
#define _TIMES		70
#define _TOOLTYPE	71
#define _TRANSCRIPT	72
#define _TRAP		73
#define _UNTIL		74
#define _USER		75
#define _WELCOME	76
#define _WHILE		77
#define _WORKING	78
#define _XOR		79

#define NUMCMDS		79
/* Parameters */
#define _PARAMETER	128 /* Base number for parameters */

/* Parameters with args */
#define _APPEND		(_PARAMETER + 1)
#define _CHOICES	(_PARAMETER + 2)
#define _COMMAND	(_PARAMETER + 3)
#define _CONFIRM	(_PARAMETER + 4)
#define _DEFAULT	(_PARAMETER + 5)
#define _DELOPTS	(_PARAMETER + 6)
#define _DEST		(_PARAMETER + 7)
#define _HELP		(_PARAMETER + 8)
#define _INCLUDE	(_PARAMETER + 9)
#define _NEWNAME	(_PARAMETER + 10)
#define _OPTIONAL	(_PARAMETER + 11)
#define _PATTERN	(_PARAMETER + 12)
#define _PROMPT		(_PARAMETER + 13)
#define _RANGE		(_PARAMETER + 14)
#define _SETDEFAULTTOOL	(_PARAMETER + 15)
#define _SETSTACK	(_PARAMETER + 16)
#define _SETTOOLTYPE	(_PARAMETER + 17)
#define _SOURCE		(_PARAMETER + 18)

/* Boolean parameters */
#define _ALL		(_PARAMETER + 19)
#define _ASSIGNS	(_PARAMETER + 20)
#define _DISK		(_PARAMETER + 21)
#define _FILES		(_PARAMETER + 22)
#define _FONTS		(_PARAMETER + 23)
#define _INFOS		(_PARAMETER + 24)
#define _NEWPATH	(_PARAMETER + 25)
#define _NOGAUGE	(_PARAMETER + 26)
#define _NOPOSITION	(_PARAMETER + 27)
#define _QUIET		(_PARAMETER + 28)
#define _SAFE		(_PARAMETER + 29)
#define _SWAPCOLORS	(_PARAMETER + 30)

#define NUMPARAMS	30	/* Number of keywords used as parameters */
#define NUMARGPARAMS	18	/* Number of keywords used as parameters which may have arguments */

#define _MAXCOMMAND	(NUMPARAMS+NUMCMDS)	/* Total number of keywords */

#define GetPL( x, y )	x[ y - _PARAMETER -1 ]

/* _DATABASE keywords */

/* Installer 1.24 keywords */
#define _VBLANK		1
#define _CPU		2
#define _GRAPHICS_MEM	3
#define _TOTAL_MEM	4
/* Installer V43 keywords */
#define _FPU		5
#define	_CHIPREV	6


#endif /* _EXECUTE_H */

