.align 2

.global track_673

track_673_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte W10
	.byte VOICE, 3
	.byte VOL, 66
	.byte PAN, c_v
	.byte PRIO, 127
	.byte W24
	.byte N04, En4, v100
	.byte W28
	.byte W01
	.byte FINE

track_673_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 94
	.byte PAN, c_v
	.byte N22, Cn3, v100
	.byte W32
	.byte W02
	.byte N18, Fn2 @ v100
	.byte W12
	.byte VOL, 94
	.byte W03
	.byte 47 @ VOL
	.byte W02
	.byte 0 @ VOL
	.byte W12
	.byte FINE

.align 2

track_673:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word 0x80a838c
	.word track_673_0
	.word track_673_1

.align 2
