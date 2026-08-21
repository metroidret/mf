.align 2

.global track_628

track_628_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 20
	.byte VOL, 90
	.byte PAN, c_v
	.byte N84, Fn1, v127
	.byte W88
	.byte W01
	.byte FINE

track_628_1:
	.byte KEYSH, 0
	.byte VOICE, 21
	.byte VOL, 127
	.byte PAN, c_v
	.byte PRIO, 127
	.byte N36, Gn2, v120
	.byte W88
	.byte W01
	.byte FINE

.align 2

track_628:
	.byte 2
	.byte 0
	.byte 182
	.byte 0
	.word 0x80a7aa4
	.word track_628_0
	.word track_628_1

.align 2
