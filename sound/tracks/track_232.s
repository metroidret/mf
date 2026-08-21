.align 2

.global track_232

track_232_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 31
	.byte VOL, 55
	.byte PAN, c_v
	.byte BENDR, 12
	.byte PRIO, 1
	.byte BEND, c_v+51
	.byte N13, Cn3, v100
	.byte W16
	.byte FINE

track_232_1:
	.byte KEYSH, 0
	.byte VOICE, 20
	.byte VOL, 33
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+51
	.byte N13, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_232:
	.byte 2
	.byte 0
	.byte 197
	.byte 0
	.word 0x80a6af0
	.word track_232_0
	.word track_232_1

.align 2
