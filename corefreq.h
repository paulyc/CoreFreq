/*
 * CoreFreq
 * Copyright (C) 2015-2019 CYRIL INGENIERIE
 * Licenses: GPL2
 */

#define SHM_FILENAME	"corefreq-shm"

typedef struct
{
	Bit64				OffLine __attribute__ ((aligned (64)));

	unsigned int			Toggle;

	struct
	{
		CPUID_0x00000000	StdFunc;
		CPUID_0x80000000	ExtFunc;

		unsigned int		Microcode;

		struct {
		unsigned short int	CfgLock :  1-0,
					IORedir :  2-1,
					Unused	: 16-2;
		};
		unsigned short int	CStateLimit,
					CStateInclude;
	} Query;

	struct {
		signed int		ApicID,
					CoreID,
					ThreadID,
					PackageID;
		struct {
			Bit32		BSP,
					x2APIC;
		} MP;
		struct {
		unsigned int		Set,
					Size;
		unsigned short		LineSz,
					Part,
					Way;
		    struct {
		    unsigned short	WriteBack: 1-0,
					Inclusive: 2-1,
					_pad16	: 16-2;
		    } Feature;
		} Cache[CACHE_MAX_LEVEL];
	} Topology;

	struct {
		THERMAL_PARAM		Param;
		unsigned int		TM1,
					TM2,
					Limit[2];
		struct {
			unsigned int	ClockMod : 16-0,
					Extended : 32-16;
			} DutyCycle;
		unsigned int		PowerPolicy;
		struct {
			struct {
			unsigned int	Highest,
					Guaranteed,
					Most_Efficient,
					Lowest;
			} Capabilities;
			struct {
			unsigned int	Minimum_Perf,
					Maximum_Perf,
					Desired_Perf,
					Energy_Pref;
			} Request;
		} HWP;
	} PowerThermal;

	struct FLIP_FLOP {

		struct
		{
		unsigned long long
					INST;
			struct {
		unsigned long long
				UCC,
				URC;
			}		C0;
		unsigned long long
					C3,
					C6,
					C7,
					TSC,
					C1;
		} Delta;

		CLOCK			Clock;

		struct {
			double		IPS,
					IPC,
					CPI,
					Turbo,
					C0,
					C3,
					C6,
					C7,
					C1;
		} State;

		struct {
			double		Ratio,
					Freq;
		} Relative;

		struct {
		unsigned int		Sensor,
					Temp;
		enum THERM_PWR_EVENTS	Events;
		} Thermal;

		struct {
			int		VID;
			double		Vcore;
		} Voltage;

		struct {
		unsigned int		SMI;
			struct {
			unsigned int	LOCAL,
					UNKNOWN,
					PCISERR,
					IOCHECK;
			} NMI;
		} Counter;
	} FlipFlop[2];

	struct {
		Bit64			RFLAGS,
					CR0,
					CR3,
					CR4,
					EFCR,
					EFER;
	} SystemRegister;

	CPUID_STRUCT			CpuID[CPUID_MAX_FUNC];

	struct SLICE_STRUCT {
		struct
		{
		unsigned long long	TSC,
					INST;
		} Delta;

		struct {
		unsigned long long	TSC,
					INST;
		} Counter[3];

		unsigned long long	Error;
	} Slice;
} CPU_STRUCT;

typedef struct
{
	volatile unsigned long long	Sync __attribute__ ((aligned (128)));

	FEATURES			Features;

	Bit64			PowerNow	__attribute__ ((aligned (64)));

	struct {
		unsigned long long
				PowerNow	:  1-0,
				ODCM		:  2-1,
				PowerMgmt	:  3-2,
				EIST		:  4-3,
				Turbo		:  5-4,
				C1E		:  6-5,
				C3A		:  7-6,
				C1A		:  8-7,
				C3U		:  9-8,
				C1U		: 10-9,
				CC6		: 11-10,
				PC6		: 12-11,
				SMM		: 13-12,
				VM		: 14-13,
				IOMMU		: 15-14,
				_pad64		: 64-15;
	} Technology;

	enum THERMAL_FORMULAS	thermalFormula;
	enum VOLTAGE_FORMULAS	voltageFormula;
	enum POWER_FORMULAS	powerFormula;

	struct {
		unsigned int		Count,
					OnLine;
	} CPU;

	SERVICE_PROC			Service;

	unsigned int			Boost[BOOST(SIZE)],
					PM_version;

	unsigned int			Top;

	unsigned int			Toggle;

	struct PKG_FLIP_FLOP {
		struct {
		unsigned long long	PTSC,
					PC02,
					PC03,
					PC06,
					PC07,
					PC08,
					PC09,
					PC10,
					ACCU[PWR_DOMAIN(SIZE)];
		} Delta;

		struct {
		unsigned long long	FC0;
		} Uncore;

		struct {
		unsigned int		Sensor,
					Temp;
		enum THERM_PWR_EVENTS	Events;
		} Thermal;
	} FlipFlop[2];

	struct {
		double			PC02,
					PC03,
					PC06,
					PC07,
					PC08,
					PC09,
					PC10,
					Energy[PWR_DOMAIN(SIZE)],
					Power[PWR_DOMAIN(SIZE)];
	} State;

	struct {
		double			Turbo,
					C0,
					C3,
					C6,
					C7,
					C1;
	} Avg;

	struct {
		struct {
			double		Watts,
					Joules,
					Times;
		} Unit;
	} Power;

	enum HYPERVISOR 		HypervisorID;
	char				Brand[64],
					Architecture[CODENAME_LEN];
} PROC_STRUCT;

typedef struct
{
	struct {
		signed int	AutoClock, /* 10: Auto, 01: Init, 00: Specs */
				Experimental,/* 0: Disable, 1: Enable	*/
				hotplug, /* < 0: Disable, Other: Enable */
				pci,	/*  < 0: Disable, other: Enable */
				nmi;	/* <> 0: Failed, == 0: Enable	*/
		struct {
		unsigned short
				cpuidle :  1-0,/* 0: Disable, 1: Enable */
				cpufreq :  2-1,/* 0: Disable, 1: Enable */
				unused	: 16-2;
		} Driver;
	} Registration;

	struct {
		Bit64		Operation	__attribute__ ((aligned (64)));

		OS_DRIVER	OS;

		unsigned int	tickReset,
				tickStep;

		pid_t		trackTask;
		enum SORTBYFIELD sortByField;
		int		reverseOrder,
				taskCount;
		TASK_MCB	taskList[TASK_LIMIT];

		MEM_MCB		memInfo;

		struct {
		unsigned short	version,
				major,
				minor;
		} kernel;

		char		sysname[MAX_UTS_LEN],
				release[MAX_UTS_LEN],
				version[MAX_UTS_LEN],
				machine[MAX_UTS_LEN];
	} SysGate;

	struct {
		unsigned int	Interval;
		struct timespec pollingWait,
				ringWaiting,
				childWaiting,
				sliceWaiting;
	} Sleep;

	struct {
		RING_CTRL	buffer[RING_SIZE] __attribute__((aligned(128)));
		unsigned int	head, tail;
	} Ring[2]; /* [0] Parent ; [1] Child				*/

	char				ShmName[TASK_COMM_LEN];
	pid_t				AppSvr,
					AppCli;

	struct {
		unsigned int		Boost[UNCORE_BOOST(SIZE)];
	    struct
	    {
		unsigned long long	Speed;
		unsigned int		Rate;
	    } Bus;

	    struct {
		struct {
			RAM_TIMING	Timing;
			RAM_GEOMETRY	DIMM[MC_MAX_DIMM];
		} Channel[MC_MAX_CHA];
		unsigned short		SlotCount, ChannelCount;
	    } MC[MC_MAX_CTRL];

	unsigned long long		CtrlSpeed;
	unsigned short			CtrlCount,
					ChipID;

	    struct {
		unsigned char	/* 00:MHz , 01:MT/s , 10:MB/s , 11:VOID */
					Bus_Rate: 2-0,
					BusSpeed: 4-2,
					DDR_Rate: 6-4,
					DDRSpeed: 8-6;
	    } Unit;

	    struct {
		enum CHIPSET		ArchID;
		char			CodeName[CODENAME_LEN];
	    } Chipset;
	} Uncore;

	SMBIOS_ST		SMB;

	PROC_STRUCT		Proc;
	CPU_STRUCT		Cpu[];
} SHM_STRUCT;


enum REASON_CLASS {
	RC_SUCCESS	= 0,
	RC_CMD_SYNTAX	= 1,
	RC_SHM_FILE	= 2,
	RC_SHM_MMAP	= 3,
	RC_PERM_ERR	= 4,
	RC_MEM_ERR	= 5,
	RC_EXEC_ERR	= 6,
	RC_SYS_CALL	= 15
};

typedef struct {
	__typeof__ (errno)	no: 32;
	__typeof__ (__LINE__)	ln: 28;
	enum REASON_CLASS	rc: 4;
} REASON_CODE;

#define REASON_SET_2xARG(_reason, _rc, _no)				\
({									\
	_reason.no = _no;						\
	_reason.ln = __LINE__;						\
	_reason.rc = _rc;						\
})

#define REASON_SET_1xARG(_reason, _rc)					\
({									\
	_reason.no = errno;						\
	_reason.ln = __LINE__;						\
	_reason.rc = _rc;						\
})

#define REASON_SET_0xARG(_reason)					\
({									\
	_reason.no = errno;						\
	_reason.ln = __LINE__;						\
	_reason.rc = RC_SYS_CALL;					\
})

#define REASON_DISPATCH(_1,_2,_3,REASON_CURSOR, ... ) REASON_CURSOR

#define REASON_SET( ... )						\
	REASON_DISPATCH( __VA_ARGS__ ,	REASON_SET_2xARG,		\
					REASON_SET_1xARG,		\
					REASON_SET_0xARG)( __VA_ARGS__ )

#define REASON_INIT(_reason)		\
	REASON_CODE _reason = {.no = 0, .ln = 0, .rc = RC_SUCCESS}

#define IS_REASON_SUCCESSFUL(_reason) (_reason.rc == RC_SUCCESS)
