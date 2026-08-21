.align 2

.global track_462

track_462_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 96
	.byte VOL, 127
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N18, Cn3, v100
	.byte W18
	.byte FINE

.align 2

track_462:
	.byte 1
	.byte 0
	.byte 165
	.byte 128
	.word 0x80a8554
	.word track_462_0

.align 2
