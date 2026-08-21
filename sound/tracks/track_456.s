.align 2

.global track_456

track_456_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 90
	.byte VOL, 127
	.byte BEND, c_v
	.byte W54
	.byte N32, Cn3, v016
	.byte W32
	.byte FINE

.align 2

track_456:
	.byte 1
	.byte 0
	.byte 163
	.byte 128
	.word 0x80a8554
	.word track_456_0

.align 2
