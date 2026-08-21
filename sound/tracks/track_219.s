.align 2

.global track_219

track_219_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte MOD, 0
	.byte VOL, 60
	.byte PAN, c_v
	.byte LFOS, 0
	.byte PRIO, 1
	.byte W08
	.byte N48, Cn3, v127
	.byte W03
	.byte VOL, 61
	.byte W03
	.byte 63 @ VOL
	.byte W03
	.byte 65 @ VOL
	.byte W03
	.byte 67 @ VOL
	.byte W03
	.byte 69 @ VOL
	.byte W03
	.byte 71 @ VOL
	.byte W03
	.byte 74 @ VOL
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 81 @ VOL
	.byte W03
	.byte 85 @ VOL
	.byte W03
	.byte 98 @ VOL
	.byte W03
	.byte 109 @ VOL
	.byte W03
	.byte 117 @ VOL
	.byte W03
	.byte 121 @ VOL
	.byte W03
	.byte 125 @ VOL
	.byte W03
	.byte FINE

track_219_1:
	.byte KEYSH, 0
	.byte W08
	.byte VOICE, 37
	.byte MOD, 80
	.byte VOL, 60
	.byte LFOS, 20
	.byte N48, Gn3, v040
	.byte W03
	.byte VOL, 69
	.byte W03
	.byte 77 @ VOL
	.byte W03
	.byte 83 @ VOL
	.byte W03
	.byte 87 @ VOL
	.byte W03
	.byte 89 @ VOL
	.byte W18
	.byte 89 @ VOL
	.byte W03
	.byte 73 @ VOL
	.byte W03
	.byte 59 @ VOL
	.byte W03
	.byte 51 @ VOL
	.byte W03
	.byte 47 @ VOL
	.byte W03
	.byte FINE

.align 2

track_219:
	.byte 2
	.byte 0
	.byte 181
	.byte 0
	.word 0x80a6af0
	.word track_219_0
	.word track_219_1

.align 2
