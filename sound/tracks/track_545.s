.align 2

.global track_545

track_545_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 100
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N09, Cn3, v127
	.byte W02
	.byte BEND, c_v-45
	.byte W02
	.byte c_v-39 @ BEND
	.byte W02
	.byte c_v-29 @ BEND
	.byte W02
	.byte c_v-15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte N09, Dn3, v100
	.byte W09
	.byte FINE

.align 2

track_545:
	.byte 1
	.byte 0
	.byte 228
	.byte 0
	.word 0x80a826c
	.word track_545_0

.align 2
