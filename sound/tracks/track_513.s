.align 2

.global track_513

track_513_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 80
	.byte VOL, 32
	.byte BENDR, 16
	.byte BEND, c_v+59
	.byte N19, Ds1, v012, 45
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v+56
	.byte W01
	.byte VOL, 127
	.byte BEND, c_v+52
	.byte W01
	.byte VOL, 119
	.byte BEND, c_v+49
	.byte W01
	.byte VOL, 111
	.byte BEND, c_v+46
	.byte W01
	.byte VOL, 103
	.byte BEND, c_v+42
	.byte W01
	.byte VOL, 95
	.byte BEND, c_v+39
	.byte W01
	.byte VOL, 87
	.byte BEND, c_v+36
	.byte W01
	.byte VOL, 79
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 71
	.byte BEND, c_v+29
	.byte W01
	.byte VOL, 63
	.byte BEND, c_v+26
	.byte W01
	.byte VOL, 55
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 47
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 39
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+13
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+9
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v
	.byte W01
	.byte FINE

.align 2

track_513:
	.byte 1
	.byte 0
	.byte 251
	.byte 128
	.word 0x80a8554
	.word track_513_0

.align 2
