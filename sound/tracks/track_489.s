.align 2

.global track_489

track_489_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 50
	.byte VOL, 25
	.byte PAN, c_v
	.byte TIE, Gn2, v127
	.byte W30
	.byte VOL, 27
	.byte W30
	.byte 30 @ VOL
	.byte W30
	.byte 32 @ VOL
	.byte W06
	.byte W24
	.byte 35 @ VOL
	.byte W32
	.byte W01
	.byte 37 @ VOL
	.byte W30
	.byte 40 @ VOL
	.byte W09
	.byte W21
	.byte 42 @ VOL
	.byte W32
	.byte W01
	.byte 45 @ VOL
	.byte W30
	.byte 47 @ VOL
	.byte W12
	.byte W18
	.byte 50 @ VOL
	.byte W03
	.byte 50 @ VOL
	.byte W24
	.byte W03
	.byte 52 @ VOL
	.byte W32
	.byte W01
	.byte 55 @ VOL
	.byte W15
	.byte W15
	.byte 57 @ VOL
	.byte W30
	.byte 60 @ VOL
	.byte W32
	.byte W01
	.byte 62 @ VOL
	.byte W18
	.byte W12
	.byte 65 @ VOL
	.byte W30
	.byte 68 @ VOL
	.byte W32
	.byte W01
	.byte 70 @ VOL
	.byte W21
	.byte W09
	.byte 73 @ VOL
	.byte W30
	.byte 75 @ VOL
	.byte W30
	.byte 78 @ VOL
	.byte W24
	.byte W03
	.byte 80 @ VOL
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W48
	.byte EOT @ Gn2, v127
	.byte FINE

.align 2

track_489:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a7798
	.word track_489_0

.align 2
