.align 2

.global track_123

track_123_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 50
	.byte PAN, c_v
	.byte N08, Gs2, v100
	.byte W08
	.byte N40, Gn2, v040
	.byte W03
	.byte VOL, 37
	.byte W03
	.byte 27 @ VOL
	.byte W03
	.byte 18 @ VOL
	.byte W03
	.byte 12 @ VOL
	.byte W03
	.byte 8 @ VOL
	.byte W03
	.byte 6 @ VOL
	.byte W03
	.byte 4 @ VOL
	.byte W03
	.byte 3 @ VOL
	.byte W03
	.byte 2 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 1 @ VOL
	.byte W03
	.byte 0 @ VOL
	.byte W04
	.byte FINE

.align 2

track_123:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word 0x80a682c
	.word track_123_0

.align 2
