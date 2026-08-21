.align 2

.global track_350

track_350_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 35
	.byte VOL, 70
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-32
	.byte N10, Cn4, v080
	.byte W02
	.byte BEND, c_v+3
	.byte W03
	.byte c_v+7 @ BEND
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v @ BEND
	.byte W01
	.byte FINE

.align 2

track_350:
	.byte 1
	.byte 0
	.byte 166
	.byte 0
	.word 0x80a6d54
	.word track_350_0

.align 2
