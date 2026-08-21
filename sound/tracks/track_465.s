.align 2

.global track_465

track_465_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 100
	.byte VOL, 127
	.byte BENDR, 24
	.byte BEND, c_v
	.byte N02, Cn3, v024
	.byte W04
	.byte Dn3 @ N02, v024
	.byte W04
	.byte En3 @ N02, v024
	.byte W04
	.byte Fs3 @ N02, v024
	.byte W04
	.byte Gs3, v032 @ N02
	.byte W02
	.byte FINE

.align 2

track_465:
	.byte 1
	.byte 0
	.byte 168
	.byte 128
	.word 0x80a8554
	.word track_465_0

.align 2
