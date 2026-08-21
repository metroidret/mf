.align 2

.global track_685

track_685_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 120
	.byte PAN, c_v
	.byte N30, An2, v100
	.byte W24
	.byte VOL, 120
	.byte W01
	.byte 96 @ VOL
	.byte W01
	.byte 71 @ VOL
	.byte W01
	.byte 48 @ VOL
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_685:
	.byte 1
	.byte 0
	.byte 229
	.byte 0
	.word 0x80a838c
	.word track_685_0

.align 2
