/*
 * CoreFreq
 * Copyright (C) 2015-2019 CYRIL INGENIERIE
 * Licenses: GPL2
 */

#define CLEAR_EVENT_MASK	0x0000000000000ff0

#define TRACK_TASK		0x0200000000000000
#define TRACK_MASK		0x0000000000007fff

#define CPU_ONLINE		0x0000080000000000
#define CPU_OFFLINE		0x0000100000000000
#define CPU_SELECT		0x0000200000000000
#define CPU_MASK		0x00000000000000ff

#define BOXKEY_TURBO_CLOCK	0x00010000
#define BOXKEY_TURBO_CLOCK_NC	0x00020000LLU

#define BOXKEY_RATIO_CLOCK	0x00040000
#define BOXKEY_RATIO_CLOCK_OR	0x00080000LLU

#define BOXKEY_UNCORE_CLOCK	0x00400000
#define BOXKEY_UNCORE_CLOCK_OR	0x00800000LLU

#define CLOCKMOD_RATIO_MASK	0x0000ffff

#define OPS_RECORDER_MASK	0x00000000000000f0LLU

#define SMBIOS_STRING_INDEX	0x0010000000000000
#define SMBIOS_STRING_MASK	0x00000000000000ffLLU

enum {
	SORTBY_STATE		= 0x010000000000000e,
	SORTBY_RTIME		= 0x010000000000000d,
	SORTBY_UTIME		= 0x010000000000000c,
	SORTBY_STIME		= 0x010000000000000b,
	SORTBY_PID		= 0x010000000000000a,
	SORTBY_COMM		= 0x0100000000000009,

	OPS_INTERVAL		= 0x1000000000001000,
	OPS_INTERVAL_100	= 0x1000000000001001,
	OPS_INTERVAL_150	= 0x1000000000001011,
	OPS_INTERVAL_250	= 0x1000000000001021,
	OPS_INTERVAL_500	= 0x1000000000001031,
	OPS_INTERVAL_750	= 0x1000000000001041,
	OPS_INTERVAL_1000	= 0x1000000000001051,
	OPS_INTERVAL_1500	= 0x1000000000001061,
	OPS_INTERVAL_2000	= 0x1000000000001071,
	OPS_INTERVAL_2500	= 0x1000000000001081,
	OPS_INTERVAL_3000	= 0x1000000000001091,
	OPS_AUTOCLOCK		= 0x1000000000002000,
	OPS_AUTOCLOCK_OFF	= 0x1000000000002001,
	OPS_AUTOCLOCK_ON	= 0x1000000000002002,
	OPS_EXPERIMENTAL	= 0x1000000000004000,
	OPS_EXPERIMENTAL_OFF	= 0x1000000000004001,
	OPS_EXPERIMENTAL_ON	= 0x1000000000004002,
	OPS_INTERRUPTS		= 0x1000000000008000,
	OPS_INTERRUPTS_OFF	= 0x1000000000008001,
	OPS_INTERRUPTS_ON	= 0x1000000000008002,
	OPS_RECORDER		= 0x1000000000010000,
	OPS_RECORDER_RESET	= 0x1000000000010010,
	OPS_RECORDER_X002	= 0x1000000000010020,
	OPS_RECORDER_X010	= 0x1000000000010030,
	OPS_RECORDER_X020	= 0x1000000000010040,
	OPS_RECORDER_X060	= 0x1000000000010050,
	OPS_RECORDER_X090	= 0x1000000000010060,
	OPS_RECORDER_X120	= 0x1000000000010070,
	OPS_RECORDER_X240	= 0x1000000000010080,

	BOXKEY_EIST		= 0x3000000000000004,
	BOXKEY_EIST_OFF 	= 0x3000000000000005,
	BOXKEY_EIST_ON		= 0x3000000000000006,
	BOXKEY_C1E		= 0x3000000000000008,
	BOXKEY_C1E_OFF		= 0x3000000000000009,
	BOXKEY_C1E_ON		= 0x300000000000000a,
	BOXKEY_TURBO		= 0x3000000000000010,
	BOXKEY_TURBO_OFF	= 0x3000000000000011,
	BOXKEY_TURBO_ON 	= 0x3000000000000012,
	BOXKEY_C1A		= 0x3000000000000020,
	BOXKEY_C1A_OFF		= 0x3000000000000021,
	BOXKEY_C1A_ON		= 0x3000000000000022,
	BOXKEY_C3A		= 0x3000000000000040,
	BOXKEY_C3A_OFF		= 0x3000000000000041,
	BOXKEY_C3A_ON		= 0x3000000000000042,
	BOXKEY_C1U		= 0x3000000000000080,
	BOXKEY_C1U_OFF		= 0x3000000000000081,
	BOXKEY_C1U_ON		= 0x3000000000000082,
	BOXKEY_C3U		= 0x3000000000000100,
	BOXKEY_C3U_OFF		= 0x3000000000000101,
	BOXKEY_C3U_ON		= 0x3000000000000102,
	BOXKEY_PKGCST		= 0x3000000000000200,
	BOXKEY_PKGCST_C0	= 0x3000000000000201,
	BOXKEY_PKGCST_C1	= 0x3000000000000211,
	BOXKEY_PKGCST_C2	= 0x3000000000000221,
	BOXKEY_PKGCST_C3	= 0x3000000000000231,
	BOXKEY_PKGCST_C6	= 0x3000000000000261,
	BOXKEY_PKGCST_C7	= 0x3000000000000271,
	BOXKEY_PKGCST_C8	= 0x3000000000000281,
	BOXKEY_PKGCST_C9	= 0x3000000000000291,
	BOXKEY_PKGCST_C10	= 0x30000000000002a1,
	BOXKEY_IOMWAIT		= 0x3000000000000400,
	BOXKEY_IOMWAIT_OFF	= 0x3000000000000401,
	BOXKEY_IOMWAIT_ON	= 0x3000000000000402,
	BOXKEY_IORCST		= 0x3000000000000800,
	BOXKEY_IORCST_C0	= 0x3000000000000801,
	BOXKEY_IORCST_C3	= 0x3000000000000831,
	BOXKEY_IORCST_C4	= 0x3000000000000841,
	BOXKEY_IORCST_C6	= 0x3000000000000861,
	BOXKEY_IORCST_C7	= 0x3000000000000871,
	BOXKEY_IORCST_C8	= 0x3000000000000881,
	BOXKEY_ODCM		= 0x3000000000001000,
	BOXKEY_ODCM_OFF 	= 0x3000000000001001,
	BOXKEY_ODCM_ON		= 0x3000000000001002,
	BOXKEY_DUTYCYCLE	= 0x3000000000001100,
	BOXKEY_ODCM_DC00	= 0x3000000000001101,
	BOXKEY_ODCM_DC01	= 0x3000000000001111,
	BOXKEY_ODCM_DC02	= 0x3000000000001121,
	BOXKEY_ODCM_DC03	= 0x3000000000001131,
	BOXKEY_ODCM_DC04	= 0x3000000000001141,
	BOXKEY_ODCM_DC05	= 0x3000000000001151,
	BOXKEY_ODCM_DC06	= 0x3000000000001161,
	BOXKEY_ODCM_DC07	= 0x3000000000001171,
	BOXKEY_ODCM_DC08	= 0x3000000000001181,
	BOXKEY_ODCM_DC09	= 0x3000000000001191,
	BOXKEY_ODCM_DC10	= 0x30000000000011a1,
	BOXKEY_ODCM_DC11	= 0x30000000000011b1,
	BOXKEY_ODCM_DC12	= 0x30000000000011c1,
	BOXKEY_ODCM_DC13	= 0x30000000000011d1,
	BOXKEY_ODCM_DC14	= 0x30000000000011e1,
	BOXKEY_PWR_POLICY	= 0x3000000000002100,
	BOXKEY_PWR_POL00	= 0x3000000000002101,
	BOXKEY_PWR_POL01	= 0x3000000000002111,
	BOXKEY_PWR_POL02	= 0x3000000000002121,
	BOXKEY_PWR_POL03	= 0x3000000000002131,
	BOXKEY_PWR_POL04	= 0x3000000000002141,
	BOXKEY_PWR_POL05	= 0x3000000000002151,
	BOXKEY_PWR_POL06	= 0x3000000000002161,
	BOXKEY_PWR_POL07	= 0x3000000000002171,
	BOXKEY_PWR_POL08	= 0x3000000000002181,
	BOXKEY_PWR_POL09	= 0x3000000000002191,
	BOXKEY_PWR_POL10	= 0x30000000000021a1,
	BOXKEY_PWR_POL11	= 0x30000000000021b1,
	BOXKEY_PWR_POL12	= 0x30000000000021c1,
	BOXKEY_PWR_POL13	= 0x30000000000021d1,
	BOXKEY_PWR_POL14	= 0x30000000000021e1,
	BOXKEY_PWR_POL15	= 0x30000000000021f1,
	BOXKEY_CC6		= 0x3000000000004000,
	BOXKEY_CC6_OFF		= 0x3000000000004001,
	BOXKEY_CC6_ON		= 0x3000000000004002,
	BOXKEY_PC6		= 0x3000000000004010,
	BOXKEY_PC6_OFF		= 0x3000000000004011,
	BOXKEY_PC6_ON		= 0x3000000000004012,
	BOXKEY_HWP		= 0x3000000000004020,
	BOXKEY_HWP_ON		= 0x3000000000004021,
	BOXKEY_HWP_EPP		= 0x3000000000004040,
	BOXKEY_HWP_EPP_MIN	= 0x3000000000004041,
	BOXKEY_HWP_EPP_MED	= 0x3000000000004042,
	BOXKEY_HWP_EPP_PWR	= 0x3000000000004043,
	BOXKEY_HWP_EPP_MAX	= 0x3000000000004044,

	BOXKEY_TOOLS_MACHINE	= 0x3000000000010000,
	BOXKEY_TOOLS_ATOMIC	= 0x3000000000010010,
	BOXKEY_TOOLS_CRC32	= 0x3000000000010020,
	BOXKEY_TOOLS_CONIC	= 0x3000000000011000,
	BOXKEY_TOOLS_CONIC0	= 0x3000000000011401,
	BOXKEY_TOOLS_CONIC1	= 0x3000000000011411,
	BOXKEY_TOOLS_CONIC2	= 0x3000000000011421,
	BOXKEY_TOOLS_CONIC3	= 0x3000000000011431,
	BOXKEY_TOOLS_CONIC4	= 0x3000000000011441,
	BOXKEY_TOOLS_CONIC5	= 0x3000000000011451,
	BOXKEY_TOOLS_TURBO_RND	= 0x3000000000012001,
	BOXKEY_TOOLS_TURBO_RR	= 0x3000000000012011,
	BOXKEY_TOOLS_TURBO_CPU	= 0x3000000000012021,

	BOXKEY_LANG_ENGLISH	= 0x3000000000014021,
	BOXKEY_LANG_FRENCH	= 0x3000000000014022,

	BOXKEY_LIMIT_IDLE_STATE = 0x3000000000014800,
	BOXKEY_LIMIT_IDLE_ST00	= 0x3000000000014801,
	BOXKEY_LIMIT_IDLE_ST01	= 0x3000000000014811,
	BOXKEY_LIMIT_IDLE_ST02	= 0x3000000000014821,
	BOXKEY_LIMIT_IDLE_ST03	= 0x3000000000014831,
	BOXKEY_LIMIT_IDLE_ST04	= 0x3000000000014841,
	BOXKEY_LIMIT_IDLE_ST05	= 0x3000000000014851,
	BOXKEY_LIMIT_IDLE_ST06	= 0x3000000000014861,
	BOXKEY_LIMIT_IDLE_ST07	= 0x3000000000014871,
	BOXKEY_LIMIT_IDLE_ST08	= 0x3000000000014881,
	BOXKEY_LIMIT_IDLE_ST09	= 0x3000000000014891,
	BOXKEY_LIMIT_IDLE_ST10	= 0x30000000000148a1,

	BOXKEY_CLR_THM_SENSOR	= 0x3000000000020011,
	BOXKEY_CLR_THM_PROCHOT	= 0x3000000000020021,
	BOXKEY_CLR_THM_CRIT	= 0x3000000000020041,
	BOXKEY_CLR_THM_THOLD	= 0x3000000000020081,
	BOXKEY_CLR_PWR_LIMIT	= 0x3000000000020101,
	BOXKEY_CLR_CUR_LIMIT	= 0x3000000000020201,
	BOXKEY_CLR_X_DOMAIN	= 0x3000000000020401,

	BOXKEY_TURBO_CLOCK_1C	= ((BOXKEY_TURBO_CLOCK_NC | 1) << 32),
	BOXKEY_TURBO_CLOCK_2C	= ((BOXKEY_TURBO_CLOCK_NC | 2) << 32),
	BOXKEY_TURBO_CLOCK_3C	= ((BOXKEY_TURBO_CLOCK_NC | 3) << 32),
	BOXKEY_TURBO_CLOCK_4C	= ((BOXKEY_TURBO_CLOCK_NC | 4) << 32),
	BOXKEY_TURBO_CLOCK_5C	= ((BOXKEY_TURBO_CLOCK_NC | 5) << 32),
	BOXKEY_TURBO_CLOCK_6C	= ((BOXKEY_TURBO_CLOCK_NC | 6) << 32),
	BOXKEY_TURBO_CLOCK_7C	= ((BOXKEY_TURBO_CLOCK_NC | 7) << 32),
	BOXKEY_TURBO_CLOCK_8C	= ((BOXKEY_TURBO_CLOCK_NC | 8) << 32),

	BOXKEY_RATIO_CLOCK_TGT	= ((BOXKEY_RATIO_CLOCK_OR|CLOCK_MOD_TGT) << 32),
	BOXKEY_RATIO_CLOCK_MAX	= ((BOXKEY_RATIO_CLOCK_OR|CLOCK_MOD_MAX) << 32),
	BOXKEY_RATIO_CLOCK_MIN	= ((BOXKEY_RATIO_CLOCK_OR|CLOCK_MOD_MIN) << 32),
    BOXKEY_RATIO_CLOCK_HWP_TGT =((BOXKEY_RATIO_CLOCK_OR|CLOCK_MOD_HWP_TGT)<<32),
    BOXKEY_RATIO_CLOCK_HWP_MAX =((BOXKEY_RATIO_CLOCK_OR|CLOCK_MOD_HWP_MAX)<<32),
    BOXKEY_RATIO_CLOCK_HWP_MIN =((BOXKEY_RATIO_CLOCK_OR|CLOCK_MOD_HWP_MIN)<<32),

	BOXKEY_UNCORE_CLOCK_MAX =((BOXKEY_UNCORE_CLOCK_OR|CLOCK_MOD_MAX) << 32),
	BOXKEY_UNCORE_CLOCK_MIN =((BOXKEY_UNCORE_CLOCK_OR|CLOCK_MOD_MIN) << 32)
};

#define powered(bit)	( (bit) ? (char*) RSC(PRESENT).CODE()		\
				: (char*) RSC(MISSING).CODE() )

#define enabled(bit)	((bit) ? " ON" : "OFF")

#define MARGIN_WIDTH	2
#define MARGIN_HEIGHT	1
#define INTER_WIDTH	3
#define INTER_HEIGHT	(3 + 1)
#define LEADING_LEFT	(MIN_WIDTH / (MARGIN_WIDTH + (4 * INTER_WIDTH)))
#define LEADING_TOP	1

#define LOAD_LEAD	4

#define LayerDeclare(_ID, _len, _col, _row, _var)			\
	struct {							\
		Coordinate	origin ;				\
		CUINT		length ;				\
		ATTRIBUTE	*attr;					\
		ASCII		*code;					\
	} _var = {							\
		.origin = {						\
			.col = _col,					\
			.row = _row					\
		},							\
		.length = _len,						\
		.attr = RSC(_ID).ATTR(),				\
		.code = RSC(_ID).CODE() 				\
	}

typedef char HBCLK[11 + 1];

enum DISPOSAL {
	D_MAINVIEW,
	D_DASHBOARD,
	D_ASCIITEST
};

#define DISPOSAL_SIZE	(1 + D_ASCIITEST)

enum VIEW {
	V_FREQ,
	V_INST,
	V_CYCLES,
	V_CSTATES,
	V_PACKAGE,
	V_TASKS,
	V_INTR,
	V_VOLTAGE,
	V_SLICE
};

#define VIEW_SIZE	(1 + V_SLICE)

typedef void (*DISPOSAL_FUNC)(Layer*);

typedef CUINT (*VIEW_FUNC)(Layer*, const unsigned int, CUINT);

#define CELL_ARGS	Window *win,					\
			unsigned long long key, 			\
			ATTRIBUTE *attrib,				\
			ASCII *item

typedef TGrid* (*CELL_FUNC)(CELL_ARGS);

#define RENDER_OK	0x000
#define RENDER_KO	0x010
#define RENDER_OFF	0x100

#define RECORDER_DEFAULT 30

#define RECORDER_COMPUTE(_recorder, _interval)				\
({									\
	_recorder.Reset = (	(_recorder.Ratios[_recorder.Select]	\
				* RECORDER_DEFAULT			\
				* 1000) / _interval );			\
})

#define RECORDER_SECONDS(_tick, _interval)				\
	((_interval * _tick) / 1000)

