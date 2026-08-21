.align 2

.global track_147

track_147_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 30
	.byte PAN, c_v
	.byte N08, En2, v080
	.byte W08
	.byte Fn2, v100 @ N08
	.byte W08
	.byte Gn2, v080 @ N08
	.byte W08
	.byte N40, An2, v064
	.byte W03
	.byte VOL, 22
	.byte W03
	.byte 16 @ VOL
	.byte W03
	.byte 11 @ VOL
	.byte W03
	.byte 7 @ VOL
	.byte W03
	.byte 5 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W04
	.byte FINE

.align 2

track_147:
	.byte 1
	.byte 0
	.byte 150
	.byte 0
	.word 0x80a682c
	.word track_147_0

.align 2
