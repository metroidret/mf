.align 2

.global track_270

track_270_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 26
	.byte VOL, 50
	.byte PAN, c_v
	.byte N04, Cn4, v060
	.byte W04
	.byte En4, v068 @ N04
	.byte W04
	.byte As4, v072 @ N04
	.byte W04
	.byte Dn4, v076 @ N04
	.byte W04
	.byte Gs4, v080 @ N04
	.byte W04
	.byte Fs4, v088 @ N04
	.byte W04
	.byte Cn5, v092 @ N04
	.byte W04
	.byte Dn4, v096 @ N04
	.byte W04
	.byte As4, v100 @ N04
	.byte W04
	.byte Fs4, v108 @ N04
	.byte W04
	.byte Gs4, v112 @ N04
	.byte W04
	.byte Cn5, v116 @ N04
	.byte W04
	.byte Cn4, v060 @ N04
	.byte W04
	.byte En4, v068 @ N04
	.byte W04
	.byte As4, v072 @ N04
	.byte W04
	.byte Dn4, v076 @ N04
	.byte W04
	.byte Gs4, v080 @ N04
	.byte W04
	.byte Fs4, v088 @ N04
	.byte W04
	.byte Cn5, v092 @ N04
	.byte W04
	.byte Gs4, v096 @ N04
	.byte W04
	.byte As4, v100 @ N04
	.byte W04
	.byte Dn4, v108 @ N04
	.byte W04
	.byte Gs4, v112 @ N04
	.byte W04
	.byte Cn5, v116 @ N04
	.byte W04
	.byte Cn4, v060 @ N04
	.byte W04
	.byte En4, v068 @ N04
	.byte W04
	.byte As4, v072 @ N04
	.byte W04
	.byte Dn4, v076 @ N04
	.byte W04
	.byte Gs4, v080 @ N04
	.byte W04
	.byte Fs4, v088 @ N04
	.byte W04
	.byte Cn5, v092 @ N04
	.byte W04
	.byte Cn4, v096 @ N04
	.byte W04
	.byte Fs4, v072 @ N04
	.byte W04
	.byte Gs4, v060 @ N04
	.byte W04
	.byte En4, v052 @ N04
	.byte W04
	.byte Cn5, v048 @ N04
	.byte W04
	.byte FINE

track_270_1:
	.byte KEYSH, 0
	.byte VOICE, 28
	.byte VOL, 19
	.byte PAN, c_v
	.byte N10, Dn3, v127, 69
	.byte W48
	.byte En3 @ N10, v127
	.byte N10, Bn3 @ v127
	.byte W48
	.byte N20, Cs3 @ v127
	.byte N20, Gs3 @ v127
	.byte W48
	.byte FINE

track_270_2:
	.byte VOL, 50
	.byte KEYSH, 0
	.byte VOICE, 29
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v+56
	.byte TIE, Cn3, v040
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte c_v+56 @ BEND
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+48
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+40
	.byte W01
	.byte VOL, 27
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 23
	.byte BEND, c_v+24
	.byte W01
	.byte VOL, 21
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v
	.byte W01
	.byte VOL, 15
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 13
	.byte BEND, c_v-16
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-24
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-32
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-40
	.byte W01
	.byte VOL, 5
	.byte BEND, c_v-48
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-56
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-64
	.byte W01
	.byte EOT @ Cn3, v040
	.byte FINE

.align 2

track_270:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word 0x80a71ec
	.word track_270_0
	.word track_270_1
	.word track_270_2

.align 2
