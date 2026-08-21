.align 2

.global track_474

track_474_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 0
	.byte PAN, c_v
	.byte N06, Cn3, v127
	.byte W06
	.byte VOICE, 29
	.byte N03, Fs3, v112
	.byte W03
	.byte Cs3, v080 @ N03
	.byte W03
	.byte Gs2, v052 @ N03
	.byte W03
	.byte Fn2, v020 @ N03
	.byte W03
	.byte FINE

.align 2

track_474:
	.byte 1
	.byte 0
	.byte 132
	.byte 0
	.word 0x80a6d54
	.word track_474_0

.align 2
